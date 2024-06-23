long long gcd (long long A, long long B) {
    long long temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}