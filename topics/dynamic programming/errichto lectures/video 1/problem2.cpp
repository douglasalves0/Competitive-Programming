#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    int f[n+1][k+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j < 1) f[i][j] = i==0?1:0;
            else if (i < 2){
                if(i == 1) f[i][j] = j==1?1:0;
                else f[i][j] = 0;
            }else{
                f[i][j] = f[i-1][j-1] + f[i-2][j-1];
            }
        }
    }

    cout << f[n][k] << endl;

    return 0;
}