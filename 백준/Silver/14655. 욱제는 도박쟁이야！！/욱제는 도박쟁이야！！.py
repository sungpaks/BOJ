n = int(input())

firstRoundSum = 0
secondRoundSum = 0
firstRound = list(map(int, input().split()))
secondRound = list(map(int, input().split()))
for i in range(n) :
	firstRoundSum += abs(firstRound[i])
for i in range(n) :
	secondRoundSum += -abs(secondRound[i])

print(firstRoundSum - secondRoundSum)