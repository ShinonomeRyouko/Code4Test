#include "corporate_flight_bookings.h"

using namespace std;

corporate_flight_bookings::corporate_flight_bookings() {}

corporate_flight_bookings::~corporate_flight_bookings() {}

vector<int> corporate_flight_bookings::corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> ans(n);
    for (const vector<int>& booking : bookings) {
        ans[booking[0] - 1] += booking[2];
        if (booking[1] < n) {
            ans[booking[1]] -= booking[2];
        }
    }
    int val = 0;
    for (int i = 0; i < n; i++) {
        ans[i] += val;
        val = ans[i];
    }
    return ans;
}