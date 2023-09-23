#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "func.h"
#include "back.h"
#include "valid.h"

TEST(HelloTest, PositiveInteger) {
  // arrange 
  int n = 1;
  int dec = 0;
  std::vector<int> ans(32);

  // act
  ans = dec_to_bin(n);
  dec = back_to_dec(ans);

  // assert
  EXPECT_EQ(dec, n);
}

TEST(HelloTest, Invalid_Arg) {
  // arrange
  int n = -1;

  // act


  // assert
  EXPECT_THROW(invalid_data(n), std::invalid_argument);
}