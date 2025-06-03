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
    int maxDepth(Node* root) {
       vector<vector<int>>res;
       int currLevel=0;
        if(!root)return currLevel;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int level_size=q.size();
           
            for(int i=0;i<level_size;++i){
                Node*curr=q.front();
                q.pop();
                
                for(Node*child:curr->children)
{
    q.push(child);

}            }
currLevel++;

        }
        return currLevel;
    }
};