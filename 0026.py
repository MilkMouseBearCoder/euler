import decimal

def str_index_list(s, c):
    '''Find all positions of a set of characters in a string'''
    lc = len(c)

    return [i for i in range(len(s) - lc + 1) if c == s[i:i + lc]]

def repeating_pattern(s):
    s = s[:-1]
    pattern = ''

    for n in range(len(s)):
        for l in range(n + 1, len(s)):
            chunk = s[n:l]

            if len(chunk) > (len(s) / 3):
                break

            if s.count(chunk) == len(s[n:]) / len(chunk):
                if s.count(chunk + chunk) == len(s[n:]) / len(chunk):
                   return chunk
            if s.count(chunk) == 1:
                break

    return pattern
            

decimal.getcontext().prec = 10000

s = str(decimal.Decimal(1)/6).replace('0.', '')
tr = repeating_pattern(s)

#print tr


#exit()

ld = 0
lr = ''
for d in range(2, 1000):
    s = str(decimal.Decimal(1)/d).replace('0.', '')
    tr = repeating_pattern(s)
    print d, tr
    if tr is not None and len(tr) > len(lr):
        lr = tr
        ld = d

print ld, len(lr), lr

print repeating_pattern('testtesttest')
