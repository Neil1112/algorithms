/*
    1D tiling problem: Given a board of length n. Find the number of ways to tile the board with 1x1 and 1x2 tiles.
*/

#include <iostream>
using namespace std;


// Recursive solution
// Time complexity: O(2^n)
// Let f(n) be the number of ways to tile the board of length n.
// f(n) = f(n-1) + f(n-2)
int tiling(int n) {
    // base case
    // case1: if n == 0, then there is only one way to tile the board, i.e. with no tiles.
    if(n == 0) {
        return 1;
    }

    // case2: if n == 1, then there is only one way to tile the board, i.e. with one 1x1 tile.
    if(n == 1) {
        return 1;
    }


    // recursive step
    // case1: if we place a 1x1 tile, then we have to tile the remaining board of length n-1.
    // case2: if we place a 1x2 tile, then we have to tile the remaining board of length n-2.
    return tiling(n-1) + tiling(n-2);
}


int main() {
    int n;

    cout << "Enter the length of the board: ";
    cin >> n;
    cout << tiling(n) << endl;

    return 0;
}