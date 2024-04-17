t = int(input())
for _ in range(t) :
    n = int(input())
    d = n % 100
    if (n+1)%d == 0 : 
        print("Good")
    else :
        print("Bye")