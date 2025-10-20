def main():
    while True:
        s = input()
        if s == "*":
            return

        n = int(s, 2)
        print(n % 12)

main()