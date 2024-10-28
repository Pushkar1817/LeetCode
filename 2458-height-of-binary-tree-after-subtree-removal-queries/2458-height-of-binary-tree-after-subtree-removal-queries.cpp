/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxHeiAfterRemo[100001];
    int currMaxHeight = 0;
    void ltr(TreeNode*root, int currHeight){
        if(!root){
            return;
        }
        maxHeiAfterRemo[root->val] = currMaxHeight;
        currMaxHeight = max(currMaxHeight,currHeight);
        ltr(root->left,currHeight+1); 
        ltr(root->right,currHeight+1); 
    }
    void rtl(TreeNode*root, int currHeight){
        if(!root){
            return;
        }
        maxHeiAfterRemo[root->val] = max(maxHeiAfterRemo[root->val],currMaxHeight);
        currMaxHeight = max(currMaxHeight,currHeight);
        rtl(root->right,currHeight+1); 
        rtl(root->left,currHeight+1); 
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        ltr(root,0);
        currMaxHeight = 0;
        rtl(root,0);

        vector<int>ans(queries.size(),0);

        for(int i = 0 ;i< queries.size() ;i++)
            ans[i] = maxHeiAfterRemo[queries[i]];
        
        return ans;
    }
};