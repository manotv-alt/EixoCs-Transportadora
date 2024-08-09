#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
 
#include "grafo.h"

int prevenir_erros(int limite_inferior, int limite_superior){ // limitese estão incluidos no intervalo
    int temporario;
    do{
        scanf("%d%*c", &temporario);

    } while (temporario < limite_inferior || temporario > limite_superior);
    return temporario;
}

int **gerar_grafo(int linha, int coluna){

    int **grafotemporario = NULL;
    do{
        grafotemporario = (int **)malloc(linha * sizeof(int *));
    } while (grafotemporario == NULL);

    for (int contador = 0; contador < linha; contador++){
        do{
            grafotemporario[contador] = (int *)malloc(coluna * sizeof(int));
        } while (grafotemporario[contador] == NULL);
    }
    return grafotemporario;
}

void preencher_grafo(int tamanho_grafo, grafo matrix, cidade *lista_cidades){ //preciço alterar a parada do --
    int qtd_rotas;
    printf("Insira a quantidade de rotas: \n>> ");
    scanf("%d%*c", &qtd_rotas);
    for(int contador = 0; contador < matrix.tamanho_lados_grafo; contador++){
        if(contador == 0){
            printf("\n%7s %34s\n", "indice", "Nome da cidade");
        }
        printf("%7d %34s\n", lista_cidades[contador].indice_cidade, lista_cidades[contador].nome);
    }
    for (int contador = 0; contador < qtd_rotas; contador++){
        int saida, entrada, distancia;

        printf("\nInsira a cidade de saida: \n>> ");
        scanf("%d%*c", &saida);
        
        printf("Insira a cidade de entrada: \n>> ");
        scanf("%d%*c", &entrada);
        
        printf("Insira a distancia entre %s e %s: \n>> ", lista_cidades[saida].nome, lista_cidades[entrada].nome);
        scanf("%d%*c", &distancia);
        
        matrix.matrix_grafo[saida][entrada] = distancia;
        putchar('\n');
    }
    putchar('\n');
}

void iniciar_grafo(grafo matrix){
    for (int contador = 0; contador < matrix.tamanho_lados_grafo; contador++){
        for (int contador2 = 0; contador2 < matrix.tamanho_lados_grafo; contador2++){
            if (contador != contador2){
                matrix.matrix_grafo[contador][contador2] = -1;
            }
            else{
                matrix.matrix_grafo[contador][contador2] = 0;
            }
        }
    }
}

void mostrar_grafo(grafo matrix){
    for (int contador = 0; contador < matrix.tamanho_lados_grafo; contador++){
        if (contador == 0){
            printf("%5s|", "");
            for (int contador2 = 0;
                 contador2 < matrix.tamanho_lados_grafo; contador2++){
                printf("%5d|", contador2);
            }
            putchar('\n');
        }

        printf("%5d|", contador);
        for (int contador2 = 0; contador2 < matrix.tamanho_lados_grafo; contador2++){
            printf("%5d|", matrix.matrix_grafo[contador][contador2]);
        }
        putchar('\n');
    }
    putchar('\n');
}

void matar_grafo(grafo matrix){
    for(int contador = 0; contador < matrix.tamanho_lados_grafo; contador++){ 
        free(matrix.matrix_grafo[contador]);
    }
    free(matrix.matrix_grafo);
}

int distancia_minima(int distancias[], bool vetor_estado_vertices[], grafo matrix){
    int minimo = INT_MAX, index_minimo;
    for(int contador = 0; contador < matrix.tamanho_lados_grafo; contador++){
        if(vetor_estado_vertices[contador] == false && distancias[contador] <= minimo){
            minimo = distancias[contador];
            index_minimo = contador;
        }
    }
    return index_minimo;
}

void printar_vetor(int vetor[], grafo matrix){
    for(int contador = 0; contador < matrix.tamanho_lados_grafo; contador++){
        printf("%d ", vetor[contador]);
    }
    putchar('\n');
}

int *gerar_vetores(int tamanho){
    int *temporario = NULL;
    do{
        temporario = (int*) malloc(tamanho*sizeof(int));
    }while(temporario == NULL);
    return temporario;
}

int *regressao(int *vetor_entrada, grafo matrix, int cidade_origem, int cidade_destino){
    int *vetor_saida = gerar_vetores(matrix.tamanho_lados_grafo); //mexi aqui, caso dê problema adiciona +1 
    bool *estado_vertices_acessados = NULL;
    do{
        estado_vertices_acessados = (bool*) malloc(matrix.tamanho_lados_grafo*sizeof(bool)); 
    } while ( estado_vertices_acessados == NULL);
    
    for(int contador = 0; contador < matrix.tamanho_lados_grafo; contador++){
        vetor_saida[contador] = -1;
    }
    
    for(int contador = 0; contador < matrix.tamanho_lados_grafo; contador++){
        estado_vertices_acessados[contador] = false;
    }

    int vertice_atual = cidade_destino;
    

    for(int contador = 0; contador < matrix.tamanho_lados_grafo; contador++){
        vetor_saida[contador] = vertice_atual;
        estado_vertices_acessados[vertice_atual] = true;
        
        if(vertice_atual == cidade_origem){
            free(estado_vertices_acessados);
            return vetor_saida;
        }
        
        int menor_distancia = INT_MAX;
        int indice_menor_distancia = vertice_atual;

        for(int contador2 = 0; contador2 < matrix.tamanho_lados_grafo; contador2++){
            if(!estado_vertices_acessados[contador2] && matrix.matrix_grafo[contador2][vertice_atual] != -1 && matrix.matrix_grafo[contador2][vertice_atual] != INT_MAX && (vetor_entrada[contador2] + matrix.matrix_grafo[contador2][vertice_atual] < menor_distancia)){
                menor_distancia = matrix.matrix_grafo[contador2][vertice_atual] + vetor_entrada[contador2];
                indice_menor_distancia = contador2;
            }
        }
        vertice_atual = indice_menor_distancia;        
    }

    free(estado_vertices_acessados);
    return vetor_saida;
}

int *dijkstra(grafo matrix, int vertice_raiz, int destino_final, int *variavel_armazenar_distancia_f, int *tam_vet_cid_perc){
    int *distancia = gerar_vetores(matrix.tamanho_lados_grafo); //vetores de controle
    int *cidades_percorridas = NULL;
    int contador_d = 0; 
    bool *estado_vertices; 
    do{
        estado_vertices = (bool*) malloc(matrix.tamanho_lados_grafo*sizeof(bool));
    }while(estado_vertices == NULL);

    for(int contador = 0; contador < matrix.tamanho_lados_grafo; contador++){//inicializar os vetores
        distancia[contador] = INT_MAX;
        estado_vertices[contador] = false;
    }

    distancia[vertice_raiz] = 0; //a distancia entre a raiz e ela mesma, obviamente, é 0
    
    for(int contador = 0; contador < matrix.tamanho_lados_grafo - 1; contador++){
        int menor_vertice_atual = distancia_minima(distancia, estado_vertices, matrix);
        estado_vertices[menor_vertice_atual] = true;
        //cidades_percorridas[contador] = menor_vertice_atual;

        for(int contador2 = 0; contador2 < matrix.tamanho_lados_grafo; contador2++){
            if(!estado_vertices[contador2] && matrix.matrix_grafo[menor_vertice_atual][contador2] != -1 && matrix.matrix_grafo[menor_vertice_atual][contador2] != INT_MAX && distancia[menor_vertice_atual] + matrix.matrix_grafo[menor_vertice_atual][contador2] < distancia[contador2]){
                distancia[contador2] = distancia[menor_vertice_atual] + matrix.matrix_grafo[menor_vertice_atual][contador2];
            }
        }
    }

    cidades_percorridas = regressao(distancia, matrix, vertice_raiz, destino_final);

    for(int contador = 0; contador < matrix.tamanho_lados_grafo; contador++){
        if(cidades_percorridas[contador] != -1){
            contador_d++;
        }

    }

    printf("contador_d: %d\n", contador_d);

    if(contador_d != matrix.tamanho_lados_grafo){
        cidades_percorridas = (int*) realloc(cidades_percorridas, contador_d);
        *tam_vet_cid_perc = contador_d;
        for(int contador = 0; contador < contador_d/2; contador++){
            int troca = cidades_percorridas[contador];
            cidades_percorridas[contador] = cidades_percorridas[contador_d - 1 - contador];
            cidades_percorridas[contador_d - 1 - contador] = troca;
        }
    }

    //0 1 2 3 4



    //printar_vetor(distancia, matrix);
    //printar_vetor(cidades_percorridas, matrix);

    *variavel_armazenar_distancia_f = distancia[destino_final];

    free(distancia);
    free(estado_vertices);
    return cidades_percorridas;
}

cidade *registrar_cidades(int quantidade_cidades){
    char nome_temporario[34];
    
    cidade *cidades = NULL; 
    bool *estado_cidades = NULL;

    do{
        cidades = (cidade*) malloc(quantidade_cidades*sizeof(cidade));
    }while(cidades == NULL);

    do{
        estado_cidades = (bool*) malloc(quantidade_cidades*sizeof(bool));
    }while(estado_cidades == NULL);
    
    for(int contador = 0; contador < quantidade_cidades; contador++){
        estado_cidades[contador] = false;
    }

    cidade temporaria;

    for(int contador = 0; contador < quantidade_cidades; contador++){
        printf("Insira o nome da %d° cidade:\n>> ", contador + 1);
        fgets(nome_temporario, 34, stdin);
        nome_temporario[strlen(nome_temporario) - 1] = '\0';
        strcpy(temporaria.nome, nome_temporario);
        do{
        printf("Insira um indice valido para essa cidade no grafo: [indice >= 0 e indice < quantidade cidades, e nao pode ja ter sido usado anteriormente]\n>> ");
        scanf("%d%*c", &(temporaria.indice_cidade));
        } while(temporaria.indice_cidade < 0 || temporaria.indice_cidade >= quantidade_cidades || estado_cidades[temporaria.indice_cidade] == true);
        //scanf("%d%*c", &(temporaria.indice_cidade));
        estado_cidades[temporaria.indice_cidade] = true;
        cidades[temporaria.indice_cidade] = temporaria;
    }

    free(estado_cidades);
    return cidades;
}

char *f_embalagem(){
    char *retorno = NULL;
    do{
        retorno = (char*) malloc(4*sizeof(char));
    }while(retorno == NULL);

    char embalagem[5];
    printf("\nEMBALAGENS DISPONÍVEIS: Largura(cm) x Comprimento(cm) x Altura(cm) - Peso máximo(kg)\n");
    printf("\nP04: 12x16x04 - 1,5");
    printf("\nC08: 12x32x08 - 3\nC12: 12x32x12 - 4");
    printf("\nM08: 24x16x08 - 3\nM12: 24x16x12 - 4");
    printf("\nG08: 24x32x08 - 6\nG12: 24x32x12 - 9\nG16: 24x32x16 - 11\nG20: 24x32x20 - 14");
    printf("\nS04: 48x32x04 - 6\nS08: 48x32x08 - 11\nS012: 48x32x12 - 17\nS016: 48x32x16 - 22\nS20: 48x32x20 - 28\nS24: 48x32x24 - 30\nS28: 48x32x28 - 30");
    printf("\nH12: 48x64x12 - 30\nH20: 48x64x20 - 30\nH28: 48x64x28 - 30\nH32: 48x64x32 - 30\nH48: 48x64x48 - 30\n");
    printf("\nInsira o índice da embalagem: ");
    
    fgets(embalagem,5,stdin);
    embalagem[strlen(embalagem) - 1] = '\0';
    strcpy(retorno, embalagem);
    
    return retorno;
}

float preco(int distancia, char *ind_embalagem) {
  float precof, dimencoes;

  switch (*ind_embalagem) {
  case 'A':
    dimencoes = 40;
    break;
  case 'B':
    dimencoes = 56;
    break;
  case 'C':
    dimencoes = 56;
    break;
  case 'D':
    dimencoes = 76;
    break;
  case 'E':
    dimencoes = 108;
    break;
  case 'F':
    dimencoes = 160;
    break;
  }

  precof = distancia * dimencoes * 1/4000;

  return precof;
}

int inicializar(FILE *arquivo, int *quantidade_cidades, grafo *rota_cidades, cidade *cidades){
    if(arquivo == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        return 0;
    }else{
        fscanf(arquivo,"%d%*c", quantidade_cidades);
        rota_cidades -> matrix_grafo = gerar_grafo(*quantidade_cidades, *quantidade_cidades);
        rota_cidades -> tamanho_lados_grafo = *quantidade_cidades;
        
        do{
          cidades = (cidade*) malloc(*quantidade_cidades*sizeof(cidade));  
        } while(cidades == NULL);
        
        for(int contador = 0; contador < *quantidade_cidades; contador++){
            for(int contador2 = 0; contador2 < *quantidade_cidades; contador2++){
                fscanf(arquivo,"%d", &rota_cidades -> matrix_grafo[contador][contador2]);
            }
        }
        for(int contador = 0; contador < *quantidade_cidades; contador++){
            fgets(cidades[contador].nome, 34, arquivo);
            cidades[contador].nome[strlen(cidades[contador].nome) - 1] = '\0';
            fscanf(arquivo,"%d%*c", &cidades[contador].indice_cidade);
        }
        return 1;
    }
}

int *valor_caminhos(int *vetor, int tamanho_vetor, grafo matrix){
    int *vetor_retorno = NULL;
    do{
        vetor_retorno = (int*) malloc((tamanho_vetor - 1)*sizeof(int));
    } while(vetor_retorno == NULL);
    for(int contador = 0; contador < tamanho_vetor - 1; contador++){
        vetor_retorno[contador] = matrix.matrix_grafo[vetor[contador]][vetor[contador + 1]];
    }

    return vetor_retorno;
}

void demora(int tamanho, int *vetor_distancia_cidades, char *data_esperada){

    int i;
    int dias = tamanho;
    
    for (i = 0; i < tamanho; i++) {    
        //printf("%d: %d\n", i, vetor_distancia_cidades[i]);
        dias = dias + vetor_distancia_cidades[i] / 1800;
    }
    
    //printf("dias: %d\n", dias);
    //printf("tamanho: %d", tamanho);

    //exit(0);

    if(dias > 1){
    sprintf(data_esperada, "SUA ENTREGA CHEGARA EM %d DIAS UTEIS", dias);
    }
    else{
        sprintf(data_esperada, "SUA ENTREGA CHEGARA EM %d DIA UTIL", dias);
    }
 
}

void valores_finais(grafo matrix, int origem, int destino, char *embalagem, char *data, float *custo){ //Que são origem, destino, embalagem e data
    int distancia, tamanho_vetor_cidades_percorridas;
    int *cidades_percorridas = NULL;
    int *vetor_distancia_cidades = NULL;

    cidades_percorridas = dijkstra(matrix, origem, destino, &distancia, &tamanho_vetor_cidades_percorridas);

    vetor_distancia_cidades = valor_caminhos(cidades_percorridas, tamanho_vetor_cidades_percorridas, matrix);

    *custo = preco(distancia, embalagem);

    demora(tamanho_vetor_cidades_percorridas - 1, vetor_distancia_cidades, data);

    free(cidades_percorridas);
    free(vetor_distancia_cidades);
}