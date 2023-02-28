from collections import defaultdict


class FindElements:

    def __init__(self, root: TreeNode):
        self.d = defaultdict(bool)
        self._dfs(root, 0)

    def _dfs(self, node, value):
        if node:
            node.val = value
            self.d[value] = True
            self._dfs(node.left, node.val * 2 + 1)
            self._dfs(node.right, node.val * 2 + 2)

    def find(self, target: int) -> bool:
        if target in self.d:
            return True
        return False
