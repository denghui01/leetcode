#include <math.h>
#include <stdint.h>
#include "array.h"

// 1266. Minimum Time Visiting All Points
int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int result = 0;
    for(int i = 1; i < points.size(); ++i)
    {
        result += max(abs(points[i][0] - points[i-1][0]), abs(points[i][1] - points[i-1][1]));
    }
    return result;
}

// 1252. Cells with Odd Values in a Matrix
int oddCells(int n, int m, vector<vector<int>>& indices) {
    uint64_t nbits = 0;
    uint64_t mbits = 0;

    for(int i = 0; i < indices.size(); ++i)
    {
        nbits ^= (uint64_t)1 << indices[i][0];
        mbits ^= (uint64_t)1 << indices[i][1];
    }
    int dn = 0;
    int dm = 0;
    for(int i = 0; i < 64; ++i)
    {
        if(nbits & ((uint64_t)1 << i)) dn++;
        if(mbits & ((uint64_t)1 << i)) dm++;
    }
    return dm * n + dn * m - dn * dm * 2;           
}