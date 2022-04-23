#include <bits/stdc++.h>
using namespace std;

// given an array a with positive different integers, answer in how many ways its possible
// to make a number v by using only the numbers of array a

int main(){

    int n, v;
    cin >> n >> v;

    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }    

    int f[v+1];
    f[0] = 1;
    for(int i=1;i<=v;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            if(i - a[j] < 0) continue;
            sum += f[i - a[j]];
        }
        f[i] = sum;
    }

    cout << f[v] << endl;

    return 0;
}