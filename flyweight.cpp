#include "flyweight.hpp"

namespace jc {

    ConcreteFlyweight::ConcreteFlyweight(char key) : key_(key) {}

    void ConcreteFlyweight::Print() {
        std::cout << key_;
    }

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
#include "flyweight.hpp"

#int main() {
#   jc::FlyweightFactory factory;
#    factory.FlyweightPtr('a')->Print();  // a
#   factory.FlyweightPtr('a')->Print();  // existing key: a
#    factory.FlyweightPtr('b')->Print();  // b
#    factory.FlyweightPtr('b')->Print();  // existing key: a
#
#    return 0;
#}
