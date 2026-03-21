n = int(input())
w1 = input()
w2 = str()
result = int()

for i in range (0, len(w1)):
    w2 += w1[i]
    
    if i < n-1:
        if (w1[i] == '(' and w1[i+1] == ')'):
            w2 += '1'
        elif (w1[i] == ')' and w1[i+1] == ')'):
            w2 += '+1' 
        elif (w1[i] == ')' and w1[i+1] == '('):
            w2 += '*'

result = eval(w2)
print(result)