#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 4

typedef struct PILHA{
    int dados[TAM];
    int topo;
}PILHA;

void iniciarPilha(PILHA *p){
    for(int i = 0; i < TAM; i++){
        p->dados[i] = 0; //Inicia todos os espaçamentos para a pilha com 0
    }
    p->topo = 0;
}

void empilhar(int dado, PILHA *p){
    if(p->topo == TAM){
        printf("\n[ERRO] Pilha está cheia!\n");
    }else{
        p->dados[p->topo] = dado;
        p->topo++;
    }
}

int desempilhar(PILHA *p){
    int aux;
    if(p->topo == 0){
        printf("\n[ERRO] Pilha está vazia!\n");
    }else{
        p->topo--;
        aux = p->dados[p->topo];
        p->dados[p->topo] = 0;
        return aux;
    }
}

void imprimePilha(PILHA *p){
    printf("\nImprimindo a pilha: ");
    for(int i = 0; i < TAM; i++){
        printf(" %d ", p->dados[i]);
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    PILHA p1;

    iniciarPilha(&p1);

    empilhar(10, &p1);
    empilhar(20, &p1);
    empilhar(30, &p1);
    empilhar(40, &p1);

    imprimePilha(&p1);

    printf("\nDesempilhando: %d", desempilhar(&p1));
    printf("\nDesempilhando: %d", desempilhar(&p1));

    imprimePilha(&p1);

    empilhar(100, &p1);

    imprimePilha(&p1);

    return 0;
}