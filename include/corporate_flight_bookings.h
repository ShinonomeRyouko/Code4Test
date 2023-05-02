#ifndef __corporate_flight_bookings_h__
#define __corporate_flight_bookings_h__

#include <vector>
using std::vector;

class corporate_flight_bookings {
private:
public:
    corporate_flight_bookings();
    ~corporate_flight_bookings();
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n);
};

#endif