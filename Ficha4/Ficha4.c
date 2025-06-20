#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Funções sobre strings

// Ex 1
int eVogal (char *s, int i) {
    return (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U');
}

int contaVogais (char *s) {
    int c = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (eVogal(s,i)) c++;
    }
    return c;
}

// Ex 2
int retiraVogaisRep (char *s) {
    int len = strlen(s), r = 0;
    char aux[len*2];
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (eVogal(s,i) && s[i] == s[i+1]) {
            r++;
        } else {
            aux[j++] = s[i];
        }
    }
    aux[j] = '\0';

    for (int i = 0; i < j; i++) {
        s[i] = aux[i];
    }
    s[j] = '\0';
    
    return r;
}

int retiraVogaisRepSaux (char *s) {
    int len = strlen(s), j = 0, c = 0;

    for (int i = 0; i < len; i++) {
        if (!(eVogal(s,i) && s[i] == s[i + 1])) {
            s[j++] = s[i];
        } else {
            c++;
        }
    }
    s[j] = '\0';

    return c;
}

// Ex 3
int duplicaVogais (char *s) {
    int len = strlen(s), c = 0;
    char aux[len + 1];
    for (int i = 0; i < len; i++) {
        if (eVogal(s,i)) {
            aux[i++] = s[i];
            c++;
        }
        aux[i] = s[i];
    }

    return c;
}

int duplicaVogaisSaux (char *s) {
    int len = strlen(s), c = 0;
    for (int i = 0; i < len; i++) {
        if (eVogal(s,i)) c++;
    }
    int new_len = len + c;
    s[new_len] = '\0';

    for (int i = len - 1, j = new_len - 1; i >= 0; i--) {
        s[j--] = s[i];
        if (eVogal(s,i)) s[j--] = s[i];
    }

    printf("%s\n",s);
    return c;
}

// Arrays ordenados

// Ex 1
int ordenado (int v[], int N) {
    if (N <= 0) return -1;
    int r = 1;

    for (int i = 1; i < N; i++) {
        if (v[i] < v[i-1]) {
            r = 0;
            break;
        }
    }
    return r;
}

int max (int a, int b) {
    return (a > b ? a : b);
}

// Ex 2
void merge (int a[], int na, int b[], int nb, int r[]) {
    if (na <= 0 && nb <= 0) return;
    int i = 0, j = 0, k = 0;

    while (i < na && j < nb) {
        if (a[i] > b[j]) {
            r[k++] = b[j++];
        } else {
            r[k++] = a[i++];
        }
    }
    while (i < na) r[k++] = a[i++];
    while (j < nb) r[k++] = b[j++];
}

// Ex 3
int partitionAux (int v[], int N, int x) {
    int aux[N], c = 0, j = 0;

    for (int i = 0; i < N; i++) {
        if (v[i] <= x) {
            aux[j++] = v[i];
            c++;
        }
    }
    for (int i = 0; i < N; i++) {
        if (v[i] > x) {
            aux[j++] = v[i];
        }
    }

    for (int i = 0; i < N; i++) {
        v[i] = aux[i];
    }

    return c;
}

void swap (int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition (int v[], int N, int x) {
    int a = 0, b = 0;

    while (b < N) {
        if (v[b] <= x) {
            swap(v[a],v[b]);
            a++;
        }
        b++;
    }
    return a;
}

int main() {
    return 0;
}