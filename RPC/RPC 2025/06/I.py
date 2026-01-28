N = int(input())
for n in range(0, N):
    s = input()
    nHyphens = s.count('-')
    f = True
    if nHyphens == 3 and s[-2] != '-':
        f = False
    if nHyphens > 3:
        f = False
    if len(s) - nHyphens != 10:
        f = False
    if s[-1] == '-' or s[0] == '-':
        f = False
    check = 0
    idx = 10
    for i in range(0, len(s)-1):
        if s[i] == '-':
            if s[i + 1] == '-':
                f = False
            continue
        if s[i] == 'X':
            f = False
            continue
        check = (check + idx * int(s[i])) % 11
        idx -= 1
    if s[-1] == '-':
        f = False
    elif s[-1] == 'X':
        check = (check + 10) % 11
    else:
        check = (check + int(s[-1])) % 11
    if check != 0:
        f = False
    if f == False:
        print("invalid")
    else:
        check2 = 0
        idx = 1
        s = "978-" + s
        for i in range(0, len(s)-1):
            if s[i] == '-':
                continue
            if idx % 2 == 1:
                check2 = (check2 + int(s[i])) % 10
            else:
                check2 = (check2 + 3 * int(s[i])) % 10
            idx += 1
        print(s[0:-1] + str((10 - check2) % 10))