import itertools

lexi = itertools.permutations(range(10))

count = 1
for x in lexi:
    if count == 1000000:
        print x
        break
    count += 1 

