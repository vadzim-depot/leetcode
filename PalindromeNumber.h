class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if (x < 0)
        {
            return false;
        }
        
        int x0 = x, x1 = 0;
        while (x0 > 0)
        {
            int r = x0 % 10;
            x0 = x0 / 10;
            x1 = 10*x1 + r;
        }
        
        if (x1 == x)
        {
            return true;
        }
        
        return false;
    }
};