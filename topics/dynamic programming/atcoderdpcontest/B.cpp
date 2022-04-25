#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    int h[n];
    for(int i=0;i<n;i++){
        cin >> h[i];
    }

    int f[n];
    
    f[0] = 0;

    for(int i=1;i<n;i++){
        int minimum = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j < 0) break;
            minimum = min(minimum, f[i-j] + abs(h[i]-h[i-j]));
        }
        f[i] = minimum;
    }

    cout << f[n-1] << endl;

    return 0;
}