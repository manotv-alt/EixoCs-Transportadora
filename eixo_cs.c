#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <unistd.h>
#include <locale.h>
#include "funcoes.h"
#include "grafo.h"
#define a 3
#define b 35
#define c 15
#define d 18


int main() {

/*
Essa e' a iniciacao do nosso programa, usaremos um arquivo para preencher a matrix (o grafo) das rotas, e tambem as cidades disponiveis para o usuario escolher.
*/


FILE *arquivo = NULL;
grafo rota_cidades; // contem o grafo e a quantidade de cidades em sua struct
rota_cidades.matrix_grafo = NULL;
cidade *cidades = NULL; // contem os nomes das cidades e seus indices no grafo 
int *rotas = NULL; // esse ponteiro(recebera o endereco do vetor que contem os caminhos percorridos entre a cidade de origem e a de destino, usando: rotas = djikstra(rota_cidades, origem, destino, &distancia, &tamanho_vetor_cidades_percorridas)
int *rotas_com_valor = NULL; // essponteiro(contera a distancia entre uma cidade e outra, usando a funcao: rotas_com_valor = valor_caminhos(rotas, tamanho_vetor_cidades_percorridas, rota_cidades)
int origem, destino, distancia, tamanho_vetor_cidades_percorridas, quantidade_cidades; // a primeira variavel contem o tamanho do vetor das cidades percorridas apos djikstra ser executado
int bem_sucedido; // se bem sucedido a inicializacao, o valor 1 sera armazenado nessa variavel, do contrario, 0.
arquivo = fopen("grafos_definidos.txt", "r");
bem_sucedido = inicializar(arquivo, &quantidade_cidades, &rota_cidades, cidades);
char dias_entrega[100];

//char dias_entrega[] = "preco preco preco.";
float preco_final = 0;

//mostrar_grafo(rota_cidades);

fclose(arquivo);



//a inicializacao acabou

char cidade[8][20];
strcpy(cidade[0], "GOIANIA");
strcpy(cidade[1], "CUIABA");
strcpy(cidade[2], "SAO PAULO");
strcpy(cidade[3], "RIO DE JANEIRO");
strcpy(cidade[4], "VITORIA");
strcpy(cidade[5], "BRASILIA");
strcpy(cidade[6], "CAMPO GRANDE");
strcpy(cidade[7], "BELO HORIZONTE");


wchar_t interface[max_l][max_c];
int linha, coluna;
base dados;
pessoais pessoa;
printf("\033[1;34m");

    for(linha = 0; linha < max_l; linha++){
        for(coluna = 0; coluna < max_c; coluna++){
            if (linha == 0 || linha == max_l-1) interface[linha][coluna] = 0x2588;
            if (linha > 0 && linha < max_l-1) interface[linha][coluna] = 0x0020;
        }
    }

    for(coluna = 0; coluna < max_c; coluna++){
        for(linha = 1; linha < max_l-1; linha++){
            if (coluna == 0 || coluna == max_c-1) interface[linha][coluna] = 0x2588;
            if (coluna > 1 && coluna < max_c-2) interface[linha][coluna] = 0x0020;
           
        }
    }

    grava_e(a, b, interface);

    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    sleep(1);
    system("clear");

    grava_i(a, b+7, interface);

    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    sleep(1);
    system("clear");

    grava_x(a, b+11, interface);

    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    sleep(1);
    system("clear");

    grava_o(a, b+18, interface);

    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    sleep(1);
    system("clear");

    grava_ifem(a+2, b+25, interface);

    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    sleep(1);
    system("clear");

    grava_c(a, b+32, interface);

    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    sleep(1);
    system("clear");

    grava_s(a, b+39, interface);

    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }


    grava_perguntas_primarias(c, d, interface);

    system("clear");
    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    int ori, dest;

    while (1) {

    strcpy(cidade[0], "GOIANIA");
    strcpy(cidade[1], "CUIABA");
    strcpy(cidade[2], "SAO PAULO");
    strcpy(cidade[3], "RIO DE JANEIRO");
    strcpy(cidade[4], "VITORIA");
    strcpy(cidade[5], "BRASILIA");
    strcpy(cidade[6], "CAMPO GRANDE");
    strcpy(cidade[7], "BELO HORIZONTE");  

    int verificacao;
    
    system("clear");
    ponteiro(interface, c, d+19);

    grava_origem(&dados, interface, c, d, cidade);

    system("clear");
    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    system("clear");
    ponteiro(interface, c, d+75);


    grava_destino(&dados, interface, c, d, cidade);

    system("clear");
    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    ori = converte_pra_indice(dados.origem);
    dest = converte_pra_indice(dados.destino);

    system("clear");
    ponteiro(interface, c+4, d+20);


    grava_embalagem(&dados, interface, c, d);

    system("clear");
    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }
    
    system("clear");
    ponteiro(interface, c+4, d+87);


    grava_data(&dados, interface, c, d);

    system("clear");
    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    confirma(c, d, interface);

    system("clear");
    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    scanf("%d%*c", &verificacao);

    if(verificacao == 1) break;
    
    limpa_origem(interface, c, d);
    limpa_destino(interface, c, d);
    limpa_embalagem(interface, c, d);
    limpa_data(interface, c, d);
    limpa_confirma(interface, c, d);
    
    }

    //FUNÇÕES QUE CALCULAM PREÇO E TEMPO

    limpa_confirma(interface, c, d);

    grava_perguntas_secundarias(c, d, interface);

    system("clear");
    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }


    while(1) {

    system("clear");
    ponteiro(interface, c+8, d+20);

    grava_nome_remetente(&pessoa, interface, c, d);

    system("clear");
    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }
    
    system("clear");
    ponteiro(interface, c+8, d+74);

    grava_cpf_remetente(&pessoa, interface, c, d);

    system("clear");
    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    system("clear");
    ponteiro(interface, c+12, d+23);

    grava_nome_destinatario(&pessoa, interface, c, d);

    system("clear");
    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    system("clear");
    ponteiro(interface, c+12, d+77);
    
    grava_cpf_destinatario(&pessoa, interface, c, d);

    system("clear");
    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    confirma(c, d, interface);

    int verificacao;

    system("clear");
    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    scanf("%d%*c", &verificacao);

    if (verificacao == 1) break;

    limpa_cpf_remetente(interface, pessoa, c, d);
    limpa_cpf_destinatario(interface, pessoa, c, d);
    limpa_nome_destinatario(interface, pessoa, c, d);
    limpa_nome_remetente(interface, pessoa, c, d);
    limpa_confirma(interface, c, d);

    system("clear");
    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    }

    limpa_cidades_disponiveis(interface, c, d);

    limpa_confirma(interface, c, d);

    grava_resumo_dados(interface, c, d);

    valores_finais(rota_cidades, ori, dest, dados.embalagem, dias_entrega, &preco_final);

    grava_estimativa_de_tempo(interface, c, d, dias_entrega);

    grava_preco(interface, c, d, preco_final);

    system("clear");
    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    system("clear");
    confirma_pedido(c, d, interface);

    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", interface[linha][coluna]);
        }
        printf("\n");
    }

    int verifica;
    scanf("%d", &verifica);

    if (verifica == 1) {
        FILE *dados_cadastrais = fopen("banco_de_dados.txt", "a+");

        fprintf(dados_cadastrais, "CIDADE DE ORIGEM: %s\n", dados.origem);
        fprintf(dados_cadastrais, "CIDADE DE DESTINO: %s\n", dados.destino);
        fprintf(dados_cadastrais, "TIPO DE EMBALAGEM: %s\n", dados.embalagem);
        fprintf(dados_cadastrais, "DATA DA POSTAGEM: %s\n", dados.data);
        fprintf(dados_cadastrais, "NOME DO REMETENTE: %s\n", pessoa.nome_remetente);
        fprintf(dados_cadastrais, "CPF DO REMETENTE: %s\n", pessoa.cpf_remetente);
        fprintf(dados_cadastrais, "NOME DO DESTINATARIO: %s\n", pessoa.nome_destinatario);
        fprintf(dados_cadastrais, "CPF DO DESTINATARIO: %s\n", pessoa.cpf_destinatario);
        fprintf(dados_cadastrais, "ENTREGA EM %s DIAS UTEIS\n", dias_entrega);
        fprintf(dados_cadastrais, "VALOR DO SERVIÇO: %.2f\n", preco_final);
        fprintf(dados_cadastrais, "\n");
        fprintf(dados_cadastrais, "---------------------------------\n");
        fprintf(dados_cadastrais, "\n");
    }

    if (verifica == 2) {
        system("clear");
        return 0;
    }

    system("clear");
    
    free(cidades);
    matar_grafo(rota_cidades);

    

    return 0;
}
