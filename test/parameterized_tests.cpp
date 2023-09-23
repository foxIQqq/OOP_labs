#include <gtest/gtest.h>
#include "func.h"
#include "back.h"
#include "valid.h"
#include <vector>

class func_parameterized_test_fixture :public ::testing::TestWithParam<int> {};

TEST_P(func_parameterized_test_fixture, simple_tests) {
  long dec = GetParam();
  std::vector<int> ans(32);
  long back_dec;
  try {
    invalid_data(dec);
    ans = dec_to_bin(dec);
    back_dec = back_to_dec(ans);
    ASSERT_EQ(back_dec, dec);
  }
  catch(std::invalid_argument) {
    ASSERT_THROW(invalid_data(dec), std::invalid_argument);
  }
  catch(std::out_of_range) {
    ASSERT_THROW(invalid_data(dec), std::out_of_range);
  }
}

INSTANTIATE_TEST_SUITE_P(
  func_tests, 
  func_parameterized_test_fixture,
  ::testing::Values(
    -10, -1, 0, 1, 5, 10, 100, 234, 5757557, 4294967296
  ));