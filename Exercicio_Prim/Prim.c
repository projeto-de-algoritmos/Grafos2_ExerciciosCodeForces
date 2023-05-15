#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 500
#define MAX_M 124750

// Estrutura para representar uma rodovia
typedef struct {
    int u, v, c;
} Rodovia;

// Função para encontrar o vértice com a menor distância
int findMinDistance(int dist[], bool mstSet[], int N){
    int min = INT_MAX, minIndex;

    for (int v = 1; v <= N; v++){
      if (mstSet[v] == false && dist[v] < min){
        min = dist[v], minIndex = v;
      }
    }
    return minIndex;
}

// Função para calcular a soma mínima dos comprimentos das rodovias
int calculateMinimumSum(Rodovia rodovias[], int N, int M){
    // Inicialização dos vetores de distâncias, conjunto de vértices já processados e árvore geradora mínima
    int dist[MAX_N + 1];
    bool mstSet[MAX_N + 1];

    for (int i = 1; i <= N; i++){
        dist[i] = INT_MAX;
        mstSet[i] = false;
    }

    // O vértice de partida é o 1
    dist[1] = 0;

    // Loop para processar todos os vértices
    for (int count = 0; count < N - 1; count++){
        // Encontra o vértice com a menor distância ainda não processado
        int u = findMinDistance(dist, mstSet, N);

        // Marca o vértice como processado
        mstSet[u] = true;

        // Atualiza as distâncias dos vértices adjacentes ao vértice atual
        for (int i = 0; i < M; i++){
            if (rodovias[i].u == u || rodovias[i].v == u){
                int v = (rodovias[i].u == u) ? rodovias[i].v : rodovias[i].u;
                int c = rodovias[i].c;

                if (mstSet[v] == false && c < dist[v]){
                  dist[v] = c;
                }
            }
        }
    }
    // Calcula a soma mínima dos comprimentos das rodovias
    int sum = 0;
    for (int i = 1; i <= N; i++)
        sum += dist[i];

    return sum;
}

int main(){
    int N, M;
    Rodovia rodovias[MAX_M];

    // Leitura do número de cidades e rodovias
    scanf("%d %d", &N, &M);

    // Leitura das informações das rodovias
    for (int i = 0; i < M; i++)
        scanf("%d %d %d", &rodovias[i].u, &rodovias[i].v, &rodovias[i].c);

    // Cálculo da soma mínima dos comprimentos das rodovias
    int minimumSum = calculateMinimumSum(rodovias, N, M);

    // Impressão do resultado
    printf("%d\n", minimumSum);
    return 0;
}