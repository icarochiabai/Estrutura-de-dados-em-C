//Lista duplamente ligada. Cada nó aponta para o proximo e para o anterior.
//Autor: Ícaro Chiabai. Data: 30/09/2021.
//MC202 - Estrutura de Dados. Universidade Estadual de Campinas (Unicamp).

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    
    struct No * proximo;
    struct No * anterior;
} No;

typedef No * p_no;

p_no criar_lista(){
    p_no lista = malloc(sizeof(No));
    lista->proximo = NULL;
    lista->anterior = NULL;

    return lista;
}

p_no inserir_elemento(p_no lista, int valor){
    p_no novo = malloc(sizeof(No));
    lista->anterior = novo;

    novo->proximo = lista;
    novo->anterior = NULL;

    novo->valor = valor;
    return novo;
}

p_no deletar_elemento(p_no lista, int valor){
    if(lista->valor == valor){
        p_no aux = lista->proximo;
        aux->anterior = NULL;
        free(lista);
        return aux;
    }
    p_no anterior = lista;

    for(p_no atual = lista->proximo; atual != NULL; atual = atual->proximo){
        if(atual->valor == valor){
            anterior->proximo = atual->proximo;
            atual->proximo->anterior = anterior;
            free(atual);
            break;
        }
        anterior = atual;
    }

    return lista;
}

void imprimir_lista(p_no lista){
    if(lista->proximo != NULL){
        printf("%d ", lista->valor);
        imprimir_lista(lista->proximo);
    }
}

int main(){
    p_no lista = criar_lista();
    int input[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(int i = 0; i < 10; ++i){
        lista = inserir_elemento(lista, input[i]);
    }
    lista = deletar_elemento(lista, 3);
    imprimir_lista(lista);
}