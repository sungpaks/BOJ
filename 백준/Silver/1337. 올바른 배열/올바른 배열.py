a = []
n = int(input())
for i in range (0, n) :
    a.append(int(input()))
# a.sort();

def getMax(n, a) :
    result = 0
    for i in range (0, 5) :
        cur = 0
        for j in range (n-i, n-i+5) :
            if j in a :
                cur+=1
        if result < cur :
            result = cur
    return result


max = 0

for i in range (0, n) :
    cur = getMax(a[i], a)
    if (max < cur) :
        max = cur;


print(5-max)
