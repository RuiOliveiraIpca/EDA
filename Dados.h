/* Created by: Rui Oliveira 23043
 Created on: 2025-03-28
EDA - Programa para inserção de antenas
*/

#pragma once

#define V 1

typedef struct Antena {
    int pos;
    char frequencia[V];
    struct Antena *prox;
}Antena;

