#include <stdio.h>

template <typename Type>

Type Min(Type a, Type b) {

  if (a <= b) {
    return a;
  } else {
    return b;
  }
}

int main() {

  int ia = 7, ib = -2;
  float fa = 10.5f, fb = 3.2f;
  double da = -1.25, db = -4.8;

  printf("%d,%f,%lf", Min<int>(ia, ib), Min<float>(fa, fb),
         Min<double>(da, db));

  return 0;
}