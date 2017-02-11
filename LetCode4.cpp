#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
private:
    double findKth(vector<int>& nums1, int m, vector<int>& nums2, int n, int k){
        if(m > n)
            return findKth(nums2, n, nums1, m, k);
        if(m == 0)
            return nums2[k -1];
        if(k == 1)
            return min(nums1[0], nums2[0]);
        
        int pa = min(k / 2, m), pb = k - pa;

        if(nums1[pa - 1] < nums2[pb - 1]){
        	vector<int> a = vector<int>(nums1.begin() + pa, nums1.end());
        	return findKth(a, m - pa, nums2, n, k - pa);
		}          
        else if(nums1[pa - 1] > nums2[pb - 1]){
        	vector<int> b = vector<int>(nums2.begin() + pb, nums2.end());
        	return findKth(nums1, m, b, n - pb, k - pb);
		}      
        else 
            return nums1[pa - 1];
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        int total = len1 + len2;

        if(total & 0x1)
            return findKth(nums1, len1, nums2, len2, total / 2 + 1);
        else
            return (findKth(nums1, len1, nums2, len2, total / 2) + findKth(nums1, len1, nums2, len2, total / 2 + 1)) / 2;

    }
};

int main(){
    
}
