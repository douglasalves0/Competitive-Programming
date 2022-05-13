#include <bits/stdc++.h>
using namespace std;

int BIT[1010][1010];
int grid[1010][1010];

void build(int v, int y, int x){
    for(int i=y;i<=1010;i=(i|(i-1))+1){
        for(int j=x;j<=1010;j=(j|(j-1))+1){
            BIT[i][j] += v;
        }
    }
}

int query(int y, int x){
    int answer = 0;
    for(int i=y;i>0;i=i&(i-1)){
        for(int j=x;j>0;j=j&(j-1)){
            answer += BIT[i][j];
        }
    }
    return answer;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    int casenumber = 1;

    while(t--){

        memset(BIT, 0, sizeof(BIT));
        memset(grid, 0, sizeof(grid));

        int q;
        cin >> q;

        cout << "Case " << casenumber++ << ":\n";
        while(q--){

            int type;
            cin >> type;

            if(!type){
                int x, y; 
                cin >> x >> y; 
                x++; y++;
                if(!grid[y][x]){
                    build(1, y, x);
                    grid[y][x]++;
                }
            }else{
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                x1++; y1++; x2++; y2++;
                int q1 = +query(y2, x2);
                int q2 = -query(y2, x1-1);
                int q3 = -query(y1-1, x2);
                int q4 = +query(y1-1, x1-1);
                cout << q1 + q2 + q3 + q4 << endl;
            }

        }

    }

    return 0;
}