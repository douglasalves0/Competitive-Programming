#include <bits/stdc++.h>
using namespace std;

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

int main(){

	int t, teste = 1;
	cin >> t;

	while(t--){

		ll a, b, c, p;
		cin >> a >> b >> c >> p;

		ll x[2], y[2];
		
		ll g  = extendedGcd(a, b, &x[1], &y[1]);
		ll g2 = extendedGcd(g, c, &x[0], &y[0]);

		ll times = p/g2;
		
		x[0] *= times;
		y[0] *= times;

		ll pack = g/g2;
		ll pack2 = c/g2;

		if(y[0] < 0){
			ll mult = (((-y[0])-1)/pack)+1;
			y[0] = y[0] + pack  * mult; 
			x[0] = x[0] - pack2 * mult;
		}else{
			ll mult = y[0]/pack;
			y[0] = y[0] - pack  * mult;
			x[0] = x[0] + pack2 * mult;
		}

		ll cnt = 0;
		ll packa = b/g;
		ll packb = a/g;

		while(1){
			
			if(x[0] < 0) break;

			ll iniX = x[1]*x[0];
			ll iniY = y[1]*x[0];

			if(iniX < 0){
				ll mult = (((-iniX)-1)/packa) + 1;
				iniX = iniX + packa * mult;
				iniY = iniY - packb * mult;
			}else{
				ll mult = iniX/packa;
				iniX = iniX - packa * mult;
				iniY = iniY + packb * mult;
			}

			if(iniY < 0){
				y[0] = y[0] + pack;
				x[0] = x[0] - pack2;
				continue;
			}			

			ll fimX = x[1]*x[0];
			ll fimY = y[1]*x[0];

			if(fimY < 0){
				ll mult = (((-fimY)-1)/packb) + 1;
				fimY = fimY + packb * mult;
				fimX = fimX - packa * mult;
			}else{
				ll mult = fimY/packb;
				fimY = fimY - packb * mult;
				fimX = fimX + packa * mult;
			}

			cnt += ((fimX - iniX) / packa) + 1;

			y[0] = y[0] + pack;
			x[0] = x[0] - pack2;
		
		}

		cout << "Case " << teste++ << ": " << cnt << endl;

	}

	return 0;
}