%{
	#include<stdio.h>
	int state=0;
%}
letter	[a-zA-Z]
digit	[0-9]
identifier	{letter}({letter}{digit})*
constant	{digit}+(\.{digit}+)?(E[+\-]?{digit}+)?
%%
int 		{if(!state);printf("\n %s is the keyword:",yytext);}
{identifier}	{if(!state);printf("\n %s is the	id:",yytext);}
{constant}		{if(!state);printf("\n %s is the constant:",yytext);}
"+"		{if(!state);printf("\n %s is the addition:",yytext);}
"-"		{if(!state);printf("\n %s is the subtraction:",yytext);}
"*"		{if(!state);printf("\n %s is the multiplication:",yytext);}
"/"		{if(!state);printf("\n %s is the divison:",yytext);}
"//"		{if(!state);printf("\n %s is the single comment:",yytext);}
"/*"		{state=1;printf("%s comment state begins: ",yytext);}
"*/"		{state=0;printf("%s comment state endds: ",yytext);}
%%
int yywrap()
{
	if(state==1)
	{
		printf("Unterminated comment");
		return 1;
	}
}
int main()
{
	FILE *fp;
	fp=fopen("ass.txt","r");
	yyin=fp;
	yylex();
}
	
