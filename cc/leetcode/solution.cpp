#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0; i<nums.size(); ++i)
        {
            for(int j = i+1; j<nums.size(); ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums1{2,7,11,15};
    vector<int> r1;
    int t1 = 9;
    Solution s1;
    r1 = s1.twoSum(nums1,t1);
    vector<int>::iterator v = r1.begin();
    for(v = r1.begin(); v != r1.end(); v++)
    {
        cout << *v << endl;
    }
    return 0;
}
