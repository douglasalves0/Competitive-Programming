# [UVA] - 12775 - Gift Dilemma

## Problem description

You all know Dr. Sheldon Cooper. Everything Sheldon gets, he must give back the same. He doesn’t
want to be in someone’s debt.

Another friend of Sheldon, Penny has given him a very precious gift for his birthday. What penny
didn’t know, now Sheldon is going over his head to find out some gifts that will exactly match the price
of Penny’s gift. So my first task was to find out the price of the gift. With my super powerful sixth
sense I found out that the price was P .

Now comes the hardest part. Sheldon needs to buy a gift which will cost exactly P . He went
to the nearby shop for this. It is a crazy shop. Because it sells only three types of things: Rubik’s
cubes, mouth organs and chocolates. The prices of them are A, B, C accordingly. Now Sheldon faces
a dilemma. What to buy and how many to buy? Because it turns out he can buy things costing P in
various ways. For example if, A = 202, B = 203, C = 200 and P = 606, then are two different way
to buy gifts costing exactly P . The first way is buying no Rubik’s cubes, two mouth organs and one
chocolate. The second way is buying three Rubik’s cubes, no mouth organs and no chocolates.

Now Sheldon is asking for your help (because I am retired from contests). Given A, B, C and P ,
you need to find out in how many ways he can buy gifts costing exactly P .

## Solution

To simple began the solution, its good to observe that we want to find the coefficients c1,c2 and c3 with some constraints that solve this equation:

`a.c1 + b.c2 + c.c3 = p`

```
c1 ≥ 0, c1 ∈ Z
c2 ≥ 0, c2 ∈ Z
c3 ≥ 0, c3 ∈ Z
```

All the coefficients should be integers because we can't give fractions of gifts and should be greater or equal than 0 because we can't give a negative number of gifts.

This type of equation is a generalization of <a href="https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity">Bezout's Lemma</a> for three numbers that can be solved using the <a href="https://cp-algorithms.com/algebra/extended-euclid-algorithm.html">extended euclidean algorithm</a>.

To generalize that let's begin with the observation that:

`gcd(a, b, c) = gcd(gcd(a, b), c)`

By Bezout's Lemma:

`gcd(a, b) = ax + by`

So:

`gcd(gcd(a, b), c) = gcd(a, b)x + cy`

And, since we can write `gcd(a, b)` as `ax' + by'`, we have that:

`gcd(gcd(a, b), c) = (ax' + by')x + cy`

And equivalently:

`gcd(a, b, c) = a(x'x) + b(y'x) + cy`

Also observe that `a(x'x) + b(y'x) + cy` ever will be a multiple of `gcd(a, b, c)`, since `a(x'x) + b(y'x) + cy` can be written as: 

`gcd(a, b, c)(i(x'x) + j(y'x) + k(y))`

Where:

```
i = a/gcd(a,b,c)
j = b/gcd(a,b,c)
k = c/gcd(a,b,c)
```

So, we can say that if p is not a multiple of gcd(a, b, c), the answer will be 0.

Consequently, our task at this problem will be to find all combinations of such x, y, x' and y' to make `a(x'x) + b(y'x) + cy` be equal to p with the following constraints:

```
x'x ≥ 0, x'x ∈ Z
y'x ≥ 0, y'x ∈ Z
y ≥ 0, y ∈ Z
```