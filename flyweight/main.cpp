#include "flyweight.cpp"

int main() {
  jc::FlyweightFactory factory;
  factory.FlyweightPtr('a')->Print();  // a
  factory.FlyweightPtr('a')->Print();  // existing key: a
  factory.FlyweightPtr('b')->Print();  // b
  factory.FlyweightPtr('b')->Print();  // existing key: a
}
