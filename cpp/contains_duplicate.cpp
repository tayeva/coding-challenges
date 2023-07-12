/*
Given an integer array nums, return true if any value
appears at least twice in the array, and return false
if every element is distinct.

Problem statement source: Leetcode
*/

#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

bool contains_duplicate(const std::vector<int> &nums) {
  std::unordered_set<int> num_set;
  for (const auto &num : nums) {
    if (num_set.count(num) > 0) {
      return true;
    }
    num_set.insert(num);
  }
  return false;
}

int main() {
  std::vector<int> nums{1, 2, 3, 1};
  bool result = contains_duplicate(nums);
  std::cout << std::boolalpha << result << std::endl;
  std::vector<int> dups{1, 2, 3, 1};
  assert(contains_duplicate(dups) == true);
  std::vector<int> no_dups{1, 2, 3, 4};
  assert(contains_duplicate(no_dups) == false);
  return EXIT_SUCCESS;
}
