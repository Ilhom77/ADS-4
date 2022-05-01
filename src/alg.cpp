// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int ar1 = 0; ar1 < len - 1; ar1++) {
        for (int ar2 = ar1 + 1; ar2 < len; ar2++) {
            if (arr[ar1] + arr[ar2] == value) {
                count++;
            } else {
                continue;
            }
        }
    }
       return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int z = len - 1; z > i; z--) {
            if (arr[i] + arr[z] == value) {
                count += 1;
            }
        }
    }
       return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int  j = i + 1;
        int f = len;
        while (j < f) {
            int c = (j + f) / 2;
            if (arr[c] < (value - arr[i])) {
                j = c + 1;
            } else {
                f = c;
            }
        }
        while (arr[j] + arr[i] == value) {
            count++;
            j++;
        }
    }
    return count;
}
