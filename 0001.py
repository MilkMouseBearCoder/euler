def addFactors(factor, maxvalue):
	number = 0;
	total = 0;

	while number < maxvalue:
		print number
		if number % factor == 0:
				total+=number
		number+=1
	print total
	return total

print addFactors(3, 1000) + addFactors(5, 1000) - addFactors(15, 1000)

# now that I know python a little better
print reduce(lambda a, b: a + b, (x for x in range(1, 1000) if x % 3 == 0 or x % 5 == 0))
