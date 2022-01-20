#include <bits/stdc++.h>
using namespace std;

/*
 *    Criado por Douglas Alves de Sousa
 *    Programa que recebe dois números a e b e retorna gcd(a,b)
 *
 */

int gcd(int a,int b){
    if(b > a) swap(a,b);
    while(b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(){

    int a, b;
    cin >> a >> b;

    int g = gcd(a,b);

    if(g == 0){
        cout << "NÃO EXISTE\n";
    }else{
        cout << g << endl;
    }

    return 0;
}
