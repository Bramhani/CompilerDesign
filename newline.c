#include<stdio.h>
void linePrint()
{
	char c,l,k;
	int count=0,x=0,m;
	FILE *f,*f1;
	f=fopen("prgm.txt","w");
	f1=fopen("line.c","r");
	while((c=fgetc(f1))!=EOF)
	{
		if(count!=2)
		{
			x=1;
			if(c=='#')
			{
				fputc(c,f);
				fputc('\n',f);
			}
			else if((c=='('))
			{
				fputc('\n',f);
				fputc(c,f);
				fputc('\n',f);
				l=c;		//to make sure after this ),}} are there
			}
			else if((c=='{'))
			{
				fputc(c,f);
				fputc('\n',f);
				l=c;
			}
			else if((c==')')||(c=='}'))
			{
				if((l=='(')||(l=='{'))
				{
					fputc(c,f);
					fputc('\n',f);
				}
				else
				{
					fputc('\n',f);
					fputc(c,f);
					fputc('\n',f);
				}
				if(c==')')
				k=c;			//for no space after ) and ;
			
			}
			else if(c==' ')
				fputc('\n',f);
		
			else if((c=='\t')||(c=='\n'))
			{
			}
			else if(c=='=')
			{
				if(l=='=')
				{
				fputc(c,f);
				fputc('\n',f);
				}
				else
				{
				fputc('\n',f);
				fputc(c,f);
				fputc('\n',f);
				l=c;
				}
			}
			else if((c=='<')||(c=='>')||(c==';')||(c==',')||(c=='*')||(c=='!')||(c=='"'))
			{
				if((k==')')&&(k==';'))
				{
				fputc(c,f);
				fputc('\n',f);
				}
				else if(c=='"')
				{
				fputc('\n',f);
				fputc(c,f);
				fputc('\n',f);
				count=6;
				}
				else 
				{
				fputc('\n',f);
				fputc(c,f);
				fputc('\n',f);
				}
			
			}
			else
			{
				x=2;
				l=c;
				fputc(c,f);
			}
		   }
		
		
	}
	fclose(f1);
	fclose(f);
}
	
int main()
{
	linePrint();
}	
