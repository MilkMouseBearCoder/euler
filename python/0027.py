from math import floor, sqrt

def is_prime(n):
    n = abs(n)
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

prime_dict = {}
def is_prime_cache(n):
    if n in prime_dict:
        return prime_dict[n]

    prime_dict[n] = is_prime(n)

    return prime_dict[n]

a_max = 0
b_max = 0
c_max = 0

for a in range(-999, 1000):
    for b in range(1000):
        c, n = 0, 0 
        while is_prime_cache(n**2 + a*n + b):
            n += 1
            c += 1
        if c > c_max:
            a_max, b_max, c_max = a, b, c

print a_max, b_max, c_max, a_max * b_max
