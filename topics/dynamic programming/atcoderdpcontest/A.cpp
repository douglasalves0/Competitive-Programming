#include <bits/stdc++.h>
using namespace std;

// A - frog 1
// https://atcoder.jp/contests/dp/tasks/dp_a

int main(){

    int n;
    cin >> n;

    int a[n];   
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int f[n];

    f[0] = 0;
    f[1] = abs(a[0]-a[1]);

    for(int i=2;i<n;i++){
        int a1 = f[i-1]+abs(a[i-1]-a[i]);
        int a2 = f[i-2]+abs(a[i-2]-a[i]);
        f[i] = min(a1, a2);
    }

    cout << f[n-1] << endl;

    return 0;
}