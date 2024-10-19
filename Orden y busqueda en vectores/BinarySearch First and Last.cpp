int binarySearchFirstOccurrence(vector<int>& A, int i, int j, int k) {
    int result, result2;
    result = binarySearch(A, i, j, k);
    if (result >= 0) {
        result2 = binarySearch(A, i, result - 1, k);
        while (result2 >= 0) {
            result = result2;
            result2 = binarySearch(A, i, result - 1, k);
        }
    }
    return result;
}

int binarySearchLastOccurrence(vector<int>& A, int i, int j, int k) {
    int result, result2;
    result = binarySearch(A, i, j, k);
    if (result >= 0) {
        result2 = binarySearch(A, result + 1, j, k);
        while (result2 >= 0) {
            result = result2;
            result2 = binarySearch(A, result + 1, j, k);
        }
    }
    return result;
}
