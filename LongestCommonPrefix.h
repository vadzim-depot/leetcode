class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        size_t count0 = strs.size();
        size_t minLen = -1;
        
        string prefixCandidate;
        for (size_t i = 0; i < count0; i++)
        {
            if (strs[i].size() < minLen)
            {
                minLen = strs[i].size();
                prefixCandidate = strs[i];
            }
        }
        
        string prefix;
        
        size_t count1 = prefixCandidate.size();
        for (size_t i = 0; i < count1; i++)
        {
            for (size_t j = 0; j < count0; j++)
            {
                string& str = strs[j];
                if (prefixCandidate[i] != str[i])
                {
                    return prefix;
                }
            }
            
            prefix = prefix + prefixCandidate[i];
        }
        
        return prefix;
    }
};