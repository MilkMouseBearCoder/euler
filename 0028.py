from math import floor, sqrt

def quadratic(a, b, n):
   return (n**2) + (a*n) + b

def is_prime(n):
    if (n == 1): return False
    if (n < 4): return True
    if ((n % 2) == 0): return False
    if (n < 9): return True
    if ((n % 3) == 0): return False

    r = floor(sqrt(n))
    f = 5

    while f <= r :
        if ((n % f) == 0): return False;
        if ((n % (f + 2)) == 0): return False;
        f += 6;

    return True;

a1 = 0
b1 = 0
primes = 0

for a in range(1000):
    for b in range(1000):
        n = 0 
        prime_count = 0
        while is_prime(quadratic(a, b, n)):
            n += 1
            prime_count = n
        if prime_count > primes:
            a1 = a
            b1 = b
            primes = prime_count

print a1, b1, primes
