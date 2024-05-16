#include "flyweight.hpp"

namespace jc {

std::unique_ptr<Flyweight>& FlyweightFactory::FlyweightPtr(char c) {
  if (const auto it = m_.find(c); it != std::end(m_)) {
    std::cout << "existing key: ";
    return it->second;
  }
  std::unique_ptr<Flyweight> p = std::make_unique<ConcreteFlyweight>(c);
  m_.emplace(c, std::move(p));
  return m_.at(c);
}

}  // namespace jc
