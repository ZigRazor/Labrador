#include "LabradorConfig.h"
#include "gtest/gtest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "Running Test for Labrador " << LABRADOR_VERSION_MAJOR << "."
            << LABRADOR_VERSION_MINOR << "." << LABRADOR_VERSION_PATCH
            << std::endl;
  return RUN_ALL_TESTS();
}