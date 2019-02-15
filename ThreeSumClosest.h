class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int sum = 0;
        int minDif = 99999999;
        
        sort(nums.begin(), nums.end());
        
        size_t count = nums.size();        
        for (size_t i = 0; i < count - 2; ++i)
        {
            int j = i + 1;
            int k = count - 1;
            
            int a = nums[i];            
            while (j < k)
            {
                int b = nums[j];
                int c = nums[k];
                
                int curSum = a + b + c;
                int curDif = curSum - target;
                
                if (curDif == 0)
                {
                    return curSum;
                }
                else if (curDif < 0)
                {
                    ++j;   
                }
                else if (curDif > 0)
                {
                    --k;
                }
                
                int absDif = abs(curDif);
                if (absDif < minDif)
                {
                    minDif = absDif;
                    sum = curSum;    
                }
            }            
        }
        
        return sum;
    }
};