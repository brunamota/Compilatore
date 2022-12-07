![linguagem_cmp](https://user-images.githubusercontent.com/66503956/205923023-2a0e0291-5569-49ed-a489-afc864da5923.png)

## ![icon_florzinha_20](https://user-images.githubusercontent.com/66503956/205974127-561cf0ec-5992-4ddb-92f6-bcfdc13c0e3e.png) A linguagem do Compilatore é baseada na lingua italiana

Compilatore | Linguagem C | Tradução IT-BR
:---------: | :---------: | :---------:
forse | if | talvez
altro | else | outro
anche | and (&&) | e
uno | or (\| \|) | ou
ripetere | while | repetir
stampa | printf |  imprimir
\| | ; |  pipe*

* a tradução do inglês para o português de pipe é cano, utilizei esse símbolo, pois o Mario é um encanador.
 
#### ![icon_florzinha_20](https://user-images.githubusercontent.com/66503956/205974127-561cf0ec-5992-4ddb-92f6-bcfdc13c0e3e.png) Aqui no léxico, conseguimos ver as definições da gramática, caracteres e tokens para a nossa linguagem:
 
 ```c
%{
	#include <stdio.h>
	#include "header.h"
	#include "calc.tab.h"
%}

%option yylineno

D	[0-9]
L	[a-zA-Z_]

%% 

[ \t\r\n]       {}
"stampa"        { return TOK_STAMPA; }
"="        	{ return '=';  }
"*"        	{ return '*'; }
"/"        	{ return '/'; }
"+"        	{ return '+'; }
"-"        	{ return '-'; }
"("        	{ return '('; }
")"        	{ return ')'; }
"^"        	{ return '^'; }

[<>!{}]		{ return yytext[0]; }
"anche"		{ return TOK_anche; }
"uno"		{ return TOK_uno; }
"forse"		{ return TOK_forse; }
"altro"		{ return TOK_altro; }
"ripetere"	{ return TOK_ripetere; }
"|"             { return '|';}

{D}+		{ yylval.args.intv = atoi(yytext); return TOK_INTEGER;}
{D}+\.{D}+      { yylval.args.dblv = atof(yytext); return TOK_FLOAT;}
{L}({L}|{D})*	{ yylval.args.ident = strndup(yytext, yyleng); return TOK_IDENT; }
 
.               { printf("Invalid caracter: %c.\n", yytext[0]); }

%%

int yywrap() {
	return 1;
}

int main(int argc, char *argv[]) {
	
	if (argc <= 1) {
		printf("%s [file]\n", argv[0]);
		return 1;
	}

	FILE *f = fopen(argv[1], "r");
	yyin = f;
	yyparse();
	fclose(f);
	return 0;
}
```
