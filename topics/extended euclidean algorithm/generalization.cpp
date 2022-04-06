#include <bits/stdc++.h>
using namespace std;

//
// Given an array a with n numbers
// find some solution of the array c that satisfy the equation below
//
// a1.c1 + a2.c2 + ... + an-1.cn-1 + an.cn = gcd(a1, a2, ..., an-1, an)
//

int extendedGcd(int a, int b, int * x, int * y){
    if(b == 0){
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int g = extendedGcd(b, a%b, &x1, &y1);
    *x = y1;
    *y = x1-y1*(a/b);
    return g;
}

int main(){

    int n;
    cin >> n;
 
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];  
    }

    int x[n-1], y[n-1];   
    
    int current = a[n-1];
    for(int i=n-2;i>=0;i--){
        int x1, y1;
        current = extendedGcd(a[i], current, &x1, &y1);
        x[i] = x1;
        y[i] = y1;
    }
    
    int c[n], gcd = current;
    current = 1;
    for(int i=0;i<n;i++){
        if(i == n-1){
            c[i] = current;
            break;
        }
        c[i] = x[i] * current;
        current *= y[i];
    }

    cout << "\nGCD: " << gcd << "\nSOLUTION: ";

    for(int i=0;i<n;i++){
        cout << a[i] << "." << c[i];
        if(i != n-1) cout << " + ";  
    }
    cout << " = " << gcd << endl;

    return 0;
}
