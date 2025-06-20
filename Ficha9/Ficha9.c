#include <stdlib.h>
#include <stdio.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof(struct nodo));
    if (a!=NULL) {
        a->valor = r; a->esq = e; a->dir = d;
    }
    return a;
}

int max (int a, int b) {
    return (a > b ? a : b);
}

// a)
int altura (ABin a) {
    if (a == NULL) return 0;
    
    int a = 1 + max(altura(a->esq),altura(a->dir));
    return a;
}

// b)
int nFolhas (ABin a) {
    if (a == NULL) return 0;

    if (a->esq == NULL && a->dir == NULL) return 1;

    return (nFolhas(a->esq) + nFolhas(a->dir));
}

// c)
ABin maisEsquerda (ABin a) {
    if (a == NULL) return NULL;

    while (a->esq != NULL) {
        a = a->esq;
    }
    return a;
}

// d)
void imprimeNivel (ABin a, int l) {
    if (a == NULL) return;
    if (l == 0) printf("%d\n", a->valor);

    else {
    imprimeNivel(a->esq, l - 1);
    imprimeNivel(a->dir, l - 1);
    }
}

// e)
int procuraE (ABin a, int x) {
    if (a == NULL) return 0;

    if (a->valor == x) return 1;

    return (procuraE(a->esq,x) || procuraE(a->dir,x));
}

// f)
struct nodo *procura (ABin a, int x) {
    if (a == NULL) return NULL;
    if (a->valor == x) return a;

    if (a->valor > x) {
        a = a->esq;
        return procura(a,x);
    } else {
        a = a->dir;
        return procura(a,x);
    }
}

// g)
int nivel (ABin a, int x) {
    if (a == NULL) return -1;
    if (a->valor == x) return 0;

    if (a->valor > x) {
        return 1 + nivel(a->esq,x);
    } else {
        return 1 + nivel(a->dir,x);
    }
    return -1;
}

// h)
void imprimeAte (ABin a, int x) {
    if (a == NULL) return;
    
    if (a->valor < x) {
        printf("%d ", a->valor);
        imprimeAte(a->esq,x);
        imprimeAte(a->dir,x);
    } else {
        imprimeAte(a->esq,x);
    }
}