#include "gtest/gtest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "Running Test for Labrador " << std::endl;
  return RUN_ALL_TESTS();
}