/*prints the post order traversal of the 
tree */
#include <iostream>
#include <stack>
#include <map>

using namespace std;

//Function from http://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/
void BinaryTreeFromPreorderInorderHelper(int preorder[], int preorderStart, int preorderEnd,
                                         int inorderStart, int inorderEnd, map<int, int> &nodeToInorderIdx,
                                         stack<int> &postOrderStack) {
    if (preorderEnd <= preorderStart || inorderEnd <= inorderStart)
        return;

    int rootInorderIndex = nodeToInorderIdx[preorder[preorderStart]];
    int leftSubtreeSize = rootInorderIndex - inorderStart;

    postOrderStack.push(preorder[preorderStart]);

    BinaryTreeFromPreorderInorderHelper(preorder, preorderStart + 1 + leftSubtreeSize, preorderEnd, rootInorderIndex + 1, inorderEnd, nodeToInorderIdx, postOrderStack);
    BinaryTreeFromPreorderInorderHelper(preorder, preorderStart + 1, preorderStart + leftSubtreeSize + 1, inorderStart, rootInorderIndex, nodeToInorderIdx, postOrderStack);
}

// Function from http://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/
void printPostOrder(int in[], int pre[], int n) {
    map<int, int> nodeToInorderIdx;

    for (int i = 0; i < n; i++) {
        nodeToInorderIdx.emplace(in[i], i);
    }

    stack<int> postOrderStack;

    BinaryTreeFromPreorderInorderHelper(pre, 0, n, 0, n, nodeToInorderIdx, postOrderStack);

    while (!postOrderStack.empty()) {
        cout << postOrderStack.top() << " ";
        postOrderStack.pop();
    }
}

int main(int argc, char * argv[]) {
    // if(argc < 2) {
    //     //std::cerr("Usage: traversal \"preorder=xyz.txt;inorder=xyz.txt\"\n");
    //     return 1;
    // }
    // ArgumentManager am(argc, argv);
    // std::string fpreorder = am.get("preorder");
    // std::string finorder = am.get("inorder");
    // ifstream fspreorder(fpreorder, ios::in);
    // ifstream fsinorder(finorder, ios::in);
    ifstream fspreorder("preorder1.txt", ios::in);
    ifstream fsinorder("inorder1.txt", ios::in);
    string spreorder;
    string sinorder;    


    // int in[] = {1,2,3,4,5,6,7,8};
    // int pre[] = {5,2,1,4,3,7,6,8};
    // int n = sizeof(in) / sizeof(in[0]);
    // cout << "\tPostorder traversal " << endl;
    // cout << "\t";
    // printPostOrder(in, pre, n);
    // cout << endl;
    return 0;
}