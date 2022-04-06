#include <bits/stdc++.h>
using namespace std;

//Link to problem: https://www.spoj.com/problems/CEQU/

int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	return gcd(b, a%b);
}

int main(){

	int t;
	cin >> t;

	int cnt = 1;

	while(t--){

		int a, b, c;
		cin >> a >> b >> c;

		int g = gcd(a, b);

		if(c%g != 0){
			cout << "Case " << cnt++ << ": No\n";
			continue;
		}

		cout << "Case " << cnt++ << ": Yes\n";

	}

}