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
 * @return {number[]}
 */
const postorderTraversal = (root) => {
  const arr = [];
  const traverasl = (node) => {
    if (node !== null) {
      traverasl(node.left);
      traverasl(node.right);
      arr.push(node.val);
    }
  };
  traverasl(root);
  return arr;
};

const root = new TreeNode(1);
root.right = new TreeNode(2);
root.right.left = new TreeNode(3);

// const arrayToTreeNode = (arr) => {
//   if (arr[0] !== null) {

//   }

// }

console.log(postorderTraversal(root));
