class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        static map<char, string> DigToN = 
        {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, 
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, 
            {'8', "tuv"}, {'9', "wxyz"}    
        };
        
        vector<string> ret;
        
        size_t len = digits.size();
        if (len == 0)
        {
            return ret;
        }
        else if (len == 1)
        {
            string s = DigToN[digits[0]];
            for (size_t i = 0; i < s.size(); ++i)
            {
                ret.push_back(string(1, s[i]));
            }
            
            return ret;
        }
        else if (len == 2)
        {
            string s0 = DigToN[digits[0]];
            string s1 = DigToN[digits[1]];
            
            for (size_t i = 0; i < s0.size(); ++i)
            {
                for (size_t j = 0; j < s1.size(); ++j)
                {
                    string c = string() + s0[i] + s1[j];
                    ret.push_back(c);
                }
            }          
            
            return ret;
        }
        
        size_t d = len / 2;
        
        string subdig0 = digits.substr(0, d);
        string subdig1 = digits.substr(d, len);
        
        vector<string> comb0 = letterCombinations(subdig0);
        vector<string> comb1 = letterCombinations(subdig1);
        
        for (size_t i = 0; i < comb0.size(); ++i)
        {
            for (size_t j = 0; j < comb1.size(); ++j)
            {
                ret.push_back(comb0[i] + comb1[j]);
            }
        }
        
        return ret;
    }
};