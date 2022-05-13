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

    int t;
    cin >> t;

    int numbercase = 1;

    while(t--){

        int n, q;
        cin >> n >> q;

        int a[n+1], BIT[n+1];
        memset(BIT, 0, sizeof(BIT));
        for(int i=1;i<=n;i++){
            cin >> a[i];
            build(BIT, a[i], i, n);
        }

        cout << "Case " << numbercase++ << ":\n";
        while(q--){
            int type;
            cin >> type;
            if(type == 1){
                int idx;
                cin >> idx;
                cout << a[idx+1] << endl;
                build(BIT, -a[idx+1], idx+1, n);
                a[idx+1] = 0;
            }else if(type == 2){
                int idx, v;
                cin >> idx >> v;
                build(BIT, v, idx+1, n);
                a[idx+1] += v;
            }else{
                int l, r;
                cin >> l >> r;
                cout << query(BIT, r+1) - query(BIT, l) << endl;
            }
        }

    }

    return 0;
}