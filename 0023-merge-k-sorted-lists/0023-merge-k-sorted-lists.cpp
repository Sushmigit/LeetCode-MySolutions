/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeList(ListNode*l1,ListNode*l2)
    {
        ListNode*res = new ListNode(-1);
        ListNode*temp = res;
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val <= l2->val)
            {
                temp->next = l1;
                l1=l1->next;
                temp = temp->next;
            }
            else
            {
                temp->next = l2;
                l2=l2->next;
                temp = temp->next;
            }
        }
        while(l1!=NULL)
        {
            temp->next = l1;
            l1=l1->next;
            temp = temp->next;
        }
        while(l2!=NULL)
        {
            temp->next = l2;
            l2=l2->next;
            temp = temp->next;
        }
        return res->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i;
        if(lists.size()==0)
            return NULL;
        ListNode*root = lists[0];
        for(i=1;i<lists.size();i++)
        {
            root = mergeList(root,lists[i]);
        }
        return root;
    }
};