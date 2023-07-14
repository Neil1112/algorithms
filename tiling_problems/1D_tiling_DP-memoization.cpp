/*
    1D tiling problem: Give a board of length n. Find the number of ways to tile the board with 1x1 and 1x2 tiles.
    Use dynamic programming to reduce the time complexity from O(2^n) to O(n).
*/

/*
    Memoization - Top down approach - Recursive method
    Time complexity: O(n)
    Let f(n) be the number of ways to tile the board of length n.
    f(n) = f(n-1) + f(n-2)
*/

#include <iostream>
#include <unordered_map>
using namespace std;


// Memoization - Top down approach - Recursive method
int tiling(int n, unordered_map<int, int>& dp_memo) {
    // checking out of bounds
    if(n < 0) {
        return 0;
    }

    // checking if the result is already present in the dp_memo
    if(dp_memo.count(n)) {
        return dp_memo[n];
    }

    // base case
    // case1: if n == 0, then there is only one way to tile the board, i.e. with no tiles.
    // case2: if n == 1, then there is only one way to tile the board, i.e. with one 1x1 tile.
    if(n == 0 || n == 1) {
        dp_memo[n] = 1;
    }


    // recursive step
    // case1: if we place a 1x1 tile, then we have to tile the remaining board of length n-1.
    // case2: if we place a 1x2 tile, then we have to tile the remaining board of length n-2.
    if (n > 1) {
        dp_memo[n] = tiling(n-1, dp_memo) + tiling(n-2, dp_memo);
    }
    return dp_memo[n];
}


int main() {
    int n;
    unordered_map<int, int> dp_memo;

    cout << "Enter the length of the board: ";
    cin >> n;
    cout << tiling(n, dp_memo) << endl;

    return 0;
}