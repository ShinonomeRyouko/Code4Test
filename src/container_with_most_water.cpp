#include "container_with_most_water.h"

using namespace std;

container_with_most_water::container_with_most_water() {}

container_with_most_water::~container_with_most_water() {}

int container_with_most_water::maxArea(vector<int>& height) {
    int ret = 0;
    int left = 0, right = height.size() - 1;
    while (left < right) {
        if (height[left] > height[right]) {
            ret = max(ret, height[right] * (right - left));
            right--;
        } else {
            ret = max(ret, height[left] * (right - left));
            left++;
        }
    }
    return ret;
}