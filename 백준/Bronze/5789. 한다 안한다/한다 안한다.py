n = int(input())

for _ in range (n) :
	str = input()
	for i in range (0, (int)(len(str) /2)) :
		if (str[i] == str[len(str)-1-i]) : result = True	
		else : result = False
	if result : print("Do-it")
	else : print("Do-it-Not")

