t = int(input())

fibonacci = [1,1]
for i in range(2, 10001) :
	fibonacci.append(fibonacci[i-1]+fibonacci[i-2])

for i in range (t) :
	p, q = map(int, input().split())
	print("Case #%d: %d" %(i+1, fibonacci[p-1]%q))
