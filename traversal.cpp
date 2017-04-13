#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <numeric>
#include "ArgumentManager.h"

using namespace std;

template <long int T_begin, long int T_end>
class range_class {
  public:
    class iterator : public std::iterator<std::random_access_iterator_tag, long int, long int> {
        friend class range_class;

      public:
        long int operator*() const { return i_; }

        const iterator &operator++() {
            if (T_begin > T_end)
                --i_;
            else
                ++i_;
            return *this;
        }

        const iterator &operator--() {
            if (T_begin > T_end)
                ++i_;
            else
                --i_;
            return *this;
        }

        iterator operator++(int) {
            iterator copy(*this);
            if (T_begin > T_end)
                --i_;
            else
                ++i_;
            return copy;
        }

        iterator operator--(int) {
            iterator copy(*this);
            if (T_begin > T_end)
                ++i_;
            else
                --i_;
            return copy;
        }

        iterator &operator=(const iterator &other) {
            this->i_ = other.i_;
            return *this;
        }

        bool operator==(const iterator &other) const { return i_ == other.i_; }
        bool operator!=(const iterator &other) const { return i_ != other.i_; }
        bool operator<(const iterator &other) const { return i_ < other.i_; }
        bool operator>(const iterator &other) const { return i_ > other.i_; }
        bool operator<=(const iterator &other) const { return i_ <= other.i_; }
        bool operator>=(const iterator &other) const { return i_ >= other.i_; }

        iterator &operator+(const long int &add) const {
            iterator copy(*this);
            auto t = std::abs(T_begin - T_end);
            auto v = std::abs(this->i_ - T_begin);
            auto val = ((v + add) % t) < 0 ? ((v + add) % t) + t : ((v + add) % t);
            if (T_begin > T_end)
                copy.i_ = T_begin - val;
            else
                copy.i_ = T_begin + val;
            return copy;
        }

        iterator &operator+=(const long int &add) {
            auto t = std::abs(T_begin - T_end);
            auto v = std::abs(this->i_ - T_begin);
            auto val = ((v + add) % t) < 0 ? ((v + add) % t) + t : ((v + add) % t);
            if (T_begin > T_end)
                this->i_ = T_begin - val;
            else
                this->i_ = T_begin + val;
            return *this;
        }

        iterator &operator-(const long int &add) const {
            iterator copy(*this);
            auto t = std::abs(T_begin - T_end);
            auto v = std::abs(this->i_ - T_begin);
            auto val = ((v - add) % t) < 0 ? ((v - add) % t) + t : ((v - add) % t);
            if (T_begin > T_end)
                copy.i_ = T_begin - val;
            else
                copy.i_ = T_begin + val;
            return copy;
        }

        iterator &operator-=(const long int &add) {
            auto t = std::abs(T_begin - T_end);
            auto v = std::abs(this->i_ - T_begin);
            auto val = ((v - add) % t) < 0 ? ((v - add) % t) + t : ((v - add) % t);
            if (T_begin > T_end)
                this->i_ = T_begin - val;
            else
                this->i_ = T_begin + val;
            return *this;
        }

        long int &operator[](const long int &n) const {
            auto t = std::abs(T_begin - T_end);
            auto v = std::abs(this->i_ - T_begin);
            auto val = ((v + n) % t) < 0 ? ((v + n) % t) + t : ((v + n) % t);
            if (T_begin > T_end)
                return (T_begin - val);
            else
                return (T_begin + val);
        }

      protected:
        iterator(long int start) : i_(start) {}

      private:
        unsigned long i_;
    };

    iterator begin() const { return iterator(T_begin); }
    iterator end() const { return iterator(T_end); }
};

template <long int T_begin, long int T_end>
const range_class<T_begin, T_end>
range() {
    return range_class<T_begin, T_end>();
}

int search(vector<string> & inorder, vector<string> & preorder, int size) {
	for (int unsigned i = 0; i < size; i++) {
		if (inorder.at(i) == preorder.at(0)) {
            return i;
		}
	}
    return -1;
}

void printPostOrder(vector<string> & inorder, vector<string> & preorder, int size) {
    // The first element in pre[] is always root, search it
    // in in[] to find left and right subtrees
    //int root = search(inorder, preorder, size);

    //// If left subtree is not empty, print left subtree
    //if (root != 0){
    //    printPostOrder(inorder, preorder + 1, root);
    //}

    //// If right subtree is not empty, print right subtree
    //if (root != size - 1)
    //    printPostOrder(inorder + root + 1, preorder + root + 1, size - root - 1);

    //// Print root
    //cout << preorder.at(0) << " ";
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

	int size = vinorder.size();

    for (auto i : range<10, -1>()) {
        // stuff with i
        cout << i << endl;
    }
    auto one = range<10, -1>();
    cout << accumulate(one.begin(), one.end(), 0) << endl;

    printPostOrder(vinorder, vpreorder, size);

	getchar();

    return 0;
}