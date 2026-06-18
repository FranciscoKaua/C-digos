Descrição do Projeto:

Este trabalho tem como objetivo demonstrar a utilização das estruturas de dados Pilha e Fila através de aplicações práticas implementadas na linguagem C.

As duas aplicações:

Pilha de Livros:
Simula uma pilha de livros onde o último livro inserido é o primeiro a ser removido.

Operações:
- Empilhar livro
- Desempilhar livro
- Imprimir pilha de livros

Vantagens:
- Implementação simples
- Inserção e remoção rápidas
- Baixo consumo de memória

Desvantagens:
- Permite acesso apenas ao topo da pilha
- Não possibilita acesso direto aos elementos
- Pode ocorrer estouro da pilha

Compilação:
gcc Pilha.c main.c -o pilha

Fila de Supermercado:
Simula uma fila de clientes em um supermercado, onde o primeiro cliente a entrar é o primeiro a ser atendido.

Operações implementadas:
- Inserir cliente na fila
- Atender cliente
- Imprimir fila de clientes

Vantagens:
- Atendimento por ordem de chegada
- Fácil implementação
- Inserção e remoção eficientes

Desvantagens:
- Elementos no final da fila podem esperar muito tempo
- Não permite acesso direto a elementos no meio
- Pode atingir rapidamente sua capacidade máxima

Compilação:
gcc Fila.c main.c -o fila

Estrutura do Projeto:
Trabalho-II
    pilha/
        -pilha.h
        -pilha.c
        -main.c
    fila/
        -fila.h
        -fila.c
        -main.c
    README.md
