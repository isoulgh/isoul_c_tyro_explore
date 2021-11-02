//
// Created by Jason Luo on 2021/11/2.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NUM 4

typedef struct MGraph { /* 邻接表存储结构 */
    int edges[NUM][NUM];
    int n, e;
} MGraph;

MGraph *build_mgraph();

void Floyd(MGraph *mgraph);

void Ppath(int path[][NUM], int i, int j);

void Dispath(int A[][NUM], int path[][NUM], int n);

int main(void) {
    MGraph *mgraph;
    printf("\n*************************************************************\n");
    printf("该图的矩阵表示为:\n");
    mgraph = build_mgraph();
    printf("\n*************************************************************\n");
    printf("各顶点间最短路径为:\n");
    Floyd(mgraph);
    printf("\n*************************************************************\n");
    return 0;
}

MGraph *build_mgraph() {
    int i, j;
    int num_e = 0;
    MGraph *mgraph = (MGraph *) malloc(sizeof(MGraph));
    int matrix[NUM][NUM] = {{0,       5, INT_MAX, 7},
                            {INT_MAX, 0,       4, 2},
                            {3,       3,       0, 2},
                            {INT_MAX, INT_MAX, 1, 0}};
    for (i = 0; i < NUM; i++) {
        for (j = 0; j < NUM; j++) {
            mgraph->edges[i][j] = matrix[i][j];
            if (matrix[i][j] != 0 && matrix[i][j] != INT_MAX)
                num_e++;
        }
    }
    mgraph->n = NUM;
    mgraph->e = num_e;
    printf("node=%d;edges=%d\n", mgraph->n, mgraph->e);
    for (i = 0; i < NUM; i++) {
        for (j = 0; j < NUM; j++) {
            if (mgraph->edges[i][j] != INT_MAX)
                printf("%3d", mgraph->edges[i][j]);
            else
                printf("%3c", '&');
        }
        printf("\n");
    }
    return mgraph;
}

void Floyd(MGraph *mgraph) {
    int A[NUM][NUM], path[NUM][NUM];
    int i, j, k;
    for (i = 0; i < mgraph->n; i++) {
        for (j = 0; j < mgraph->n; j++) {
            A[i][j] = mgraph->edges[i][j];
            path[i][j] = -1;
        }
    }
    for (k = 0; k < mgraph->n; k++) {   // 最外层，第几个顶点
        for (i = 0; i < mgraph->n; i++) {   // 里层，行列两次循环
            for (j = 0; j < mgraph->n; j++) {
                if (A[i][k] != INT_MAX && A[k][j] != INT_MAX && A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
    Dispath(A, path, mgraph->n);
}

void Ppath(int path[][NUM], int i, int j) {
    int k;
    k = path[i][j];
    if (k == -1)
        return;
    Ppath(path, i, k);
    printf("%d,", k);
    Ppath(path, k, j);
}

void Dispath(int A[][NUM], int path[][NUM], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] == INT_MAX)
                printf("%d-%d have no path", i, j);
            printf("%d-%d-%d: ", i, j, A[i][j]);
            printf("%d,", i);
            Ppath(path, i, j);
            printf("%d\n", j);
        }
    }
}