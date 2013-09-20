def reciprocal(d):
    decimal = []
    pattern = {}
    n = 1
    while n < d:
        n *= 10

    e = 1
    i = 0
    while(e > 0):
        e *= n

        r, e = e / d, e % d

        # Have we seen this pattern before?
        p = str(e) + '_' + str(r)

        if p in pattern:
            break;

        pattern[p] = i
        decimal.append(r)
        i += 1

    result = str(reduce(lambda a, b: 10 * a + b, decimal))

    if e > 0:
        result = result[0: pattern[p]] + "(" + result[pattern[p]:] + ")"

    return "0." + result

t_length = 0
r_length = 0
r = 0
d = 0
for n in range(2, 1000):
    r = reciprocal(n)
    if r.find("(") > -1:
        t_length = r.find(")") - r.find("(")
        if t_length > r_length:
            r_length = t_length
            d = n

print d, r_length, reciprocal(d)
