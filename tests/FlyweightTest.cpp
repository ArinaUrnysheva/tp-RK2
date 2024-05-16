#include <gtest/gtest.h>
#include "../flyweight.cpp"

/*
TEST(FlyweightTest, FlyweightFactoryWorks) {
  jc::FlyweightFactory factory;

  // Request a Flyweight for a new character
  char new_char = 'A';
  std::unique_ptr<jc::Flyweight>& flyweight_ptr1 = factory.FlyweightPtr(new_char);
  EXPECT_NE(flyweight_ptr1, nullptr);

  // Check if the Flyweight is correctly created
  testing::internal::CaptureStdout();
  flyweight_ptr1->Print();
  std::string output1 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output1, std::string(1, new_char));

  // Request a Flyweight for an existing character
  std::unique_ptr<jc::Flyweight>& flyweight_ptr2 = factory.FlyweightPtr(new_char);
  EXPECT_EQ(flyweight_ptr1, flyweight_ptr2);

  // Request a Flyweight for another character
  char another_char = 'B';
  std::unique_ptr<jc::Flyweight>& flyweight_ptr3 = factory.FlyweightPtr(another_char);
  EXPECT_NE(flyweight_ptr3, nullptr);

  // Check if it was correctly created
  testing::internal::CaptureStdout();
  flyweight_ptr3->Print();
  std::string output3 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output3, std::string(1, another_char));
}
*/

TEST(FlyweightTest, CreateNewFlyweight) {
  jc::FlyweightFactory factory;

  // Request a Flyweight for a new character
  char new_char = 'A';
  std::unique_ptr<jc::Flyweight>& flyweight_ptr1 = factory.FlyweightPtr(new_char);
  EXPECT_NE(flyweight_ptr1, nullptr);

  // Check if the Flyweight is correctly created
  testing::internal::CaptureStdout();
  flyweight_ptr1->Print();
  std::string output1 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output1, std::string(1, new_char));
}

TEST(FlyweightTest, ReuseExistingFlyweight) {
  jc::FlyweightFactory factory;

  // Request a Flyweight for a new character
  char new_char = 'A';
  std::unique_ptr<jc::Flyweight>& flyweight_ptr1 = factory.FlyweightPtr(new_char);

  // Request a Flyweight for the same character again
  std::unique_ptr<jc::Flyweight>& flyweight_ptr2 = factory.FlyweightPtr(new_char);
  EXPECT_EQ(flyweight_ptr1, flyweight_ptr2);
}

TEST(FlyweightTest, CreateDifferentFlyweights) {
  jc::FlyweightFactory factory;

  // Request a Flyweight for a new character
  char new_char = 'A';
  std::unique_ptr<jc::Flyweight>& flyweight_ptr1 = factory.FlyweightPtr(new_char);

  // Request a Flyweight for another character
  char another_char = 'B';
  std::unique_ptr<jc::Flyweight>& flyweight_ptr2 = factory.FlyweightPtr(another_char);
  EXPECT_NE(flyweight_ptr1, flyweight_ptr2);

  // Check if the Flyweights are correctly created
  testing::internal::CaptureStdout();
  flyweight_ptr2->Print();
  std::string output2 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output2, std::string(1, another_char));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
