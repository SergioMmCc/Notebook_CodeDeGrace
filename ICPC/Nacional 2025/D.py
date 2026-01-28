import sys

binom = []

def calcBinom():
    for i in range(0, 61):
        binom.append(list())
        for j in range(0, 61):
            binom[i].append(0)
    for i in range(0, 61):
        binom[i][0] = 1
        binom[i][i] = 1

    for i in range(1, 61):
        for j in range(1, 61):
            binom[i][j] = binom[i-1][j-1] + binom[i-1][j]

def main():
    while True:
        try:
            read = input()
            numbers = read.split()
            numbers = list(map(int, numbers))
            n = numbers[0]
            k = numbers[1]

            if k == 0 and n == 0:
                return

            l = 0
            r = binom[n][k]

            read = input()
            perm = read.split()
            perm = list(map(int, perm))
            last = 1

            for i in range(0, k):
                for j in range(last, n+1):
                    # print(f"i {i}, j {j}")
                    if perm[i] == j:
                        r = l + binom[n - j][k - i - 1]
                        last = j + 1
                        break
                    else:
                        l += binom[n - j][k - i - 1]

            print(l)
        
        except EOFError:
            break

calcBinom()
main()