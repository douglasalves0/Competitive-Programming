#include <bits/stdc++.h>
using namespace std;

//solution to "the equation", available at:
//https://codeforces.com/problemsets/acmsguru/problem/99999/106

typedef long long ll;

ll extendedGcd(ll a, ll b, ll * x, ll * y){
	if(b == 0){
		*x = 1;
		*y = 0;
		return a;
	}
	ll x1, y1;
	ll g = extendedGcd(b, a%b, &x1, &y1);
	*x = y1;
	*y = x1-y1*(a/b);
	return g;
}

ll findGreaterOrEqualThan(ll n, ll pack, ll min){
	ll l = -1000000000;
	ll r = 1000000000;
	while(r - l > 0){
		ll k = floor((r+l)/2.0);
		if(n + pack * k >= min){
			r = k;
		}else{
			l = k+1;
		}
	}
	return l;
}

ll findLowerOrEqualThan(ll n, ll pack, ll max){
	ll l = -1000000000;
	ll r = 1000000000;
	while(r - l > 0){
		ll k = ceil((r+l)/2.0);
		if(n + pack * k <= max){
			l = k;
		}else{
			r = k-1;
		}
	}
	return l;
}

ll MAX(ll a, ll b){return (a>b?a:b);}
ll MIN(ll a, ll b){return (a<b?a:b);}

int main(){

	ll a, b, c;
	cin >> a >> b >> c;

	ll xmin, xmax;
	cin >> xmin >> xmax;

	ll ymin, ymax;
	cin >> ymin >> ymax;

	if(a == 0 && b == 0){
		if(c==0) cout << (xmax-xmin+1)*(ymax-ymin+1) << endl;
		else cout << "0\n";
		return 0;
	}

	ll x, y;
	ll g = extendedGcd(a, b, &x, &y);	

	if(g < 0){
		g = -g;
		x = -x;
		y = -y;
	}

	if((-c)%g != 0){
		cout << 0 << endl;
		return 0;
	}

	x = x * ((-c)/g);
	y = y * ((-c)/g);

	ll kxmin, kxmax, kymin, kymax;

	kxmin = findGreaterOrEqualThan(x, abs(b/g), xmin);
	kxmax = findLowerOrEqualThan(x, abs(b/g), xmax);

	kymin = findGreaterOrEqualThan(y, abs(a/g), ymin);
	kymax = findLowerOrEqualThan(y, abs(a/g), ymax);

	if((a <= 0 && b <= 0) || (a >= 0 && b >= 0)){
		kymin = -kymin;
		kymax = -kymax;
		swap(kymin, kymax);
	}

	ll answer = MAX(0, MIN(kxmax, kymax) - MAX(kxmin, kymin) + 1);	

	cout << answer << endl;

	return 0;
}