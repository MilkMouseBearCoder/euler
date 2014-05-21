def isSumOf5thPowers(n):
    s = str(n);

    r = 0;
    for d in list(s):
        r += int(d)**5

    if r == n:
        return True;

if __name__ == '__main__':
    total = 0
    for i in range(2, 355000):
        if isSumOf5thPowers(i):
            total += i
            print(i)

    print(total)
