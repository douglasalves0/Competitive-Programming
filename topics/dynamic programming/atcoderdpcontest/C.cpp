#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n], b[n], c[n];
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    int f[n][3];
    
    f[0][0] = max(b[0], c[0]);
    f[0][1] = max(a[0], c[0]);
    f[0][2] = max(a[0], b[0]);

    for(int i=1;i<n;i++){
        for(int blocked=0;blocked<3;blocked++){
            int r1 = 0, r2 = 0, r3 = 0;
            if(blocked!=0) r1 = f[i-1][0] + a[i];
            if(blocked!=1) r2 = f[i-1][1] + b[i];
            if(blocked!=2) r3 = f[i-1][2] + c[i];
            r2 = max(r1, r2);
            r3 = max(r2, r3);
            f[i][blocked] = r3;
        }
    }

    cout << max(f[n-1][0], f[n-1][1]) << endl;

    return 0;
}