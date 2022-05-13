#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int BIT[N];

void add(int v, int i){
    for(;i<=N;i=(i|(i-1))+1){
        BIT[i] += v;
    } 
}

int query(int i){
    int answer = 0;
    for(;i>0;i=i&(i-1)) answer += BIT[i]; 
    return answer;
}

int main(){

    int n;
    cin >> n;

    int a[n+1];
    for(int i=1;i<=n;i++){
        cin >> a[i];
        add(a[i],i);
    }
    
    cout << "1-indexed fenwick tree 1d\nTREE = [ ";
    for(int i=1;i<=n;i++){
        cout << BIT[i] << " ";
    }
    cout << "]\n";

    return 0;
}