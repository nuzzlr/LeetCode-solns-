class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;

        root = processNode(root, toDeleteSet, forest);
        if (root) {
            forest.push_back(root);
        }

        return forest;
    }

private:
    TreeNode* processNode(TreeNode* node, unordered_set<int>& toDeleteSet,
                          vector<TreeNode*>& forest) {
        if (!node) {
            return nullptr;
        }

        node->left = processNode(node->left, toDeleteSet, forest);
        node->right = processNode(node->right, toDeleteSet, forest);

        if (toDeleteSet.find(node->val) != toDeleteSet.end()) {
            
            if (node->left) {
                forest.push_back(node->left);
            }
            if (node->right) {
                forest.push_back(node->right);
            }
            delete node;
            return nullptr;
        }

        return node;
    }
};