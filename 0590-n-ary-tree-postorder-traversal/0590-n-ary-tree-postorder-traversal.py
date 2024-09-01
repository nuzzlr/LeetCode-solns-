class Solution:
    def postorder(self, root: "Node") -> List[int]:
        result = []

        # If the root is None, return the empty list
        if root is None:
            return result

        node_stack = [root]

        # Traverse the tree using the stack
        while node_stack:
            current_node = node_stack.pop()
            result.append(current_node.val)
            # Push all the children of the current node to the stack
            for child in current_node.children:
                node_stack.append(child)

        # Reverse the result list to get the correct postorder traversal
        result.reverse()
        return result