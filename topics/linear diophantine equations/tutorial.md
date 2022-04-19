_"It always seems to be impossible_

_until it's done"_

# Linear diofantine equations

## What they are?

Linear diophantine equations are equation that are write in the form:

ax + by = c

Such that, **a**, **b** and **c** are known, and we want to find integers **x** and **y** to make the equation true.

This type of equation can appear in a lot of problems, imagine that you want to go to the market of your city, and you need to buy some chocolates and candies(possibly zero), but you are aiming to spend exactly **c** coins, and you know that each chocolate cost **a** coins, and each candy costs **b** coins, so, how many units of each you need to spend your **c** coins?

Let's put numbers into this, for now, imagine that each chocolate costs a = 5 coins and each candy costs b = 10 coins, and we want to spend c = 20 coins, now, try to find some numbers of chocolates **x** and candies **y** to make us spend our 20 coins.

One possible solution can be x = 2, and y = 1, because if we buy 2 chocolates we will spend 5+5 = 10 coins and if we buy one candy we will spend 10 coins. Observe that here our equation will be:

chocolateCost * chocolatesBought + candyCost * candiesbought = spentCoins

And some solutions to our above example could be:

5 * 4 + 10 * 0 = 20

5 * 2 + 10 * 1 = 20

5 * 0 + 10 * 2 = 20

## How to (algorithmically) find some solution?

Let gcd(a,b) = g (_gcd stands to greatest common divisor_), and observe that ax + by can be written as:

ax + by = g(ix + jy)

where i = a/g and j = b/g

So, for all **x** and **y**, ax + by will always be a multiple of gcd(a, b), and since gcd(a, b) is the greatest common divisor, ax + by = c, will have solution only if **c** is a multiple of gcd(a, b).
