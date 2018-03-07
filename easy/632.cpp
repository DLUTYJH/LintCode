class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return the max node
     */
    TreeNode* maxNode(TreeNode* root) {
        // Write your code here
        
        using std::queue;
        
        queue<TreeNode *> node;
        TreeNode* p = root;
        int temp = 0 ;
        TreeNode* t = NULL ;
        
        if(p != NULL){
            temp = p->val ;
            node.push(p);
        }
        
        while(!node.empty()){
            p = node.front();
            //if()
            if(temp <= p->val ){
                temp = p->val ;
                t =p ;
            }
            node.pop();
            
            if(p->left != NULL) node.push(p->left);
            
            if(p->right != NULL) node.push(p->right);
        }
        
        return t ;
    }
};
