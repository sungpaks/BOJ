n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

cnt = 0
for i in range(n) :
    if (A[i] <= B[i]) : 
        cnt+=1
print(cnt)