class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> children, parents;
        unordered_map<int, vector<pair<int, int>>> parentToChildren;

        for (auto& d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];
            parents.insert(parent);
            parents.insert(child);
            children.insert(child);
            parentToChildren[parent].emplace_back(child, isLeft);
        }

        for (auto it = parents.begin(); it != parents.end();) {
            if (children.find(*it) != children.end()) {
                it = parents.erase(it);
            } else {
                ++it;
            }
        }
        TreeNode* root = new TreeNode(*parents.begin());

        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* parent = queue.front();
            queue.pop();
            for (auto& childInfo : parentToChildren[parent->val]) {
                int childValue = childInfo.first, isLeft = childInfo.second;
                TreeNode* child = new TreeNode(childValue);
                queue.push(child);
                if (isLeft == 1) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
            }
        }

        return root;
    }
};