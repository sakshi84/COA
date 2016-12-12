#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
FILE *fin,*fout;
void add1(int ,int ,int);
void sub1(int ,int ,int);
void mul1(int ,int ,int);
void div1(int ,int ,int);
int findreg(char a[],int i);
void three(char a[]);
void one(char a[]);
void dec(int r1);
void inc(int r1);
void jmp(int r1);
void jeq(int r1);
void jlt(int r1);
void jne(int r1);
void jgt(int r1);

int findreg(char a[],int i){
	char b[19];
	int t=0,p;
	int j,sum=0,k;
	for(p=i;p<i+5;p++){
	b[t]=a[p];
	t++;
	}
	b[5]='\0';
	for(j=0;j<=4;j++){
	k=b[4-j]-'0';
	sum=sum+pow(2,j)*k;
	}
    
	return sum;
}


int reg[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void three(char a[]){
	int r1=0,r2=0,r3=0;
	r1=findreg(a,17);
	r2=findreg(a,22);
	r3=findreg(a,27);
	//printf("#%d %d %d #\n",r1,r2,r3);
	if(a[15]=='0' && a[16]=='0')
	add1(r1,r2,r3);
	else if(a[15]=='0' && a[16]=='1')
	sub1(r1,r2,r3);
	else if(a[15]=='1' && a[16]=='0')
	mul1(r1,r2,r3);
	else if(a[15]=='1' && a[16]=='1')
	div1(r1,r2,r3);
	else
	printf("error \n");
}

void two(char a[]){
//	printf("two called");
	int r1=0,r2=0;
	r1=findreg(a,22);
	r2=findreg(a,27);
	//printf("#%d %d #\n",r1,r2);
	if(a[20]=='0' && a[21]=='0')
	mov(r1,r2);	
	else if(a[20]=='0' && a[21]=='1'){
	movi(r1,r2);
}
	else if(a[20]=='1' && a[21]=='0')
	cmp(r1,r2);	
		else if(a[20]=='1' && a[21]=='1')
	cmpi(r1,r2);

	
	else
	printf("**error \n");
}


void one(char a[]){
    	int r1;
    	r1=findreg(a,27);
   //	printf("one called   %d",r1);
    	if(a[24]=='0'&&a[25]=='0'&&a[26]=='0')
    	jeq(r1);
	else if(a[24]=='0'&&a[25]=='0'&&a[26]=='1')
    	jmp(r1);
	else if(a[24]=='0'&&a[25]=='1'&&a[26]=='0')
    	jlt(r1);
	else if(a[24]=='0'&&a[25]=='1'&&a[26]=='1')
    	jgt(r1);
    	else if(a[24]=='1'&&a[25]=='0'&&a[26]=='0')
    	inc(r1);
    	else if(a[24]=='1'&&a[25]=='0'&&a[26]=='1')
    	dec(r1);
    	else if(a[24]=='1'&&a[25]=='1'&&a[26]=='0')
    	jne(r1);
	else
    	printf("error in one!!");
}
 
void jeq(int r1){
	if(reg[18]==1){
	fprintf(fout,"\njump if equal to %d\n",r1);
    	jmp(r1);// address of destination
	}
	else  
    	;
}
void jne(int r1){
		fprintf(fout,"\njump if not equal to %d\n",r1);
	if(reg[18]!=1){
    	jmp(r1);// address of destination
	}
	else  
    	;
}
 
void jmp(int r1){
		fprintf(fout,"\njump to %d\n",r1);
	fseek(fin,33*(r1-1)+1,SEEK_SET);
	}
 
void jlt(int r1){
		fprintf(fout,"\njump if less than %d\n",r1);
	if(reg[17]==1)
    	jmp(r1);
	else  
    	;
}
 
void jgt(int r1){
	fprintf(fout,"\njump if greater than %d\n",r1);
	if(reg[18]==0&&reg[17]==0)
    	jmp(r1);
	else  
    	;
}
 
void inc(int r1){
	fprintf(fout,"\n%d index in inc\n",r1);  
   reg[r1]++;
}
 
void dec(int r1){
	fprintf(fout,"\n%d index in dec\n",r1);
	reg[r1]--;
}

void add1(int r1,int r2,int r3){
	fprintf(fout,"\naddition of %d and %d registers stored in %d register\n",r2,r3,r1);
	reg[r1]=reg[r2]+reg[r3];
	//printf("%d %d %d \n",reg[r1],reg[r2],reg[r3]);
}

void sub1(int r1,int r2,int r3){
	fprintf(fout,"\nsubstraction of %d and %d registers stored in %d register\n",r2,r3,r1);
	reg[r1]=reg[r2]-reg[r3];
	//printf("%d %d %d \n",reg[r1],reg[r2],reg[r3]);
}

void mul1(int r1,int r2,int r3){
		fprintf(fout,"\nmultiplication of %d and %d registers stored in %d register\n",r2,r3,r1);
	reg[r1]=reg[r2]*reg[r3];
	//printf("%d %d %d \n",reg[r1],reg[r2],reg[r3]);
}

void div1(int r1,int r2,int r3){
		fprintf(fout,"\ndivision of %d and %d registers stored in %d register\n",r2,r3,r1);
	reg[r1]=reg[r2]/reg[r3];
	//printf("%d %d %d \n",reg[r1],reg[r2],reg[r3]);
}


void mov(int r1,int r2){
	fprintf(fout,"movement of %d register to %d register",r1,r2);
	reg[r2]=reg[r1];
}
void movi(int r1,int r2){
		fprintf(fout,"movement of %d  to %d register",r1,r2);
	reg[r2]=r1;
}


void cmp(int r1,int r2){
	fprintf(fout,"comparision of register %d %d",r1,r2);
	if(reg[r1]==reg[r2])
	reg[18]=1;    	//R18 is Z
	else if(reg[r1]>reg[r2])
	reg[17]=1;    	//R17 is Negative(N)
	else
	return ;
}
void cmpi(int r1,int r2){
	fprintf(fout,"comparision of register %d and %d",r2,r1);
	if(r1==reg[r2])
	reg[18]=1;    	//R18 is Z
	else if(r1>reg[r2])
	reg[17]=1;    	//R17 is Negative(N)
	else
	return ;
}


void print(FILE * fout){
	int i;
	fprintf(fout,"\n***************OUTPUT***************\n");
	for(i=0;i<17;i++){
    	fprintf(fout,"|R%d %d |",i,reg[i]);
	}
	fprintf(fout,"\n ####SPECIAL REGISTERS#### \n");
	for(i=17;i<=20;i++){
    	fprintf(fout,"|R%d %d |",i,reg[i]);
	}
}

void halt(){
	exit(0);
}



int main(){
int i,length;
	int zero=0;
	char string1[40];
	 
     	fin = fopen("in.txt","r");
     	fout = fopen("out.txt","w");  
  
  	while ( fgets( string1, 80, fin ) != NULL ){// input from file
    	zero=0;
    	print(fout);
        	length = strlen(string1);
    	for(i=0;i<length;i++){
        	if(string1[i]=='0')
        	zero++;
        	else  
            	break;   	 
           	}
    	//printf("%d %d ",zero,i);
    	
    	if(zero==14)
    	three(string1);
    	else if(zero==19)
    	two(string1);
    	else if(zero==23)
    	one(string1);
    	else if(zero==0)
    	halt();
    	else
    	{
    	
    	exit(0);
   }
   	 
    	}
//	print(fout);

	return 0;
}


