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
Node* dfs(Node* node,map<int,Node*>&mp)
{
    if(mp[node->val]) return mp[node->val];
    Node* n=new Node(node->val);
    mp[n->val]=n;
    for(auto e:node->neighbors) n->neighbors.push_back(dfs(e,mp));
    return n;
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        map<int,Node*> mp;
        return dfs(node,mp);
    }
};