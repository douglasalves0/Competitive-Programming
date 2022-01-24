#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector< pair<int,int> > adj[n+1];

        for(int i=0;i<n-1;i++){
            int a,b;
            cin >> a >> b;
            adj[b].push_back({a,i+1});
            adj[a].push_back({b,i+1});
        }

        queue<int> q;
        int used[n+1];
        int label[n];

        memset(used,-1,sizeof used);
        int s = -1;

        for(int i=1;i<=n;i++){
            if((int)adj[i].size()==1){
                s = i;
                break;
            }
        }

        used[s] = 5;
        q.push(s);
        bool da = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            int sz = (int)adj[v].size();
            if(sz > 2){
                da = false;
                break;
            }
            for (int i=0;i<sz;i++) {
                pair<int,int> u = adj[v][i];
                if (used[u.first] == -1){
                    q.push(u.first);
                    if(used[v] == 5){
                        used[u.first] = 2;
                        label[u.second] = 5;
                    }else{
                        used[u.first] = 5;
                        label[u.second] = 2;
                    }
                }
            }
        }

        if(!da){
            cout << -1 << endl;
            continue;
        }

        for(int i=1;i<n;i++){
            cout << label[i] << " ";
        }
        cout << endl;

    }

    return 0;
}