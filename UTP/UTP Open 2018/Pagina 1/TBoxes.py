def main():
    n = int(input())
    read = input()
    numbers = read.split()
    numbers = list(map(int, numbers))
    
    mina = 2e9
    maxa = 0
    
    for number in numbers:
        mina = min(mina, number)
        maxa = max(maxa, number)
        
        print(mina + maxa)
        
main()