#include <gtest/gtest.h>
#include "../flyweight/Flyweight.cpp"  // Include the implementation file for testing

// Test the FlyweightFactory class
TEST(FlyweightFactoryTest, FlyweightCreation) {
  jc::FlyweightFactory factory;

  // Test creating and printing flyweight objects
  EXPECT_NO_THROW({
    EXPECT_NO_THROW(factory.FlyweightPtr('a')->Print());
    EXPECT_NO_THROW(factory.FlyweightPtr('a')->Print());
    EXPECT_NO_THROW(factory.FlyweightPtr('b')->Print());
    EXPECT_NO_THROW(factory.FlyweightPtr('b')->Print());
  });
}

/* Run all tests
int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}*/
