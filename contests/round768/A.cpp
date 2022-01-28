#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++){
            cin >> b[i];
        }

        int p = -1;
        int maxi = INT_MIN;
        bool isata = true;

        for(int i=0;i<n;i++){
            if(a[i] > maxi){
                maxi = a[i];
                p = i;
                isata = true;
            }
            if(b[i] > maxi){
                maxi = b[i];
                p = i;
                isata = false;
            }
        }

        if(!isata){
            swap(a[p],b[p]);
        }

        int ans = a[p];
        maxi = INT_MIN;

        for(int i=0;i<n;i++){
            if(i!= p && a[i] < b[i]){
                swap(a[i],b[i]);
            }
            maxi = max(b[i],maxi);
        }

        cout << ans * maxi << endl;

    }

    return 0;
}