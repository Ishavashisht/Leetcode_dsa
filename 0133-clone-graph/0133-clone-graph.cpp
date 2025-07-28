/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
unordered_map<Node*,Node*>cloneMap;
    Node* cloneGraph(Node* node) {
     if(!node) return nullptr;
     if(cloneMap.find(node)!=cloneMap.end())return cloneMap[node];
     Node*cloned=new Node(node->val);
     cloneMap[node]=cloned;
     for(Node*child:node->neighbors){
        cloned->neighbors.push_back(cloneGraph(child));
     }  
     return cloned;
    }
};