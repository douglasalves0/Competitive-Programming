#include <bits/stdc++.h>
using namespace std;

int liga(int mask,int i){
    return (mask | (1 << i));
}

int taligado(int mask,int i){
    return (mask & (1 << i));
}

int desliga(int mask,int i){
    int inv = ~(1 << i);
    return (mask & inv);
}

int main(){

    int t;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;

        int bits = 0;
        int x = n;
        while(x!=1){
            x/=2;
            bits++;
        }

        int maskk = n-1;

        if(k == n-1){
            if(n == 4){
                cout << -1 << endl;
                continue;
            }
            cout << "1 3\n" << n-2 << " " << n-1 << "\n0 " << n-4 << endl;
            for(int i=0;i<n/2;i++){
                if(i==1 || i==3 || i==n-2 || i==n-1 || i==0 || i==n-4){
                    continue;
                }
                int invi = 0;
                for(int j=0;j<bits;j++){
                    if(taligado(i,j)){
                        invi = desliga(invi,j);
                    }else{
                        invi = liga(invi,j);
                    }
                }
                cout << i << " " << invi << endl;
            }
            continue;
        }

        cout << k << " " << maskk << endl;
        
        int invk = 0;
        for(int i=0;i<bits;i++){
            if(taligado(k,i)){
                invk = desliga(invk,i);
            }else{
                invk = liga(invk,i);
            }
        }
        
        if(k!=0){
            cout << 0 << " " << invk << endl;
        }

        for(int i=0;i<n/2;i++){
            if(i==k || i==maskk || i==0 || i==invk){
                continue;
            }
            int invi = 0;
            for(int j=0;j<bits;j++){
                if(taligado(i,j)){
                    invi = desliga(invi,j);
                }else{
                    invi = liga(invi,j);
                }
            }
            cout << i << " " << invi << endl;
        }

    }

    return 0;
}