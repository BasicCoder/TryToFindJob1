#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res = intervals;
        vector<Interval>::iterator it = res.begin();
        int overlap = 0;

        while(it != res.end()){
            if(newInterval.end < it -> start)break;
            else if(newInterval.start > it -> end){}
            else{
                newInterval.start = min(newInterval.start, it -> start);
                newInterval.end = max(newInterval.end, it -> end);
                ++overlap;
            }
            ++it;
        }

        if(overlap  != 0) it = res.erase(it - overlap, it);
        res.insert(it, newInterval);
        return res;
    }
};

int main(){

}