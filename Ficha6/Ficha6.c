#include <stdio.h>
#include <stdlib.h>

#define Max 100

// Ex 1

struct staticStack {
    int sp;
    int values [Max];
};
typedef struct staticStack *SStack;

// Ex1 a)
void SinitStack (SStack s) {
    s->sp = 0;
}

// Ex1 b)
int SisEmpty (SStack s) {
    return (s->sp == 0);
}

// Ex1 c)
int Spush (SStack s, int x) {
    if (s->sp == Max) return 1;

    s->values[s->sp] = x;
    s->sp++;

    return 0;
}

// Ex1 d)
int Spop (SStack s, int *x) {
    if (SisEmpty(s)) return 1;

    s->sp--;
    *x = s->values[s->sp];

    return 0;
}

// Ex1 e)
int Stop (SStack s, int *x) {
    if (SisEmpty(s)) return 1;

    *x = s->values[s->sp - 1];

    return 0;
}

//------------------------------------------------//

// Ex 2

struct staticQueue {
    int front;
    int length;
    int values [Max];
};
typedef struct staticQueue *SQueue;

// Ex2 a)
void SinitQueue (SQueue q) {
    q->length = 0;
}

// Ex2 b)
int SisEmptyQ (SQueue q) {
    return (q->length == 0);
}

// Ex2 c)
int Senqueue (SQueue q, int x) {
    if (q->length == Max) return 1;

    int pos = (q->length + q->front) % Max;
    q->values[pos] = x;
    q->length++;

    return 0;
}

// Ex2 d)
int Sdequeue (SQueue q, int *x) {
    if (SisEmptyQ(q)) return 1;

    *x = q->values[q->front];
    q->length--;
    q->front = (q->front + 1) % Max;

    return 0;
}

// Ex2 e)
int Sfront (SQueue q, int *x) {
    if (SisEmpty(q)) return 1;

    *x = q->values[q->front];
    
    return 0;
}

//---------------------------------------------//

// Ex3

typedef struct dinStack {
    int size; // guarda o tamanho do array values
    int sp;
    int *values;
} *DStack;

// Ex 3.1 a)
void DinitStack (DStack s) {
    s->size = 1;
    s->sp = 0;
    s->values = malloc(s->size * sizeof(int));

    if (s->values == NULL) {
        s->size = 0;
    }
}

// Ex 3.1 b)
int DisEmpty (DStack s) {
    return (s->sp == 0);
}

// Ex 3.1 c)
int Dpush (DStack s, int x) {
    if (s->sp == s->size) {
        s->size *= 2;
        s->values = realloc(s->values, s->size * sizeof(int));

        if (s->values == NULL) return 1;
    }

    s->values[s->sp] = x;
    s->sp++;

    return 0;
}

// Ex 3.1 d)
int Dpop (DStack s, int *x) {
    if (DisEmpty(s)) return 1;

    s->sp--;
    *x = s->values[s->sp];

    return 0;
}

// Ex 3.1 e)
int Dtop (DStack s, int *x) {
    if (DisEmpty(s)) return 1;

    *x = s->values[s->sp - 1];

    return 0;
}

typedef struct dinQueue {
    int size; // guarda o tamanho do array values
    int front;
    int length;
    int *values;
} *DQueue;

// Ex 3.2 a)
void DinitQueue (DQueue q) {
    q->size = 1;
    q->length = 0;
    q->front = 0;
    q->values = malloc(q->size * sizeof(int));

    if (q->values == NULL) q->size = 0;
}

// Ex 3.2 b)
int DisEmptyQ (DQueue q) {
    return (q->length == 0);
}

// Ex 3.2 c)
int Denqueue (DQueue q, int x) {
    if (q->length == q->size) {
        q->size *= 2;
        q->values = realloc(q->values, q->size * sizeof(int));

        if (q->values == NULL) return 1;
    }

    q->values[q->length++] = x;

    return 0;
}

// Ex 3.2 d)
int Ddequeue (DQueue q, int *x) {
    if (DisEmptyQ(q)) return 1;

    *x = q->values[q->front];
    q->length--;
    q->front = (q->front + 1) % q->size;

    return 0;
}

// Ex 3.2 e)
int Dfront (DQueue q, int *x) {
    if (DisEmptyQ(q)) return 1;

    *x = q->values[q->front];

    return 0;
}

// Funções auxiliares para libertar uma DStack e uma DQueue
void DdestroyStack (DStack s) {
    if (s != NULL) {
        free(s->values);
        free(s);
    }
}

void DdestroyQueue (DQueue q) {
    if (q != NULL) {
        free(q->values);
        free(q);
    }
}

int main() {
    return 0;
}