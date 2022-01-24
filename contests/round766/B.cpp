#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        vector <int> ans;
        vector <int> mid1,mid2;

        if(n%2==0){
            mid1.push_back(n/2);
            mid1.push_back(n/2+1);
        }else{
            mid1.push_back(n/2+1);
        }

        if(m%2==0){
            mid2.push_back(m/2);
            mid2.push_back(m/2+1);
        }else{
            mid2.push_back(m/2+1);
        }
/*
        vector<vector<int>> adj;  // adjacency list representation
        int n; // number of nodes
        int s; // source vertex*/

        bool used[n+1][m+1];
        int d[n+1][m+1];

        memset(used,0,sizeof used);
        memset(d,0,sizeof d);

        queue < pair<int,int> > roots;

        for(int i=0;i<(int)mid1.size();i++){
            for(int j=0;j<(int)mid2.size();j++){
                roots.push({mid1[i],mid2[j]});
                used[mid1[i]][mid2[j]] = true;
                d[mid1[i]][mid2[j]] = 0;
                ans.push_back(0);
            }
        }

        int mx[] = {0,0,1,-1};
        int my[] = {1,-1,0,0};

        while (!roots.empty()) {
            pair<int,int> v = roots.front();
            roots.pop();
            for (int i=0;i<4;i++) {
                int iu = v.first + my[i];
                int ju = v.second + mx[i];
                if (iu > 0 && iu <= n && ju > 0 && ju <= m && !used[iu][ju]) {
                    used[iu][ju] = true;
                    roots.push({iu,ju});
                    d[iu][ju] = d[v.first][v.second] + 1;
                    ans.push_back(d[iu][ju]);
                }
            }
        }

        int dis = abs(mid1[0]-n) + abs(mid2[0]-m);

        for(int i=0;i<(int)ans.size();i++){
            cout << ans[i]+dis << " ";
        }
        cout << endl;

    }

    return 0;
}