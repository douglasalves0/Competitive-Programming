#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    
    double a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    double f[n][n+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            if(i==0){
                if(j==0){ f[0][0] = 1 - a[0]; continue;}
                if(j==1){ f[0][1] = a[0]; continue;}
                f[0][j] = 0;
                continue;
            }
            double a1 = (i-1>=0 && j-1>=0)?f[i-1][j-1] * a[i]: 0;
            double a2 = i-1>=0?f[i-1][j] * (1-a[i]): 0;
            f[i][j] = a1 + a2;
        }
    }
            
    
    double answer = 0;
    for(int coins=(n+1)/2;coins<=n;coins++){
        answer = answer + f[n-1][coins];
    }
    cout << setprecision(10) << fixed << answer << endl;

    return 0;   
}
