#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        int cnt = 0;
        int base = a[n-1];
        while(1){
            int p = -1;
            for(int i=n-1;i>=0;i--){
                if(a[i] != base){
                    p = i;
                    break;
                }
            }
            if(p==-1){
                break;
            }
            cnt++;
            int repete = (n-1)-(p+1)+1;
            for(int i=0;i<repete;i++){
                if(p-i < 0) break;
                a[p-i] = base;
            }
        }
        cout << cnt << endl;

    }

    return 0;
}