#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Grafo{
    int tamanho_lados_grafo;
    int **matrix_grafo;
} grafo;

typedef struct Cidade{
    char nome[34];
    int indice_cidade;
} cidade;

int prevenir_erros(int limite_inferior, int limite_superior); //função inutil pq n usei em lugar nenhum
/**
 * @brief
 *
 * @param  
 * 
 * @return 
 */
int **gerar_grafo(int linha, int coluna); // gera um grafo de dimensao linha * coluna, mas sem valor algum

void preencher_grafo(int tamanho_grafo, grafo matrix, cidade *lista_cidades); //preenche o grafo a partir das rotas dadas pelo usuario 

void iniciar_grafo(grafo matrix); // Faz todos os valores do grafo serem -1, isso é importante para djikstra

void mostrar_grafo(grafo matrix); //mostra o grafo

void matar_grafo(grafo matrix); //dá free completamente no grafo

int distancia_minima(int distancias[], bool vetor_estado_vertices[], grafo matrix); //função auxiliar de djikstra, serve para falar para uma cidade qual é a cidade vizinha mais próxima dela

void printar_vetor(int vetor[], grafo matrix); //printa um vetor de inteiros

int *gerar_vetores(int tamanho); //gera um vetor de inteiro de tamanho n

int *regressao(int *vetor_entrada, grafo matrix, int cidade_origem, int cidade_destino); //faz o caminho reverso de djikstra, para mostrar as rotas percorridas do destino final até o inicio

int *dijkstra(grafo matrix, int vertice_raiz, int destino_final, int *variavel_armazenar_distancia_f, int *tam_vet_cid_perc); // função para encontrar a menor distancia entre duas cidades

cidade *registrar_cidades(int quantidade_cidades); // serve para dar nome as cidades e também dizer seus indices

char *f_embalagem(); //serve para pegar o rótulo da embalagem

float preco(int distancia, char *ind_embalagem); //serve para calcular o preco total

int inicializar(FILE *arquivo, int *quantidade_cidades, grafo *rota_cidades, cidade *cidades);

int *valor_caminhos(int *vetor, int tamanho_vetor, grafo matrix);

void demora(int tamanho, int *vetor_distancia_cidades, char *data_esperada);

void valores_finais(grafo matrix, int origem, int destino, char *embalagem, char *data, float *custo);