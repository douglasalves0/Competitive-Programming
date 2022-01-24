#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        int r, c;
        cin >> r >> c;

        int cntlinha[n];
        int cntcoluna[m];

        memset(cntlinha, 0, sizeof cntlinha);
        memset(cntcoluna, 0, sizeof cntcoluna);

        string s[n];
        bool allwhite = true;
        for(int i=0;i<n;i++){
            cin >> s[i];
            for(int j=0;j<m;j++){
                if(s[i][j] == 'B'){
                    allwhite = false;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j] == 'B'){
                    cntlinha[i]++;
                    cntcoluna[j]++;
                }
            }
        }

        if(allwhite){
            cout << -1 << endl;
            continue;
        }

        r--;c--;

        if(s[r][c]=='B'){
            cout << 0 << endl;
            continue;
        }

        if(cntlinha[r] > 0 || cntcoluna[c] > 0){
            cout << 1 << endl;
            continue;
        }

        cout << 2 << endl;
        continue;

    }

    return 0;
}