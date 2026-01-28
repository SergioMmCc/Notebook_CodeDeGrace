n = int(input())
if n == 2:
    print("1")
else:
    print((2**(n-3) * n)%1000000007)