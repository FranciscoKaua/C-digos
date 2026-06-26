#include "../include/BancoDados.hpp"
#include <iostream>
using namespace std;
int callbackLivros(void* data,int argc,char** argv,char** colName){
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
int callbackBibliotecario(void* data,int argc,char** argv, char** colName){
    for(int i = 0; i < argc; i++){
        cout
            << colName[i]
            << ": "
            << (argv[i] ? argv[i] : "NULL")
            << endl;
    }
    cout << endl;
    return 0;
}
int callbackEmprestimo(void* data,int argc,char** argv,char** colName){
    for(int i = 0; i < argc; i++){
        cout
            << colName[i]
            << ": "
            << (argv[i] ? argv[i] : "NULL")
            << endl;
    }
    cout << endl;
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
    
     const char* sqlBibliotecarios =
    "CREATE TABLE IF NOT EXISTS bibliotecarios("
    "codigo INTEGER PRIMARY KEY,"
    "nome TEXT,"
    "cpf TEXT);";

    sqlite3_exec(db, sqlLivros, nullptr, nullptr, nullptr);
    sqlite3_exec(db, sqlUsuarios, nullptr, nullptr, nullptr);
    sqlite3_exec(db, sqlEmprestimos, nullptr, nullptr, nullptr);
    sqlite3_exec(db, sqlBibliotecarios, nullptr, nullptr, nullptr);
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
    if(sqlite3_exec(db,sql.c_str(),nullptr,nullptr,&mensagemErro) != SQLITE_OK){
        cout << "Erro: "
             << mensagemErro
             << endl;
        sqlite3_free(mensagemErro);
    }
    else{
        cout << "Livro salvo no banco.\n";
    }
}

void BancoDados::atualizarLivro(string isbn,string titulo, string autor){
    string sql =
    "UPDATE livros SET "
    "titulo='" + titulo +
    "', autor='" + autor +
    "' WHERE isbn='" +
    isbn +
    "';";

    sqlite3_exec(db,sql.c_str(),nullptr,nullptr,nullptr);
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
void BancoDados::listarLivrosBanco(){
    const char* sql =
        "SELECT * FROM livros;";
    char* mensagemErro = nullptr;
    if(sqlite3_exec(db,sql,callbackLivros,nullptr,&mensagemErro) != SQLITE_OK){
        cout << "Erro: "
             << mensagemErro
             << endl;
        sqlite3_free(mensagemErro);
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

void BancoDados::atualizarUsuario(int matricula,string nome,string cpf){
    string sql =
    "UPDATE usuarios SET "
    "nome='" + nome +
    "', cpf='" + cpf +
    "' WHERE matricula=" +
    to_string(matricula) +
    ";";
    sqlite3_exec(db,sql.c_str(),nullptr,nullptr,nullptr);
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

void BancoDados::listarUsuariosBanco(){
    sqlite3_exec(db,"SELECT * FROM usuarios;",callbackUsuarios,nullptr,nullptr);
}


void BancoDados::salvarBibliotecario(
    const Bibliotecario& bibliotecario
){
    string sql =
    "INSERT INTO bibliotecarios VALUES(" +
    to_string(
        bibliotecario.getCodigoFuncionario()
    ) +
    ",'" +
    bibliotecario.getNome() +
    "','" +
    bibliotecario.getCpf() +
    "');";

    sqlite3_exec(db,sql.c_str(),nullptr,nullptr,nullptr);
}

void BancoDados::atualizarBibliotecario(int codigo,string nome,string cpf){
    string sql =
    "UPDATE bibliotecarios SET "
    "nome='" + nome +
    "', cpf='" + cpf +
    "' WHERE codigo=" +
    to_string(codigo) +
    ";";

    sqlite3_exec(db,sql.c_str(),nullptr,nullptr,nullptr);
}

void BancoDados::removerBibliotecario(int codigo){
    string sql =
    "DELETE FROM bibliotecarios "
    "WHERE codigo=" +
    to_string(codigo) +
    ";";
    sqlite3_exec(db,sql.c_str(),nullptr,nullptr,nullptr);
}

void BancoDados::listarBibliotecarios(){
    string sql =
    "SELECT * FROM bibliotecarios;";

    sqlite3_exec(db,sql.c_str(),callbackBibliotecario,nullptr,nullptr);
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

void BancoDados::atualizarEmprestimo(int id,string dataDevolucao){
    string sql =
    "UPDATE emprestimos SET "
    "dataDevolucao='" +
    dataDevolucao +
    "' WHERE id=" +
    to_string(id) +
    ";";
    sqlite3_exec(db,sql.c_str(),nullptr,nullptr,nullptr);
}

void BancoDados::removerEmprestimo(int id){
    string sql =
    "DELETE FROM emprestimos "
    "WHERE id=" +
    to_string(id) +
    ";";
    sqlite3_exec(db,sql.c_str(),nullptr,nullptr,nullptr);
}

void BancoDados::listarEmprestimos(){
    string sql =
    "SELECT * FROM emprestimos;";

    sqlite3_exec(db,sql.c_str(),callbackEmprestimo,nullptr,nullptr);
}



void BancoDados::contarLivrosUsuario(int matricula){
    string sql =
    "SELECT COUNT(*) "
    "FROM emprestimos "
    "WHERE matricula=" +
    to_string(matricula) +
    ";";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(),-1,&stmt,nullptr);
    if(sqlite3_step(stmt) == SQLITE_ROW){
        cout
            << "Quantidade de livros emprestados: "
            << sqlite3_column_int(stmt, 0)
            << endl;
    }
    sqlite3_finalize(stmt);
}
void BancoDados::contarLivrosAutor(string autor){
    string sql =
    "SELECT COUNT(*) "
    "FROM livros "
    "WHERE autor='" +
    autor +
    "';";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db,sql.c_str(),-1,&stmt,nullptr);
    if(sqlite3_step(stmt) == SQLITE_ROW){
        cout
            << "Quantidade de livros do autor: "
            << sqlite3_column_int(stmt, 0)
            << endl;
    }
    sqlite3_finalize(stmt);
}
void BancoDados::contarLivrosDisponiveis(){
    string sql =
    "SELECT COUNT(*) "
    "FROM livros "
    "WHERE disponivel = 1;";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db,sql.c_str(),-1,&stmt,nullptr);
    if(sqlite3_step(stmt) == SQLITE_ROW){
        cout
            << "Livros disponiveis: "
            << sqlite3_column_int(stmt, 0)
            << endl;
    }
    sqlite3_finalize(stmt);
}

void BancoDados::listarEmprestimosAtrasados(){
    string sql =
    "SELECT * "
    "FROM emprestimos "
    "WHERE ativo = 1 "
    "AND dataDevolucao < DATE('now');";

    sqlite3_exec(db,sql.c_str(),callbackEmprestimo,nullptr,nullptr);
}