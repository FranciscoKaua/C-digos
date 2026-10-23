Biblioteca de Grafos em C

1. Descrição do projeto

Este projeto consiste no desenvolvimento de uma biblioteca em linguagem C para manipulação de grafos não direcionados.

A biblioteca permite carregar grafos a partir de arquivos de texto, armazenar suas informações utilizando diferentes representações e executar a Busca em Largura (BFS — Breadth-First Search).

O projeto também permite analisar características dos grafos e comparar o uso de memória e o desempenho das diferentes representações.

2. Objetivos

- Implementar uma biblioteca reutilizável para manipulação de grafos.
- Representar grafos por matriz de adjacência e lista de adjacência.
- Ler grafos a partir de arquivos de texto.
- Calcular o número de vértices e arestas.
- Calcular os graus mínimo, máximo e médio dos vértices.
- Implementar a Busca em Largura (BFS).
- Identificar o pai e o nível de cada vértice durante a BFS.
- Gerar arquivos com os resultados das execuções.
- Comparar o consumo de memória e o tempo de execução das representações.

3. Tecnologias utilizadas

- Linguagem: C
- Compilador: GCC
- Bibliotecas: bibliotecas padrão da linguagem C.
- Sistema de compilação: Makefile

4. Estrutura do projeto

TrabalhoGrafos/
include/
    -Matriz.h
    -Lista.h
    -bfs.h
src/
    - Matriz.c
    -Lista.c
    - bfs.c
    -main.c
dados/
    -grafo_1.txt
resultados/
Makefile
README.md

Descrição dos arquivos

- "grafo_matriz.h": declara as estruturas e funções da representação por matriz de adjacência.
- "grafo_lista.h": declara as estruturas e funções da representação por lista de adjacência.
- "bfs.h": declara as funções relacionadas à Busca em Largura.
- "grafo_matriz.c": implementa as operações da matriz de adjacência.
- "grafo_lista.c": implementa as operações da lista de adjacência.
- "bfs.c": implementa a Busca em Largura para as representações utilizadas.
- "main.c": contém o programa principal e o menu de execução.
- "Makefile": automatiza a compilação do projeto.
- "dados/": armazena os arquivos de entrada dos grafos.
- "resultados/": armazena os arquivos gerados pelo programa.

5. Representações dos grafos

5.1. Matriz de adjacência

A matriz de adjacência utiliza uma matriz bidimensional para representar as conexões entre os vértices.

Uma posição da matriz indica se existe uma aresta entre dois vértices.

Complexidade de espaço: O(V²).

Vantagem: verificar se existe uma aresta entre dois vértices é uma operação rápida.

Desvantagem: o consumo de memória pode ser muito elevado em grafos com muitos vértices.

5.2. Lista de adjacência

A lista de adjacência armazena, para cada vértice, os vértices diretamente conectados a ele.

Complexidade de espaço: O(V + E).

Vantagem: geralmente consome menos memória em grafos esparsos, nos quais existem relativamente poucas arestas.

Desvantagem: verificar a existência de uma aresta pode exigir percorrer a lista de um vértice.

Onde:

- V representa o número de vértices.
- E representa o número de arestas.

6. Formato do arquivo de entrada

O arquivo de entrada deve ser um arquivo de texto contendo o número de vértices na primeira linha e as arestas nas linhas seguintes.

Exemplo:

10
1 2
1 3
2 4
2 5
3 6
3 7
4 8
5 8
6 9
7 10
8 9
9 10

7. Funcionalidades

7.1. Leitura do grafo

O programa lê o arquivo de entrada e constrói o grafo utilizando a representação selecionada.

7.2. Informações do grafo

O programa calcula e apresenta:

- Número de vértices.
- Número de arestas.
- Grau mínimo.
- Grau máximo.
- Grau médio.

O grau médio é calculado pela fórmula:

Grau médio = 2 × número de arestas / número de vértices

7.3. Busca em Largura (BFS)

A Busca em Largura percorre o grafo a partir de um vértice inicial.

Durante a execução, o programa registra:

- Vértice: identificador do vértice visitado.
- Pai: vértice pelo qual ele foi descoberto na busca.
- Nível: distância, em número de arestas, entre o vértice inicial e o vértice visitado.

O vértice inicial possui nível 0 e não possui pai.

Quando um vértice não é alcançável a partir do vértice inicial, seu pai e seu nível permanecem como -1 na implementação apresentada.

A complexidade da BFS é O(V²) na implementação com matriz de adjacência e O(V + E) na implementação com lista de adjacência, considerando as operações usuais dessas estruturas.

8. Como compilar

É necessário ter o compilador GCC e o utilitário Make instalados.

No terminal, entre na pasta principal do projeto e execute:

make

Se a compilação for concluída corretamente, será gerado o executável "programa".

Para remover os arquivos gerados durante a compilação, execute:

make clean

9. Como executar

Na pasta principal do projeto, execute:

./programa

No Windows, dependendo do ambiente utilizado, o comando poderá ser:

programa.exe

Siga as opções apresentadas no menu para escolher a representação do grafo e informar o vértice inicial da BFS.

O arquivo de entrada utilizado pelo programa está definido no código como:

dados/grafo.txt

Portanto, coloque o arquivo que deseja testar nesse local ou altere o caminho no código para corresponder ao arquivo desejado.

10. Arquivos de resultados

Os resultados são gravados no diretório "resultados/".

12. Limitações

- A biblioteca foi desenvolvida para grafos não direcionados.
- A representação por matriz de adjacência pode consumir muita memória em grafos grandes.
- O desempenho depende do tamanho e da densidade do grafo, da representação escolhida e do ambiente de execução.
- A BFS encontra as menores distâncias em número de arestas em grafos não ponderados.
- Vértices que não podem ser alcançados a partir da origem não possuem uma distância válida até ela.
