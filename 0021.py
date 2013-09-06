def factors(n):
    return list(set(reduce(list.__add__,
                           ([i, n//i] for i in
                            range(1, int(n**0.5) + 1) if n % i == 0))))


def amicable_numbers():
    numbers = []
    n = 10
    while n <= 10000:
        f1 = factors(n)

        n2 = reduce(lambda a, b: a + b, [x for x in f1 if x < n])

        if n != n2:
            f2 = factors(n2)

            if len(f2) > 1:
                n3 = reduce(lambda a, b: a + b, [x for x in f2 if x < n2])

                if n3 == n:
                    numbers.extend([n, n2])

        n += 1

    return set(numbers)

numbers = list(amicable_numbers())

print reduce(lambda x, y: x + y, numbers)
