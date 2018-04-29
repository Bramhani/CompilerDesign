#include<stdio.h>
void linePrint()
{
	char c;
	int count=0;
	FILE *f,*f1;
	f=fopen("prgm.txt","w");
	f1=fopen("line.c","r");
	while((c=fgetc(f1))!=EOF)
	{
		if((c=='#')||(c=='<')||(c=='>')||(c=='(')||(c==')')||(c==';')||(c==',')||(c=='*')||(c=='=')||(c=='!')||(c=='"')||(c==' ')||(c=='\t')||(c=='{')||(c=='}'))
		{
			
			
			fputc('\n',f);
			fputc(c,f);
			fputc('\n',f);
			
		}
		else if(c=='\n')
		{
		}
		else
		{
				
			fputc(c,f);
			count=1;
		}
		
	}
	fclose(f1);
	fclose(f);
}
	
int main()
{
	linePrint();
}	
