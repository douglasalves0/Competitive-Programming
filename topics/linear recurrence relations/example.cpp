#include <bits/stdc++.h>
using namespace std;


// This sample algorithm shows how to find the n-th fibonacci number
// in O(log n) complexity analysis
//
// Some useful links:
// https://codeforces.com/blog/entry/67776
// https://codeforces.com/blog/entry/80195


// Get references to matrices A(n rows m columns) and B(x rows y columns), and changes given matrix C
void matrixMultiplier(int * a, int n, int m, int * b, int x, int y, int * c){
    if(a==0 || b==0 || x==0 || y==0) return;
    if(m != x) return;
    int d[n*y];
    for(int i=0;i<n;i++){
        for(int j=0;j<y;j++){
            int sum = 0;
            for(int k=0;k<m;k++){
                sum += a[i*m+k] * b[j*m+k];
            }
            d[i*y+j] = sum;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<y;j++){
            c[i*y+j] = d[i*y+j];
        }
    }
    return;
}

void fastExpo(int * a, int n, int m, int power, int * copy){
    if(power == 1) return;
    fastExpo(a,n,m,power/2,copy);
    matrixMultiplier(a,n,m,a,n,m,a);
    if(power%2!=0) matrixMultiplier(a,n,m,copy,n,m,a);
}

int main(){

    int fibonacciIndex;
    cin >> fibonacciIndex;

    if(fibonacciIndex < 2){
        cout << "Answer: " << fibonacciIndex << endl;
        return 0;
    }

    int *answer;
    int transformation[] = {1,1,1,0};
    int copyOfTransformation[] = {1,1,1,0};
    int initial[] = {1, 0};

    fastExpo(transformation, 2, 2, fibonacciIndex - 1, copyOfTransformation);
    matrixMultiplier(transformation, 2, 2, initial, 2, 1, answer);

    cout << "Answer: " << answer[0] << endl;

    return 0;
}