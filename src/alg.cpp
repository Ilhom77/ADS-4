// Copyright 2021 NNTU-CS

@@ -1,12 +1,12 @@
// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int l, int r, int value) {
int bs(int* arr, int l, int r, int value) {
  int mid = 0;
  bool f = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (arr[mid] == value) {
      return cbinsearch(arr, l, mid - 1, value) + cbinsearch(arr, mid + 1, r, value) + 1;
      return bs(arr, l, mid - 1, value) + bs(arr, mid + 1, r, value) + 1;
    }
    if (value < arr[mid])
      r = mid - 1;
@@ -15,6 +15,7 @@ int cbinsearch(int* arr, int l, int r, int value) {
    }
  return 0;
}

int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < (len - 1); i++) {
@@ -25,6 +26,7 @@ int countPairs1(int* arr, int len, int value) {
  }
  return count;
}

int countPairs2(int* arr, int len, int value) {
  int count = 0, k = len - 1;
  while (arr[k] > value) {
@@ -39,6 +41,7 @@ int countPairs2(int* arr, int len, int value) {
  }
  return count;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0, tmp, k = len - 1;
  while (arr[k] > value) {
@@ -47,5 +50,7 @@ int countPairs3(int* arr, int len, int value) {
  }
  for (int i = 0; i < len; i++) {
    tmp = value - arr[i];
    count += cbinsearch(arr + i + 1, 0, len, tmp);
    count += bs(arr + i + 1, 0, len - i, tmp);
  }
  return count;
}
