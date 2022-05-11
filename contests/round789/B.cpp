#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string s;
        cin >> s;

        pii f[n][2];

        f[0][0] = {s[0]=='0'?0:1,1};
        f[0][1] = {s[0]=='0'?1:0,1};
        
        for(int i=1;i<n;i++){
            for(int j=0;j<2;j++){
                int change = s[i]-'0'==j?0:1;
                pii continua = f[i-1][j];
                pii quebra = f[i-1][1-j];
                pii r1 = {continua.first + change, continua.second};
                pii r2 = {i%2==0?quebra.first + change:INT_MAX, quebra.second + 1};
                f[i][j] = min(r1, r2);
            }
        }

        pii resposta = min(f[n-1][0], f[n-1][1]);
        cout << resposta.first << " " << resposta.second << endl;

    }

    return 0;
}
