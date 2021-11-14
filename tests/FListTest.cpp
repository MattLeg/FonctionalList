//
// Created by sorge on 21/03/2021.
//
#include "include/FList.h"
#include "gtest/gtest.h"
#include "tuple"

class FListTest : public testing::Test {

    void SetUp() {
        //std::cout << "start of a test" << std::endl;
        beginVal0 = 0;
        beginVal10 = 10;
    }

    void TearDown( ) {
        //std::cout << "end of a test" << std::endl;
    }

    protected :
        FList<int> previousList = {12,2,3,4,5,10};
        FList<int> myList = {12,2,3,4,5,10};
        const int headExpect = 12;
        const FList<int> tailExpect = {2,3,4,5,10};
        const FList<int> expectListMap = {120,20,30,40,50,100};
        const int resExpectFoldLeft0 = 36;
        const int resExpectFoldLeft10 = 46;
        const int resExpectFoldRight0 = 4;
        const int resExpectFoldRight10 = 14;
        int beginVal0;
        int beginVal10;
        FList<std::string> previousListFlatMap = {{"mon voisin "},{"t"},{"o"}, {"t"},{"o"}, {"r"},{"o"}};
        FList<std::string> mylistFlatMap = {{"mon voisin "},{"t"},{"o"}, {"t"},{"o"}, {"r"},{"o"}};
        const std::string expectResFlatMap = "MON VOISIN TOTORO";
        const FList<int> expectListFilter = {12,2,4,10};
};

TEST_F(FListTest, operatorEql)
{
    EXPECT_TRUE(myList == previousList);
}

TEST_F(FListTest, operatorAffectation)
{
    const FList<int> aList = {12,2,3,4,5,10};

    EXPECT_EQ(aList, previousList);
}

TEST_F(FListTest, head)
{
    int head = myList.head();

    // check that head is ok
    EXPECT_TRUE(head == headExpect);
    // check that list don't change
    EXPECT_TRUE(myList == previousList);
}

TEST_F(FListTest, tail)
{
    FList<int> tail = myList.tail();

    // check that tail is ok
    EXPECT_TRUE(tail == tailExpect);
    // check that list don't change
    // have to use reference, to prevent stack overflow
    EXPECT_TRUE(myList == previousList);
}

TEST_F(FListTest, fetch)
{
    int head = 0;
    FList<int> tail;

    std::tie<int, FList<int>>(head, tail) = myList.fetch();

    // check head ok
    EXPECT_TRUE(head == headExpect);
    // check that tail is ok
    EXPECT_TRUE(tail == tailExpect);
    // check that list don't change
    EXPECT_TRUE(myList == previousList);
}

TEST_F(FListTest, map)
{
    // lambda function to inject
    auto lf = [](auto p){
        return p*10;
    };

    FList<int> reslist = myList.map(lf);

    // check no side effect
    EXPECT_TRUE( myList == previousList);
    // check that lists elem are the same
    EXPECT_TRUE(reslist == expectListMap);
}

TEST_F(FListTest, foldLeft)
{
    // lambda function to inject
    auto lf = [](auto n1, auto n2){return n1+n2;};

    int res0 = myList.foldLeft(beginVal0, lf);
    int res10 = myList.foldLeft(beginVal10, lf);

    // check no side effect
    EXPECT_TRUE( myList == previousList);
    // check the result of foldleft
    EXPECT_TRUE(resExpectFoldLeft0 == res0);
    EXPECT_TRUE(resExpectFoldLeft10 == res10);
}

TEST_F(FListTest, foldRight)
{
    const int resExpect0 = -7;
    const int resExpect10 = 3;

    // lambda function to inject
    auto lf = [](auto n1, auto n2){return n1-n2;};

    int res0 = myList.foldRight(beginVal0, lf);
    int res10 = myList.foldRight(beginVal10, lf);

    // check no side effect
    EXPECT_TRUE( myList == previousList);
    // check the result of foldleft
    EXPECT_TRUE(resExpectFoldRight0 == res0);
    EXPECT_TRUE(resExpectFoldRight10 == res10);
}

TEST_F(FListTest, flatMap)
{
    auto lf = [](auto p){
        auto i = 0;
        for(auto e : p) {
            p[i] = std::toupper(e);
            i++;
        }
        return p;
    };

    auto res = mylistFlatMap.flatMap(lf);

    // check no side effect
    EXPECT_TRUE( mylistFlatMap == previousListFlatMap);
    // check the result of flatmap
    EXPECT_TRUE(res == expectResFlatMap);
}

TEST_F(FListTest, filter)
{
    auto pred = [](auto p) {
        return p%2?false:true;
    };

    auto res = myList.filter(pred);

    // check no side effect
    EXPECT_TRUE(myList == previousList);
    // check the result of the filter
    EXPECT_TRUE(res == expectListFilter);
}