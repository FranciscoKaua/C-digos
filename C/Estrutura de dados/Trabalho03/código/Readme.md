Sistema de Cadastro de Alunos com Árvore AVL

Descrição

Este projeto implementa um sistema simples de cadastro de alunos utilizando uma Árvore AVL, um tipo de árvore binária de busca balanceada.

O sistema permite:
- Inserir alunos através da matrícula;
- Buscar alunos pela matrícula;
- Exibir todas as matrículas em ordem crescente;
- Liberar a memória utilizada ao encerrar o programa.

Arquivos
Index.h
- Define a estrutura do nó da árvore.
- Contém os protótipos das funções.

Index.c
- Implementa as operações da árvore AVL.
- Inserção.
- Busca.
- Rotações.
- Percurso em ordem.
- Liberação de memória.

main.c
- Implementa o menu principal.
- Permite interação com o usuário.

Após cada inserção ou remoção, a árvore verifica seu fator de balanceamento e realiza rotações quando necessário.

O fator de balanceamento é calculado por:
FB = altura(esquerda) - altura(direita)

Uma árvore AVL é considerada balanceada quando:
FB ∈ {-1, 0, 1}

Operações Implementadas
Inserção
Insere uma nova matrícula na árvore respeitando as regras da árvore binária de busca.

Complexidade:
O(log n)

Busca
Localiza uma matrícula específica.

Complexidade:
O(log n)

Percurso em Ordem
Exibe os elementos em ordem crescente.

Exemplo:
50 30 70 20 40

Saída:
20 30 40 50 70

Rotações Utilizadas
Rotação Simples à Direita
Aplicada quando ocorre desbalanceamento à esquerda.
Rotação Simples à Esquerda
Aplicada quando ocorre desbalanceamento à direita.
Rotação Dupla Esquerda-Direita
Primeiro uma rotação à esquerda e depois uma à direita.
Rotação Dupla Direita-Esquerda
Primeiro uma rotação à direita e depois uma à esquerda.

Exemplo de Execução
SISTEMA DE ALUNOS:
1 - Inserir aluno
2 - Buscar aluno
3 - Mostrar matriculas
0 - Sair

Opcao: 1
Matricula: 50
Aluno cadastrado!

Opcao: 1
Matricula: 30
Aluno cadastrado!

Opcao: 1
Matricula: 70
Aluno cadastrado!

Opcao: 3
Matriculas cadastradas:
30 50 70

Opcao: 2
Matricula para buscar: 70
Aluno encontrado!

Complexidade das Operações
Operação| Complexidade
Inserção| O(log n)
Busca| O(log n)
Remoção| O(log n)
Percurso| O(n)

Compilação
gcc Index.c main.c -o index

Estrutura do Projeto
projeto/
│
├── Index.h
├── Index.c
└── main.c