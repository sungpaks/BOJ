n = int(input())
cars = list(map(int, input().split()))
sum = 0
for car in cars :
    if car == n :
        sum += 1
        
print (sum)