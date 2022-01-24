#include <bits/stdc++.h>
using namespace std;

bool cnt[1000010];

int gcd(int a,int b){
    if(b > a) swap(a,b);
    while(b!=0){
        int resto = a%b;
        a = b;
        b = resto;
    }
    return a;
}

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        cnt[a[i]] = 1;
    }

    int ans = 0;
    for(int g=1000000;g>=1;g--){
        if(cnt[g]) continue;
        int ini = 0;
        int c = 0;
        for(int i=g;i<=1000000;i+=g){
            if(cnt[i]){
                ini = gcd(ini,i);
                c++;
            }
        }
        if(c > 1 && ini == g){
            ans++;
            cnt[g] = 1;
        }
    }
    cout << ans << endl;

    return 0;
}