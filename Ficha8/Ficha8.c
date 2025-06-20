#include <stdio.h>
#include <stdlib.h>

typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x; r->prox = xs;
    }
    return r;
}

typedef LInt Stack;

typedef struct {
    LInt inicio,fim;
} Queue;

typedef LInt QueueC;

typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} *DList;

typedef struct {
    DList back, front;
} Deque;

// Ex1
void initStack (Stack *s) {
    *s = NULL;
}

int SisEmpty (Stack s) {
    return (s == NULL);
}

int push (Stack *s, int x) {
    LInt novo = malloc(sizeof(struct slist));
    if (novo == NULL) return 1;

    novo->valor = x;
    novo->prox = *s;
    *s = novo;

    return 0;
}

int pop (Stack *s, int *x) {
    if (SisEmpty(*s)) return 1;

    LInt temp = *s;
    *x = temp->valor;
    *s = temp->prox;
    free(temp);

    return 0;
}

int top (Stack s, int *x) {
    if (SisEmpty(s)) return 1;

    *x = s->valor;
    
    return 0;
}

// Ex2
void initQueue (Queue *q) {
    q->inicio = NULL;
    q->fim = NULL;
}

int QisEmpty (Queue q) {
    return (q.inicio == NULL);
}

int enqueue (Queue *q, int x) {
    LInt novo = malloc(sizeof(struct slist));
    if (novo == NULL) return 1;

    novo->valor = x;
    novo->prox = NULL;

    if (QisEmpty(*q)) q->inicio = q->fim = novo;
    else {
        q->fim->prox = novo;
        q->fim = novo;
    }

    return 0;
}

int dequeue (Queue *q, int *x) {
    if (QisEmpty(*q)) return 1;

    LInt temp = q->inicio;
    *x = temp->valor;
    q->inicio = temp->prox;

    if (q->inicio == NULL) q->fim = NULL;
    free(temp);

    return 0;
}

int front (Queue q, int *x) {
    if (QisEmpty(q)) return 1;

    *x = q.inicio->valor;

    return 0;
}

// Ex3
void initQueueC (QueueC *q) {
    *q = NULL;
}

int QCisEmpty (QueueC q) {
    return (q == NULL);
}

int enqueueC (QueueC *q, int x) {
    LInt novo = malloc(sizeof(struct slist));
    if (novo == NULL) return 1;
    novo->valor = x;

    if (QCisEmpty(*q)) {
        novo->prox = novo;
        *q = novo;
    } else {
        novo->prox = (*q)->prox;
        (*q)->prox = novo;
        *q = novo;
    }

    return 0;
}

int dequeueC (QueueC *q, int *x) {
    if (QCisEmpty(*q)) return 1;

    LInt temp = (*q)->prox;
    *x = temp->valor;

    if ((*q)->prox == (*q)) {
        free(temp);
        *q = NULL;
    } else {
        (*q)->prox = temp->prox;
        free(temp);
    }

    return 0;
}

int frontC (QueueC q, int *x) {
    if (QCisEmpty(q)) return 1;

    *x = q->prox->valor; // ??

    return 0;
}

// Ex4
void initDeque (Deque *q) {
    q->back = NULL;
    q->front = NULL;
}

int DisEmpty (Deque q) {
    return (q.back == NULL && q.front == NULL);
}

int pushBack (Deque *q, int x) {
    DList novo = malloc(sizeof(struct dlist));
    if (novo == NULL) return 1;

    novo->valor = x;
    novo->prox = NULL;
    novo->ant = q->back;

    if (q->back != NULL) {
        q->back->prox = novo;
    } else {
        q->front = novo;
    }

    q->back = novo;

    return 0;
}

int pushFront (Deque *q, int x) {
    DList novo = malloc(sizeof(struct dlist));
    if (novo == NULL) return 1;

    novo->valor = x;
    novo->ant = NULL;
    novo->prox = q->front;

    if (q->front != NULL) {
        q->front->ant = novo;
    } else {
        q->back = novo;
    }

    q->front = novo;

    return 0;
}

int popBack (Deque *q, int *x) {
    if (q->back == NULL) return 1;

    DList temp = q->back;
    *x = temp->valor;

    q->back = temp->ant;
    if (q->back != NULL) {
        q->back->prox = NULL;
    } else {
        q->front = NULL;
    }

    free(temp);
    return 0;
}

int popFront (Deque *q, int *x) {
    if (q->front == NULL) return 1;

    DList temp = q->front;
    *x = temp->valor;

    q->front = temp->prox;
    if (q->front != NULL) {
        q->front->ant = NULL;
    } else {
        q->back = NULL;
    }

    free(temp);
    return 0;
}

int popMax (Deque *q, int *x) {
    if (q->front == NULL) return 1;

    DList max = q->front;
    DList atual = q->front->prox;

    while (atual != NULL) {
        if (atual->valor > max->valor)
            max = atual;
        atual = atual->prox;
    }

    *x = max->valor;

    if (max->ant != NULL)
        max->ant->prox = max->prox;
    else
        q->front = max->prox;

    if (max->prox != NULL)
        max->prox->ant = max->ant;
    else
        q->back = max->ant;

    free(max);
    return 0;
}

int back (Deque q, int *x) {
    if (q.back == NULL) return 1;  // Deque vazia

    *x = q.back->valor;
    return 0; 
}

int front (Deque q, int *x) {
    if (q.front == NULL) return 1;

    *x = q.front->valor;
    return 0;
}