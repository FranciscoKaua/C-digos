#include "../include/BancoDados.hpp"
#include <iostream>

using namespace std;

int callbackLivros(
    void* data,
    int argc,
    char** argv,
    char** colName
){
    for(int i = 0; i < argc; i++){
        cout << colName[i]
             << ": "
             << (argv[i] ? argv[i] : "NULL")
             << endl;
    }

    cout << "-------------------" << endl;

    return 0;
}

int callbackUsuarios(void* data, int argc, char** argv, char** col){

    cout << "Matricula: " << argv[0] << endl;
    cout << "Nome: " << argv[1] << endl;
    cout << "CPF: " << argv[2] << endl;
    cout << "-----------------\n";

    return 0;
}

BancoDados::BancoDados(){

    if(sqlite3_open("biblioteca.db", &db) != SQLITE_OK){
        cout << "Erro ao abrir banco\n";
    }
    else{
        cout << "Banco aberto\n";
    }
}

BancoDados::~BancoDados(){
    sqlite3_close(db);
}

void BancoDados::criarTabelas(){
    const char* sqlLivros =
    "CREATE TABLE IF NOT EXISTS livros("
    "isbn TEXT PRIMARY KEY,"
    "titulo TEXT,"
    "autor TEXT,"
    "disponivel INTEGER);";

    const char* sqlUsuarios =
    "CREATE TABLE IF NOT EXISTS usuarios("
    "matricula INTEGER PRIMARY KEY,"
    "nome TEXT,"
    "cpf TEXT);";

    const char* sqlEmprestimos =
    "CREATE TABLE IF NOT EXISTS emprestimos("
    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
    "matricula INTEGER,"
    "isbn TEXT,"
    "dataEmprestimo TEXT,"
    "dataDevolucao TEXT,"
    "ativo INTEGER);";

    sqlite3_exec(db, sqlLivros, nullptr, nullptr, nullptr);
    sqlite3_exec(db, sqlUsuarios, nullptr, nullptr, nullptr);
    sqlite3_exec(db, sqlEmprestimos, nullptr, nullptr, nullptr);
}

void BancoDados::salvarLivro(const Livro& livro){

    string sql =
    "INSERT INTO livros VALUES('"
    + livro.getIsbn() + "','"
    + livro.getTitulo() + "','"
    + livro.getAutor() + "',"
    + to_string(livro.getDisponivel())
    + ");";

    char* mensagemErro = nullptr;

    if(sqlite3_exec(
        db,
        sql.c_str(),
        nullptr,
        nullptr,
        &mensagemErro
    ) != SQLITE_OK){

        cout << "Erro: "
             << mensagemErro
             << endl;

        sqlite3_free(mensagemErro);
    }
    else{
        cout << "Livro salvo no banco.\n";
    }
}

void BancoDados::salvarUsuario(const Usuario& u){

    string sql =
    "INSERT INTO usuarios VALUES("
    + to_string(u.getMatricula()) + ",'"
    + u.getNome() + "','"
    + u.getCpf()
    + "');";

    sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
}

void BancoDados::salvarEmprestimo(int matricula, string isbn, string dataEmp, string dataDev){

    string sql =
    "INSERT INTO emprestimos VALUES(NULL,"
    + to_string(matricula) + ",'"
    + isbn + "','"
    + dataEmp + "','"
    + dataDev + "',1);";

    sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
}

void BancoDados::devolverLivro(const string& isbn){

    string sqlEmprestimo =
    "UPDATE emprestimos SET ativo = 0 WHERE isbn = '" + isbn + "';";

    string sqlLivro =
    "UPDATE livros SET disponivel = 1 WHERE isbn = '" + isbn + "';";

    sqlite3_exec(db, sqlEmprestimo.c_str(), nullptr, nullptr, nullptr);
    sqlite3_exec(db, sqlLivro.c_str(), nullptr, nullptr, nullptr);

    cout << "Livro devolvido no banco.\n";
}

void BancoDados::listarLivrosBanco(){

    const char* sql =
        "SELECT * FROM livros;";

    char* mensagemErro = nullptr;

    if(sqlite3_exec(
        db,
        sql,
        callbackLivros,
        nullptr,
        &mensagemErro
    ) != SQLITE_OK){

        cout << "Erro: "
             << mensagemErro
             << endl;

        sqlite3_free(mensagemErro);
    }
}
void BancoDados::listarUsuariosBanco(){

    sqlite3_exec(
        db,
        "SELECT * FROM usuarios;",
        callbackUsuarios,
        nullptr,
        nullptr
    );
}
void BancoDados::apagarLivro(const string& isbn){

    string sql =
    "DELETE FROM livros WHERE isbn = '" + isbn + "';";

    char* erro = nullptr;

    if(sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &erro) != SQLITE_OK){
        cout << "Erro ao apagar livro: " << erro << endl;
        sqlite3_free(erro);
    }else{
        cout << "Livro removido com sucesso.\n";
    }
}
void BancoDados::apagarUsuario(int matricula){

    string sql =
    "DELETE FROM usuarios WHERE matricula = " + to_string(matricula) + ";";

    char* erro = nullptr;

    if(sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &erro) != SQLITE_OK){
        cout << "Erro ao apagar usuario: " << erro << endl;
        sqlite3_free(erro);
    }else{
        cout << "Usuario removido com sucesso.\n";
    }
}
