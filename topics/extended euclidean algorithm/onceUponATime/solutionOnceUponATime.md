To simple began the solution, its good to observe that we want to find x and y with some constraints that solve this equation :

k + ax = n+my

x ≥ 1, x ∈ Z

y ≥ 0, y ∈ Z

x must be greater or equal than 1 because when x equals to 0, the man approaches and not stretches, and x < 0 does not make sense.

y must be greater or equal than 0 because when y equals to 0, the woman already stretches, and y < 0 does not make sense.

Also observe that we can write the above equation in another way:

ax − my = n − k

And also:

ax + (−m)y = n − k

And this type of equation can be solved simply using the extend euclidean algorithm, <a href="https://cp-algorithms.com/algebra/extended-euclid-algorithm.html" target="__blank">see the link</a>.

Observe that we don't have answer if n-k is not a multiple of gcd(a,−m).

Unfortunately, sometimes x, and y could be negative, but observe that:

0 = a*((-m)/gcd(a,-m))+(-m)*(a/gcd(a,-m))

And use that to change x and y without affect the answer.
