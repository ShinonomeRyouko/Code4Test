#include "corporate_flight_bookings.h"

#include "gtest/gtest.h"

TEST(corporate_flight_bookingsTest, SimpleTest) {
    corporate_flight_bookings* obj = new corporate_flight_bookings();
    vector<vector<int>> vec{{{1, 2, 10}, {2, 3, 20}, {2, 5, 25}}};
    vector<int> ans{10, 55, 45, 25, 25};
    EXPECT_TRUE(obj->corpFlightBookings(vec, 5) == ans);
    delete obj;
}