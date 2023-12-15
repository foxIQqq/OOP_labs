#include <gtest/gtest.h>

#include "hex.h"

using namespace form;

TEST(HexTest, ConstructorTest) {
    Hex a = {15, 1, 10};
    Hex b = std::string("a1f");
    Hex c = {1, 1, 1};
    Hex d(3, 1);
    
    EXPECT_EQ(a, b);
    EXPECT_EQ(c, d);
}
TEST(HexTest, ArithmeticTest) {
    Hex a = "123", b = "321", c = "444";
    Hex d = a;
    d += b;

    EXPECT_EQ(a + b, c);
    EXPECT_EQ(d, c);

    d -= b;
    
    EXPECT_EQ(d, a);

    EXPECT_TRUE(a == c - b);

}