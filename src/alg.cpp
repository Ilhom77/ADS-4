/#include <cstdint>
#include "alg.h"
double pown(double value, uint16_t n) {
  double res = value;
  if (n == 0) return 1;
  if (n == 1) return value;
  res *= pown(value, n - 1);
  return res;
}
uint64_t fact(uint16_t n) {
  uint64_t res = n;
  if (n == 0) return 1;
  res *= fact(n - 1);
  return res;
}
double calcItem(double x, uint16_t n) {
  double res = 0;
  res = pown(x, n) / fact(n);
  return res;
}
double expn(double x, uint16_t count) {
  double e = 0;
  for (uint16_t j = 0; j <= count; j++) {
    e += calcItem(x, j);
  }
  return e;
}
double sinn(double x, uint16_t count) {
  double sin = 0;
  for (uint16_t j = 1; j <= count; j++) {
    sin += pown(-1, j - 1) * calcItem(x, 2 * j - 1);
  }
  return sin;
}
double cosn(double x, uint16_t count) {
  double cos = 0;
  for (uint16_t j = 1; j <= count; j++) 
    cos += pown(-1, j - 1) * calcItem(x, 2 * j - 2);
  }
  return cos;
}
