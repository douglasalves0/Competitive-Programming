#include <bits/stdc++.h>
using namespace std;

vector <int> graph[100010];
bool found[100010];
int dp[100010];

int f(int v){
    found[v] = true;
    for(int u: graph[v]){
        int childValue = found[u]?dp[u]+1:f(u)+1;
        dp[v] = max(dp[v], childValue);
    }
    return dp[v];
}

int main(){

    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    int answer = 0;
    for(int i=1;i<=n;i++){
        answer = max(answer, f(i));
    }
    cout << answer << endl;

    return 0;
}