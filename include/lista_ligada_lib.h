#ifndef LISTA_LIGADA_LIB


typedef int Item;


typedef struct nodo
{
    Item item;
    struct nodo* proximo;
} Nodo;


typedef Nodo* PtrNodo;


typedef struct lista
{
    PtrNodo inicio;
} Lista;


/**
 * A funcao "inicializar_lista" recebe por parametro uma lista ligada
 * e "seta" o valor do ponteiro "inicio" com NULL (Nulo).
 */
void inicializar_lista(Lista* lista);

/**
 * A funcao "insere_lista_final" recebe uma "lista"  e "item", depois
 * insere no lugar do "final" da "lista".
 */
void insere_lista_final(Lista* lista, Item item);

/**
 * A funcao "insere_lista_inicio" recebe uma "lista"  e "item", depois
 * insere no lugar do "inicio" da "lista".
 */
void insere_lista_inicio(Lista* lista, Item item);

/**
 * Função que mostra uma "lista" na saida padrao no 
 * formato => Lista: ' a b c '.
 */
void printar_lista(Lista* lista);

/**
 * Função que remove um "item" da "lista" 
 * baseado no valor do parametro "item" e
 * retorna 1 se excluiu e 0 se não.
 */
int remove_lista(Lista* lista, Item item);

/**
 * Função que remove um "nodo final" da "lista" 
 * percorrendo-a de de forma iterativa,
 * retorna 1 se excluiu e 0 se não.
 */
int remove_lista_final(Lista* lista);



/**
 * Função que remove um "nodo inicial" da "lista" 
 * retorna 1 se excluiu e 0 se não.
 */
int remove_lista_inicio(Lista* lista);

/**
 * Retorna o tamanho da lista.
 */
int tamanho_lista(Lista* lista);

/**
 * Retorna 1 se a lista estiver vazia
 * e 0 caso contrário.
 */
int lista_vazia(Lista* lista);

/***
 * Funcao que reotna 1 caso o item esteja na lista
 * e 0 caso o contrario.
 */
int busca_lista_elem(Lista* lista, Item item);

/**
 * Funcao que devolve uma posicao 
 * relativa (pois a lista nao e contigua) do
 * item buscado na lista, e retorna -1 caso não encontre.
 */
int busca_lista_pos(Lista* lista, Item item);

#endif // !LISTA_LIGADA_LIB
