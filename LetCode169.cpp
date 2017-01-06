#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 自己实现快速排序，调用库函数sort,无法通过, 时间超出
class Solution1 {
private:
	void quicksort(vector<int>& nums, int l, int r){
        if(l < r){
            int i = l, j = r, x = nums[l];
            while(i < j){
                while(i < j && nums[j] >= x)
                    --j;
                if(i < j)
                    nums[i++] = nums[j];

                while(i < j && nums[i] <= x)
                    ++i;
                if(i < j)
                    nums[j--] = nums[i];
            }
            nums[i] = x;
            quicksort(nums, l, i -1);
            quicksort(nums, i +1, r);
        }
    }
    void printresult(vector<int>& nums){
    	int size = nums.size();
    	for(int i = 0; i < size; ++i){
    		cout << nums[i] << ' ';
		}
		cout << endl;
	}
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];
        quicksort(nums, 0, size -1);
        
		printresult(nums);
		
        int count = 0;
        int i = 0;
        for(i = 0; i < size-1; ++i){
            if(nums[i] == nums[i+1]){
                ++count;
            }else{
                ++count;
                if(count > (size/2))
                    return nums[i];           
                	count = 0;      
            }
        }
        ++count;
        if(count > (size/2))
            return nums[i];
            
       	return -1;
    }
};

class Solution{
	public:
		int majorityElement(vector<int>& nums) {
			int max;
			int count = 0;
			int size = nums.size();
			for(int i = 0; i < size; ++i){
				if(count == 0){
					max = nums[i];
					count = 1;
					continue;
				}
				
				if(max != nums[i]){
					count--;
				}else{
					count++;
				}
			}
			return max;
			
	}
};

int main(){
    int a[3] = {3, 2, 3};
	vector<int> nums;
	
	for(int i = 0; i < 3; ++i){
		nums.push_back(a[i]);
	}
	Solution solution;
	cout << solution.majorityElement(nums) << endl;
}
