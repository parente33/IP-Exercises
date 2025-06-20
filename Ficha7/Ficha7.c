#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula *prox;
}*Palavras;

// Ex1
void libertaLista (Palavras l) {
    Palavras temp;
    while (l != NULL) {
        temp = l;
        l = l->prox;
        free(temp->palavra);
        free(temp);
    }
}

// Ex2
int quantasP (Palavras l) {
    int c = 0;
    while (l != NULL) {
        c++;
        l = l->prox;
    }

    return c;
}

// Ex3
void listaPal (Palavras l) {
    while (l != NULL) {
        printf("%s;%d\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}

// Ex4
char * ultima (Palavras l) {
    if (l == NULL) return NULL;

    while (l->prox != NULL) {
        l = l->prox;
    }

    return l->palavra;
}

// Ex5
Palavras acrescentaInicio (Palavras l, char *p) {
    Palavras nova = malloc(sizeof(struct celula));
    if (nova == NULL) return l;
    nova->palavra = strdup(p);
    nova->ocorr = 1;
    nova->prox = l;

    return nova;
}

// Ex6
Palavras acrescentaFim (Palavras l, char *p) {
    Palavras nova = malloc(sizeof(struct celula));
    if (nova == NULL) return l;
    nova->palavra = strdup(p);
    nova->ocorr = 1;
    nova->prox = NULL;

    if (l == NULL) {
        return nova;
    }
    Palavras atual = l;
    while (atual->prox != NULL) atual = atual->prox;
    atual->prox = nova;

    return l;
}

// Ex7
Palavras acrescenta (Palavras l, char *p) {
    Palavras atual = l, ant = NULL;

    while (atual != NULL && strcmp(atual->palavra, p) < 0) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual != NULL && strcmp(atual->palavra, p) == 0) {
        atual->ocorr++;
        return l;
    }

    Palavras nova = malloc(sizeof(struct celula));
    if (nova == NULL) return l;
    nova->palavra = strdup(p);
    nova->ocorr = 1;
    nova->prox = atual;

    if (ant == NULL) return nova;
    ant->prox = nova;

    return l;
}

// Ex8
struct celula *maisFreq (Palavras l) {
    if (l == NULL) return NULL;
    Palavras maisFreq = l;
    while (l != NULL) {
        if (l->ocorr > maisFreq->ocorr) {
            maisFreq = l;
        }
        l = l->prox;
    }

    return maisFreq;
}