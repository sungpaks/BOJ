n = int(input())
level = list(map(int, input().split()))
for i in range (n) :
    if (level[i] == 300) : print(1)
    elif (level[i] >= 275) : print(2)
    elif (level[i] >= 250) : print(3)
    else : print(4)