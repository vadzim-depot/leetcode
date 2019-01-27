class Solution 
{
public:
    int myAtoi(string str) 
    {
        int res = 0, carry = 1;
        size_t temp = 0, count = str.size();
        
        int i = 0;
        while ((str[i] == ' ') && (i < count))
        {
            ++i;
        }
        
        if (str[i] == '-')
        {
            carry = -1;
            ++i;
        }
        else if (str[i] == '+')
        {
            ++i;
        }
        
        for(; i < count; i++)
        {
            int val = str[i] - '0';
            
            if ((val < 0) || (val > 9))
            {
                break;
            }
            
            temp = 10 * temp + val;
        
            if (temp > INT_MAX)
            {
                return carry == -1 ? INT_MIN : INT_MAX;
            }
        }
        
        return carry * temp;
    }
};