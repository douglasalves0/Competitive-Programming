#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ll n;
    cin >> n;

    ll a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }    

    ll ans = LLONG_MAX;
    for(int i=0;i<n;i++){
        ll previous = 0;
        ll sum = 0;
        for(int j=i-1;j>=0;j--){
            ll k = (previous/a[j])-1;
            sum += abs(k);
            previous = a[j]*k;
        }
        previous = 0;
        for(int j=i+1;j<n;j++){
            ll k = (previous/a[j])+1;
            sum += abs(k);
            previous = a[j]*k;
        }
        ans = min(ans, sum);
    }

    cout << ans << endl;

    return 0;
}