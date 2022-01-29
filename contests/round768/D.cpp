#include <bits/stdc++.h>
using namespace std;

int BIT[200010];
int n, k;

void update(int i){
    while(i <= n){
        BIT[i]++;
        i += i&(-i);
    }
}

int sum(int i){
    int ans = 0;
    while(i > 0){
        ans += BIT[i];
        i -= i&(-i);
    }
    return ans;
}

int main(){

    int t;
    cin >> t;

    while(t--){

        cin >> n >> k;

        for(int i=1;i<=n;i++){
            BIT[i] = 0;
        }

        int a[n+1];
        for(int i=1;i<=n;i++){
            cin >> a[i];
            update(a[i]);
        }

        int ansx = 0, ansy = 1000000;
        for(int x=1;x<=n;x++){
            int ini = x;
            int fim = n;
            while(fim - ini > 0){
                int mid = (fim+ini)/2;
                int s = (sum(mid) - sum(x-1)) - (sum(n) - sum(mid)) - (sum(x-1));
                if(s >= k){
                    fim = mid;
                }else{
                    ini = mid+1;
                }
            }
            int y = ini;
            int s = (sum(ini) - sum(x-1)) - (sum(n) - sum(ini)) - (sum(x-1));
            if(!(s >= k)){
                continue;
            }
            if(y-x < ansy-ansx){
                ansy = y;
                ansx = x;
            }
        }

        cout << ansx << " " << ansy << endl;

        int p = 1;
        int sum = 0;
        cout << 1 << " ";
        for(int i=1;i<=n;i++){
            if(p==k){
                break;
            }
            if(a[i] < ansx || a[i] > ansy){
                sum--;
            }else{
                sum++;
            }
            if(sum == p){
                cout << i << "\n" << i+1 << " ";
                p++;
            }
        }
        cout << n << endl;

    }

    return 0;
}