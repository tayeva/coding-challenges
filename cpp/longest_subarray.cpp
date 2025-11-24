/*

You are given an array of integers nums (which can contain positive, negative, and zero values) and an integer k.

Return the length of the longest contiguous subarray such that the sum of its elements is ≤ k.

If no such subarray exists, return 0.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int longest_subarray(const std::vector<int>& nums, int k) {
    int max_length = 0;
    int current_sum = 0;
    int left = 0;

    for (int right = 0; right < nums.size(); ++right) {
        current_sum += nums[right];

        while (current_sum > k && left <= right) {
            current_sum -= nums[left];
            ++left;
        }

        max_length = std::max(max_length, right - left + 1);
    }

    return max_length;
}

int main() {
    std::vector<int>nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int k = 6;
    std::cout << "Longest subarray length: " << longest_subarray(nums, k) << std::endl;
    return EXIT_SUCCESS;
}