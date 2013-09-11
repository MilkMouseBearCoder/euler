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
            if x > top:
                break
            abundant.append(x)

    return abundant

def abundant_numbers_sum(top):
    abundant = abundant_numbers(top)
    abundant_sum = []
    total = 0

    pairs = [pair[0] + pair[1] for pair in itertools.product(abundant, abundant) if pair[0] + pair[1] < top]

    print len(pairs)

    # Find all the integers that cannot be written
    for x in range(top):
        if x not in pairs:
            total += x

    return total
    

print abundant_numbers_sum(28123)
