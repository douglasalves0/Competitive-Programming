#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll const IMPOSSIBLE = LLONG_MAX;

int main(){

    ll n, W;
    cin >> n >> W;        

    ll w[n], v[n], maxv = 0;
    for(int i=0;i<n;i++){
        cin >> w[i] >> v[i];
        maxv += v[i];
    }
    
    ll f[n][maxv+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<=maxv;j++){
            if(i==0){
                f[0][j] = j==0?0:(v[0]==j?w[0]:IMPOSSIBLE);
                continue;
            }
            ll minimum = IMPOSSIBLE;
            if(j-v[i] >= 0 && f[i-1][j-v[i]] != IMPOSSIBLE) minimum = f[i-1][j-v[i]] + w[i];
            minimum = min(minimum, f[i-1][j]);
            f[i][j] = minimum;
        }
    }
        
    for(int i=maxv;i>=0;i--){
        if(f[n-1][i] <= W){
            cout << i << endl;
            break;
        }
    }
        
    return 0;
}