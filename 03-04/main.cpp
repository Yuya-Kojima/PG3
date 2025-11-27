#include "Circle.h"
#include "Rectangle.h"

int main() {

  IShape *c = new Circle(5);
  IShape *r = new Rectangle(4, 3);

  c->Draw();
  r->Draw();

  delete c;
  delete r;

  return 0;
}
