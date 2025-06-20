#include <stdlib.h>
#include <stdio.h>

/* Estados e Atribuições

1.
    int x, y;
    x = 3; y = x+1;
    x = x*y; y = x + y;
    printf("%d %d\n", x, y);

Output: 12 16

2.
    int x, y;
    x = 0;
    printf ("%d %d\n", x, y);

Output: 0 lixo

3.  códigos ASCII dos caracteres ’A’, ’0’, ’ ’ e ’a’ são respetivamente 65, 48, 32 e 97
    char a, b, c;
    a = ’A’; b = ’ ’; c = ’0’;
    printf ("%c %d\n", a, a);
    a = a+1; c = c+2;
    printf ("%c %d %c %d\n", a, a, c, c);
    c = a + b;
    printf ("%c %d\n", c, c);

Output: A 65
        B 66 2 50
        b 98

4.
    int x, y;
    x = 200; y = 100;
    x = x+y; y = x-y; x = x-y;
    printf ("%d %d\n", x, y);

Output: 100 200
*/

/* Estruturas de Controlo

1.
    int x, y;
    x = 3; y = 5;
    if (x > y)
    y = 6;
    printf ("%d %d\n", x, y);

Output: 3 5

2.
    int x, y;
    x = y = 0;
    while (x != 11) {
    x = x+1; y += x;
    }
    printf ("%d %d\n", x, y);

Output: 11 66

3.
    int i;
    for (i = 0; i < 20; i++)
    if (i%2 == 0) putchar (’_’);
    else putchar (’#’);

Output: _#_#_#_#_#_#_#_#_#_#

4.
    void f (int n) {
        while (n > 0) {
            if (n%2 == 0) putchar ('0');
            else putchar ('1');
            n = n/2;
        }
        putchar ('\n');
    }
    int main () {
        int i;
        for (i = 0; i < 16; i++) f(i);
        return 0;
    }

Output: 
        1
        0 1
        1 1
        0 0 1
        1 0 1
        0 1 1
        1 1 1
        0 0 0 1
        1 0 0 1
        0 1 0 1
        0 0 1 1
        1 0 1 1
        0 1 1 1
        1 1 1 1
*/

/* Programas Interativos */

/* 1. Escreva um programa que desenhe no ecrã (usando o caracter #) um quadrado de
dimensão 5. O resultado da invocação da função com um argumento 5 deverá ser: 
    #####
    #####
    #####
    #####
    #####
*/
void quadrado (int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            putchar('#');
        }
        putchar('\n');
    }
}

/* 2. Escreva um programa que desenhe no ecrã (usando os caracteres # e _) um tabuleiro
de xadrez. O resultado da invocação dessa função com um argumento 5 deverá ser:
    #_#_#
    _#_#_
    #_#_#
    _#_#_
    #_#_#
*/
void tabuleiro (int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i+j) % 2 == 0) putchar('#');
            else putchar('_');
        }
        putchar('\n');
    }
}

/* 3. Escreva duas funções que desenham triângulos (usando o caracter #). O resultado da
invocação dessas funções com um argumento 5 deverá ser
    #                               #
    ##                             ###
    ###                           #####
    ####                         #######
    #####                       #########
    ####
    ###
    ##
    #
*/
//void triangulo_vertical (int N) {
//    int linhas = 2*N-1; // Nº de linhas a ser desenhadas
//    int colunas = N;
//    int altura_inicio = 0;
//    int altura_final = linhas;
//    
//    for (int j = 0; j < linhas; j++) {
//        for (int k = 0; k < colunas; k++) {
//            if (k >= altura_inicio && k < altura_final) {
//                putchar('#');
//            }
//        }
//        putchar('\n');
//        altura_inicio++;
//        altura_final--;
//    }
//}
void triangulo_vertical (int N) {
    for (int i = 0; i < N; i++) {
        putchar('#');
        for (int j = 0; j < i; j++) {
            putchar('#');
        }
        putchar('\n');
    }
    for (int k = N; k < 2*N-1; k++) {
        putchar('#');
        for (int l = 0; l < 2*N - 2 - k; l++) {
            putchar('#');
        }
        putchar('\n');
    }
}

void triangulo_horizontal (int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            putchar(' ');
        }
        for (int k = 0; k < 2 * i + 1; k++) {
            putchar('#');
        }
        putchar('\n');
    }
}

void circulo (int N) {
    int diametro = 2 * N + 1;
    int totalHashes = 0;

    for (int y = 0; y < diametro; y++) {
        for (int x = 0; x < diametro; x++) {
            double dist = sqrt((x - N) * (x - N) + (y - N) * (y - N));
            if (dist <= N + 0.5) {
                printf("#");
                totalHashes++;
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return totalHashes;
}

int main() {

    return 0;
}