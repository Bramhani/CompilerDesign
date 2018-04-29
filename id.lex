%{
	#include<stdio.h>
	int count=0;
	int a=0,s=0,m=0,d=0,ob=0,cb=0;
	int flaga=0, flags=0, flagm=0, flagd=0;
	char c='/';
%}
op 		[+-*/]
comment 		"//"
letter 		[a-zA-Z]
digit 		[0-9]
id 		{letter}*|({letter}{digit})*
notid 		({digit}+{letter}*)


%%

("auto") |     
("break") |    
("case") |
("char") |    
("const") |    
("continue") |
("default") |
("do") |
("double") |
("else") |
("enum") |
("extern") |
("float") |
("for") |
("goto") |
("if") |
("int") |
("long") |
("register") |
("return") |   
("short") |    
("signed") |   
("sizeof") |    
("static") |
("struct") |     
("switch") |   
("typedef") |  
("union") |    
("unsigned") |  
("void") |
("volatile") |   
("while")  	{printf("%s is a keyword\n", yytext);}
{id} 		{printf("%s is an identifier\n", yytext); count++;}
{notid} 	{printf("%s is not an identifier\n", yytext);}

{comment} 	{printf("%s is comment",yytext);}
[+] 		{a++;flaga=1;}
[-] 		{s++;flags=1;}
[*] 		{m++;flagm=1;}
[/] 		{d++;flagd=1;}
[(] 		{ob++;}
[)] 		{cb++;}
%%
int yywrap()
{}
int main()
{
	FILE *fp;
	char file[10];
	fp=fopen("abc.c","r");
	yyin=fp;
	yylex();
	printf("Total identifiers are: %d\n", count);
 	if(ob-cb==0)
	{
		printf("Valid expression\n");
	}
	else
	{
		printf("Invalid expression");
	}
	printf("\nAdd=%d\nSub=%d\nMul=%d\nDiv=%d\n",a,s,m,d);
	printf("Operators are: \n");
	if(flaga)
		printf("+\n");
	if(flags)
		printf("-\n");
	if(flagm)
		printf("*\n");
	if(flagd)
		printf("/\n");

	return 0;
}
