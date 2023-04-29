#include "sample.h"

#include "gtest/gtest.h"

TEST(sampleTest, SimpleTest) {
    sample* obj = new sample();
    delete obj;
}