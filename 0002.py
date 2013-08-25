num1 = 1
num2 = 2
total = 0


while True:
	if num1 >= 4000000:
		break
	if num1 % 2 == 0:
		print num1 
		total+=num1

	if num2 >= 4000000:
		break
	if num2 % 2 == 0:
		print num2
		total+=num2

	num1 = num1 + num2
	num2 = num1 + num2

print total
