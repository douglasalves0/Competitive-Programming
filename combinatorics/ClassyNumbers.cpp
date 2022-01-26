#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fat[20];

ll calc(ll n){
    string maxnumber = "0000000000000000000";
    ll x = n;
    int cnt = 0;
    while(x!=0){
        maxnumber[18 - cnt++] = x%10 + '0';
        x/=10;
    }
    ll ans = 0;
    cnt = 0;
    for(int i=0;i<19;i++){
        if(maxnumber[i] == '0') continue;
        cnt++;
        int len = 18-i;
        if(cnt == 3){
            ans += maxnumber[i]-'0'-1;
            ans += len * 9;
            ans++;
            break;
        }
        ll esquerda = (maxnumber[i]-'0'-1);
        for(int nz=min(len,3-cnt);nz>=0;nz--){
            ans += esquerda * pow(9,nz) * (fat[len]/fat[len-nz]/fat[nz]);
        }
        for(int nz=0;nz<=3-cnt+1;nz++){
            if(len < nz) continue;
            ans += pow(9,nz) * (fat[len]/fat[len-nz]/fat[nz]);
        }
    }
    return ans;
}

int main(){

    fat[0] = 1;
    for(int i=1;i<=19;i++){
        fat[i] = fat[i-1] * i;
    }

    int t;
    cin >> t;

    while(t--){

        ll l, r;
        cin >> l >> r;

        cout << calc(r) - calc(l-1) << endl;

    }

    return 0;
}