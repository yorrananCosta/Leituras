#include <iostream>
#include <fstream>

using namespace std;

typedef struct
{
    int isbn_13;
    int isbn_10;
    string nome_lendo;
    int paginas_lendo;
    int ano;
    string idioma;
    string autor;
    string editora;
    int nota;
}
Leitura;
/*
void criar_arquivo()
{
    ofstream arquivo ("arquivo.csv", ios::app);
    arquivo.open("arquivo.csv");
    if (!arquivo)
    {
        cout << "O arquivo nao pode ser aberto!" << endl;
    }
    else
    {
        cout << "Arquivo criado com sucesso!" << endl;
    }
    arquivo.close();  
}
*/
/**
 * @brief
 * Abaixo deve se inserir um linha de registro com o uso da struct 
 * 
 * @return int 
 */

int contador_de_linhas(){
    string linha;
    int tamanho_linhas = 0;
    ifstream arquivo("arquivo.csv");
        if(!arquivo.is_open()) 
        {
            cout << "O arquivo não pode ser aberto" << endl;
        }
        while (getline(arquivo, linha))
        {
            tamanho_linhas++;
        }
    arquivo.close();

    return tamanho_linhas;
}

void incluir_registro()
{
    string isbn_13_s;
    string isbn_10_s;
    string nome_lendo;
    string paginas_lendo_s;
    string ano_s;
    string idioma;
    string autor;
    string editora;
    string nota_s;
    Leitura *lendo ;
    int tamanho;
    tamanho = contador_de_linhas();
    lendo =  new (nothrow) Leitura[tamanho];;
    ifstream arquivo("arquivo.csv");

    if(!arquivo.is_open()) 
    {
        cout << "Erro ao abrir o arquivo!" << '\n';
    }
    int posicao=0;
   
    while(arquivo.peek()!=EOF)
    {
        cout << "include..." << endl;
        getline(arquivo, isbn_13_s, ',');
        getline(arquivo, isbn_10_s,',');
        getline(arquivo, nome_lendo,',');
        getline(arquivo, paginas_lendo_s,',');
        getline(arquivo, ano_s,',');
        getline(arquivo, idioma,',');
        getline(arquivo, autor,',');
        getline(arquivo, editora,',');
        getline(arquivo, nota_s);

        //note a conversao de string para inteiro (codigo) e string para float (preco)
        lendo[posicao].isbn_13 = stoi(isbn_13_s);
        lendo[posicao].isbn_10 = stoi(isbn_10_s);
        lendo[posicao].nome_lendo = nome_lendo;
        lendo[posicao].paginas_lendo = stoi(paginas_lendo_s);
        lendo[posicao].ano = stoi(ano_s);
        lendo[posicao].idioma = idioma;
        lendo[posicao].editora = editora;
        lendo[posicao].nota = stoi(nota_s);
        posicao++;
    
    }

    for (int i = 0; i < tamanho; i++){

        cout << lendo[i].isbn_13 << endl;
        cout << lendo[i].isbn_10 << endl;
        cout << lendo[i].nome_lendo << endl;
        cout << lendo[i].paginas_lendo << endl;
        cout << lendo[i].ano << endl;
        cout << lendo[i].idioma << endl;        
        cout << lendo[i].editora << endl;
        cout << lendo[i].nota << endl;

    }
}
/*
void excluir_registro()
{
}
void buscar_lendo()
{
}
void editar_leitura()
{
}

int mostrar_registro()
{
    string linha;
    cout << "Abrindo o arquivo para leitura" << endl;
    ifstream arquivo ("arquivo.csv"); // abre o arquivo para leitura
    if (!arquivo){
        cout << "O arquivo nao pode ser aberto!" << endl;
    return -1;
    }
    while (!arquivo.eof()){
        getline(arquivo, linha);
    cout << linha << endl;
    }
    arquivo.close();
    return 0;
}

void exportar_txt()
{
}
void excluir_registro()
{
}
*/

void menu()
{
    int selecao;
    cout << "1) Incluir Registro" << endl;
    cout << "2) Buscar lendo" << endl;
    cout << "3) Editar Leitura" << endl;
    cout << "4) Mostrar Registro" << endl;
    cout << "5) Exportar para .txt" << endl;
    cout << "6) Excluir este arquivo" << endl;
    cin >> selecao;
    incluir_registro();
}

int main()
{
    //criar_arquivo();
    menu();
    return 0;
}