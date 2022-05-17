#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1000010;

ll BIT[N];

void update(ll x, ll v){
    for(ll i=x;i<N;i=(i|(i-1))+1){
        BIT[i] += v;
    }
}

ll query(ll x){
    ll answer = 0;
    for(ll i=x;i>0;i=i&(i-1)){
        answer += BIT[i];
    }
    return answer;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, c;
    cin >> n >> m >> c;
    
    update(1, c);
    update(n+1, -c);

    while(m--){

        char type;
        cin >> type;

        if(type == 'Q'){
            ll p;
            cin >> p;
            cout << query(p) << '\n';
        }else{
            ll u, v, k;
            cin >> u >> v >> k;
            update(u, k);
            update(v+1, -k);
        }

    }

    return 0;
}
