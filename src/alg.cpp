// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++)
    for (int j = i + 1; j < len; j++)
      if (arr[i] + arr[j] == value) {
        count = count + 1;
      }
  return count;
}
int countPairs2(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++)
    for (int j = len - 1; j > i; j--)
      if (arr[i] + arr[j] == value) {
        count = count + 1;
      }
  return count;
}
int binser(int* arr, int leftposit, int rightposit, int x) {
  int l = leftposit, r = rightposit;
  int middleposit = 0;
  while (l <= r) {
    middleposit = (l + r) / 2;
    if (arr[middleposit] == x)
      return binser(arr, leftposit, middleposit - 1, x) +
             binser(arr, middleposit + 1, rightposit, x) + 1;
    if (x < arr[middleposit])
      r = middleposit - 1;
    else
      l = middleposit + 1;
  }
  return 0;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    count += binser(&arr[i + 1], 0, len - i, value - arr[i]);
  }
  return count;
}
