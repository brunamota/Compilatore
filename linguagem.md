![linguagem_cmp](https://user-images.githubusercontent.com/66503956/205923023-2a0e0291-5569-49ed-a489-afc864da5923.png)

##  ![icon_verde](https://user-images.githubusercontent.com/66503956/205933163-e6f4181f-b638-43db-b9a7-d99981350ec5.png) A linguagem do Compilatore é baseada na lingua italiana

Compilatore | Linguagem C | Tradução IT-BR
:---------: | :---------: | :---------:
forse | if | talvez
altro | else | outro
anche | and (&&) | e
uno | or (\| \|) | ou
ripetere | while | repetir
stampa | printf |  imprimir
 
 
 ```
 [ \t\r\n]			{}
"stampa"				{ return TOK_STAMPA; }
"="					{ return '=';  }
"*"					{ return '*'; }
"/"					{ return '/'; }
"+"					{ return '+'; }
"-"					{ return '-'; }
"("					{ return '('; }
")"					{ return ')'; }
"^"					{ return '^'; }

[<>!{}]		{ return yytext[0]; }
"anche"		{ return TOK_anche; }
"uno"		{ return TOK_uno; }
"forse"		{ return TOK_forse; }
"altro"		{ return TOK_altro; }
"ripetere"	{ return TOK_ripetere; }
"|"             { return '|';}
```
