import time
import itertools

def factors(n):
    return list(set(reduce(list.__add__,
                           ([i, n//i] for i in
                            range(1, int(n**0.5) + 1) if n % i == 0))))

def abundant_numbers(top):
    abundant = []

    for x in range(12, top):
        factor_list = factors(x)
        
        if reduce(lambda a, b: a + b, [i for i in factor_list if i < x]) > x:
           abundant.append(x)

    return abundant

def abundant_numbers_sum(top):
    abundant = abundant_numbers(top)
    total = 0

    pairs = [pair[0] + pair[1] for pair in itertools.product(abundant, abundant) if pair[0] + pair[1] < top]

    return sum(set(range(1, top)) - set(pairs))

start_time = time.time()

print abundant_numbers_sum(28123)

print time.time() - start_time, "seconds"
