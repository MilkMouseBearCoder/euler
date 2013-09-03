#! /usr/bin/python

# start at 99, since timing by 100 wll only add 2 zeros
factor = 99

result = 1
# We can skip 1, it does nothing to the result
while factor > 1:
    result *= factor

    # strip zerosw
    if result % 10 == 0:
        result /= 10

    factor -= 1

str_result = str(result)

result = 0
i = 0
while i < len(str_result):
    result += int(str_result[i])
    i += 1

print result

print reduce(lambda x, y: x + y,[int(i) for i in str(reduce(lambda x, y: x * y, range(1, 100)))])
