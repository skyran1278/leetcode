/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
function TreeNode(val) {
  this.val = val;
  this.left = null;
  this.right = null;
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
const maxDepth = (root) => {
  let ans = 0;

  const recursive = (node, depth) => {
    if (!node) {
      ans = Math.max(ans, depth);
      return;
    }
    recursive(node.left, depth + 1);
    recursive(node.right, depth + 1);
  };

  recursive(root, 0);

  return ans;
};

const root = new TreeNode(3);
root.left = new TreeNode(9);
root.right = new TreeNode(20);
root.right.left = new TreeNode(15);
root.right.right = new TreeNode(7);

console.log(maxDepth(root));
