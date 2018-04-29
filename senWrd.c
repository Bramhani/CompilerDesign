#include<stdio.h>
int senCount()
{
	FILE *f;
	char c;
	int count=0;
	f=fopen("orig.txt","r");
	while((c=fgetc(f))!=EOF)
	{
		if(c=='.')
		{
			count++;
		}
	}
	return(count);
	fclose(f);
}
void sentence()
{
	FILE *f,*f1;
	char c,d;
	int i=1;
	f=fopen("orig.txt","r");
	f1=fopen("sentence.txt","w");
	int count=senCount();
	if((c=fgetc(f))!=EOF)
	{
		fprintf(f1,"%d:",i);
		i++;		//this is for line numbers
	}
	ungetc(c,f);		//this is for going back 1 char
	while((c=fgetc(f))!=EOF)
	{
		
		if(c=='.')
		{
			
			fputc('\n',f1);
			if(count!=1)	//tells it is one sentence or not
			{
				fprintf(f1,"%d:",i);
				i++;
				count--;	//making sentences
			}
		}
		else
		fputc(c,f1);
	}
	fclose(f);
	fclose(f1);
}
void words()
{
	FILE *f,*f1;
	char c;
	int count=0,i=1;
	f=fopen("sentence.txt","r");
	f1=fopen("words.txt","w+");
	count=senCount();
	while((c=fgetc(f))!=EOF)
	{
		if(c==':')
		fputs("wrdLst*******:\n",f1);
		else if((c==',')||(c==' '))
		fputc('\n',f1);
		else
		{
			if(c!='.')
			fputc(c,f1);
		}
	}
	fclose(f);
	fclose(f1);
	
}
void tokens()
{
	FILE *f,*f1;
	f=fopen("sentence.txt","r");
	f1=fopen("tokens.txt","w");
	char c;
	int count=0;
	while((c=fgetc(f))!=EOF)
	{
		count=0;
		if((c==',')||(c=='"')||(c=='?')||(c=='.'))
		{
			count=2;	
			if((c=='.'))
			{
				fputc('\n',f1);
				fputc(c,f1);
			}
			else
			{
			
			fputc('\n',f1);
			fputc(c,f1);
			fputc('\n',f1);
			}
		}
		if(((c==' ')||(c=='\t')||(c=='\n'))&&(count!=2))
			fputc('\n',f1);
		else if(count!=2)
			fputc(c,f1);
		
	}
	fclose(f);
}	
int main()
{
	sentence();
	words();
	tokens();
}
		
	
