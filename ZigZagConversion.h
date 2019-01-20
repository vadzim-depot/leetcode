class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if (numRows < 2)
        {
            return s;
        }
        
        vector<string> cache;
        cache.resize(numRows);
                
        int M = 2 * numRows - 2;
        
        for (int i = 0; i < s.size(); ++i)
        {
            char ch = s[i];
            
            int r = i % M;
            int row = r < numRows ? r : M - r;
            
            cache[row] += ch;
        }
        
        string result;
        for (auto row : cache)
        {
            result += row;
        }
        
        return result;
    }
};