sum, diff = map(int, input().split())
a = (sum+diff) // 2
b = sum - a
if (sum+diff)%2 != 0 or a < 0 or b < 0 :
    print(-1)
elif a > b :
    print(a, b)
else :
    print(b, a)