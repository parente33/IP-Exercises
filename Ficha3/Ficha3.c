#include <stdio.h>

/*
*p -> o conteúdo do endereço p
&p -> o endereço de memória p
*/

/* Ex 1
int main () {
    int x [15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int *y, *z, i;
    y = x;
    z = x+3;
    for (i = 0; i < 5; i++) {
        printf ("%d %d %d\n", x[i], *y, *z);
        y = y+1; z = z+2;
    }

    return 0;
}

Output: 1 1 4
        2 2 6
        3 3 8
        4 4 10
        5 5 12
*/

/*
int main () {
    int i, j, *a, *b;
    i = 3; j = 5;
    a = b = 42;
    a = &i; b = &j;
    i++;
    j = i + *b;
    b = a;
    j = j + *b;
    printf ("%d\n", j);
    return 0;
}

Output: 13
*/

// Ex 2
void swapM (int *x, int *j) {
    int temp = *x;
    *x = *j;
    *j = temp;
}

// Ex 3
void swap (int v[], int i, int j) {
    /* 
    int a = &v[i];
    int b = &v[j];
    swapM(a, b);
    */

    swapM(&v[i], &v[j]);
}

// Ex 4
int soma (int v[], int N) {
    int r = 0;
    if (N <= 0) return r;
    
    for (int i = 0; i < N; i++) {
        r += v[i];
    }
    return r;
}

int soma2 (int v[], int N) {
    if (N <= 0) return 0;
    int r = v[0];

    for (int i = 1; i < N; i++) {
        r += v[i];
    }

    return r;
}

// Ex 5
void inverteArrayCswapM (int v[], int N) {
    for (int i = 0; i < N/2; i++) {
        int j = N - i - 1;
        swapM(&v[i],&v[j]);
    }
    //int i = 0, j = N - 1;
    //While (i < j) {
    //    swapM(&v[i],&v[j]);
    //    i++;
    //    j--;
    //}
}

void inverteArrayCswap (int v[], int N) {
    int i = 0, j = N-1;
    while (i < j) {
        swap(v,i,j);
        i++;
        j--;
    }
}

// Ex 6
int maximum (int v[], int N, int *m) {
    if (N <= 0) return -1;
    int max = v[0];

    for (int i = 0; i < N; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }

    *m = max;
    return 0;
}

// Ex 7
void quadrados (int q[], int N) {
    if (N <= 0) return;

    //for (int i = 0; i < N; i++) {
    //    q[i] = i*i;
    //}
    q[0] = 0;
    for (int i = 1; i < N; i++) {
        q[i] = (i-1)*(i-1) + 2*(i-1) + 1;
    }
}

// Ex 8
void pascal (int v[], int N) {
    v[0] = 1;
    for (int i = 1; i <= N; i++) {
        v[i] = 1;
        for (int j = i - 1; j >= 1; j--) {
            v[j] += v[j - 1];
        }
    }
}

void pascalb (int v[], int N) {
    if (N == 0) {
        printf("1\n");
    }
    for (int i = 0; i <= N; i++) {
        v[i] = 0;
    }
    v[0] = 1;

    for (int i = 0; i <= N; i++) {
        for (int j = i; j > 0; j--) {
            v[j] += v[j - 1];
        }

        for (int k = 0; k <= i; k++) {
            printf("%d ", v[k]);
        }
        printf("\n");
    }
}


int main() {
    int v[5];
    pascalb(v,5);

    return 0;
}