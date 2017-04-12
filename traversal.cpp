#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <deque>
#include <vector>
#include "ArgumentManager.h"

using namespace std;

class BigNumber {
public:
    BigNumber() {}

    ~BigNumber(){ /*cout << "BN ~" << endl;*/ }

    BigNumber(string str) {
		int index = 0;
        while (index < str.size()) {
			if (!isspace(str.at(index))) {
				int length = 1;
				while (isspace(str.at(length)) == 0) {
					length++;
				}
				data.push_back(str.substr(index, length));
			}
            index++;
        }
    }

    BigNumber(BigNumber const & other) {
        //cout << "BN copy" << endl;
        data = other.data;
    }

    BigNumber & operator= (BigNumber const & other) {
        //cout << "BN =" << endl;
        data = other.data;
        return *this;
    }

    void swap(BigNumber & other) {
        data.swap(other.data);
    }

    void postorder(BigNumber & inorder, BigNumber & preorder) {
		string root = preorder.data.at(0);
		cout << root << endl;
        //find first element of preorder in inorder
        //Everything to the left of inorder is in the left subtree
        //Everything to the right of inorder is in the right subtree
        //place first element of preorder into a stack
    }

private:
    deque<string> data;
};

int size(string str) {
    int size = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (!isspace(str.at(i))) {
			size++;
		}
	}
    return size;
}

//Function from http://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/
// A utility function to search x in arr[]
// int search(int arr[], int x, int n) {
//     for (int i = 0; i < n; i++)
//         if (arr[i] == x)
//             return i;
//     return -1;
// }

// Prints postorder traversal from given inorder and preorder traversals
// Function from http://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/
// void printPostOrder(int in[], int pre[], int n) {
//     // The first element in pre[] is always root, search it
//     // in in[] to find left and right subtrees
//     int root = search(in, pre[0], n);

//     // If left subtree is not empty, print left subtree
//     if (root != 0)
//         printPostOrder(in, pre + 1, root);

//     // If right subtree is not empty, print right subtree
//     if (root != n - 1)
//         printPostOrder(in + root + 1, pre + root + 1, n - root - 1);

//     // Print root
//     cout << pre[0] << " ";
// }

int main(int argc, char *argv[]) {
    // if(argc < 2) {
    //     //std::cerr("Usage: traversal \"preorder=xyz.txt;inorder=xyz.txt\"\n");
    //     return 1;
    // }
    // ArgumentManager am(argc, argv);
    // string file = am.get("preorder");
    // string file2 = am.get("inorder");
    // ifstream infile(file, ios::in);
    // ifstream infile2(file2, ios::in);
    ifstream infile("preorder1.txt", ios::in);
    ifstream infile2("inorder1.txt", ios::in);

    string preorder;
    if(!infile){
        cout << "Cannot open preorder input file. Program terminates!!!" << endl;
        return 1;
    }
    while(getline(infile, preorder)){
        if(preorder.empty() || preorder.at(0) == '\n') { continue; }
    }
	infile.close();

    string inorder;
    if(!infile2) {
        cout << "Cannot open inorder input file. Program terminates!!!" << endl;
        return 1;
    }
    while(getline(infile2, inorder)) {
        if(inorder.empty() || inorder.at(0) == '\n') { continue; }
    }
    infile2.close();

	stringstream ss(preorder);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;
	vector<string> vpreorder(begin, end);
	copy(vpreorder.begin(), vpreorder.end(), ostream_iterator<string>(cout, "\n"));

    stringstream ss(inorder);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;
	vector<string> vinorder(begin, end);
	copy(vinorder.begin(), vinorder.end(), ostream_iterator<string>(cout, "\n"));

	vpreorder.

    // int n = sizeof(in) / sizeof(in[0]);
    // cout << "Postorder traversal " << endl;
    // printPostOrder(in, pre, n);

    // BigNumber bignumberinorder(inorder);
	// BigNumber bignumberpreorder(preorder);
	// BigNumber a;
	// a.postorder(bignumberinorder, bignumberpreorder);

	getchar();

    return 0;
}