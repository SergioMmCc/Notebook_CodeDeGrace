def main():
    s = input()
    d = input()
    m = input()

    d10 = int(d, 2)
    cond = True
    if len(m) < d10 or len(s) < d10:
        cond = False

    if cond:
        print("Infinite money!")

    else:
        test = False
        s10 = int(s, 2)
        m10 = int(m, 2)
        ans = 0
        while not test:
            if m10 == 0:
                test = True
                continue
            ans += 1
            m10 //= 2
            if ans % d10 == 0:
                m10 += s10
            
        ans2 = bin(ans)[2:]
        print(ans2)

main()        