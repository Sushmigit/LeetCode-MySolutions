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
    Node*dfs(Node* cur,unordered_map<Node*,Node*> &mpp)
    {
        Node*clone = new Node(cur->val);
        mpp[cur]=clone;
        vector<Node*>neighbours;
        for(auto it:cur->neighbors)
        {
            if(mpp.find(it)!=mpp.end())
                neighbours.push_back(mpp[it]);
            else
                neighbours.push_back(dfs(it,mpp));
        }
        clone->neighbors = neighbours;
        return clone;
    }
    Node* cloneGraph(Node* node) { //TC->O(v+E) SC->O(V)
        unordered_map<Node*,Node*>mpp;
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0)
        {
            Node*clone = new Node(node->val);
            return clone;
        }
        return dfs(node,mpp);
    }
};