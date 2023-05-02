#include "product_of_array_except_self.h"

using namespace std;

product_of_array_except_self::product_of_array_except_self() {}

product_of_array_except_self::~product_of_array_except_self() {}

vector<int> product_of_array_except_self::productExceptSelf(vector<int>& nums) {
    int len = nums.size();
    vector<int> ans(len);
    // product of prefix i, [0. i).
    ans[0] = 1;
    for (int i = 1; i < len; i++) {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    // reverse iterate.
    int R = 1;
    for (int i = len - 1; i >= 0; i--) {
        ans[i] *= R;
        R *= nums[i];
    }
    return ans;
}