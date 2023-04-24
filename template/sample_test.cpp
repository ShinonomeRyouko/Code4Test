#include <gtest/gtest.h>
#include "sample.h"


TEST(sampleTest, SimpleTest) {
    sample* obj = new sample();
    delete obj;
}