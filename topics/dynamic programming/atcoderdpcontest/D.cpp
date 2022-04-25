#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ll n, W;
    cin >> n >> W;

    ll w[n], v[n];
    for(int i=0;i<n;i++){
        cin >> w[i] >> v[i];
    }

    ll f[n][W+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            if(i==0){
                f[0][j] = j>=w[0]?v[0]:0;
                continue;
            }
            ll maximum = f[i-1][j];
            if(j>=w[i]) maximum = max(f[i-1][j-w[i]] + v[i], maximum);
            f[i][j] = maximum;
        }
    }

    cout << f[n-1][W] << endl;

    return 0;
}