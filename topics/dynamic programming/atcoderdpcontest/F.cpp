#include <bits/stdc++.h>
using namespace std;

// dp[n][m] = lcs of substrings s[0...n] and t[0...m]

// AT SOME STATE OF DP[N][M]...
// if s[n] and t[m] are equal, so:
//     dp[n][m] = dp[n-1][m-1] + 1 --> see proof 1
// else:
//     dp[n][m] = max(dp[n-1][m], dp[m][n-1])

// <PROOF 1>
// imagine that we have the answer of dp[n][m]
// let's try to see the answer to dp[n][m-1]
// if the char at t[m] are at the answer of dp[n][m], so
// dp[n][m-1] = dp[n][m] - 1, at the worst case
// so we can say that dp[n][m-1] + 1 >= dp[n][m]
// now about dp[n-1][m-1], if s[n] are at the answer of dp[n][m], so
// s[n] makes pair with t[m]
// and we already have removed 1 from the answer, so
// dp[n-1][m-1] + 1 >= dp[n][m]

int main(){

    string s, t;
    cin >> s >> t;

    int n = s.length();
    int m = t.length();

    pair<int,int> f[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i]==t[j]){
                f[i][j] = {1 + ((i>=1 && j>=1)?f[i-1][j-1].first:0), 0};
                continue;
            }
            pair<int, int> r1 = {i>=1?f[i-1][j].first:0, 1};
            pair<int, int> r2 = {j>=1?f[i][j-1].first:0, 2};
            f[i][j] = max(r1, r2);
        }
    }

    n--;m--;
    string answer;
    while(1){
        if(n < 0 || m < 0) break;
        if(f[n][m].second == 0){
            answer.push_back(s[n]);
            n--;m--;
            continue;
        }
        if(f[n][m].second == 1){
            n--;
            continue;
        }
        if(f[n][m].second == 2){
            m--;
            continue;
        }
    }

    for(int i=answer.length()-1;i>=0;i--){
        cout << answer[i];
    }
    cout << endl;

    return 0;
}