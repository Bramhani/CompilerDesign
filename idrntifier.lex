%{
	#include<stdio.h>
	int count=0;
%}
DIGIT 	[0-9]
LETTER 	[a-zA-Z]
UNDER 	[_]
FLOAT 	[{0-9}*?\.{0-9}+]
id	({LETTER}*|({LETTER}{DIGIT})*)|({LETTER}+{DIGIT}+{LETTER}+)
notid	({DIGIT}+{LETTER}*)
comment 	"//"


%%
{id} 	{printf("%s is an identifier\n", yytext); count++;}
{notid} 	{printf("%s is not an identifier\n", yytext);}
{comment} 	{printf("%s is comment",yytext);}
{FLOAT}     {ECHO;printf(" FLOAT");}
%%
int yywrap()
{
}
int main()
{
	FILE *fp;
	fp=fopen("xyz.txt","r");
	yyin=fp;
	yylex();
	printf("Total id=%d",count);
	return(0);
}
	
