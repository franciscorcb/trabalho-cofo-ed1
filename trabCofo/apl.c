/*------
Aqui possui minha função main e vai chamar as funções do meu TAD
------*/
#include <stdio.h>
#include "matrix.h"
#define TRUE 1
#define FALSE 0
//inclui a minha pasta matrix.h para que meu arquivo app.c identifique os dados presentes em meu arquivo

void main() {
    Matrix *m;
    float elm;
    int stat;
    int l,c;

    printf("Digite o tamanho da sua linha da sua matrix: \n");
    scanf("%d",&l);
    printf("Digite o tamanho da sua coluna da sua matrix: \n");
    scanf("%d",&c);

    m = matCreate(l,c);
    //Aqui eu crio a minha matrix e aloco a mesma baseado nas entradas do usuario
    if(m!=NULL){
        for(int i=0;i<l;i++){
            for(int j=0;j<c;j++){
                printf("Elemento da [%d][%d] posicao: ",i,j);
                scanf("%f",&elm);
                matSetElemIJ(m,i,j,elm);
                //recebe os valores para colocar na matrix
            }
        }
        for (int i=0; i<l; i++) {
            for(int j=0; j<c; j++){
                elm = matGetElemIJ(m,i,j);
                if(elm != FLOAT_ERR){
                    printf("Elemento [%d][%d] eh igual a %.1f\n", i, j, elm);
                    //imprime os valores que foram definidos anteriormente 
                }
            }
        }

        //Abaixo está uma implementação simples que optei por fazer livremente,somente para fins de fixação de conteudo
        int escolha;
        printf("Deseja verificar a soma de sua matrix? 1 para sim e 0 para nao:\n");
        scanf("%d",&escolha);
        if(escolha){
            printf("Soma eh:%d\n",matSomaMatrix(m,l,c));
        }
        else{
            printf("-----Desacolando matrix-----");
        }
        //Desaloca a matrix
        matDestroy(m);
    }else{
        printf("Falha na matrix");
    }

    //Apenas uma implementação para que o terminal não feche rapidamente 
    printf("Pressione ENTER para encerrar o programa...\n");
    getchar();
    getchar(); 

}
