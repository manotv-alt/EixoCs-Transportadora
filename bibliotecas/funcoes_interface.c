#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include <string.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
#define a 3
#define b 35
#define c 14
#define d 20
wchar_t interface[max_l][max_c];


void grava_e(int linha_0, int coluna_0, wchar_t mat[x][y])
{
    int i, j;
    int linha_f = linha_0 + 5, coluna_f = coluna_0 + 5;

    setlocale(LC_CTYPE, "");

    for (i = linha_0; i < linha_f; i++)
    {
        for (j = coluna_0; j < coluna_f; j++)
        {
            if (i == linha_0 || i == linha_f - 1 || i == linha_0 + 2)
                mat[i][j] = 0x2588;
            else
            {
                mat[i][j] = 0x2588;
                break;
            }
        }
    }
}

void grava_i(int linha_0, int coluna_0, wchar_t mat[x][y])
{
    int i, j;
    int linha_f = linha_0 + 5, coluna_f = coluna_0 + 2;

    setlocale(LC_CTYPE, "");

    for (i = linha_0; i < linha_f; i++)
    {
        for (j = coluna_0; j < coluna_f; j++)
        {
            mat[i][j] = 0x2588;
        }
    }
}

void grava_x(int linha_0, int coluna_0, wchar_t mat[x][y])
{
    int linha_f = linha_0 + 5, coluna_f = coluna_0 + 5;
    int i, j, cres = coluna_0, dec = coluna_f - 1;

    setlocale(LC_CTYPE, "");

    for (i = linha_0; i < linha_f; i++)
    {
        for (j = coluna_0; j < coluna_f; j++)
        {
            if (j == cres || j == dec)
                mat[i][j] = 0x2588;
        }
        cres++;
        dec--;
    }
}

void grava_o(int linha_0, int coluna_0, wchar_t mat[x][y])
{
    int i, j;
    int linha_f = linha_0 + 5, coluna_f = coluna_0 + 5;

    setlocale(LC_CTYPE, "");

    for (i = linha_0; i < linha_f; i++)
    {
        for (j = coluna_0; j < coluna_f; j++)
        {
            if (i == linha_0 || i == linha_f - 1)
                mat[i][j] = 0x2588;
            if (j == coluna_0 || j == coluna_f - 1)
                mat[i][j] = 0x2588;
        }
    }
}

void grava_c(int linha_0, int coluna_0, wchar_t mat[x][y])
{
    int i, j;
    int linha_f = linha_0 + 5, coluna_f = coluna_0 + 5;

    setlocale(LC_CTYPE, "");

    for (i = linha_0; i < linha_f; i++)
    {
        for (j = coluna_0; j < coluna_f; j++)
        {
            if (i == linha_0 || i == linha_f - 1)
                mat[i][j] = 0x2588;
            if (j == coluna_0)
                mat[i][j] = 0x2588;
        }
    }
}

void grava_s(int linha_0, int coluna_0, wchar_t mat[x][y])
{
    int i, j;
    int linha_f = linha_0 + 5, coluna_f = coluna_0 + 5;

    setlocale(LC_CTYPE, "");

    for (i = linha_0; i < linha_f; i++)
    {
        for (j = coluna_0; j < coluna_f; j++)
        {
            if (i == linha_0 || i == linha_f - 1)
                mat[i][j] = 0x2588;
            if (j == coluna_0 && i <= linha_0 + 2 || j == coluna_f - 1 && i >= linha_0 + 2)
                mat[i][j] = 0x2588;
            if (j == coluna_0 + 1 && i == linha_0 + 2 || j == coluna_f - 2 && i == linha_0 + 2)
                mat[i][j] = 0x2588;
            if (j == coluna_0 + 2 && i == linha_0 + 2)
                mat[i][j] = 0x2588;
        }
    }
}

void grava_ifem(int linha_0, int coluna_0, wchar_t mat[x][y])
{
    int i, j;
    int linha_f = linha_0 + 1, coluna_f = coluna_0 + 5;

    setlocale(LC_CTYPE, "");

    for (i = linha_0; i < linha_f; i++)
    {
        for (j = coluna_0; j < coluna_f; j++)
        {
            mat[i][j] = 0x2588;
        }
    }
}

void grava_perguntas_primarias(int linha_0, int coluna_0, wchar_t mat[x][y])
{
    int i, j;
    int z = 0;
    setlocale(LC_CTYPE, "");
    char origem[20];
    char destino[21];
    char embalagem[21];
    char data[33];
    char cidades_disponiveis[99];
    char nomes_cidades[21];

    strcpy(origem, "CIDADE DE ORIGEM: ");
    strcpy(destino, "CIDADE DE DESTINO: ");
    strcpy(embalagem, "TIPO DE EMBALAGEM: ");
    strcpy(data, "DATA DA POSTAGEM (DD/MM/AAAA): ");
    strcpy(cidades_disponiveis, "GOIANIA - BRASILIA - CUIABA - CAMPO GRANDE - BELO HORIZONTE - SAO PAULO - RIO DE JANEIRO - VITORIA");
    strcpy(nomes_cidades, "CIDADES DISPONIVEIS:");

    z = 0;
    for (i = linha_0;; i++)
    {
        for (j = coluna_0; j < strlen(origem) + coluna_0; j++, z++)
        {
            mat[i][j] = origem[z];
        }
        break;
    }

    z = 0;
    for (i = linha_0;; i++)
    {
        for (j = coluna_0 + 55; j < strlen(destino) + coluna_0 + 55; j++, z++)
        {
            mat[i][j] = destino[z];
        }
        break;
    }

    z = 0;
    for (i = linha_0 + 4;; i++)
    {
        for (j = coluna_0; j < strlen(embalagem) + coluna_0; j++, z++)
        {
            mat[i][j] = embalagem[z];
        }
        break;
    }

    z = 0;
    for (i = linha_0 + 4;; i++)
    {
        for (j = coluna_0 + 55; j < strlen(data) + coluna_0 + 55; j++, z++)
        {
            mat[i][j] = data[z];
        }
        break;
    }

    z = 0;
    for (i = linha_0-4;; i++)
    {
        for (j = coluna_0-8; j < strlen(cidades_disponiveis) + coluna_0-8; j++, z++)
        {
            mat[i][j] = cidades_disponiveis[z];
        }
        break;
    }

    z = 0;
    for (i = linha_0-5;; i++)
    {
        for (j = coluna_0+28; j < strlen(nomes_cidades) + coluna_0+28; j++, z++)
        {
            mat[i][j] = nomes_cidades[z];
        }
        break;
    }

}

void limpa_cidades_disponiveis(wchar_t mat[x][y], int linha_0, int coluna_0){
    int i, j, z;

    z = 0;
    for (i = linha_0-4;; i++)
    {
        for (j = coluna_0-8; j < 99 + coluna_0-8; j++, z++)
        {
            mat[i][j] = ' ';
        }
        break;
    }

    z = 0;
    for (i = linha_0-5;; i++)
    {
        for (j = coluna_0+28; j < 21 + coluna_0+28; j++, z++)
        {
            mat[i][j] = ' ';
        }
        break;
    }

}

void confirma(int linha_0, int coluna_0, wchar_t mat[x][y])
{
    int i, j, z;
    setlocale(LC_CTYPE, "");
    char confirma[20];
    char sim[10];
    char nao[10];
    strcpy(confirma, "CONFIRMAR DADOS ?");
    strcpy(sim, "[1] SIM");
    strcpy(nao, "[2] NAO");


        z = 0;
        for (i = linha_0 + 17;; i++)
        {
            for (j = coluna_0 + 30; j < strlen(confirma) + coluna_0 + 30; j++, z++)
            {
                mat[i][j] = confirma[z];
            }
            break;
        }

        z = 0;
        for (i = linha_0 + 19;; i++)
        {
            for (j = coluna_0 + 27; j < strlen(sim) + coluna_0 + 27; j++, z++)
            {
                mat[i][j] = sim[z];
            }
            break;
        }

        z = 0;
        for (i = linha_0 + 19;; i++)
        {
            for (j = coluna_0 + 42; j < strlen(nao) + coluna_0 + 42; j++, z++)
            {
                mat[i][j] = nao[z];
            }
            break;
        }
}

void limpa_origem(wchar_t mat[x][y], int linha_0, int coluna_0){
    int i, j, z;
    for (i = linha_0;; i++) {
        for (j = coluna_0+19; j < 20 + coluna_0+19; j++, z++) {
                mat[i][j] = L' ';
        }
        break;
    }

}
void limpa_destino(wchar_t mat[x][y], int linha_0, int coluna_0){
    int i, j, z;
    for (i = linha_0;; i++) {
        for (j = coluna_0+75; j < 20 + coluna_0+75; j++, z++) {
                mat[i][j] = L' ';
        }
            break;
    }
}
void limpa_embalagem(wchar_t mat[x][y], int linha_0, int coluna_0){
    int i, j, z;
    for (i = linha_0+4;; i++) {
        for (j = coluna_0+20; j < 5 + coluna_0+20; j++, z++) {
            mat[i][j] = ' ';
        }
        break;
    }

}
void limpa_data(wchar_t mat[x][y], int linha_0, int coluna_0){
    int i, j, z;
    for (i = linha_0+4;; i++) {
        for (j = coluna_0+87; j < 12 + coluna_0+87; j++, z++) {
            mat[i][j] = ' ';
        }
        break;
    }

}
void limpa_confirma(wchar_t mat[x][y], int linha_0, int coluna_0){
    int i, j, z;
    for (i = linha_0 + 17;; i++)
    {
        for (j = coluna_0 + 30; j < 20 + coluna_0 + 30; j++, z++)
        {
            mat[i][j] = ' ';
        }
        break;
    }
    z = 0;
    for (i = linha_0 + 19;; i++)
    {
        for (j = coluna_0 + 27; j < 10 + coluna_0 + 27; j++, z++)
        {
            mat[i][j] = ' ';
        }
        break;
    }
    z = 0;
    for (i = linha_0 + 19;; i++)
    {
        for (j = coluna_0 + 42; j < 10 + coluna_0 + 42; j++, z++)
        {
            mat[i][j] = ' ';
        }
        break;
    }

}

void grava_perguntas_segundarias(int linha_0, int coluna_0, wchar_t mat[x][y])
{
    char cpf_remetente[16];
    char cpf_destinatario[20];
    char nome_remetente[17];
    char nome_destinatario[21];
    int i, j;
    int z = 0;
    setlocale(LC_CTYPE, "");

    strcpy(cpf_remetente, "CPF REMETENTE: ");
    strcpy(cpf_destinatario, "CPF DESTINATARIO: ");
    strcpy(nome_remetente, "NOME REMETENTE: ");
    strcpy(nome_destinatario, "NOME DESTINATARIO: ");

    z = 0;
    for (i = linha_0 + 8;; i++)
    {
        for (j = coluna_0; j < strlen(cpf_remetente) + coluna_0; j++, z++)
        {
            mat[i][j] = cpf_remetente[z];
        }
        break;
    }

    z = 0;
    for (i = linha_0 + 8;; i++)
    {
        for (j = coluna_0 + 55; j < strlen(cpf_destinatario) + coluna_0 + 55; j++, z++)
        {
            mat[i][j] = cpf_destinatario[z];
        }
        break;
    }

    z = 0;
    for (i = linha_0 + 12;; i++)
    {
        for (j = coluna_0; j < strlen(nome_remetente) + coluna_0; j++, z++)
        {
            mat[i][j] = nome_remetente[z];
        }
        break;
    }

    z = 0;
    for (i = linha_0 + 12;; i++)
    {
        for (j = coluna_0 + 55; j < strlen(nome_destinatario) + coluna_0 + 55; j++, z++)
        {
            mat[i][j] = nome_destinatario[z];
        }
        break;
    }
}

void grava_origem(base *dados, wchar_t mat[x][y], int linha_0, int coluna_0, char cidades[8][20]) {
    int i, j, z;
    int comp;
    /*faz scanf na cidade de origem. Depois disso 
    passa todas as letras dela para minusculo,
    assim, compara com as cidades da matriz cidades, 
    fazendo a verificacao. Depois grava-a na matriz
    de interface*/
   
    char origem[20];
    scanf("\n%[^\n]%*c", origem);
    for (int i = 0; i < strlen(origem); i++){
        if ((int)origem[i] >= 97 && (int)origem[i] <= 122){
            origem[i] = (char)((int)origem[i] - 32);
        }
    }

    for (int i = 0; i < 8; i++){
        if (strcmp(origem, cidades[i]) == 0){
            comp = 1;
            strcpy(cidades[i], "em uso");
        }
    }

    while (comp != 1){
        printf("Cidade indisponivel, digite novamente:\n");
        scanf("%[^\n]%*c", origem);
        for (int i = 0; i < strlen(origem); i++){
            if ((int)origem[i] >= 97 && (int)origem[i] <= 122){
                origem[i] = (char)((int)origem[i] - 32);
            }
        }

        for (int i = 0; i < 8; i++){
            if (strcmp(origem, cidades[i]) == 0){
                comp = 1;
                strcpy(cidades[i], "em uso");
            }
        }
    }
    
    strcpy(dados->origem, origem);
    
    z = 0;
    for (i = linha_0;; i++) {
        for (j = coluna_0+19; j < strlen(origem) + coluna_0+19; j++, z++) {
            mat[i][j] = origem[z];
        }
        break;
    }
}

void grava_destino(base *dados, wchar_t mat[x][y], int linha_0, int coluna_0, char cidades[8][20]) {
    int i, j, z;
    int comp;
    /*faz scanf na cidade de destino. Depois disso 
    passa todas as letras dela para minusculo,
    assim, compara com as cidades da matriz cidades, 
    fazendo a verificacao. Apos isso, a grava na matriz
    de interface*/

    char destino[20];
    scanf("\n%[^\n]%*c", destino);
    for (int i = 0; i < strlen(destino); i++){
        if ((int)destino[i] >= 97 && (int)destino[i] <= 122){
            destino[i] = (char)((int)destino[i] - 32);
        }
    }

    for (int i = 0; i < 8; i++){
        if (strcmp(destino, cidades[i]) == 0){
            comp = 1;
        }
    }

    while (comp != 1){
        printf("Cidade indisponivel, digite novamente:\n");
        scanf("%[^\n]%*c", destino);
        for (int i = 0; i < strlen(destino); i++){
            if ((int)destino[i] >= 97 && (int)destino[i] <= 122){
                destino[i] = (char)((int)destino[i] - 32);
            }
        }

        for (int i = 0; i < 8; i++){
            if (strcmp(destino, cidades[i]) == 0){
                comp = 1;
            }
        }
    }


    strcpy(dados->destino, destino);

        z = 0;
        for (i = linha_0;; i++) {
            for (j = coluna_0+75; j < strlen(destino) + coluna_0+75; j++, z++) {
                mat[i][j] = destino[z];
            }
            break;
        }
}

void grava_embalagem(base *dados, wchar_t mat[x][y], int linha_0, int coluna_0) {
    int i, j, z;

   
    printf("\nEMBALAGENS DISPONIVEIS: Largura(cm) x Comprimento(cm) x Altura(cm) - Peso máximo(kg)\n");
    printf("\nA: 12x16x04 - 1,5");
    printf("\nB: 12x32x12 - 4");
    printf("\nC: 24x16x12 - 4");
    printf("\nD: 24x32x20 - 14");
    printf("\nE: 48x32x28 - 30");
    printf("\nF: 48x64x48 - 30\n");


    
    char embalagens[12][2];
    int comp = 0;
    strcpy(embalagens[0], "A");
    strcpy(embalagens[1], "B");
    strcpy(embalagens[2], "C");
    strcpy(embalagens[3], "D");
    strcpy(embalagens[4], "E");
    strcpy(embalagens[5], "F");
    strcpy(embalagens[6], "a");
    strcpy(embalagens[7], "b");
    strcpy(embalagens[8], "c");
    strcpy(embalagens[9], "d");
    strcpy(embalagens[10],"e");
    strcpy(embalagens[11],"f");

    printf("\nInsira o indice da embalagem: \n");

    fgets(dados->embalagem, 3, stdin);
    dados->embalagem[1] = '\0';
    //dados->embalagem[1] = ' ';
    
    for (int i = 0; i < 12; i++){
        if (strcmp(dados->embalagem, embalagens[i]) == 0)
        {
            comp = 1;
        }
    }

    while (comp != 1){
        printf("Indice incorreto, digite novamente: \n");
        fgets(dados->embalagem, 3, stdin);
        dados->embalagem[1] = '\0';
        for (int i = 0; i < 12; i++){
            if (strcmp(dados->embalagem, embalagens[i]) == 0){
                comp = 1;
            }
        }
    }
    
    dados->embalagem[1] = ' ';
    dados->embalagem[2] = ' ';

    //se estiver minusculo passa para maiusculo
    if((int)dados->embalagem[0] >= 97 && (int)dados->embalagem[0] <= 122){
        dados->embalagem[0] = (char)((int)dados->embalagem[0] - 32);
    }

    z = 0;
    for (i = linha_0+4;; i++) {
        for (j = coluna_0+20; j < strlen(dados->embalagem) + coluna_0+20; j++, z++) {
            mat[i][j] = dados->embalagem[z];
        }
        break;
    }
}

void grava_data(base *dados, wchar_t mat[x][y], int linha_0, int coluna_0) {
    int i, j, z;
  
    char data[15];
    scanf("\n%[^\n]%*c", data);
    verifica_data(data);
    while(verifica_data(data) == 1){
        printf("Digitos invalidos, insira a data novamente:\n");
        scanf("\n%[^\n]%*c", data);
        verifica_data(data);
    }
    string_int(data);
    while(string_int(data) == 1){
        printf("Data invalida, digite novamente:\n");
        scanf("\n%[^\n]%*c", data);
        verifica_data(data);
        while(verifica_data(data) == 1){
            printf("Digitos invalidos, insira a data novamente:\n");
            scanf("\n%[^\n]%*c", data);
            verifica_data(data);
        }
        string_int(data);
    }
    strcpy(dados->data, data);
    
    z = 0;
    for (i = linha_0+4;; i++) {
        for (j = coluna_0+87; j < strlen(dados->data) + coluna_0+87; j++, z++) {
            mat[i][j] = dados->data[z];
        }
        break;
    }

}

int string_int(char data[15]){
    int dia, mes, ano;

    dia = ((int)data[0] - 48)*10 + ((int)data[1] - 48);
    mes = ((int)data[3] - 48)*10 + ((int)data[4] - 48);
    ano = ((int)data[6] - 48)*1000 + ((int)data[7] - 48)*100 + ((int)data[8] - 48)*10 + ((int)data[9] - 48);
    
    if(dia > 31 || mes > 12 || ano < 2023 || (mes == 2 && dia > 28)){
        return 1;
    }else{
        return 0;
    }

}

int verifica_data(char data[15]){
    int i, j;
    int teste = 0;
    for(i = 0; i < 10; i++){
        if(i == 2 || i == 5){
            continue;
        }

        if((int)data[i] < 48 || (int)data[i] > 57){
            teste = 1;
            break;
        }
    }  
    if(teste == 1) return 1;
    if(teste == 0) return 0;
}

void ponteiro(wchar_t mat[x][y], int linha_0, int coluna_0){
    mat[linha_0][coluna_0] = 0x27A4;
    //mat[linha_0][coluna_0+1] = 0x262D;
    int linha, coluna;
    for(linha = 0; linha < max_l; linha++) {
        for(coluna = 0; coluna < max_c; coluna++){
            printf( "%lc", mat[linha][coluna]);
        }
        printf("\n");
    } 
}

void grava_perguntas_secundarias(int linha_0, int coluna_0, wchar_t mat[x][y])
{
    int i, j;
    int z = 0;
    setlocale(LC_CTYPE, "");
    char sem_ponto[17];
    char cpf_remetente[20];
    char cpf_destinatario[23];
    char nome_remetente[21];
    char nome_destinatario[24];

    strcpy(sem_ponto, "APENAS NUMEROS!");
    strcpy(cpf_remetente, "CPF DO REMETENTE: ");
    strcpy(cpf_destinatario, "CPF DO DESTINATARIO: ");
    strcpy(nome_remetente, "NOME DO REMETENTE: ");
    strcpy(nome_destinatario, "NOME DO DESTINATARIO: ");

    z = 0;
    for (i = linha_0 + 8;; i++)
    {
        for (j = coluna_0; j < strlen(nome_remetente) + coluna_0; j++, z++)
        {
            mat[i][j] = nome_remetente[z];
        }
        break;
    }

    z = 0;
    for (i = linha_0 + 8;; i++)
    {
        for (j = coluna_0 + 55; j < strlen(cpf_remetente) + coluna_0 + 55; j++, z++)
        {
            mat[i][j] = cpf_remetente[z];
        }
        break;
    }

    z = 0;
    for (i = linha_0 + 9;; i++)
    {
        for (j = coluna_0 + 55; j < strlen(sem_ponto) + coluna_0 + 55; j++, z++)
        {
            mat[i][j] = sem_ponto[z];
        }
        break;
    }

    z = 0;
    for (i = linha_0 + 12;; i++)
    {
        for (j = coluna_0; j < strlen(nome_destinatario) + coluna_0; j++, z++)
        {
            mat[i][j] = nome_destinatario[z];
        }
        break;
    }

    z = 0;
    for (i = linha_0 + 12;; i++)
    {
        for (j = coluna_0 + 55; j < strlen(cpf_destinatario) + coluna_0 + 55; j++, z++)
        {
            mat[i][j] = cpf_destinatario[z];
        }
        break;
    }

    z = 0;
    for (i = linha_0 + 13;; i++)
    {
        for (j = coluna_0 + 55; j < strlen(sem_ponto) + coluna_0 + 55; j++, z++)
        {
            mat[i][j] = sem_ponto[z];
        }
        break;
    }
}

    //CRIAR FUNÇÃO QUE SIMULA O PONTEIRO DO MOUSE ONDE O USUÁRIO ESTÁ ESCREVENDO


void grava_nome_remetente(pessoais *dados, wchar_t mat[x][y], int linha_0, int coluna_0) {
    int i, j, z = 0;

    while(1) {
        int verifica;

        scanf("\n%[^\n]%*c", dados->nome_remetente);

        while(1) {
            if (strlen(dados->nome_remetente) > 33) {
            printf("Seu nome e muito grande, use abreviacoes!\n");
            scanf("\n%[^\n]%*c", dados->nome_remetente);
            }
            else{break;}
        }

        verifica = ascii_string(dados->nome_remetente);

        if (verifica == 1) break;
        else {
            printf("Caracteres invalidos, não use nenhum tipo de acentuacao!\n");
        }
    }

    for (int i = 0; i < strlen(dados->nome_remetente); i++){
        if ((int)dados->nome_remetente[i] >= 97 && (int)dados->nome_remetente[i] <= 122){
            dados->nome_remetente[i] = (char)((int)dados->nome_remetente[i] - 32);
        }
    }

    char nome[strlen(dados->nome_remetente)+1];
    strcpy(nome, dados->nome_remetente);
    
    for (i = linha_0 + 8;; i++) {
        for (j = coluna_0+20; j < strlen(nome) + coluna_0+20; j++, z++) {
            mat[i][j] = nome[z];
        }
        break;
    }
}

void grava_nome_destinatario(pessoais *dados, wchar_t mat[x][y], int linha_0, int coluna_0) {
    int i, j, z = 0;

    while(1) {
        int verifica;

        scanf("\n%[^\n]%*c", dados->nome_destinatario);
        
        while(1) {
            if (strlen(dados->nome_destinatario) > 30) {
            printf("Seu nome e muito grande, use abreviacoes!\n");
            scanf("\n%[^\n]%*c", dados->nome_destinatario);
            }
            else{break;}
        }

        verifica = ascii_string(dados->nome_destinatario);


        if (verifica == 1) break;
        else {
            printf("Caracteres invalidos, não use nenhum tipo de acentuacao!\n");
        }
    }

    for (int i = 0; i < strlen(dados->nome_destinatario); i++){
        if ((int)dados->nome_destinatario[i] >= 97 && (int)dados->nome_destinatario[i] <= 122){
            dados->nome_destinatario[i] = (char)((int)dados->nome_destinatario[i] - 32);
        }
    }

    char nome[strlen(dados->nome_destinatario)+1];
    strcpy(nome, dados->nome_destinatario);
    
    for (i = linha_0 + 12;; i++) {
        for (j = coluna_0+23; j < strlen(nome) + coluna_0+23; j++, z++) {
            mat[i][j] = nome[z];
        }
        break;
    }
}

void grava_cpf_remetente(pessoais *dados, wchar_t mat[x][y], int linha_0, int coluna_0) {
    int i, j, z = 0;
    int teste = 0;

    scanf("\n%[^\n]%*c", dados->cpf_remetente);
    for(i = 0; i < strlen(dados->cpf_remetente); i++){
        if((int)dados->cpf_remetente[i] < 48 || (int)dados->cpf_remetente[i] > 57){
            teste = 1;
            break;
        }
        if(strlen(dados->cpf_remetente) != 11){
            teste = 1;
            break;
        }
    }  
    while(teste == 1){
        teste = 0;
        printf("CPF invalido, insira novamente:\n");
        scanf("\n%[^\n]%*c", dados->cpf_remetente);
        for(i = 0; i < strlen(dados->cpf_remetente); i++){
            if((int)dados->cpf_remetente[i] < 48 || (int)dados->cpf_remetente[i] > 57){
                teste = 1;
                break;
            }
            if(strlen(dados->cpf_remetente) != 11){
                teste = 1;
                break;
        }
        }  
    }

    char cpf[strlen(dados->cpf_remetente)+1];
    strcpy(cpf, dados->cpf_remetente);
    
    for (i = linha_0 + 8;; i++) {
        for (j = coluna_0+74; j < strlen(cpf) + coluna_0+74; j++, z++) {
            mat[i][j] = cpf[z];
        }
        break;
    }
}

void grava_cpf_destinatario(pessoais *dados, wchar_t mat[x][y], int linha_0, int coluna_0) {
    int i, j, z = 0;
    int teste = 0;

    scanf("\n%[^\n]%*c", dados->cpf_destinatario);
    for(i = 0; i < strlen(dados->cpf_destinatario); i++){
        if((int)dados->cpf_destinatario[i] < 48 || (int)dados->cpf_destinatario[i] > 57){
            teste = 1;
            break;
        }
        if(strlen(dados->cpf_destinatario) != 11){
            teste = 1;
            break;
        }
    }  
    while(teste == 1){
        teste = 0;
        printf("CPF invalido, insira novamente:\n");
        scanf("\n%[^\n]%*c", dados->cpf_destinatario);
        for(i = 0; i < strlen(dados->cpf_destinatario); i++){
            if((int)dados->cpf_destinatario[i] < 48 || (int)dados->cpf_destinatario[i] > 57){
                teste = 1;
                break;
            }
            if(strlen(dados->cpf_destinatario) != 11){
            teste = 1;
            break;
        }
        }  
    }


    char cpf[strlen(dados->cpf_destinatario)+1];
    strcpy(cpf, dados->cpf_destinatario);
    
    for (i = linha_0 + 12;; i++) {
        for (j = coluna_0+77; j < strlen(cpf) + coluna_0+77; j++, z++) {
            mat[i][j] = cpf[z];
        }
        break;
    }
}

void limpa_nome_remetente(wchar_t mat[x][y], pessoais pessoa, int linha_0, int coluna_0){
    int i, j, z;
    for (i = linha_0 + 8;; i++) {
        for (j = coluna_0+20; j < strlen(pessoa.nome_remetente)+coluna_0+20; j++, z++) {
                mat[i][j] = ' ';
        }
        break;
    }

}

void limpa_nome_destinatario(wchar_t mat[x][y], pessoais pessoa, int linha_0, int coluna_0){
    int i, j, z;
    for (i = linha_0 + 12;; i++) {
        for (j = coluna_0+23; j < strlen(pessoa.nome_destinatario)+coluna_0+23; j++, z++) {
                mat[i][j] = ' ';
        }
        break;
    }

}

void limpa_cpf_remetente(wchar_t mat[x][y], pessoais pessoa, int linha_0, int coluna_0){
    int i, j, z;
    for (i = linha_0 + 8;; i++) {
        for (j = coluna_0+74; j < strlen(pessoa.cpf_remetente)+coluna_0+74; j++, z++) {
                mat[i][j] = ' ';
        }
        break;
    }

}

void limpa_cpf_destinatario(wchar_t mat[x][y], pessoais pessoa, int linha_0, int coluna_0){
    int i, j, z;
    for (i = linha_0 + 12;; i++) {
        for (j = coluna_0+77; j < strlen(pessoa.cpf_destinatario)+coluna_0+77; j++, z++) {
                mat[i][j] = ' ';
        }
        break;
    }

}

void grava_resumo_dados(wchar_t mat[x][y], int linha_0, int coluna_0) {
    int i, j, z;
    char resumo[27];
    strcpy(resumo, "RESUMO FINAL DO PEDIDO : ");

    z = 0;
    for (i = linha_0-4;; i++)
    {
        for (j = coluna_0+27; j < strlen(resumo) + coluna_0+27; j++, z++)
        {
            mat[i][j] = resumo[z];
        }
        break;
    }
}

void grava_estimativa_de_tempo(wchar_t mat[x][y], int linha_0, int coluna_0, char *tempo) {
    int i, j, z;
    //char estimativa[25];
    //char tempo_entrega[strlen(tempo)+1];
    //strcpy(estimativa, "ESTIMATIVA DE ENTREGA: ");
    //strcat(estimativa, tempo);

    z = 0;
    for (i = linha_0+16;; i++)
    {
        for (j = coluna_0; j < strlen(tempo) + coluna_0; j++, z++)
        {
            mat[i][j] = tempo[z];
        }
        break;
    }
}

void grava_preco(wchar_t mat[x][y], int linha_0, int coluna_0, float preco_final) {
    int i, j, z;
    char preco[30];
    //char tempo_entrega[strlen(tempo)+1];
    //strcpy(preco, "VALOR DO SERVICO: ");
    sprintf(preco, "VALOR DO SERVICO: R$ %.2lf", preco_final);

    z = 0;
    for (i = linha_0+16;; i++)
    {
        for (j = coluna_0+55; j < strlen(preco) + coluna_0+55; j++, z++)
        {
            mat[i][j] = preco[z];
        }
        break;
    }
}

int ascii_string(char *s) {
   int i;
   char str[strlen(s)+1];
   strcpy(str, s);

  for (i = 0; i < strlen(str); i++) {
    if (str[i] < 0 || str[i] > 127) {
      return 0;
    }
  }
  return 1;
}

void finalizar(wchar_t mat[x][y]) {
    int i, j, l, k, contador = x, cres_li = 0, cres_co = 0, dec_co = y; 

    for(i = 0; i < max_l; i++) {
        for(j = 0; j < max_c; j++) {
            mat[i][j] = ' ';
        }
    }

    while(contador != 0) {

        for(i = cres_co; i < y; i++) {
            mat[cres_li][i] = 0x2588;
            printf("%lc", mat[cres_li][i]);
            usleep(1000);
        }
        printf("\n");
        

        for(j = cres_li; j < 0; j++) {
            mat[j][dec_co] = 0x2588;
            printf("%lc", mat[j][dec_co]);
            printf("\n");
            usleep(1000);
        }
        

        for(l = dec_co; l > 0; l--) {
            mat[contador][l] = 0x2588;
            printf("%lc", mat[contador][l]);
            usleep(1000);
        }
        

        for(k = contador; k > 0; k--) {
            mat[k][cres_co] = 0x2588;
            printf("%lc", mat[k][cres_co]);
            usleep(1000);
        }
        printf("\n");
        

        cres_co++;
        cres_li++;
        dec_co--;
        contador--;
    }
}

int converte_pra_indice(char *cidade) {
    char cidades[9][16];
    int indice_cidade = 0;

    /*
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 16; j++) {
            indice[i][j] = '\0';
        }
    }*/

    strcpy(cidades[0], "GOIANIA");
    strcpy(cidades[1], "BRASILIA");
    strcpy(cidades[2], "CUIABA");
    strcpy(cidades[3], "CAMPO GRANDE");
    strcpy(cidades[4], "BELO HORIZONTE");
    strcpy(cidades[5], "SAO PAULO");
    strcpy(cidades[6], "RIO DE JANEIRO");
    strcpy(cidades[7], "VITORIA");

    for(int i = 0; i < 8; i++) {
        if(strcmp(cidades[i], cidade) == 0) {
            indice_cidade = i;
        }
    }

    return indice_cidade;
}

void confirma_pedido(int linha_0, int coluna_0, wchar_t mat[x][y])
{
    int i, j, z;
    setlocale(LC_CTYPE, "");
    char confirma[18];
    char sim[10];
    char nao[10];
    strcpy(confirma, "EFETUAR PEDIDO ?");
    strcpy(sim, "[1] SIM");
    strcpy(nao, "[2] NAO");


        z = 0;
        for (i = linha_0 + 19;; i++)
        {
            for (j = coluna_0 + 32; j < strlen(confirma) + coluna_0 + 32; j++, z++)
            {
                mat[i][j] = confirma[z];
            }
            break;
        }

        z = 0;
        for (i = linha_0 + 20;; i++)
        {
            for (j = coluna_0 + 29; j < strlen(sim) + coluna_0 + 29; j++, z++)
            {
                mat[i][j] = sim[z];
            }
            break;
        }

        z = 0;
        for (i = linha_0 + 20;; i++)
        {
            for (j = coluna_0 + 44; j < strlen(nao) + coluna_0 + 44; j++, z++)
            {
                mat[i][j] = nao[z];
            }
            break;
        }
}