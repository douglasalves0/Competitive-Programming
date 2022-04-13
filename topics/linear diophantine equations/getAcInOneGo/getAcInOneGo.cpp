#include <bits/stdc++.h>
using namespace std;

//link to problem: https://www.codechef.com/problems/COPR16G

typedef long long ll;

ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    ll g = gcd(b, a%b);
    return g;
}
int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        ll a, b;
        scanf("%Ld %Ld", &a, &b);

        ll g = gcd(a, b);

        if(g != 1){
            cout << "-1\n";
            continue;
        }

        printf("%Ld\n",a*b-a-b+1);

    }

    return 0;
}