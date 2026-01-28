import math

def main():
    n = int(input())
    read = input()
    a = read.split()
    a = list(map(int, a))
    
    cur = []
    nex = []
    
    for i in range (n):
        cur.append(int(math.log2(a[i])))
         
    # print(cur)
    # l = len(cur)
    active = []
    for i in range (len(cur)):
        active.append(1)
    while len(cur) > 1:
        # print(f"L -> {len(cur)}")
        for i in range (len(cur)):
            active[i] = 1
            # if i < l - 1:
            #     print(i)
            #     nex.append(i)
            if i > 0 and cur[i] == cur[i-1] and active[i-1] == 1:
                # print(f"i -> {i}, cur[i] -> {cur[i]}")
                nex.append(cur[i] + 1)
                active[i] = 0
            elif ((i < len(cur) - 1 and cur[i] != cur[i+1]) or i == len(cur) - 1) and ((i > 0 and cur[i] > cur[i-1]) or (i < len(cur) - 1 and cur[i] > cur[i+1])):
                # print(f"i -> {i}, cur[i] -> {cur[i]}")
                nex.append(cur[i])
        
        cur.clear()
        for i in range(len(nex)):
            cur.append(nex[i])
        # l = len(cur)
        nex.clear()
        
    print(2 ** cur[0])
            
main()