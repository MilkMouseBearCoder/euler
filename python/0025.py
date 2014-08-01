def fibonacci():
    a, b = 1, 1

    yield a
    while True:
        yield b

        a, b = b, a + b

count = 0
for x in fibonacci():
    count += 1
    if len(str(x)) == 1000:
        print count, x
        break
