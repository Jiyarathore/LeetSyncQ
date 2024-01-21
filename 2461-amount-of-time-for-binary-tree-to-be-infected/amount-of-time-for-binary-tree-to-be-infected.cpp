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
public:

// Graph representation of tree
     unordered_map<int, vector<int>>graph;

    int amountOfTime(TreeNode* root, int start) {
        // Build graph representation of tree using dfs
        constructGraph(root);

        queue<int>q;
        q.push(start);

        unordered_set<int>visited;

        int mint=-1;

        while(!q.empty()){
            mint++;

            for(int levelSize=q.size();levelSize>0;levelSize--){
                int currentNode=q.front();
                q.pop();
                visited.insert(currentNode);

                for(int adjacentNode: graph[currentNode]){
                    if(!visited.count(adjacentNode)){
                        q.push(adjacentNode);
                    }
                }
            }
        }
        return mint;
    }


    void constructGraph(TreeNode* root){
        if(!root) return;

        // connect current node with its left child(if xists)
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        // right
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        // continue DFS with chilren 
        constructGraph(root->left);
        constructGraph(root->right);
    } 

};