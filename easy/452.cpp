/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * 注意处理重复元素和头结点
 *
 */

class Solution {
public:
    /*
     * @param head: a ListNode
     * @param val: An integer
     * @return: a ListNode
     */
    ListNode * removeElements(ListNode * head, int val) {
        // write your code here
        ListNode *temp = NULL;
        ListNode *p = NULL ;
        
        if( head != NULL && head->next != NULL){
            temp = head->next ;
            p = head ;
        }
        
        while(temp != NULL ){
                
            if(temp->val == val){
                p->next = temp->next ;
                delete temp ;
                temp = p->next;
            }else{
                p = p->next ;
                temp = temp->next ;
            }
        }
        
        if(head != NULL && head->val ==val ){
             p = head ;
             head= head->next;
             delete p ;
        }
           
           
        return head ;
    }
};
