#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, v;
    cin >> n >> v;

    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int f[v+1][n];

    for(int i=0;i<=v;i++){
        for(int j=0;j<n;j++){
            if(i == 0){
                f[i][j] = 1;
                continue;
            }
            f[i][j] = 0;
            if(j-1>=0) f[i][j] += f[i][j-1];
            if(i-a[j]>=0) f[i][j] += f[i-a[j]][j];
        }
    }

    cout << f[v][n-1] << endl;

    return 0;
}