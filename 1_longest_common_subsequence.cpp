/*
    Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

    Input:
    str1 = ABCDGH
    str2 = AEDFHR

    Output: 3

    Explanation: 
    LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// function to calculate the LCS - iterative approach
unsigned int LCS_iterative(const string& str1, const string& str2) {
    // matrix to store length of longest subsequences
    vector<vector<int>> matrix(str1.size() + 1, vector<int>(str2.size() + 1, 0));

    for (size_t i = 1; i <= str1.size(); i++) {
        for (size_t j = 1; j <= str2.size(); j++) {
            int max_value = max(matrix[i-1][j], matrix[i][j-1]);
            if (str1[i-1] == str2[j-1]) {
                max_value += 1;
            }
            matrix[i][j] = max_value;
        }
    }

    // print the matrix
    cout << endl;
    for (size_t i = 0; i <= str1.size(); i++) {
        for (size_t j = 0; j <= str2.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return matrix[str1.size()][str2.size()];
}


// recursive function to calculate the LCS
// recursive formula: LCS(i, j) = max(LCS(i-1, j), LCS(i, j-1)) + 1 if str1[i] == str2[j]
unsigned int LCS_recursive(const string& str1, const string& str2, int str1_index, int str2_index) {
    // base case
    if (str1_index == 0 || str2_index == 0)
        return 0;

    // recursive step
    int value = max(LCS_recursive(str1, str2, str1_index-1, str2_index), LCS_recursive(str1, str2, str1_index, str2_index-1));
    if (str1[str1_index-1] == str2[str2_index-1])
        return value + 1;
    return value;
}


// LCS wrapper
unsigned int LCS(const string& str1, const string& str2) {
    return LCS_recursive(str1, str2, str1.size(), str2.size());
}


int main() {
    string str1 = "ABCDGH";
    string str2 = "AEDFHR";

    cout << "Iterative LCS: " << LCS_iterative(str1, str2) << endl;
    cout << "Recursive LCS: " << LCS(str1, str2) << endl;

    return 0;
}