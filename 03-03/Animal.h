#pragma once
#include <iostream>
using namespace std;

class Animal {
public:
  virtual void Speak() { cout << "動物の鳴き声\n"; }
};

class Dog : public Animal {
public:
  void Speak() override { cout << "ワン\n"; }
};

class Cat : public Animal {
public:
  void Speak() override { cout << "ニャー\n"; }
};