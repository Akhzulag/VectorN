//
// Created by Ростислав Буржимський on 24/6/2022.
//

#include "Vector.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace std;


TEST(test, constructor)
{

    int dim = 7;

    int arr[] = {1,2,3,4,5,6,7};

    Vector a(arr, (arr+dim));

    EXPECT_EQ(dim, a.getDimention());

    for(int i=0; i<dim; ++i)
        EXPECT_EQ(arr[i], a[i]);
}

TEST(test, Constructor2)
{
    int dim = 1;

    int arr[] = {1,2};

    Vector a(arr, (arr+dim));

    EXPECT_EQ(dim, a.getDimention());

    for(int i=0; i<dim; ++i)
        EXPECT_EQ(arr[i], a[i]);
}

TEST(test, additional1)
{
    int dim = 5;

    int arr1[] = {9,2 , 3, 4 , 7 };
    int arr2[] = {1,3 , 0, 6 , 3 };
    Vector vec1(arr1, (arr1+dim));
    Vector vec2(arr2, (arr2+dim));

    int arrExp[]={10, 5 , 3, 10, 10 };
    Vector expected(arrExp, (arrExp+dim));

    Vector actual = vec1.addition(vec2);

    EXPECT_EQ(expected, actual);
}

TEST(test, additional2)
{
    int dim = 5;

    int arr1[] = {9,2 , 3, 4 , 7 };
    int arr2[] = {1,3 , 0, 6 , 3 };
    Vector vec1(arr1, (arr1+dim));
    Vector vec2(arr2, (arr2+dim));

    int arrExp[]={10, 5 , 3, 10, 10 };
    Vector expected(arrExp, (arrExp+dim));

    Vector actual = vec1.addition(vec2);

    EXPECT_EQ(expected, actual);
}

TEST(test, additional3)
{
    int dim = 2;

    int arr1[] = {2,2 };
    int arr2[] = {1,4 };
    Vector vec1(arr1, (arr1+dim));
    Vector vec2(arr2, (arr2+dim));

    int arrExp[]={3, 6};
    Vector expected(arrExp, (arrExp+dim));

    Vector actual = vec1.addition(vec2);

    EXPECT_EQ(expected, actual);
}

TEST(test, additionalThrow)
{
    int dim1 = 2;
    int dim2 = 3;
    int arr1[] = {2,2 };
    int arr2[] = {1,4, 3};
    Vector vec1(arr1, (arr1+dim1));
    Vector vec2(arr2, (arr2+dim2));

    EXPECT_ANY_THROW(vec1.addition(vec2));
}

TEST(test, substraction1)
{
    int dim = 3;

    int arr1[] = {2,2 , 2};
    int arr2[] = {1,4 , 2};
    Vector vec1(arr1, (arr1+dim));
    Vector vec2(arr2, (arr2+dim));

    int arrExp[]={1, -2, 0};
    Vector expected(arrExp, (arrExp+dim));

    Vector actual = vec1.subtraction(vec2);

    EXPECT_EQ(expected, actual);
}

TEST(test, substraction3)
{
    int dim = 3;

    int arr1[] = {2,2 , 2,6,7,8};
    int arr2[] = {1,4 , 2,9,0,3};
    Vector vec1(arr1, (arr1+dim));
    Vector vec2(arr2, (arr2+dim));

    int arrExp[]={1, -2, 0,-3,7,5};
    Vector expected(arrExp, (arrExp+dim));

    Vector actual = vec1.subtraction(vec2);

    EXPECT_EQ(expected, actual);
}



TEST(test, substractionThrow)
{
    int dim1 = 2;
    int dim2 = 3;
    int arr1[] = {2,2 };
    int arr2[] = {1,4, 3};
    Vector vec1(arr1, (arr1+dim1));
    Vector vec2(arr2, (arr2+dim2));

    EXPECT_ANY_THROW(vec1.addition(vec2));
}



TEST(test, emptyConstructor)
{

    int dim = 0;

    int arr[] = {};

    Vector a(arr, (arr+dim));

    EXPECT_EQ(dim, a.getDimention());

    for(int i=0; i<dim; ++i)
        EXPECT_EQ(arr[i], a[i]);
}


TEST(test, dotProductEmpty)
{

    int dim2 = 0;
    int dim1 = 0;
    int arr1[] = {};
    int arr2[] = {};

    Vector v1(arr1, (arr1+dim1));
    Vector v2(arr2, (arr2+dim2));

    int expected = 0;
    int actual = v1.dotProduct(v2);

    EXPECT_EQ(actual, expected);

}

TEST(test, dotProductDifDimention)
{

    int dim2 = 7;
    int dim1 = 0;
    int arr1[] = {};
    int arr2[] = {1,1,1,1,1,1,1};

    Vector v1(arr1, (arr1+dim1));
    Vector v2(arr2, (arr2+dim2));

    EXPECT_ANY_THROW(v1.dotProduct(v2));

}

TEST(test, dotProduct1)
{
    int dim = 7;

    int arr1[] = {1,2,3,4,5,6,7};
    int arr2[] = {1,1,1,1,1,1,1};

    Vector v1(arr1, (arr1+dim));
    Vector v2(arr2, (arr2+dim));
    int expected = 28;
    int actual = v1.dotProduct(v2);

    EXPECT_EQ(actual, expected);

}

TEST(test, dotProduct2)
{

    int dim = 7;

    int arr1[] = {1,2,3,4,5,6,7};
    int arr2[] = {1,1,1,1,1,1,1};

    Vector v1(arr1, (arr1+dim));
    Vector v2(arr2, (arr2+dim));
    int expected = 28;
    int actual = v1.dotProduct(v2);

    EXPECT_EQ(actual, expected);

}

TEST(test, dotProduct3)
{

    int dim = 7;

    int arr1[] = {1,2,3,4,5,6,7};
    int arr2[] = {1,1,1,1,1,1,1};

    Vector v1(arr1, (arr1+dim));
    Vector v2(arr2, (arr2+dim));
    int expected = 28;
    int actual = v1.dotProduct(v2);

    EXPECT_EQ(actual, expected);

}




GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}