#include <iostream>
#include <fstream>

using namespace std;

typedef struct
{
    string nome_livro;
    int isbn;
    int paginas_livro;
    string autor;
    string editora;
}
Leitura;

void criar_arquivo()
{
    string nome_arquivo;
    system("clear");
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

void incluir_registro()
{
    ifstream arquivo;
    arquivo.open ("arquivo.csv", ofstream::ate);
    if (!arquivo)
    {
        criar_arquivo();
    }
    else
    {
        cout << "Arquivo aberto!" << endl;
    }
    criar_arquivo();
}
/*
void excluir_registro()
{
}
void buscar_livro()
{
}
void editar_leitura()
{
}
void mostrar_registro()
{
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
    cout << "2) Excluir Registro" << endl;
    cout << "3) Buscar Livro" << endl;
    cout << "4) Editar Leitura" << endl;
    cout << "5) Mostrar Registro" << endl;
    cout << "6) Exportar para .txt" << endl;
    cout << "7) Excluir este arquivo" << endl;
    cin >> selecao;
    switch (selecao)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
    }
}

int main()
{
    criar_arquivo();
    menu();
    return 0;
}