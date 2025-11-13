#include <stdio.h>
#include <stdlib.h>

/*
* ==============================================
 *  Nome do Arquivo: Prova3.c
 *  Autor: Samuel Ferreira Santos
 *  Data: 25/10/2025
 *  Descrição:
 *     Essa implementação tem por objetivo exemplficar as questões da Prova 3 e 04 de Luciano (professor da UESC)
 *     as tecnicas usadas para cada parte da questão visarão ser de facil entendimento e escolhas
 *     todas as questões terrão explicações nelas
 *  Questões:
 *    1 )
 *     - Ler dados e colocar em um vetor alocado dinamicamente usando malloc e realloc
 *     - O Vetor deve crescer a cada novo valor inserido
 *     - A condição de parada da entrada é de livre escolha do programador, então usaraemos 69
 *   2 )
 *     - Pegar todos os valores e colocar em uma lista encadeda (caralho)
 *   3 )
 *     - Criar um main
 * * ==============================================
 */


//Quando o professor fala sobre vetores alocados dinamicamente, no geral estamos falando de ponteiros
//Ponteiros são tratados como vetores, porque podem armazenar mais do que uma informação
//No geral, isso são vetores, estruturas que armazenam mais do que uma informação
/**
 * Questão 1
 * -----------------
 * Essa é a primeira questão supracitada.
 * Parâmetros:
 *   nenhum
 * Retorno:
 *   int - retorna um vetor alocado dinamicamente
 */
int tamanho = 0; //Armazena o tamanho do vetor, será util no realloc
int *lerAlocar() { //Precisa retornar um ponteiro, pois é o nosso Vetor


    //A questão pede que o vetor aumente de tamanho, faremos isso com realloc,
    //então na hora de criarmos o vetor, alocaremos ele (malloc) com tamanho de 1 * sizeof(int),
    //pois inicialmente só caberá 1 inteiro (int)
    int *vetor = (int *) malloc(1 * sizeof(int));


    int variavel; //Essa variavel vai definir o numero que será colocado no vetor


    while (1)
    {
        scanf("%d", &variavel); //Usamos a variavel criada anteriormente para definir um valor nela

        if(variavel == 69)  //Perguntamos se o valor que foi digitado é a nossa condição de parada "69"
        {
            break; //Se for então o looping acaba
        }

        vetor[tamanho] = variavel; //Pega a ultima posição disponivel no vetor para adicionar nossa variavel
        tamanho += 1; //aumenta o tamanho do vetor, já que nosso vetor precisa de mais espaço


        int*temp = (int*)realloc(vetor, tamanho * sizeof(int)); //Usa o realloc para aumentar o tamanho do vetor para tamanho, por exemplo, se tamanho = 2, então o novo tamanho do Vetor será 2
        vetor = temp; //Obrigatorio, isso transforma nosso vetor anterior nesse novo Vetor


    }

    return vetor; //Retorna nosso vetor
}


/**
 * Questão 2
 * -----------------
 * Essa é a segunda questão supracitada.
 * Parâmetros:
 *   int* - Vetor que criamos anteriormente
 *   int - Tamanho do Vetor
 * Retorno:
 *   lista - retorna o inicio da lista encadeada
 */

//Uma lista encadeada, é basicamente uma estrutura em cadeia que vai armazenar os nós, como se fosse uma corrente.
//É só imaginar uma corrente, cada elo da corrente tá ligado a um outro elo
//A lista encadeada é uma estrutura importante pra entender a base das estruturas de dados fundamentais.
typedef struct Node {
    int data;             //O dado que tem no Node (Nó da lista)
    struct Node* next;    //Esse ponteiro vai apontar pra proxima posição da lista
} Node;


Node *CopiarValores(int *vetor, int tamanho)
{


    Node *Cabeca = (Node*)malloc(sizeof(Node));  //Esse é o começo da lista, é um valor que PRECISAMOS guardar,
    //então pra acessar lista encadeada é obrigatorio 2 variaveis, o inicio e a auxiliar

    Cabeca->data = vetor[0];
    Cabeca->next = NULL;


    Node *temp = Cabeca; //Temp é a variavel auxiliar, ela será a variavel quem percorrerá toda a lista

    for(int i =1 ; i < tamanho; i++) {
        temp->next = (Node*)malloc(sizeof(Node)); //Criamos o proximo nó, ele PRECISA ser criado

        temp = temp->next; //Passamos pra proxima posição da lista

        temp->data = vetor[i]; //Pegamos o valor de vetor[i] e colocamos no nó atual da lista
        temp->next = NULL;
    }

    return Cabeca;
}

// Essas funções tem objetivo meramente didatico, servem apenas pra printar, não fazem parte da questão
// Função para imprimir a lista encadeada
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Função para liberar memória da lista
void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    printf("Digite numeros (69 para parar):\n");
    //Realloc e Malloc
    int *vetor = lerAlocar(&tamanho);


    printf("\nVetor lido:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    //Copiar valores
    Node *lista = CopiarValores(vetor, tamanho);;
    printf("\nLista encadeada:\n");

    //Não faz parte da prova
    printList(lista);
    free(vetor);
    freeList(lista);

    return 0;
}






