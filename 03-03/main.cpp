#include "Animal.h"

int main() {
  Animal *a1 = new Dog();
  Animal *a2 = new Cat();

  a1->Speak(); // ワン
  a2->Speak(); // ニャー

  delete a1;
  delete a2;
  return 0;
}
