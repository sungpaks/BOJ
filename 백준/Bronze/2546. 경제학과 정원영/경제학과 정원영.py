t = int(input())

for _ in range (t) :
	input()
	n, m = map(int, input().split())
	clang = list(map(int, input().split()))
	economy = list(map(int, input().split()))
	
	result = 0
	clangSum = 0
	economySum = 0
	for i in range(n) :
		clangSum += clang[i]
	for i in range(m) :
		economySum += economy[i]
	for i in range(n) :
		if (clangSum-clang[i])/(n-1) > clangSum/n and (economySum+clang[i])/(m+1) > economySum/m :
			result += 1
	print(result)
