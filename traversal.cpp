#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <numeric>
#include "ArgumentManager.h"

using namespace std;

// A utility function to search x in arr[] of size n
int search(vector<string>::iterator iti, string x, int size) {
	for (int i = 0; i < size; i++) {
		if (iti[i] == x) {
            return i;
		}
	}
	return -1;
}

// Prints postorder traversal from given inorder and preorder traversals
void printPostOrder(vector<string>::iterator iti, vector<string>::iterator itp, int size) {
    // The first element in pre[] is always root, search it
    // in in[] to find left and right subtrees
	int root = search(iti, itp[0], size);

    // If left subtree is not empty, print left subtree
    if (root != 0) {
        printPostOrder(iti, itp + 1, root);
    }

    // If right subtree is not empty, print right subtree
	if (root != size - 1) {
        printPostOrder(iti + root + 1, itp + root + 1, size - root - 1);
	}

    // Print root
    cout << itp[0] << " ";
}

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

    stringstream ss2(inorder);
	istream_iterator<string> begin2(ss2);
	istream_iterator<string> end2;
	vector<string> vinorder(begin2, end2);

	vector<string>::iterator iti = vinorder.begin();
	vector<string>::iterator itp = vpreorder.begin();

	int size = vinorder.size();

    printPostOrder(iti, itp, size);
	cout << endl;
    return 0;
}