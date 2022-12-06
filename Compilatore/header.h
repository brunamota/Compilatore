
#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

enum noh_type {
	PROGRAM, ASSIGN, SUM, MINUS, MULTI,
	DIVIDE, STAMPA, POW,
	forse, anche, uno, ripetere,
	LT, GT, LE, GE, EQ, NE,
	PAREN, STMT, INTEGER, FLOAT,
	IDENT, GENERIC, CE, CD
};

static const char *noh_type_names[] = {
	"program", "=", "+", "-", "*",
	"/", "stampa", "^",
	"forse", "anche", "uno", "ripetere",
	"<", ">", "<=", ">=", "==", "!=",
	"()","stmt", "int", "float",
	"ident", "generic", "{","}"
};

typedef struct {
	int intv;
	double dblv;
	char *ident;
} token_args;

typedef struct {
	char *nome;
	int token;
	bool exists;
	int colnr;
	int linenr;
}simbolo;

static int error_count = 0;
static int simbolo_qtd = 0;
static simbolo tsimbolos[100];
simbolo *simbolo_novo(char *nome, int token);
bool simbolo_existe(char *nome);
void debug();

struct noh {
	int id;
	enum noh_type type;
	int childcount;

	double dblv;
	int intv;

	char *name;
	
	struct noh *children[1];
};
typedef struct noh noh;

typedef void (*visitor_action)(noh **root, noh *no);

void checar_atribuicao_mesma_var(noh **root, noh *no);

void check_declared_vars(noh **root, noh *no);

void code_generate(noh **root, noh *no);

void visitor_leaf_first(noh **root, visitor_action act);

void visitor_left_root(noh **root, visitor_action act);

noh *create_noh(enum noh_type, int children);

void print(noh *root);
void print_rec(FILE *f, noh *root);
