#include <stdio.h>

// Ex 1
float multInt1 (int n, float m) {
    float r = 0;
    int i = 0;

    while (i != n) {
        r += m;
        i++;
    }

    return r;
}

// Sem usar a variável extra i
float multInt1_2 (int n, float m) {
    float r = 0;
    while (n > 0) {
        r += m;
        n--;
    }

    return r;
}

// Ex 2
float multInt2 (int n, float m) {
    int r = 0, c = 0;
    while (n > 0) {
        if (n%2 != 0) {
            r += m;
        }
        n = n/2; m = m*2;
        c++;
    }
    printf("Nº de iterações: %d\n", c);
    return r;
}

// Ex 3
int mdc1 (int a, int b) {
    int min = (a < b) ? a : b, n = 1;

    int max_div = 1;
    while (n != min + 1) {
        if (a%n == 0 && b%n == 0 && n > max_div) {
            max_div = n;
        }
        n++;
    }
    return max_div;
}

// Ex 4
int mdc2 (int a, int b) {
    int c = 0;
    while (a != 0 && b != 0) {
        if (a > b) a -= b;
        else b -= a;
        c++;
    }
    printf("nº iter: %d\n", c);
    if (a == 0) return b;
    else return a;
}

// Ex 5
int mdc2_melhor (int a, int b) {
    int c = 0;
    while (a != 0 && b != 0) {
        if (a > b) a = a % b;
        else b = b % a;
        c++;
    }
    printf("nº iter melhor: %d\n", c);
    if (a == 0) return b;
    else return a;
}

// Ex 6
int fib1 (int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib1(n-1) + fib1(n-2);
}

int fib2 (int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, c = 1;
    while (c != n) {
        int temp = a + b;
        a = b;
        b = temp;
        c++;
    }
    return b;
}

int main() {
    int a = 10;
    int r = fib2(a);
    printf("res: %d\n", r);

    return 0;
}