Biblioteca de Grafos Ponderados — Dijkstra

Projeto desenvolvido para a disciplina de Estrutura de Dados, com o objetivo de implementar e analisar algoritmos para encontrar caminhos mínimos em grafos ponderados.

A implementação utiliza a linguagem C e trabalha com grafos não direcionados, representados por listas de adjacência.

Objetivos

- Implementar uma biblioteca para grafos ponderados.
- Representar grafos utilizando listas de adjacência.
- Implementar o algoritmo de Dijkstra para encontrar distâncias e caminhos mínimos.
- Comparar duas estratégias de seleção do vértice com menor distância estimada.
- Realizar testes e benchmarks com diferentes grafos.
- Analisar o desempenho dos algoritmos em grafos de diferentes tamanhos.

Funcionalidades

- Leitura de grafos ponderados a partir de arquivos.
- Representação por listas de adjacência.
- Armazenamento de pesos reais ("double").
- Cálculo das distâncias mínimas a partir de um vértice de origem.
- Reconstrução dos caminhos mínimos.
- Implementação de Dijkstra utilizando vetor.
- Implementação de Dijkstra utilizando heap mínimo.
- Verificação de pesos negativos.
- Benchmark para comparar o tempo de execução dos algoritmos.

Algoritmos implementados

Dijkstra com vetor

Nesta implementação, o algoritmo utiliza um vetor para armazenar as distâncias estimadas dos vértices.

A cada etapa, percorre os vértices para encontrar aquele que possui a menor distância estimada e ainda não foi processado.

Complexidade aproximada:

"O(V² + E)"

Essa implementação pode apresentar desempenho limitado em grafos muito grandes.

Dijkstra com heap mínimo

Nesta implementação, é utilizado um heap mínimo para selecionar o vértice com menor distância estimada.

O heap permite realizar essa seleção de maneira mais eficiente, sendo adequado para grafos esparsos de grande tamanho.

Complexidade aproximada:

"O((V + E) log E)"

A implementação utiliza inserções de novas estimativas no heap e descarta entradas antigas quando elas não correspondem à distância atual do vértice.


Tecnologias utilizadas

- Linguagem C
- GCC
- Listas de adjacência
- Heap mínimo
- Biblioteca padrão do C

Compilação

Para compilar o programa utilizando GCC:

gcc -O2 main_pesado.c Pesado.c -o programa

A opção "-O2" ativa otimizações do compilador, podendo melhorar o desempenho durante a execução dos algoritmos.

Execução

A execução depende das opções configuradas no arquivo "main_pesado.c".

O programa permite realizar consultas de caminhos mínimos e executar benchmarks dos algoritmos.

Antes de executar, verifique se o caminho do arquivo de entrada está correto.

Exemplo de caminho utilizado no projeto:

../dados/grafo_W_1.txt

Ajuste o caminho conforme a localização dos arquivos no seu ambiente.

Benchmark

O benchmark compara o desempenho das duas implementações de Dijkstra.

Para cada grafo, são selecionados "k" vértices de origem. O algoritmo é executado a partir de cada origem e o tempo total é medido.

O tempo médio é calculado por:

tempo_medio = tempo_total / k

Os resultados são apresentados em segundos.

O benchmark permite observar a diferença de desempenho entre a implementação com vetor e a implementação com heap mínimo.

Estudos de caso

O projeto contempla os seguintes estudos:

Grafos ponderados

Para cada grafo, são calculadas as distâncias e os caminhos mínimos a partir do vértice 10 para os vértices:

- 20
- 30
- 40
- 50
- 60

Comparação de desempenho

São comparados os tempos de execução das versões de Dijkstra com vetor e heap mínimo.

Rede de colaboração

O projeto também contempla uma análise de caminhos mínimos em uma rede de colaboração entre pesquisadores.

A identificação dos pesquisadores é realizada por meio de um arquivo que relaciona os IDs dos vértices aos nomes.

Limitações

- O algoritmo de Dijkstra não funciona corretamente com pesos negativos.
- O desempenho depende do tamanho e da estrutura do grafo.
- A implementação com vetor pode apresentar tempo de execução muito elevado em grafos grandes.
- O consumo de memória depende da quantidade de vértices e arestas.
- A execução de benchmarks em grafos muito grandes pode exigir um ambiente com maior capacidade de processamento e memória.

Resultados

Os resultados dos testes e benchmarks são apresentados no relatório do trabalho.

Os tempos de execução podem variar conforme o hardware, o sistema operacional, as opções de compilação e o tamanho dos grafos utilizados.

