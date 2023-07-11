/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct
ways can you climb to the top?

Source: Leetcode
*/

#include <cassert>
#include <iostream>
#include <vector>

int distinct_ways_to_climb_stairs(int n) {
  if (n <= 2)
    return n;
  std::vector<int> arr(n + 1);
  arr[1] = 1;
  arr[2] = 2;
  for (int i = 3; i <= n; ++i) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }
  return arr[n];
}

int main() {
  int n;
  std::cout << "Enter the number of steps: ";
  std::cin >> n;
  int ways = distinct_ways_to_climb_stairs(n);
  std::cout << "Number of distinct ways to climb the staircase: " << ways
            << std::endl;
  assert(distinct_ways_to_climb_stairs(2) == 2);
  assert(distinct_ways_to_climb_stairs(3) == 3);
  return EXIT_SUCCESS;
}
