class Solution {
  public:
    void preorder(Node* root, vector<int>& v) {
        if (!root) {
            v.push_back(-1);
            return;
        }

        v.push_back(root->data);
        preorder(root->left, v);
        preorder(root->right, v);
    }

    vector<int> serialize(Node *root) {
        vector<int> v;
        preorder(root, v);

        // for (auto x: v) cout << x << " ";

        return v;
    }

    Node* dHelper(vector<int>& a, int& i) {
        if (i > a.size()) return NULL;

        if (a[i] == -1) {
            i++;
            return NULL;
        }

        Node* root = new Node(a[i++]);


        root->left = dHelper(a, i);
        root->right = dHelper(a, i);

        return root;
    }

    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &a) {
        int i = 0;
        return dHelper(a, i);
    }

};