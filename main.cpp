#include <iostream>
#include <fstream>
#include <string>
#define LIMITE 1000

using namespace std;
using std::stoi;

typedef struct
{
    string isbn_13;
    string isbn_10;
    string nome_lendo;
    string paginas_lendo;
    string ano;
    string idioma;
    string autor;
    string editora;
    string nota;
}
Leitura[LIMITE];


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

int contador_de_linhas()
{
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

void ler_registros(Leitura *livro, int tamanho)
{
    string isbn13;
    string isbn10;
    string nome_livro;
    string paginas;
    string ano_publicacacao;
    string idioma;
    string autor;
    string nome_editora;
    string nota;
    int posicao = 0;
    ifstream arquivo ("arquivo.csv", ios::in);
    if(!arquivo.is_open()) 
    {
        cout << "Erro ao abrir o arquivo" << endl;
    }

    while(arquivo.peek()!=EOF){
    
    getline(arquivo, isbn13,',');
    getline(arquivo, isbn10,',');
    getline(arquivo, nome_livro,',');
    getline(arquivo, paginas,',');
    getline(arquivo, ano_publicacacao,',');
    getline(arquivo, idioma,',');
    getline(arquivo, autor,',');
    getline(arquivo, nome_editora,',');
    getline(arquivo, nota);


    livro[posicao]->isbn_13 = isbn13;
    livro[posicao]->isbn_10 = isbn10;
    livro[posicao]->nome_lendo = nome_livro;
    livro[posicao]->paginas_lendo = paginas;
    livro[posicao]->ano = ano_publicacacao;
    livro[posicao]->idioma = idioma;
    livro[posicao]->autor = autor;
    livro[posicao]->editora = nome_editora;
    livro[posicao]->nota = nota;
    posicao++;
  
  }

}

void mostrar_registros(Leitura *livro, int tamanho)
{ 
    ifstream arquivo ("arquivo.csv", ios::in);
    if(!arquivo.is_open()) 
    {
        cout << "Erro ao abrir o arquivo" << endl;
    }
    cout << "ISBN 13    ISBN 10    Nome    Paginas   Ano    Idioma    Editora     Nota " << endl;
    for (int i = 0; i < tamanho; i++)
    {
        cout << livro[i]->isbn_13 << "  ";
        cout << livro[i]->isbn_10 << "  ";
        cout << livro[i]->nome_lendo << "  ";
        cout << livro[i]->paginas_lendo << "  ";
        cout << livro[i]->ano << "  ";
        cout << livro[i]->idioma << "  ";
        cout << livro[i]->autor << "  ";
        cout << livro[i]->editora << "  ";
        cout << livro[i]->nota << endl;
    }
}

void incluir_registro()
{
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

void menu(Leitura *livro, int tamanho)
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
        mostrar_registros(livro, tamanho);
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
    Leitura *livro;
    int tamanho = contador_de_linhas();
    livro =  new (nothrow) Leitura[tamanho];
    criar_arquivo();
    ler_registros(livro, tamanho);
    menu(livro, tamanho);
    return 0;
}