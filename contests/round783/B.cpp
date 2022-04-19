#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort(a,a+n);

        bool ok = true;
        int part = (m-a[n-1])-(a[n-1]+2)+1;
        for(int i=n-2;i>=0;i--){
            if(part <= 0){
                ok = 0;
                break;
            }
            part = part - 1 - a[i];
        }

        if(ok){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }

    }   

    return 0;
}