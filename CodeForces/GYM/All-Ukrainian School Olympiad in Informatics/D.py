pot2 = []
def calcPot2():
    num = 1
    for i in range(64):
        pot2.append(num)
        num *= 2

    # for i in range(64):
    #     print(pot2[i])

def main():
    a = int(input())
    b = int(input())
    dif = a - b

    if a < b or dif % 2:
        print(-1)
        return
    
    y = b
    x = 0
    for i in range(64):
        if dif % 2 == 1:
            x += pot2[i-1]
        dif //= 2

    y += x
    print(f"{x} {y}")

calcPot2()
main()