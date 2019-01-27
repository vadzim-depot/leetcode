class Solution 
{
public:
    int reverse(int x) 
    {
        if ((x != 0) && (x < INT_MAX) && (x > INT_MIN))
        {
            int carry = x / abs(x);
            size_t res = 0;

            x = abs(x);
        
            while (x > 0)
            {
                res = 10 * res + x % 10;
                x = x / 10;
            }        

            if (res > INT_MAX)
            {
                res = 0;
            }
            
            return carry * res;
        }
        
        return 0;
    }
};