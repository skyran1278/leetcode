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
const preorderTraversal = (root) => {
  const arr = [];
  if (root !== null) {
    arr.push(root.val);
    arr.push(...preorderTraversal(root.left));
    arr.push(...preorderTraversal(root.right));
  }
  return arr;
};

const root = new TreeNode(1);
root.right = new TreeNode(2);
root.right.left = new TreeNode(3);

// const arrayToTreeNode = (arr) => {
//   if (arr[0] !== null) {

//   }

// }

console.log(preorderTraversal(root));
