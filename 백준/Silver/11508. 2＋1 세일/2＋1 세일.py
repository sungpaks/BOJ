n = int(input())

milk = []

result = 0
for i in range (0, n) :
    milk.append(int(input()))
    result += milk[i]
milk.sort()
free = n//3
i = n-3
while (free > 0) :
    free -= 1
    result -= milk[i]
    i -= 3
print(result)
