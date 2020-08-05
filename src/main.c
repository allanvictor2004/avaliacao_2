#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "lista_ligada_lib.h"

int main(/* int argc, char *argv[] */) 
{
	Lista lista;
	PtrNodo ptr_nodo;

	inicializar_lista(&lista);

	printar_lista(&lista);

	insere_lista_final(&lista , 5);
	insere_lista_final(&lista, 4);


	printar_lista(&lista);

	insere_lista_inicio(&lista, 3);

	ptr_nodo = lista.inicio->proximo;

	ptr_nodo = ptr_nodo->proximo;

	printar_lista(&lista);

	// Item item = 4;

	if (remove_lista_final(&lista))
	{
		printar_lista(&lista);
	} else
	{
		// printf("O item %d não pertence a lista", item);
		puts("Nao foi possivel remover o item pois a lista ja esta vazia!");
	}

	int teste = remove_lista_final(&lista);
	teste = remove_lista_final(&lista);
	assert(teste == 1);

	teste = remove_lista_final(&lista);
	assert(teste == 0);
	printf("Tamanho da lista: %d\n", tamanho_lista(&lista));

	printar_lista(&lista);
	assert(tamanho_lista(&lista) == 0);
	assert(lista_vazia(&lista) == 1);
	

	insere_lista_inicio(&lista, 2);
	insere_lista_inicio(&lista, 1);
	insere_lista_final(&lista, 3);

	assert(tamanho_lista(&lista) == 3);
	assert(lista_vazia(&lista) == 0);
	printar_lista(&lista);

	assert(busca_lista_elem(&lista, 1) == 1);
	assert(busca_lista_elem(&lista, 8) == 0);

	assert(busca_lista_pos(&lista, 1) == 0);
	assert(busca_lista_pos(&lista, 3) == 2);
	assert(busca_lista_pos(&lista, 15) == -1);

	printf("Tamanho da lista: %d\n", tamanho_lista(&lista));

	return 0;
}