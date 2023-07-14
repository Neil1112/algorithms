/*
    1D tiling problem: Given a board of length n. Find the number of ways to tile the board with 1x1 and 1x2 tiles.
    Use dynamic programming to reduce the time complexity from O(2^n) to O(n).
*/

/*
    Tabulation - Bottom up approach - Iterative method
    Time complexity: O(n)
    Let f(n) be the number of ways to tile the board of length n.
    f(n) = f(n-1) + f(n-2)
*/

#include <iostream>
#include <vector>
using namespace std;


// Tabulation - Bottom up approach - Iterative method
int tiling(int n) {
    // checking out of bounds
    if(n < 0) {
        return 0;
    }

    vector<int> dp_table(n+1, 0);
    dp_table[0] = 1;
    dp_table[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp_table[i] = dp_table[i-1] + dp_table[i-2];
    }

    return dp_table[n];
}


int main() {
    int n;

    cout << "Enter the length of the board: ";
    cin >> n;
    cout << tiling(n) << endl;

    return 0;
}