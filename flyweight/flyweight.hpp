#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>
#include <utility>

namespace jc {

class Flyweight {
 public:
  virtual void Print() = 0;
  virtual ~Flyweight() = default;
};

class ConcreteFlyweight : public Flyweight {
 public:
  explicit ConcreteFlyweight(char key) : key_(key) {}

  void Print() override { std::cout << key_; }

 private:
  char key_;
};

class FlyweightFactory {
 public:
  std::unique_ptr<Flyweight>& FlyweightPtr(char c);

 private:
  std::unordered_map<char, std::unique_ptr<Flyweight>> m_;
};

}  // namespace jc
