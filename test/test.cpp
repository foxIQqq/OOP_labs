#include<gtest/gtest.h>
#include "romb.h"
#include "hexagon.h"
#include "pentagon.h"

class Test_romb: public testing::Test {

  protected:
    void SetUp() override {
        r = Romb();
    }

    void TearDown() override {
        r.~Romb();
    }

    Romb r;

};

TEST_F(Test_romb, Area) {
    Point upper_point(0.0, 2.0), lower_vertex(0.0, -2.0), left_vertex(-1.0, 0.0), right_vertex(1.0, 0.0);
    r = Romb(upper_point, lower_vertex, left_vertex, right_vertex, "Romb");
    double ans_area = 4.0;
    EXPECT_DOUBLE_EQ(r.area(), ans_area);

}

TEST_F(Test_romb, Perimetr) {
    Point upper_point(0.0, 2.0), lower_vertex(0.0, -2.0), left_vertex(-1.0, 0.0), right_vertex(1.0, 0.0);
    r = Romb(upper_point, lower_vertex, left_vertex, right_vertex, "Romb");
    double ans_perimetr = 8.9442719099991592;
    EXPECT_DOUBLE_EQ(r.perimetr(), ans_perimetr);
}

TEST_F(Test_romb, Center) {
    Point upper_point(0.0, 2.0), lower_vertex(0.0, -2.0), left_vertex(-1.0, 0.0), right_vertex(1.0, 0.0);
    r = Romb(upper_point, lower_vertex, left_vertex, right_vertex, "Romb");
    Point ans = Point(0.0, 0.0);
    EXPECT_EQ(r.center(), ans);
}

TEST_F(Test_romb, OperatorDouble) {
    Point upper_point(0.0, 2.0), lower_vertex(0.0, -2.0), left_vertex(-1.0, 0.0), right_vertex(1.0, 0.0);
    r = Romb(upper_point, lower_vertex, left_vertex, right_vertex, "Romb");
    double ans_area = 4.0;
    EXPECT_DOUBLE_EQ(static_cast<double>(r), ans_area);
}

TEST_F(Test_romb, OperatorEqual) {
    Point upper_point(0.0, 2.0), lower_vertex(0.0, -2.0), left_vertex(-1.0, 0.0), right_vertex(1.0, 0.0);
    Romb r1(upper_point, lower_vertex, left_vertex, right_vertex, "Romb1");
    Romb r2(upper_point, lower_vertex, left_vertex, right_vertex, "Romb2");
    ASSERT_TRUE(r1 == r2); 
}

class Test_pentagon: public testing::Test {

  protected:
  void SetUp() override {
    p = Pentagon();
  }

  void TearDown() override {
    p.~Pentagon();
  }

  Pentagon p;
};

TEST_F(Test_pentagon, Area) {
    Point left_lower(0.0, 0.0), right_lower(2.0, 0.0), left_middle(-1.0, 2.0), right_middle(3.0, 2.0), upper(1.0, 3.0);
    p = Pentagon(left_lower, right_lower, left_middle, right_middle, upper, "pent");

    double ans = 8.0;
    EXPECT_FLOAT_EQ(p.area(), ans);
}

TEST_F(Test_pentagon, Perimetr) {
    Point left_lower(0.0, 1.0), right_lower(0.951, 0.309), left_middle(0.588, -0.809), right_middle(-0.588, -0.809), upper(-0.951, 0.309);
    p = Pentagon(left_lower, right_lower, left_middle, right_middle, upper, "pent");

    double ans = 8.0575943;
    EXPECT_FLOAT_EQ(p.perimetr(), ans);
}

TEST_F(Test_pentagon, Center) {
    Point left_lower(0.0, 1.0), right_lower(0.951, 0.309), left_middle(0.588, -0.809), right_middle(-0.588, -0.809), upper(-0.951, 0.5);
    p = Pentagon(left_lower, right_lower, left_middle, right_middle, upper, "pent");
    
    Point ans(0.0, 0.0382);
    EXPECT_FLOAT_EQ(ans.x, p.center().x);
    EXPECT_FLOAT_EQ(ans.y, p.center().y);

}

TEST_F(Test_pentagon, OperatorDouble) {
    Point left_lower(0.0, 0.0), right_lower(2.0, 0.0), left_middle(-1.0, 2.0), right_middle(3.0, 2.0), upper(1.0, 3.0);
    p = Pentagon(left_lower, right_lower, left_middle, right_middle, upper, "pent");

    double ans = 8.0;
    EXPECT_FLOAT_EQ(static_cast<double>(p), ans);
}

TEST_F(Test_pentagon, OperatorEqual) {
    Point left_lower(0.0, 1.0), right_lower(0.951, 0.309), left_middle(0.588, -0.809), right_middle(-0.588, -0.809), upper(-0.951, 0.309);
    p = Pentagon(left_lower, right_lower, left_middle, right_middle, upper, "pent");
    Pentagon p1 = Pentagon(left_lower, right_lower, left_middle, right_middle, upper, "p2");
    ASSERT_TRUE(p == p1);
}

class Test_hexagon: public testing::Test {

  protected:
    
    void SetUp() override {
        t = Hexagon();
    }

    void TearDown() override {
        t.~Hexagon();
    }

    Hexagon t;
};

TEST_F(Test_hexagon, Area) {
    Point left_lower(0.0, 0.0), right_lower(1.0, 0.0),left_middle(-1.0, 1.0),right_middle(2.0, 1.0), left_upper(0.0, 2.0), right_upper(1.0, 2.0);
    t = Hexagon(left_lower, right_lower,left_middle, right_middle, left_upper, right_upper, "Hexagon");
    double ans = 4.0;
    EXPECT_FLOAT_EQ(t.area(), ans);

}

TEST_F(Test_hexagon, Perimetr) {
    Point left_lower(0.0, 0.0), right_lower(1.0, 0.0),left_middle(-1.0, 1.0),right_middle(2.0, 1.0), left_upper(0.0, 2.0), right_upper(1.0, 2.0);
    t = Hexagon(left_lower, right_lower,left_middle, right_middle, left_upper, right_upper, "Hexagon");
    double ans = 7.6568542;
    EXPECT_FLOAT_EQ(t.perimetr(), ans);
}

TEST_F(Test_hexagon, Center) {
    Point left_lower(0.0, 0.0), right_lower(1.0, 0.0),left_middle(-1.0, 1.0),right_middle(2.0, 1.0), left_upper(0.0, 2.0), right_upper(1.0, 2.0);
    t = Hexagon(left_lower, right_lower,left_middle, right_middle, left_upper, right_upper, "Hexagon");
    Point ans = Point(0.5, 1.0);
    EXPECT_EQ(t.center(), ans);
}

TEST_F(Test_hexagon, OperatorDouble) {
    Point left_lower(0.0, 0.0), right_lower(1.0, 0.0),left_middle(-1.0, 1.0),right_middle(2.0, 1.0), left_upper(0.0, 2.0), right_upper(1.0, 2.0);
    t = Hexagon(left_lower, right_lower,left_middle, right_middle, left_upper, right_upper, "Hexagon");
    double ans = 4.0;
    EXPECT_FLOAT_EQ(static_cast<double>(t), ans);

}

TEST_F(Test_hexagon, OperatorEqual) {
    Point left_lower(0.0, 0.0), right_lower(1.0, 0.0),left_middle(-1.0, 1.0),right_middle(2.0, 1.0), left_upper(0.0, 2.0), right_upper(1.0, 2.0);
    t =  Hexagon(left_lower, right_lower,left_middle, right_middle, left_upper, right_upper, "Hexagon");
    Hexagon t2 = Hexagon(left_lower, right_lower,left_middle, right_middle, left_upper, right_upper, "Hexagon");
    ASSERT_TRUE(t == t2);
}



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}