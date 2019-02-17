class Solution 
{
public:
    bool isValid(string s) 
    {
        static map<char, char> ParMap = 
        {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };
        
        stack<char> temp;
        for (size_t i = 0; i < s.size(); ++i)
        {
            char ch = s[i];
            if (ParMap.contains(ch))
            {
                temp.push(ch);
            }
            else if (temp.size() == 0)
            {
                return false;
            }
            else if (temp.size() > 0)
            {
                char ch0 = temp.top();
                temp.pop();
                if (ParMap[ch0] != ch)
                {
                    return false;
                }
            }
        }
        
        return temp.size() == 0;
    }
};