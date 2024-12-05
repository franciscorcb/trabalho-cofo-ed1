/*------
Aqui fica a especificação do meu TAD
------*/
#ifndef __MATRIX_H
#define __MATRIX_H
#define INT_ERR -279754
#define FLOAT_ERR -1e-37
#define TRUE 1
#define FALSE 0
//definições locais
typedef struct _matrix_ Matrix;

//Conjunto das minhas funções que representam as operações

//Pre condição lin e col devem ser maior que 0 e matrix !=NULL
Matrix *matCreate(int lin,int col);

//Função para desalocar minha matrix
int matDestroy(Matrix *c);

//função responsável por retornar um valor em um indicie especifico da matrix
float matGetElemIJ (Matrix* mat, int i, int j);

//função responsável por definir um valor em um local especifico da matrix
int matSetElemIJ (Matrix* mat, int i, int j, float v);

//Retornar o numero de linhas da minha matriz
int matGetNumLines (Matrix* mat);

//Retornar o numero de colunas da minha matriz
int matGetNumCollumns(Matrix *mat);

//função para somar os valores da matriz
int matSomaMatrix(Matrix *mat,int l,int c);

#endif