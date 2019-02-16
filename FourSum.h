class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> ret;
        
        sort(nums.begin(), nums.end());
        
        int count = nums.size();
        for (int i = 0; i < count - 3; ++i)
        {
            int a = nums[i];
            for (size_t j = i + 1; j < count - 2; ++j)
            {
                int b = nums[j];
                
                int k = j + 1;
                int l = count - 1;
                
                while (k < l)
                {
                    int c = nums[k];
                    int d = nums[l];
                    
                    int s = a + b + c + d;                    
                    if (s == target)
                    {
                        vector<int> temp{a, b, c, d};
                        if (ret.end() == find(ret.begin(), ret.end(), temp))
                        {
                            ret.push_back(temp);
                        }
                        
                        ++k;                        
                        --l;                        
                    }
                    else if (s < target)
                    {
                        ++k;
                    }
                    else if (s > target)
                    {
                        --l;
                    }
                }
            }
        }
        
        return ret;
    }
};