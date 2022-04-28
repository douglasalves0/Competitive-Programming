#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll const mod = 1000000007;

int main(){

    ll n, m;
    cin >> n >> m;

    string s[n];
    for(int i=0;i<n;i++) cin >> s[i];

    ll f[n][m];
    f[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0) continue;
            if(s[i][j]=='#'){
                f[i][j] = 0;
                continue;
            }
            ll s1 = i-1>=0?f[i-1][j]:0;
            ll s2 = j-1>=0?f[i][j-1]:0;
            f[i][j] = (s1+s2)%mod;
        }
    }

    cout << f[n-1][m-1] << endl;

    return 0;
}