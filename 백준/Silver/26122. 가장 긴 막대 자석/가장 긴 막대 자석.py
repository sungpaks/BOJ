k = int(input())

str = input()

def calcLength(str, k, i, front, behind) :
	result = 0
	j = 0
	while (i-j-1 >= 0 and i+j < k and str[i-j-1] == front and str[i+j] == behind) :
		result += 2
		j += 1
	return result

max = 0

for i in range(1,k):
	if (str[i] == 'N' and str[i-1] == 'S') or (str[i] == 'S' and str[i-1] == 'N') :
		cur = calcLength(str, k, i, str[i-1], str[i])
		if (max < cur) : max = cur

print (max)