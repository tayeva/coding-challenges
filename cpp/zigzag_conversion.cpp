/*
The string "PAYPALISHIRING" is written in a zigzag 
pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make 
this conversion given a number of rows:
string convert(string s, int num_rows);
Source: leetcode
*/

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

std::string convert_zig_zag(const std::string& s, int num_rows) {
    if (num_rows <= 1 || s.length() <= 1){
        return s;
    }
    std::vector<std::string> rows(num_rows, "");
    int current_row = 0;
    bool going_down = false;
    for (char c : s) {
        rows[current_row] += c;
        if (current_row == 0  || current_row == num_rows - 1 ) {
            going_down = !going_down;
        }
        current_row += going_down ? 1 : -1;
    }
    std::string result;
    for (const std::string& row : rows) {
        result += row;
    }
    return result;
}

int main() {
    std::string input = "PAYPALISHIRING";
    int num_rows = 3;
    std::string zigzag = convert_zig_zag(input, num_rows);
    std::cout << "ZigZag conversion: " << zigzag << std::endl;
    assert(zigzag == "PAHNAPLSIIGYIR");
    return EXIT_SUCCESS;
}
