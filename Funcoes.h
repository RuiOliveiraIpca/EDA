/* Created by: Rui Oliveira 23043
 Created on: 2025-03-28
EDA - Programa para inserção de antenas
*/

#include "Dados.h"

Antena*  NovaAntena(char new);  // Função para criar uma nova antena

Antena* InsereOrdenado(Antena* inicio, Antena* novo); // Função para inserir uma antena ordenada na lista

Antena* CarregaFicheiro(); // Função para carregar um ficheiro TXT com os frequencias das antenas

Antena* MostraAntenas(Antena* inicio); // Função para mostrar as antenas


