#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ll t;
    cin >> t;

    while(t--){

        ll n;
        cin >> n;
        
        ll cnt[n+1][n+1];//first number, second index
        for(ll i=1;i<=n;i++){
            cnt[i][0] = 0;
        }

        ll a[n+1];
        for(ll i=1;i<=n;i++){
            cin >> a[i];
            for(ll j=1;j<=n;j++){
                cnt[j][i] = cnt[j][i-1];
                if(j == a[i]) cnt[j][i]++;
            }
        }

        ll ans = 0;

        for(ll i=1;i<=n-3;i++){
            ll at = 1 * (cnt[a[i+1]][n] - cnt[a[i+1]][i+2]);
            for(ll j=i+2;j<=n-1;j++){
                if(a[i] == a[j]){
                    ans += at;
                }
                if(j!=n-1){
                    
                    ll novo = a[j];
                    
                    ll xa = cnt[novo][j-1] - cnt[novo][i];
                    ll xb = cnt[novo][n] - cnt[novo][j];

                    at -= xa * xb;
                    
                    ll ya = cnt[novo][j] - cnt[novo][i];
                    ll yb = cnt[novo][n] - cnt[novo][j+1];
                    
                    at += ya*yb;

                    ll antigo = a[j+1];

                    if(antigo != novo){

                        xa = cnt[antigo][j-1] - cnt[antigo][i];
                        xb = cnt[antigo][n] - cnt[antigo][j];
                        
                        at -= xa * xb;
                        
                        ya = cnt[antigo][j] - cnt[antigo][i];
                        yb = cnt[antigo][n] - cnt[antigo][j+1];
                        
                        at += ya*yb;

                    }

                }
            }
        }

        cout << ans << endl;

    }

    return 0;
}