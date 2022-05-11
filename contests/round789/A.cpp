#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int a[n], zeros = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            zeros += !a[i]?1:0;
        }

        if(zeros > 0){
            cout << n-zeros << endl;
            continue;
        }

        bool equal = false;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                equal = a[i]==a[j] || equal;
            }
        }

        if(equal){
            cout << n << endl;
        }else{
            cout << n+1 << endl;
        }

    }

    return 0;
}