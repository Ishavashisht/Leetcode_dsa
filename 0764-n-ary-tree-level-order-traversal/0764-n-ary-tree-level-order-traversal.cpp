/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        if(!root)return res;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int level_size=q.size();
            vector<int>currLevel;
            for(int i=0;i<level_size;++i){
                Node*curr=q.front();
                q.pop();
                currLevel.push_back(curr->val);
                for(Node*child:curr->children)
{
    q.push(child);

}            }
res.push_back(currLevel);
        }
        return res;
    }
};