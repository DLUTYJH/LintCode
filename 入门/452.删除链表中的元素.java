/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

//注意重复元素
public class Solution {
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    public ListNode removeElements(ListNode head, int val) {
        // Write your code here
        
        ListNode temp = null;
        ListNode p = null ;
        
        if( head != null && head.next != null){
            temp = head.next ;
            p = head ;
        }
        
        while(temp != null ){
                
            if(temp.val == val){
                p.next = temp.next ;
                
                temp = p.next;
            }else{
                p = p.next ;
                temp = temp.next ;
            }
        }
        
        if(head != null && head.val ==val ) head= head.next;
           
           
        return head ;
    }
}
