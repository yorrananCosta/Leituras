#include <iostream>
#include <fstream>
#define LIMITE 1000

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

int criar_arquivo()
{
    ofstream arquivo ("arquivo.csv", ios::app);
    if (!arquivo)
    {
        cout << "ERRO na criacao do arquivo" << endl;
        return -1;
    }
    arquivo.close();  
}

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
    string linha;
    string isbn13;
    string isbn10;
    string nome_livro;
    string paginas;
    string ano_publicacacao;
    string idioma;
    string autor;
    string nome_editora;
    string nota;
    ofstream arquivo ("arquivo.csv", ios::app | ios::out);
    if(!arquivo)
    {
        cout << "falha ao abrir o arquivo!" << endl;
    }
    cout << "Digite o ISBN 13: " << endl;
    cin >> isbn13;
    cout << "Digite o ISBN 10: " << endl;
    cin >> isbn10;
    cout << "Digite o nome do livro: " << endl;
    getline(cin, nome_livro);
    cout << "Digite o numero de paginas do livro: " << endl;
    cin >> paginas;
    cout << "Digite o ano de publicacao: " << endl; 
    cin >> ano_publicacacao;
    cout << "Digite o idioma (PT = portugues, EN = ingles, ES = espanhol): " << endl;
    cin >> idioma;
    cout << "Digite o nome do autor: "<< endl;
    getline(cin, autor);
    cout << "Digite o nome da editora: " << endl;
    getline(cin, nome_editora);
    cout << "Digite sua nota de 0 a 10: " << endl;
    cin >> nota;
    arquivo << isbn13 << ',' << isbn10 << ',' << nome_livro << ',' << paginas << ',' << ano_publicacacao << ','
    << idioma << ',' << autor << ',' << nome_editora << ',' << nota << endl;
    arquivo.close();
}

int mostrar_registro()
{
    string linha;
    ifstream arquivo ("arquivo.csv");
    if (!arquivo){
        cout << "O arquivo nao pode ser aberto!" << endl;
    return -1;
    }
    cout << "ISBN 13    ISBN 10    Nome    Paginas   Ano    Idioma    Editora     Nota " << endl;
    while (!arquivo.eof()){
        getline(arquivo, linha, ',');
    cout << linha << "   ";
    }
    arquivo.close();
    return 0;
}

void menu()
{
    int selecao;
    cout << "1) Incluir Registro" << endl;
    cout << "2) Buscar Leitura" << endl;
    cout << "3) Editar Leitura" << endl;
    cout << "4) Mostrar Registro" << endl;
    cout << "5) Exportar para .txt" << endl;
    cout << "6) Excluir este arquivo" << endl;
    cin >> selecao;
    switch (selecao)
    {
    case 1:
        incluir_registro();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        mostrar_registro();
        break;
    case 5:
        break;
    case 6:
        break;
    default:
        break;
    }
}

int main()
{
    criar_arquivo();
    menu();
    return 0;
}