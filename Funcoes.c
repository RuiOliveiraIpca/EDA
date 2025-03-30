/* Created by: Rui Oliveira 23043
 Created on: 2025-03-28
EDA - Programa para inserção de antenas
*/

#include "Funcoes.h"
#include <stdio.h>
#include <stdlib.h>


// Função para carregar um ficheiro TXT com os frequencias das antenas

Antena* CarregaFicheiro() {

    FILE* file = fopen("Antenas.txt", "r");
    if (file == NULL){
        printf("Ficheiro errado, verifique se existe um ficheiro Antenas.txt com as frequencias das antenas!!!\n");
        return NULL;
    }
    else {
        Antena* inicio = NULL;
        Antena* novo = NULL;
        int id;
        char frequencia[V];
        while (fscanf(file," %s", frequencia) != EOF){  // Enquanto o ficheiro Antenas.txt tiver dados vai criando as antenas
            novo = NovaAntena(frequencia);
            inicio = InsereOrdenado(inicio, novo);
        }
        fclose(file);
        return inicio;
    }
}

// Função para mostrar as antenas

Antena* MostraAntenas(Antena* inicio){
    Antena* aux = inicio;
    while (aux != NULL){
        printf("Frequência: %s \n", aux->frequencia);
        aux = aux->prox;
    }
}


// Função para criar uma nova antena

Antena* NovaAntena(char new){
    Antena* aux;
    aux = (Antena*) malloc(sizeof(Antena));
    if (aux == NULL){
        aux->pos = new;
        aux->prox = NULL;
    }return aux;
}

// Função para inserir uma antena ordenada na lista

Antena* InsereOrdenado(Antena* inicio, Antena* novo){

// Validar se a lista tem dados ou está vazia


    if(novo == NULL) return inicio;

    // Se a lista estiver vazia

    if (inicio == NULL){
        inicio = novo;
        return inicio;
    }

    // Se a lista não estiver vazia
   

    Antena* aux = inicio;
    Antena* aux2 = aux;


    while ((aux->pos < novo->pos) && (aux->prox != NULL)){
        aux2 = aux;
        aux = aux->prox;
    }
    if (aux->pos < novo->pos){
        aux->prox = novo;       
    } else {
        aux2->prox = novo;
        novo->prox = aux;  
    }  
    return inicio;
}

