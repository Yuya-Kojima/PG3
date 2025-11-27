#include <iostream>
using namespace std;

template <class T1, class T2> class MinClass {
public:
  auto Min(T1 a, T2 b) { return (a < b) ? a : b; }
};

int main() {

  MinClass<int, int> m1;
  MinClass<int, float> m2;
  MinClass<int, double> m3;
  MinClass<float, float> m4;
  MinClass<float, double> m5;
  MinClass<double, double> m6;

  cout << m1.Min(3, 5) << endl;
  cout << m2.Min(3, 2.3f) << endl;
  cout << m3.Min(3, 4.5) << endl;
  cout << m4.Min(3.5f, 1.2f) << endl;
  cout << m5.Min(3.5f, 4.8) << endl;
  cout << m6.Min(8.3, 9.1) << endl;

  return 0;
}
