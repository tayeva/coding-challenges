/*
Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Problem statement source: Leetcode
*/


#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

// O(log(min(m, n)))
double find_median_sorted_arrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return find_median_sorted_arrays(nums2, nums1);
    }
    int m = nums1.size();
    int n = nums2.size();
    int low = 0;
    int high = m;
    while (low <= high) {
        int partition_x = (low + high) / 2;
        int partition_y = (m + n + 1) / 2 - partition_x;
        int max_left_x = (partition_x == 0) ? INT_MIN : nums1[partition_x - 1];
        int min_right_x = (partition_x == m) ? INT_MAX : nums1[partition_x];
        int max_left_y = (partition_y == 0) ? INT_MIN : nums2[partition_y - 1];
        int min_right_y = (partition_y == n) ? INT_MAX : nums2[partition_y];
        if (max_left_x <= min_right_y && max_left_y <= min_right_x) {
            if ((m + n) % 2 == 0) {
                return (std::max(max_left_x, max_left_y) + std::min(min_right_x, min_right_y)) / 2.0;
            } else {
                return std::max(max_left_x, max_left_y);
            }
        } else if (max_left_x > min_right_y) {
            high = partition_x - 1;
        } else {
            low = partition_x + 1;
        }
    }
    throw std::runtime_error("Invalid input");
}

void test1() {
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    double median = find_median_sorted_arrays(nums1, nums2);
    assert(median == 2.0);
}

void test2() {
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {3, 4};
    double median = find_median_sorted_arrays(nums1, nums2);
    assert(median == 2.5);
}

int main() {
    std::vector<int> nums1 = {1, 3, 5};
    std::vector<int> nums2 = {2, 4, 6};
    double median = find_median_sorted_arrays(nums1, nums2);
    std::cout << "Median: " << median << std::endl;
    test1();
    test2();
    return EXIT_SUCCESS;
}