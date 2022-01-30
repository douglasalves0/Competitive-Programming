<h1 align="center">Algoritmo para encontrar o maior divisor comum (gcd) de dois números.</h1>
<h4 align="center">(Criado por Euclides cerca de 300 A.C.)</h3>

## Afirmação principal:
- se a >= b, então:
- gcd(a,b) = gcd(a-b,b);
	
## Provando a afirmação

- Vamos chamar de g o resultado do gcd entre a e b;
- Sendo assim, g também deve dividir a-b e b para que g também seja o gcd(a-b,b);
- Se g é o gcd de a e b, então:
- a ≡ 0 mod g;
- b ≡ 0 mod g;
- Pegando a primeira equação, vamos subtrair por b em ambos os lados;
- a - b ≡ - b mod g;
- Como vimos acima que b ≡ 0 mod g, isso também implica que -b ≡ 0 mod g, ou seja;
- a - b ≡ 0 mod g;
- logo, g também divide a-b, ou seja, gcd(a,b) = gcd(a-b,b);
