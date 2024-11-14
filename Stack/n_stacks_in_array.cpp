#include <iostream>
#include <stack>
using namespace std;

/*

Two extra arr
top arr of size n -> stores index of top elm of ith stack
next arr of size s(size of input arr) -> points to next elm after top elm(below elm of top) or points to the next free space  
freeSpot variable -> points to the free spot in the array. Initially 0.

Refer notion notes for algorithm

*/