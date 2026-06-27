Sistema de Gerenciamento de Biblioteca

Descrição

Projeto desenvolvido em C++ utilizando Programação Orientada a Objetos e banco de dados SQLite para gerenciamento de uma biblioteca.

Tecnologias utilizadas

- C++17
- SQLite3
- Makefile
- Programação Orientada a Objetos (POO)

Funcionalidades implementadas

CRUD de Bibliotecário

- (sim) Cadastrar bibliotecário
- (sim) Atualizar bibliotecário
- (sim) Remover bibliotecário
- (sim) Listar bibliotecários

CRUD de Usuário

- (sim) Cadastrar usuário
- (sim) Atualizar usuário
- (sim) Remover usuário
- (sim) Listar usuários

CRUD de Livro

- (sim) Cadastrar livro
- (sim) Atualizar livro
- (sim) Remover livro
- (sim) Listar livros

CRUD de Empréstimo

- (sim) Registrar empréstimo
- (sim) Atualizar empréstimo
- (sim) Remover empréstimo
- (sim) Listar empréstimos

Consultas

- (sim) Exibir quantos livros um determinado usuário pediu emprestado.
- (sim) Exibir quantos livros existem de um determinado autor.
- (Não, está com defeito)Exibir quantos livros estão disponíveis.
- (sim) Exibir quais livros possuem entrega atrasada.

Estrutura do projeto

include/
    BancoDados.hpp
    Bibliotecario.hpp
    Emprestimo.hpp
    Livro.hpp
    Pessoa.hpp
    Usuario.hpp

src/
    BancoDados.cpp
    Bibliotecario.cpp
    Emprestimo.cpp
    Livro.cpp
    Pessoa.cpp
    Usuario.cpp
    main.cpp

Makefile
biblioteca.db
README.md

Como executar

Compilar:

make

Executar:

./biblioteca

Limpar arquivos objeto:

make clean