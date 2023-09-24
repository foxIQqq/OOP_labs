#include <gtest/gtest.h>
#include "dec_bin_convertion.h"
#include "validation.h"
#include <bitset>

class func_parameterized_test_fixture1 :public ::testing::TestWithParam<long long> {};

class func_parameterized_test_fixture2 :public ::testing::TestWithParam<long long> {};

TEST_P(func_parameterized_test_fixture1, simple_test1) {
  long dec = GetParam();
  EXPECT_THROW(invalid_data(dec), std::out_of_range);
}

TEST_P(func_parameterized_test_fixture2, simple_test2) {
  long dec = GetParam();
  std::bitset<32> ans;
  unsigned long long back_dec;

  ans = dec_to_bin(dec);
  back_dec = bin_to_dec(ans);

  EXPECT_EQ(back_dec, dec);
}

INSTANTIATE_TEST_SUITE_P(
  func_test1, 
  func_parameterized_test_fixture1,
  ::testing::Values(
    -10, -1, 0, 4294967296, 151552552525
  ));

INSTANTIATE_TEST_SUITE_P(
  func_test2, 
  func_parameterized_test_fixture2,
  ::testing::Values(
    1, 5, 10, 100, 234, 5757557
  ));