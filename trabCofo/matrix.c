/*------
Aqui fica a implementação das funções presentes no meu TAD
------*/
#ifndef __MATRIX_C
#define __MATRIX_C
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _matrix_{
    int numLin;
    int numCol;
    float *v;
}Matrix;

//Codigo para alocar e retornar uma Matriz m por n

Matrix *matCreate(int l, int c){
    Matrix *mat;
    if(l>0 && c>0){
        mat = (Matrix *)malloc(sizeof(Matrix));
        if(mat!=NULL){
            mat->numLin = l;
            mat->numCol = c;
            mat->v = (float *)malloc(sizeof(float)*(l*c));
            if(mat->v!=NULL){
                return mat;
            }
            free(mat);
        }
    }
    return NULL;
}

//Libera matrix
int matDestroy (Matrix* mat){
    if ( mat != NULL ){
        free(mat->v);
        free(mat);
        return TRUE;
    }
    return FALSE;
}

float matGetElemIJ(Matrix *mat, int i, int j){
    int indicie;
    if(mat!=NULL){
        if(i >=0 && i < mat->numLin && j >= 0 && j < mat->numCol){
            indicie=i*mat->numCol + j;
            return mat->v[indicie];
        }
    }
    return FLOAT_ERR;
}

int matSetElemIJ (Matrix *mat, int i, int j,float v){
    int indicie;
    if(mat!=NULL){
        if(i >= 0 && i < mat->numLin && j >= 0 && j < mat->numCol){
            indicie=i*mat->numCol + j;
            mat->v[indicie] = v;
            return TRUE;
        }
    }
    return FALSE;
}


int matGetNumLines(Matrix *mat){
    if(mat!=NULL){
        return mat->numLin;
    }
    return INT_ERR;
}


int matGetNumCollumns (Matrix *mat){
    if(mat!=NULL){
        return mat->numCol;
    }
    return INT_ERR;
}


int matSomaMatrix(Matrix *mat,int l,int c){
    float soma=0;
    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            soma += mat->v[i*c+j];
        }
    }
    return soma;
}

#endif