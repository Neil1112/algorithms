/*
    Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

    Input:
    str1 = ABCDGH
    str2 = AEDFHR

    Output: 3

    Explanation: 
    LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
*/

/*
    Test cases
    1.
    str1 = ABCDGH
    str2 = AEDFHR
    Output: 3

    2.
    str1 = ABC
    str2 = XYZ
    Output: 0

    3.
    str1 = ABCD
    str2 = BD
    Output: 2

    4.
    str1 = AGGTAB
    str2 = GXTXAYB
    Output: 4

    5.
    str1 = AGGCTAGCG
    str2 = GCGCAATG
    Output: 5
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// function to calculate the LCS - iterative approach
unsigned int LCS_tabulation(const string& str1, const string& str2) {
    size_t m = str1.size();
    size_t n = str2.size();

    // Create a table to store the lengths of LCS for substrings
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Compute the lengths of LCS for all subproblems
    for (size_t i = 1; i <= m; i++) {
        for (size_t j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The length of the LCS is stored in the bottom-right cell
    return dp[m][n];
}

// recursive function to calculate the LCS
// recursive formula: LCS(i, j) = max(LCS(i-1, j), LCS(i, j-1)) + 1 if str1[i] == str2[j]
unsigned int LCS_recursive(const string& str1, const string& str2, int str1_index, int str2_index) {
    // base case
    if (str1_index == 0 || str2_index == 0)
        return 0;

    // recursive step
    if (str1[str1_index - 1] == str2[str2_index - 1])
        return LCS_recursive(str1, str2, str1_index - 1, str2_index - 1) + 1;
    else
        return max(LCS_recursive(str1, str2, str1_index - 1, str2_index), LCS_recursive(str1, str2, str1_index, str2_index - 1));
}


// LCS recursive wrapper
unsigned int LCS_recursive(const string& str1, const string& str2) {
    return LCS_recursive(str1, str2, str1.size(), str2.size());
}


int main() {
    string str1 = "ABCDGH";
    string str2 = "AEDFHR";

    cout << "Tabulation DP LCS: " << LCS_tabulation(str1, str2) << endl;
    cout << "Recursive LCS: " << LCS_recursive(str1, str2) << endl;

    return 0;
}