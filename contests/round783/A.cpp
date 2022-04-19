#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ll t;
    cin >> t;

    while(t--){

        ll n, m;
        cin >> n >> m;

        if(m > n){
            swap(n,m);
        }

        if(m == 1){
            if(n <= 2){
                cout << n-1 << endl;
            }else{
                cout << "-1\n";
            }
            continue;
        }

        ll sobra = n-m;
        ll ans = ((sobra/2)*4+(sobra%2)) + (2*(m-1));

        cout << ans << endl;

    }

    return 0;
}