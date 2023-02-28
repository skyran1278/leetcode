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

  const recurssive = (node, depth) => {
    if (!node) {
      ans = Math.max(ans, depth);
      return;
    }
    recurssive(node.left, depth + 1);
    recurssive(node.right, depth + 1);
  };

  recurssive(root, 0);

  return ans;
};

const root = new TreeNode(3);
root.left = new TreeNode(9);
root.right = new TreeNode(20);
root.right.left = new TreeNode(15);
root.right.right = new TreeNode(7);

console.log(maxDepth(root));
