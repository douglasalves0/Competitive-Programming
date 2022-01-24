#include <bits/stdc++.h>
using namespace std;

vector < pair<int,int> > grafo[1000010];
int dis[1000010];

int main(){

    for(int i=0;i<1000010;i++){
        dis[i] = INT_MAX;
    }

    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int a, b, d;
        cin >> a >> b >> d;
        grafo[a].push_back({b,d});
        grafo[b].push_back({a,d});
    }

    dis[1] = 0;
    set< pair<int,int> > q;
    q.insert({0, 1});

    while(!q.empty()){
        int v = q.begin()->second;
        q.erase({dis[v], v});
        for(int i=0;i<(int)grafo[v].size();i++){
            int u = grafo[v][i].first;
            int d = grafo[v][i].second;
            if(dis[v] + d < dis[u]){
                q.erase({dis[u], u});
                q.insert({dis[v] + d, u});
                dis[u] = dis[v] + d;
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout << "DE 1 ATÉ " << i << " HÁ CUSTO DE " << dis[i] << endl; 
    }

    return 0;
}