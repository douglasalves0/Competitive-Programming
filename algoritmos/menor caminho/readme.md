<h1 align="center">Algoritmo de Dijkstra</h1>
<h4 align="center">(Criado por Edsger Dijkstra em 1956 e publicado em 1959)</h3>

## Objetivo
Encontrar o menor caminho de um vértice do grafo a todos os outros que são possíveis de serem alcançados a partir dele;

## Complexidade
Considerando N o número de vértices e M o número de arestas do grafo, a complexidade sem otimizações é O(N² + M), entretanto, é possível amenizar o número de operações com o uso de algumas estruturas de dados como a <strong>Fibonnaci heap</strong>, sendo possível alcançar O(N log N + M log N);

## Algoritmo
 1. Crie um array d[N] que guarde todas as distâncias da raiz a N e inicialize como <strong>INFINITO</strong>;
 2. Deixe s ser a raiz do grafo, e faça d[s] = 0;
 3. Crie um array de processados[N] e inicialize com todos os valores como <strong>false</strong>;
 4. Repita N vezes as seguintes operações;
    1. Encontre o vértice com menor d[V] que ainda não foi processado;
    2. Marque este vértice como processado;
    3. Passe por toda a adjacência de V procurando os vértices ainda não processados;
    4. Caso encontre um vértice U vizinho de V que ainda não foi processado, (deixe l ser o comprimento da aresta que liga U a V) veja se d[V] + l é menor que d[u], caso seja, troque d[u] por d[V] + l;
