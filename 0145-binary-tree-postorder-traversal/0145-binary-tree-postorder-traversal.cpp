class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // Vector to store the result of postorder traversal
        vector<int> result;
        // Stack to facilitate the traversal of nodes
        stack<TreeNode*> traversalStack;
        TreeNode* currentNode = root;

        // Traverse the tree while there are nodes to process
        while (currentNode != nullptr || !traversalStack.empty()) {
            if (currentNode != nullptr) {
                // Add current node's value to result list before going to its
                // children
                result.push_back(currentNode->val);
                // Push current node onto the stack
                traversalStack.push(currentNode);
                // Move to the right child
                currentNode = currentNode->right;
            } else {
                // Pop the node from the stack and move to its left child
                currentNode = traversalStack.top();
                traversalStack.pop();
                currentNode = currentNode->left;
            }
        }
        // Reverse the result list to get the correct postorder sequence
        reverse(result.begin(), result.end());
        return result;
    }
};