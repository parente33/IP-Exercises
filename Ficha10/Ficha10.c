#include <stdlib.h>
#include <stdio.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

// Ex 1

// a)
ABin removeMenor (ABin *a) {
    if (*a == NULL) return NULL;
    
    if ((*a)->esq == NULL) {
        ABin temp = *a;
        *a = (*a)->dir;
        return temp;
    }

    return removeMenor(&(*a)->esq);
}

// b)
void removeRaiz (ABin *a) {
    if (*a == NULL) return;
    
    ABin temp = *a;

    if ((*a)->esq == NULL) {
        *a = (*a)->dir;
        free(temp);
    } else if ((*a)->dir == NULL) {
        *a = (*a)->esq;
        free(temp);
    } else {
        ABin menor = removeMenor(&(*a)->dir);
        menor->esq = (*a)->esq;
        menor->dir = (*a)->dir;
        *a = menor;
        free(temp);
    }
}

// c)
int removeElem (ABin *a, int x) {
    if (*a == NULL) return 1;

    if (x < (*a)->valor) {
        return removeElem(&(*a)->esq, x);
    } else if (x > (*a)->valor) {
        return removeElem(&(*a)->dir, x);
    } else {
        removeRaiz(a);
        return 0;
    }
}

// Ex 2

void rodaEsquerda (ABin *a){
    ABin b = (*a)->dir;
    (*a)->dir = b->esq;
    b->esq = (*a);
    *a = b;
}

void rodaDireita (ABin *a){
    ABin b = (*a)->esq;
    (*a)->esq = b->dir;
    b->dir = *a;
    *a = b;
}

// d)
void promoveMenor (ABin *a) {
    if (*a == NULL || (*a)->esq == NULL) return;
    promoveMenor(&(*a)->esq);
    rodaDireita(a);
}

// e)
void promoveMaior (ABin *a) {
    if (*a == NULL || (*a)->dir == NULL) return;
    promoveMaior(&(*a)->dir);
    rodaEsquerda(a);
}

// f)
ABin removeMenorAlt (ABin *a) {
    promoveMenor(a);
    int valor = (*a)->valor;
    ABin temp = *a;
    *a = (*a)->dir;
    free(temp);
    return valor;
}

// Ex 3

// g)
int constroiEspinhaAux(ABin *a, ABin *ult) {
    if (*a == NULL) {
        *ult = NULL;
        return 0;
    }
    int n = constroiEspinhaAux(&(*a)->esq, ult);
    if (*ult != NULL) {
        (*ult)->dir = *a;
    }
    ABin aux = (*a)->dir;
    (*a)->esq = NULL;
    *ult = *a;
    *a = aux;
    return n + 1;
}

int constroiEspinha(ABin *a) {
    ABin ult = NULL;
    return constroiEspinhaAux(a, &ult);
}

// h)
ABin equilibraEspinha(ABin *a, int n) {
    if (n == 0) return NULL;
    int m = n / 2;

    ABin esq = equilibraEspinha(a, m);

    ABin raiz = *a;
    raiz->esq = esq;

    *a = raiz->dir;

    raiz->dir = equilibraEspinha(a, n - m - 1);

    return raiz;
}


// i)
void equilibra(ABin *a) {
    int n = constroiEspinha(a);
    *a = equilibraEspinha(a, n);
}