/*prints the post order traversal of the 
tree */
#include <iostream>
#include <stack>
#include <map>
#include <fstream>
#include "ArgumentManager.h"

using namespace std;

// //Function from http://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/
// void BinaryTreeFromPreorderInorderHelper(string preorder[], int preorderStart, int preorderEnd,
//                                          int inorderStart, int inorderEnd, map<string, string> &nodeToInorderIdx,
//                                          stack<int> &postOrderStack) {
//     if (preorderEnd <= preorderStart || inorderEnd <= inorderStart)
//         return;

//     string rootInorderIndex = nodeToInorderIdx[preorder[preorderStart]];
//     string leftSubtreeSize = rootInorderIndex - inorderStart;

//     postOrderStack.push(preorder[preorderStart]);

//     BinaryTreeFromPreorderInorderHelper(preorder, preorderStart + 1 + leftSubtreeSize, preorderEnd, rootInorderIndex + 1, inorderEnd, nodeToInorderIdx, postOrderStack);
//     BinaryTreeFromPreorderInorderHelper(preorder, preorderStart + 1, preorderStart + leftSubtreeSize + 1, inorderStart, rootInorderIndex, nodeToInorderIdx, postOrderStack);
// }

// // Function from http://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/
// void printPostOrder(string in[], string pre[], int n) {
//     map<string, string> nodeToInorderIdx;

//     for (int i = 0; i < n; i++) {
//         nodeToInorderIdx.emplace(in[i], i);
//     }

//     stack<int> postOrderStack;

//     BinaryTreeFromPreorderInorderHelper(pre, 0, n, 0, n, nodeToInorderIdx, postOrderStack);

//     while (!postOrderStack.empty()) {
//         cout << postOrderStack.top() << " ";
//         postOrderStack.pop();
//     }
// }

int main(int argc, char * argv[]) {
    if(argc < 2) {
        //std::cerr("Usage: traversal \"preorder=xyz.txt;inorder=xyz.txt\"\n");
        return 1;
    }
    ArgumentManager am(argc, argv);
    string fpreorder = am.get("preorder");
    string finorder = am.get("inorder");
    ifstream fspreorder(fpreorder, ios::in);
    ifstream fsinorder(finorder, ios::in);
    // ifstream fspreorder("preorder1.txt", ios::in);
    // ifstream fsinorder("inorder1.txt", ios::in);
    string spreorder;
    string sinorder;

    cout << "\tPreorder: ";
    while(getline(fspreorder, spreorder)) {
        if(spreorder.empty() || spreorder.at(0) == '\n') { continue; }
        cout << spreorder << " ";
    }
    cout << endl;

    cout << "\tInorder: ";
    while(getline(fsinorder, sinorder)) {
        if(sinorder.empty() || sinorder.at(0) == '\n') { continue; }
        cout << sinorder << " ";
    }
    cout << endl;

    int size_p = sizeof(spreorder) / sizeof(spreorder[0]);
    int size_i = sizeof(sinorder) / sizeof(sinorder[0]);

    cout << "\tSize of preorder: " << size_p << endl;
    cout << "\tSize of inorder: " << size_i << endl;
    
    

    // int in[] = {1,2,3,4,5,6,7,8};
    // int pre[] = {5,2,1,4,3,7,6,8};
    // int n = sizeof(in) / sizeof(in[0]);
    // cout << "\tPostorder traversal " << endl;
    // cout << "\t";
    // printPostOrder(in, pre, n);
    // cout << endl;
    return 0;
}