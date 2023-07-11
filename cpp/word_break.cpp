/*
Given a string s and a dictionary of strings words,
return true if s can be segmented into a space-separated
sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused
multiple times in the segmentation.

Source: Leetcode
*/

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool word_break(string s, vector<string> &words) {
  const int n = s.length();
  vector<bool> dp(n + 1, false);
  dp[0] = true;
  unordered_set<string> dict(words.begin(), words.end());
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      if (dp[j] && dict.count(s.substr(j, i - j)) > 0) {
        dp[i] = true;
        break;
      }
    }
  }
  return dp[n];
}

int main() {
  string s = "applepenapple";
  vector<string> words = {"apple", "pen"};
  if (word_break(s, words)) {
    cout << "String can be segmented into words." << endl;
  } else {
    cout << "String cannot be segmented into words." << endl;
  }
  return EXIT_SUCCESS;
}