#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string s;
        cin >> s;

        int f[n][2];

        f[0][0] = s[0]=='0'?0:1;
        f[0][1] = s[0]=='0'?1:0;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<2;j++){
                int change = s[i]-'0'==j?0:1;
                int r1 = f[i-1][j] + change;
                int r2 = i%2==0?f[i-1][1-j] + change:INT_MAX;
                f[i][j] = min(r1, r2);
            }
        }

        cout << min(f[n-1][0], f[n-1][1]) << endl;

    }

    return 0;
}