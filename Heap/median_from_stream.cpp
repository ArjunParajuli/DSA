#include<bits/stdc++.h>
using namespace std;


// brute force: sorting each time a new elm is inserted and find median

// optimized: insert the input strean of elms into min and maxheap
/*
 make left half maxheap and right half min heap

for even num of elms:
- case: maxheap.size == minheap.size, median = minheap.top+maxheap.top/2 

for odd number of elms: (jis heap mai jyada elms hoga, median usika top hoga)
- case 1: maxheap.size == minheap.size+1, median is maxm elm of maxheap

- case 2: maxheap.size+1 == minheap.size, median is minm elm of minheap
*/


// jo elm aaya hai usko kisme ouch karey minheap or maxheap
/*

*/