#include <gtest/gtest.h>
#include <iostream>
#include <bitset>
#include "dec_bin_convertion.h"
#include "validation.h"

TEST(HelloTest, PositiveInteger) {
  // arrange 
  int n = 1;
  unsigned long long dec = 0;
  std::bitset<32> ans;

  // act
  ans = dec_to_bin(n);
  dec = bin_to_dec(ans);

  // assert
  EXPECT_EQ(dec, n);
}

TEST(HelloTest, Invalid_Arg) {
  // arrange
  int n = -1;

  // act


  // assert
  EXPECT_THROW(invalid_data(n), std::out_of_range);
}