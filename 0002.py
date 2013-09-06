def fibonacci(top):
    a,b = 1,2

    yield a
    while b < top:
        yield b

        a, b = b, a + b

total = 0
for n in (x for x in fibonacci(4000000) if x % 2 ==0):
    total += n

print total
