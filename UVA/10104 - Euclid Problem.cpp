#include <bits/stdc++.h>
using namespace std;

//esta versão do algoritmo estendido de euclides sempre
//retorna a resposta com |X| + |Y| mínimo tal que X <= Y

int gcd(int a, int b, int * x, int * y){
	if(b == 0){
		*x = 1;
		*y = 0;
		return a;
	}
	int x1, y1;
	int g = gcd(b, a%b, &x1, &y1);
	*x = y1;
	*y = x1-y1*(a/b);
	return g;
}

int main(){

	int a, b;
	while(cin >> a >> b){
		int x, y;
		int g = gcd(a, b, &x, &y);
		cout << x << " " << y << " " << g << endl;
	}

	return 0;
}