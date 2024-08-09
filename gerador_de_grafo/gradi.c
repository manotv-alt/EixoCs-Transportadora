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

int **gerar_grafo(int linha, int coluna); // gera um grafo de dimensao linha * coluna, mas sem valor algum

void preencher_grafo(int tamanho_grafo, grafo matrix, cidade *lista_cidades); //preenche o grafo a partir das rotas dadas pelo usuario 

void iniciar_grafo(grafo matrix); // Faz todos os valores do grafo serem -1, isso é importante para djikstra

void mostrar_grafo(grafo matrix); //mostra o grafo

void matar_grafo(grafo matrix); //dá free completamente no grafo

int distancia_minima(int distancias[], bool vetor_estado_vertices[], grafo matrix); //função auxiliar de djikstra, serve para falar para uma cidade qual é a cidade vizinha mais próxima dela

void printar_vetor(int vetor[], grafo matrix); //printa um vetor de inteiros

int *gerar_vetores(int tamanho); //gera um vetor de inteiro de tamanho n

int *regressao(int *vetor_entrada, grafo matrix, int cidade_origem, int cidade_destino); //faz o caminho reverso de djikstra, para mostrar as rotas percorridas do destino final até o inicio

int *dijkstra(grafo matrix, int vertice_raiz, int destino_final, int *variavel_armazenar_distancia_f); // função para encontrar a menor distancia entre duas cidades

cidade *registrar_cidades(int quantidade_cidades); // serve para dar nome as cidades e também dizer seus indices

char *f_embalagem(); //serve para pegar o rótulo da embalagem

float preco(int distancia, char embalagem[]); //serve para calcular o preco total

int main(){ //em caso de erro, olhe para a variavel 'quantidade_cidades' -- estou tirando o + 1
    FILE *arquivo;
    arquivo = fopen("grafinho.txt", "w");

    grafo rotas_cidades;
    cidade *cidades;
    int quantidade_rotas, raiz, destinof, quantidade_cidades, distancia = 0;
    int *rotas_ate_destino_f;
    char *embalagem;

    printf("Insira a quantidade de cidades:\n>> ");
    scanf("%d%*c", &quantidade_cidades);
    cidades = registrar_cidades(quantidade_cidades);
    
    rotas_cidades.tamanho_lados_grafo = quantidade_cidades;
    rotas_cidades.matrix_grafo = gerar_grafo(quantidade_cidades, quantidade_cidades);

    iniciar_grafo(rotas_cidades);
    
    preencher_grafo(rotas_cidades.tamanho_lados_grafo, rotas_cidades, cidades);
    
    mostrar_grafo(rotas_cidades);

    
    for(int contador = 0; contador < quantidade_cidades; contador++){
        for(int contador2 = 0; contador2 < quantidade_cidades; contador2++){
            if(contador == 0 && contador2 == 0){
                fprintf(arquivo, "%d\n", rotas_cidades.tamanho_lados_grafo);
            }
            fprintf(arquivo, "%d\n", rotas_cidades.matrix_grafo[contador][contador2]);
        }
    }

    for(int contador = 0; contador < quantidade_cidades; contador++){
        fprintf(arquivo, "%s\n", cidades[contador].nome);
        fprintf(arquivo, "%d\n", cidades[contador].indice_cidade);
    }

    fclose(arquivo);
    
    printf("Insira a raiz para encontrar o menor caminho ate ela: \n>> ");
    scanf("%d%*c", &raiz);
    printf("Agora insire a cidade de entrega do produto:\n>> ");
    scanf("%d%*c", &destinof);
    
    rotas_ate_destino_f = dijkstra(rotas_cidades, raiz, destinof, &distancia);
    
    //parte da embalagem e preco

    //Caso queira ver a rota da cidade A até B:
    printar_vetor(rotas_ate_destino_f, rotas_cidades);
    
    //caso queira ver a distancia calculada por djikstra:
    printf("Distancia: %d\n", distancia);

    //embalagem = f_embalagem();

    //printf("\nPreco final: %.2f\n", preco(distancia, embalagem));

    

    matar_grafo(rotas_cidades);
    free(cidades);
    //free(embalagem);
    return 0;
}

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
    int *vetor_saida = gerar_vetores(matrix.tamanho_lados_grafo + 1);
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

int *dijkstra(grafo matrix, int vertice_raiz, int destino_final, int *variavel_armazenar_distancia_f){
    int *distancia = gerar_vetores(matrix.tamanho_lados_grafo); //vetores de controle
    int *cidades_percorridas = NULL;
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

float preco(int distancia, char embalagem[]){
  float precof, altura, largura, comprimento;

  altura = (embalagem[1] - 48)*10 + (embalagem[2] - 48);
  if(embalagem[0] == 'P'){
    largura = 12;
    comprimento = 16;
  }
  if(embalagem[0] == 'M'){
    largura = 24;
    comprimento = 16;
  }
  if(embalagem[0] == 'C'){
    largura = 12;
    comprimento = 32;
  }
  if(embalagem[0] == 'G'){
    largura = 24;
    comprimento = 32;
  }
  if(embalagem[0] == 'S'){
    largura = 48;
    comprimento = 32;
  }
  if(embalagem[0] == 'H'){
    largura = 48;
    comprimento = 64;
  }

  precof = distancia/1000.00 * (altura+comprimento+largura)/4.00;

  return precof;  
}