#include <bits/stdc++.h>
using namespace std;

void build(int * BIT, int v, int x, int n){
    for(int i=x;i<=n;i=(i|(i-1))+1){
        BIT[i] += v;
    }
}

int query(int * BIT, int x){
    int answer = 0;
    for(int i=x;i>0;i=i&(i-1)){
        answer += BIT[i];
    }
    return answer;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while(1){

        int n;
        cin >> n;

        if(n==0) break;

        int a[n+1], BIT[n+1];
        memset(BIT, 0, sizeof(BIT));
        for(int i=1;i<=n;i++){
            cin >> a[i];
            build(BIT, a[i], i, n);
        }

        if(t!=1) cout << "\n";
        cout << "Case " << t++ << ":\n";

        while(1){

            string op;
            cin >> op;

            if(op == "END") break;

            int x, y;
            cin >> x >> y;

            if(op == "S"){
                build(BIT, -a[x], x, n);
                build(BIT, y, x, n);
                a[x] = y;
            }else{
                cout << query(BIT, y) - query(BIT, x-1) << endl;
            }  

        }

    }    

    return 0;
}