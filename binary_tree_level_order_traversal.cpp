#include <cmath>
#include <vector>

using namespace std;
//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //master queue to push all nodes
        vector<vector<int>> result;
        vector<TreeNode*> tree;
        tree.push_back(root);
        int currNode = 0;

        if(!root) return result;
        
        //make pointer iterate through queue while noting down values
        while(1){
            if(!tree[currNode]){
                currNode++;
                if(currNode >= tree.size()){
                    break;
                }
                continue;
            }
            tree.push_back(tree[currNode]->left);
            tree.push_back(tree[currNode]->right);
            currNode++;
        }
        
        //take off trailing nulls
        int nullSize = 0;
        while(!tree[tree.size()-nullSize-1]){
            nullSize++;
        }
        
        
        //make second vector store levels 
        int currLevel = 0;
        int endTree = tree.size()-nullSize;
        if(endTree == 1){
            vector<int> node;
            node.push_back(root->val);
            result.push_back(node);
            return result;
        }
    
        for(int i=0; i<endTree;){
            //if null then continue
            //inner loop makes vector for level
            //need to increase i as well
            vector<int> level;
            for(int j=0; j<pow(2, currLevel); j++){
                if(tree[i+j]) level.push_back(tree[i+j]->val);
            }
            result.push_back(level);
            i += pow(2, currLevel);
            currLevel++;
        }
        
        return result;
    }
};

int main(){
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node4 = new TreeNode(4, node5, nullptr);
    TreeNode* node3 = new TreeNode(3, node4, nullptr);
    TreeNode* node2 = new TreeNode(2, node3, nullptr);
    TreeNode* root = new TreeNode(1, node2, nullptr);

    Solution sol1;
    sol1.levelOrder(root);

    //TreeNode* node15 = new TreeNode(15);
    //TreeNode* node7 = new TreeNode(7);
    //TreeNode* node20 = new TreeNode(20, node15, node7);
    //TreeNode* node9 = new TreeNode(9);
    //TreeNode* root = new TreeNode(3, node9, node20);

    //sol1.levelOrder(root);
    //sol1.levelOrder(node15);

    //TreeNode* node2 = new TreeNode(2);   
    //TreeNode* node1 = new TreeNode(1, node2, nullptr); 
    //sol1.levelOrder(node1);

    return 0;
}