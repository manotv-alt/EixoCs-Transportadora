typedef struct dados_base base;
typedef struct dados_pessoais pessoais;
#define x 30
#define y 120
#define max_l 38
#define max_c 120


struct dados_pessoais {
    char cpf_remetente[15];
    char cpf_destinatario[15];
    char nome_remetente[150];
    char nome_destinatario[150];
};

struct dados_base {
    char origem[30];
    char destino[30];
    char embalagem[4];
    char data[15];
};

void grava_ifem(int linha_0, int coluna_0, wchar_t mat[x][y]);

void grava_e(int linha_0, int coluna_0, wchar_t mat[x][y]);

void grava_i(int linha_0, int coluna_0, wchar_t mat[x][y]);

void grava_x(int linha_0, int coluna_0, wchar_t mat[x][y]);

void grava_o(int linha_0, int coluna_0, wchar_t mat[x][y]);

void grava_c(int linha_0, int coluna_0, wchar_t mat[x][y]);

void grava_s(int linha_0, int coluna_0, wchar_t mat[x][y]);

void grava_perguntas_primarias(int linha_0, int coluna_0, wchar_t mat[x][y]);

void grava_origem(base *dados, wchar_t mat[x][y], int linha_0, int coluna_0, char cidades[8][20]);

void grava_destino(base *dados, wchar_t mat[x][y], int linha_0, int coluna_0, char cidade[8][20]);

void grava_embalagem(base *dados, wchar_t mat[x][y], int linha_0, int coluna_0);

void grava_data(base *dados, wchar_t mat[x][y], int linha_0, int coluna_0);

void confirma(int linha_0, int coluna_0, wchar_t mat[x][y]);

void grava_perguntas_secundarias(int linha_0, int coluna_0, wchar_t mat[x][y]);

void grava_nome_remetente(pessoais *dados, wchar_t mat[x][y], int linha_0, int coluna_0);

void grava_nome_destinatario(pessoais *dados, wchar_t mat[x][y], int linha_0, int coluna_0);

void grava_cpf_remetente(pessoais *dados, wchar_t mat[x][y], int linha_0, int coluna_0);

void grava_cpf_destinatario(pessoais *dados, wchar_t mat[x][y], int linha_0, int coluna_0);

void respostas_primarias(int linha_0, int coluna_0, wchar_t *mat[x][y], base dados);

void coleta_dados(base *dados_coletar, wchar_t mat[x][y], int linha_0, int coluna_0);

pessoais cpf_nome();

void alterar_indice(char vetor[16], int *variavel);

int confirmar_cpf(pessoais cpf);

void limpa_origem(wchar_t mat[x][y], int linha_0, int coluna_0);

void limpa_destino(wchar_t mat[x][y], int linha_0, int coluna_0);

void limpa_embalagem(wchar_t mat[x][y], int linha_0, int coluna_0);

void limpa_data( wchar_t mat[x][y], int linha_0, int coluna_0);

void limpa_confirma(wchar_t mat[x][y], int linha_0, int coluna_0);

void limpa_cpf_destinatario(wchar_t mat[x][y], pessoais pessoa, int linha_0, int coluna_0);

void limpa_cpf_remetente(wchar_t mat[x][y], pessoais pessoa, int linha_0, int coluna_0);

void limpa_nome_remetente(wchar_t mat[x][y], pessoais pessoa, int linha_0, int coluna_0);

void limpa_nome_destinatario(wchar_t mat[x][y], pessoais pessoa, int linha_0, int coluna_0);

void limpa_cidades_disponiveis(wchar_t mat[x][y], int linha_0, int coluna_0);

int verifica_data(char data[15]);

int string_int(char data[15]);

void ponteiro(wchar_t mat[x][y], int linha_0, int coluna_0);

void grava_resumo_dados(wchar_t mat[x][y], int linha_0, int coluna_0);

void grava_estimativa_de_tempo(wchar_t mat[x][y], int linha_0, int coluna_0, char *tempo);

void grava_preco(wchar_t mat[x][y], int linha_0, int coluna_0, float preco);

int ascii_string(char *s);

void finalizar(wchar_t mat[x][y]);

int converte_pra_indice(char *cidade);

void confirma_pedido(int linha_0, int coluna_0, wchar_t mat[x][y]);
