#include <bits/stdc++.h>
using namespace std;

vector < pair<int,int> > grafo[1000010];
bool processado[1000010];
int dis[1000010];

//Esse Dijkstra funciona em O(n^2 + m), pois apesar de ser o algoritmo
//original de Edsger Dijkstra ele não usa nenhuma otimização com set ou priority queue
//para amenizar a complexidade até O(n log n + m log n)

int main(){

    for(int i=0;i<1000010;i++){
        dis[i] = INT_MAX-1;
    }

    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int a,b,d;
        cin >> a >> b >> d;
        grafo[a].push_back({b,d});
        grafo[b].push_back({a,d});
    }

    dis[1] = 0;

    for(int i=1;i<=n;i++){
        int menor = INT_MAX;
        int v = -1;
        for(int j=1;j<=n;j++){
            if(!processado[j] && dis[j] < menor){
                menor = dis[j];
                v = j;
            }
        }
        processado[v] = true;
        for(int j=0;j<(int)grafo[v].size();j++){
            int u = grafo[v][j].first;
            int d = grafo[v][j].second;
            if(dis[u] > dis[v] + d){
                dis[u] = dis[v] + d;
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout << "DE 1 ATÉ " << i << " HÁ CUSTO DE " << dis[i] << endl; 
    }

    return 0;
}