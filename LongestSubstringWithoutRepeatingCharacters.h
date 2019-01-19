class Solution 
{
public:
    int lengthOfLongestSubstring(string str) 
    {
        int maxLen = 0;
        int curLen = 0;
        
        unordered_map<char, int> cache;
        
        size_t count = str.size();
        for (size_t i = 0; i < count; i++)
        {
            char ch = str[i];
            
            auto it = cache.find(ch);            
            if (it != cache.end())
            {
                int oldInd = it->second;
                int temp = i - oldInd;
                
                curLen = min(temp, curLen + 1);            
                
                if (curLen == 1)
                {
                    cache.clear();
                }
            }
            else
            {
                curLen = curLen + 1;    
            }            
            
            cache[ch] = i;
            
            if (curLen > maxLen)
            {
                maxLen = curLen;
            }            
        }
        
        return maxLen;
    }
};