// A binary tree and symmetric when you can
// draw a line down the root and each element
// in the left subtree is the mirror image of
// that in the right subtree
//          EG:
//                1
//        2                2
//    3       4        4       3
// 5     6                   6     5
//
// inorder left: 5,3,6,2,4
// right would be : 4,2,6,3,5
//

struct binaryNode {
    int data;
    binaryNode * left;
    binaryNode * right;
};

struct binaryTree {
  binaryNode * root;
};

// Idea: inOrder traverse left subtree,
// inOrder traverse right subtree, store
// data from each traverse in an array,
// check to see if array of right subtree
// data is == array of left subtree data reversed

bool checkSymmetric(binaryTree * root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
        return true;
    }
    checkSymmetricHelper(root->left, root->right);
}

bool checkSymmetricHelper(binaryNode * leftSubTree, binaryNode * rightSubTree)
{
    if(leftSubTree == nullptr && rightSubTree == nullptr)
    {
        return true;
    }
    else if(!leftSubTree || !rightSubTree)
    {
        return false;
    }
    else if (leftSubTree->data == rightSubTree->data)
    {
        checkSymmetricHelper(leftSubtree->left, rightSubTree->right);
        checkSymmetricHelper(leftSubtree->right, rightSubTree->left);
    }
    return false; //one side not null, one side null
}
