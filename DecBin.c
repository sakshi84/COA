/**
 * Author: 1)Rohan kulshreshtha && 2)Sakshi sharma && 3)Sanyam jain && 4)shubham vyas
 * Dated: 6-3-2016
 * C program which converts any given mnemonic code (as used in our ISA) to its equivalent binary machine code.
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_Size 30


char * bin(int n) //decimal to binary
    {
    int c, d, count;
    char *pointer;
    count = 0;
    pointer = (char*)malloc(32+1);
    for ( c = 4 ; c >= 0 ; c-- )
    {
    d = n >> c;
    if ( d & 1 )
    *(pointer+count) = 1 + '0';
    else
    *(pointer+count) = 0 + '0';
    count++;
    }
    *(pointer+count) = '\0';
    return pointer;
    }
 
char* fun(char a[],int b[]){
int i=1,j=0;
char string3[Max_Size];	
if(a[0]=='l')
	{
		int k=0;
		while(a[k]!='\n')
		{
			k++;
		}
		return bin(b[a[k-1]-'0']);
	}
		
if(a[0]=='#')
	{
		while(a[i]!='\0')
		{			
		string3[j]=a[i];
		j++;i++;
		}
		return bin(atoi(string3));
	}
if(a[0]=='$')
	{
		while(a[i]!='\0')
		{			
			string3[j]=a[i];
			j++;i++;
		}
		return bin(b[string3[j-1]-'0']);
	}
    	
	
	if(strcmp(a,"ADD1")==0)
	{
  		return "00000000000000000";
  	}
  	else if(strcmp(a,"SUB1")==0)
	{
  		return "00000000000000001";
  	}
  	else if(strcmp(a,"MUL1")==0)
	{
  		return "00000000000000010";
  	}
  	else if(strcmp(a,"DIV1")==0)
	{
  		return "00000000000000011";
  		
  	}
  	else if(strcmp(a,"MOV")==0)
	{
  		return "0000000000000000000100";
  	}
  	else if(strcmp(a,"STB")==0)
	{
  		return "0000000000000000000101";
  	}
  	else if(strcmp(a,"LDB")==0)
	{
  		return "0000000000000000000111";
  	}
  	else if(strcmp(a,"CMP")==0)
	{
  		return "0000000000000000000110";
  	}
  	else if(strcmp(a,"JEQ")==0)
	{
  		return "000000000000000000000001000";
  	}
  	else if(strcmp(a,"JMP")==0)
	{
  		return "000000000000000000000001001";
  	}
  	else if(strcmp(a,"JLT")==0)
	{
  		return "000000000000000000000001010";
  	}
  	else if(strcmp(a,"JGT")==0)
	{
  		return "000000000000000000000001011";
  	}
  	else if(strcmp(a,"INC")==0)
	{
  		return "000000000000000000000001100";
  	}
  	else if(strcmp(a,"DEC")==0)
	{
  		return "000000000000000000000001101";
  	}
  	else if(strcmp(a,"HLT")==0)
	{
  		return "00000000000000000000000000010000";
  	}
	else if(strcmp(a,"R00")==0)
	{
  		return "00000";
  	}
	else if(strcmp(a,"R01")==0)
	{
  		return "00001";
  	}
	else if(strcmp(a,"R02")==0)
	{
  		return "00010";
  	}
  	else if(strcmp(a,"R03")==0)
	{
  		return "00011";
  	}
	else if(strcmp(a,"R04")==0)
	{
  		return "00100";
  	}
	else 
		return "nothing";  
  }     

void main() {
        
     FILE *fin,*fout;
     fin = fopen("input.txt","r");
     fout = fopen("output.txt","w"); 
     char string0[Max_Size + 1];
     char string1[Max_Size + 1];  /* This is used to store the output lines */
     char string2[Max_Size];
    
     int length;      /* keeps length in check */
     int i;
     int j=0;
     
     int arr[10];
     int line=1;
     
      while ( fgets( string0, Max_Size + 1, fin ) != NULL )
	{
	      	int k=0;
	      	if(string0[0]=='l')
		{
	      	
			while(string0[k]!='\n')
			{
				k++;
			}
		
		int m=string0[k-1]-'0';
		arr[m]=line;
		}
		line++;
		
	}
	fclose(fin);
	fin = fopen("input.txt","r");
        while ( fgets( string1, Max_Size + 1, fin ) != NULL ){
        
		length = strlen(string1);
		
		for(i=0;i<length+1;i++)
		{
			if(string1[i]=='\0')
			{
        	   		break;
        	   	}
	       		if(string1[i]!=' '&&string1[i]!=','&&string1[i]!='\n')
			{
				string2[j]=string1[i];
		   		j++;
		   	}
			else
			{
			   	string2[j]='\0';
		   		fprintf(fout,"%s ",fun(string2,arr));
				memset(string2,0,Max_Size);
				j=0;
			}
		   	
            	}
            	    fprintf(fout,"\n"); 
            	    
           }
        
   }
    

