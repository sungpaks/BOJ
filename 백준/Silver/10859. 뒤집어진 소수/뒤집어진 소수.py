n = int(input())

def reverse(n) :
    if(n == 0 or n == 1 or n == 2 or n == 5 or n == 8) : return n;
    elif (n == 6) : return 9;
    elif (n == 9) : return 6;
    else : return -1;

def isPrime(n) :
    if (n == 2) : return True;
    if (n <= 1 or n%2 == 0) : return False;
    i = 3;
    while (i*i <= n) :
        if (n % i == 0) : return False;
        i += 2
    return True;
def getReversedNumber(n) :
    result = 0;
    while(n > 0) :
        result *= 10;
        if (reverse(n%10) < 0) : return -1;
        result += reverse(n%10);
        n = n // 10;
    return result

reversed = getReversedNumber(n)
if (isPrime(n) and isPrime(reversed)) : print("yes")
else : print("no")
