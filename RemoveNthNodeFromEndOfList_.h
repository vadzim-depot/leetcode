/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if (head == 0)
        {
            return 0;
        }
        
        ListNode* ret = head;
        vector<ListNode*> temp;
        
        ListNode* node = head;
        while(node)
        {
            temp.push_back(node);
            node = node->next;
        }
        
        size_t count = temp.size();
        size_t index = count - n;
        
        if (index == 0)
        {
            ret = head->next;
        }
        else if (index < count)
        {
            temp[index-1]->next = temp[index]->next;
        }
        
        return ret;
    }
};