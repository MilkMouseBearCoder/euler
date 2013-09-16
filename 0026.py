from itertools import izip, tee
import decimal

def pairwise(iterable):
    a, b = tee(iterable)
    next(b, None)
    return izip(a, b)

def str_index_list(s, c):
    lc = len(c)

    return [i for i in range(len(s) - lc + 1) if c == s[i:i + lc]]
    for i in range(len(s) - lc + 1):
        print c, s[i:i + lc]
        if c == s[i:i + lc]:
            pass#print i

    return []

def repeating_pattern(s):

    for n in range(len(s) - 1):
        for l in range(n + 1, len(s) - 1):
            chunk = s[n:l]

            indices = str_index_list(s, chunk)

            if len(indices) < 2:
                break

            T = reduce(lambda a, b: a == b and a == len(chunk), [y-x for x,y in pairwise(indices)])

            if T == True:
                print chunk
                break

decimal.getcontext().prec = 100

#for d in range(2, 6):
#    repeating_pattern(str(decimal.Decimal(1)/d))

repeating_pattern('testtesttestt')
