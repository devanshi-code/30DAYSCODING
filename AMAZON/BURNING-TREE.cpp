class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*, Node*> parent;

        //find target
        queue<Node*> q1;
        q1.push(root);

        Node* node;

        while(!q1.empty()) {
            node = q1.front();
            q1.pop();
            
            if(node->data == target) {
                break;
            }

            if(node->left != NULL) {
                parent[node->left] = node;
                q1.push(node->left);
            }

            if(node->right != NULL) {
                parent[node->right] = node;
                q1.push(node->right);
            }
        }

        // find largest dist
        queue<Node*> q2;
        q2.push(node);
        q2.push(NULL);

        unordered_map<Node*, bool> queued;
        int dist = -1;

        while(!q2.empty()) {

            node = q2.front();
            q2.pop();

            if(node == NULL) {
                ++dist;
                if(!q2.empty()) {
                    q2.push(NULL);
                }
                continue;
            }

            if(node->left != NULL && !queued.count(node->left)) {
                q2.push(node->left);
                queued[node->left] = true;
            }

            if(node->right != NULL && !queued.count(node->right)) {
                q2.push(node->right);
                queued[node->right] = true;
            }

            if(parent.count(node) && !queued.count(parent[node])) {
                q2.push(parent[node]);
                queued[parent[node]] = true;
            }
        }

        return dist;
    }
};