#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int f[n][n];
    for(int x=1;x<=n;x++){
        for(int l=0;l<n;l++){
            int r = l + x - 1;
            int mult = l + n - r;
            if(r > n-1) continue;
            if(x == 1){
                f[l][r] = a[l]*mult;
                continue;
            }
            int r1 = f[l][r-1] + a[r] * mult;
            int r2 = f[l+1][r] + a[l] * mult;
            f[l][r] = max(r1, r2);
        }
    }

    cout << f[0][n-1] << endl;

    return 0;
}