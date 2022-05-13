#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int M = 110;
int BIT[N][M];

void add(int v, int x, int y){
    for(int i=x;i<=N;i=(i|(i-1))+1){
        for(int j=y;j<=M;j=(j|(j-1))+1){
            BIT[i][j] += v;
        }
    }
}

int query(int x,int y){
    int answer = 0;
    for(int i=x;i>0;i=i&(i-1)){ 
        for(int j=y;j>0;j=j&(j-1)){
            answer += BIT[i][j];
        }
    }
    return answer;
}

int main(){

    int n, m;
    cin >> n >> m;

    int a[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            add(a[i][j], i, j);
        }
    }

    cout << "1-indexed fenwick tree 2d\nTREE = [\n";
    for(int i=1;i<=n;i++){
        cout << "\t[ ";
        for(int j=1;j<=m;j++){        
            cout << BIT[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << "]\n";

    return 0;
}