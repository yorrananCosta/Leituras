#include <iostream>
#include <fstream>

using namespace std;

typedef struct
{
    string nome_livro;
    int isbn_13;
    int isbn_10;
    int paginas_livro;
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
void incluir_registro()
{
    ifstream arquivo;
    arquivo.open ("arquivo.csv", ofstream::ate);
    if (!arquivo)
    {
        //criar_arquivo();
    }
    else
    {
        cout << "Arquivo aberto!" << endl;
    }

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
*/
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
/*
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
    cout << "2) Buscar Livro" << endl;
    cout << "3) Editar Leitura" << endl;
    cout << "4) Mostrar Registro" << endl;
    cout << "5) Exportar para .txt" << endl;
    cout << "6) Excluir este arquivo" << endl;
    cin >> selecao;
    switch(selecao)
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
            mostrar_registro();
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
    //criar_arquivo();
    menu();
    return 0;
}