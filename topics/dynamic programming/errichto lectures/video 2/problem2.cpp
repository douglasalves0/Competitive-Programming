#include <bits/stdc++.h>
using namespace std;

// given an array a with positive different integers the values of coins
// answer what is the minimum amount of coins you need to get money v

#define IMPOSSIBLE INT_MAX

int main(){

    int n, v;
    cin >> n >> v;

    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int f[v+1];
    f[0] = 0;
    for(int i=1;i<=v;i++){
        int minimum = IMPOSSIBLE;
        for(int j=0;j<n;j++){
            if(i - a[j] < 0) continue;
            if(f[i - a[j]] == IMPOSSIBLE) continue;
            minimum = min(minimum, f[i - a[j]] + 1);
        }
        f[i] = minimum;
    }

    cout << f[v] << endl;

    return 0;
}