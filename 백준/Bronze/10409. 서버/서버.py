n, T = map(int, input().split())
task = list(map(int, input().split()))

i = 0
while i < n and T - task[i] >= 0 :
	T -= task[i]
	i += 1

print(i)