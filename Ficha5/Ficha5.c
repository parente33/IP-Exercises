#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT[5];
    float teste;
} Aluno;

/* Funções Auxiliares */
void swapAlunos (Aluno a [], int i, int j) {
    Aluno temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void imprimeAluno (Aluno a) {
    int i;
    printf("%-5d; %s; (%d", a.numero, a.nome, a.miniT[0]);
    for (int i = 1; i < 5; i++) printf(", %d", a.miniT[i]);
    printf("); %5.2f\n", a.teste);
}

void swap (int v[], int a, int b) {
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

// Ex1
int nota (Aluno a) {
    float nota_teste = a.teste * 0.8;
    float nota_miniteste = 0;
    for (int i = 0; i < 5; i++) {
        float nota_miniteste_ind = a.miniT[i] * 10 * 0.04;
        nota_miniteste += nota_miniteste_ind;
    }
    float media_minitestes = nota_miniteste / 5;
    if (media_minitestes < 5) { // 25% de 20
        return 0;
    }
    int nota_final = ceil(nota_teste + nota_miniteste);

    if (nota_final < 9.5) return 0;
    return nota_final;
}

// Ex2
int procuraNum (int num, Aluno t[], int N) {
    int found = 0;
    for (int i = 0; i < N && !found; i++) {
        if (t[i].numero == num) {
            found = 1;
            return i;
        }
    }
    if (!found) return -1;
}

// Ex3
void ordenaPorNum (Aluno t[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (t[i].numero > t[j].numero) {
                swapAlunos(t,i,j);
            }
        }
    }
}

// Ex4
void criaIndPorNum (Aluno t[], int N, int ind[]) {
    for (int i = 0; i < N; i++) {
        ind[i] = i;
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (t[ind[j]].numero > t[ind[j+1]].numero) swap(ind,j,j+1);
        }
    }
}

// Ex5
void imprimeTurma (int ind[], Aluno t[], int N) {
    for (int i = 0; i < N; i++) {
        imprimeAluno(t[ind[i]]);
    }
}

// Ex6
int procuraNum2 (int num, Aluno t[], int N, int ind[]) {
    int i = 0, j = N - 1;

    while (i <= j) {
        int meio = (i + j) / 2;

        if (t[ind[meio]].numero == num) {
            return ind[meio];
        } else if (t[ind[meio]].numero < num) {
            i = meio + 1;
        } else {
            j = meio - 1;
        }
    }
    return -1;
}

// Ex7
void criaIndPorNome (Aluno t[], int N, int ind[]) {
    for (int i = 0; i < N; i++) ind[i] = i;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (strcmp(t[ind[j]].nome,t[ind[j+1]].nome) >= 0) {
                swap(ind,j,j+1);
            } else {
                continue;
            }
        }
    }
}

int main() {
    Aluno a1[5] = {{123456, "Daniel", {2,2,1,1,2}, 12}
                  ,{986547, "Nuno", {0,0,0,0,0}, 5}
                  ,{234567, "Pedro", {2,2,2,2,1}, 14}
                  ,{345678, "Baguetes", {2,2,2,2,1}, 16}
                  ,{112489, "Martins", {0,1,0,1,1}, 2}};

    return 0;
}