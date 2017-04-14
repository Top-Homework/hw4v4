# hw4v4
Simple C++ program to print postorder traversal from preorder and inorder traversals. I learned how to use iterators on this project and reinforced vectors.

## Iterators
* [Documentation](http://www.cplusplus.com/reference/iterator/)
* An iterator is literally a pointer. It points to some element in a range of elements such as an array or a container like a list, BUT not all iterators have the same functionality as pointers. Iterators are classified into five different categories
* Types of iterators
	1. Input
	2. Output
		* Input and output iterators are the most limited types of iterators: they can perform sequential single-pass input or output operations.
	3. Forward
		* Forward iterators have all the functionality of input iterators and -if they are not constant iterators- also the functionality of output iterators, although they are limited to one direction in which to iterate through a range (forward). All standard containers support at least forward iterator types.
	4. Bidirectional
		* Bidirectional iterators are like forward iterators but can also be iterated through backwards.
	5. Random Access
		* Random-access iterators implement all the functionality of bidirectional iterators, and also have the ability to access ranges non-sequentially: distant elements can be accessed directly by applying an offset value to an iterator without iterating through all the elements in between. These iterators have a similar functionality to standard pointers (pointers are iterators of this category).
* Notes
	* This [video](https://youtu.be/vO2AlrBf5rQ) provided a great foundation on iterators.
	* Chapter 4 STL of the textbook Data Structures Using C++ provided a much better understanding of iterators.
	* Finally, the C++ documentation reinforced the concepts

## Vectors
* [Documentation](http://www.cplusplus.com/reference/vector/)
* I used vectors to implement my program. I believe if I had left the data in strings I could have accomplished everything a vector does. I will have to implement it to test this theory. 

## string
* assign() - [Documentation](http://www.cplusplus.com/reference/string/string/assign/)
	* Copies one string into another
* at() - [Documentation](http://www.cplusplus.com/reference/string/string/at/)
	* One parameter that takes in an index. Index is a zero-based index
* length() - [Documentation](http://www.cplusplus.com/reference/string/string/length/)
	* No parameters
	* Returns number of bytes in the string
* substr() - [Documentation](http://www.cplusplus.com/reference/string/string/substr/)
	* Two parameters
		1. The beginning index
		2. How many characters you want to include in the substring
* swap() - [Documentation](http://www.cplusplus.com/reference/string/string/swap/)
	* Especially useful when sorting
	* Basically takes one string and swaps it with another string
	* One parameter that takes in the string you want to swap it with.
* find() - [Documentation](http://www.cplusplus.com/reference/string/string/find/)
	* Searches the string for the first occurrence going from left to right
		* Will return the starting location of the first found occurrence
* rfind() - [Documentation](http://www.cplusplus.com/reference/string/string/rfind/)
	* 'r' in rfind() stands for reverse
	* Finds last occurrence of content in string. Does this by going from right to left
		* Will return the starting location of the last found occurence
* erase() - [Documentation](http://www.cplusplus.com/reference/string/string/erase/)
	* Erases everthing from and including whatever element is given
  * If passing in 1 paramater it takes which position to start at and erases the rest of the string
* replace() - [Documentation](http://www.cplusplus.com/reference/string/string/replace/)
  * 3 parameters
    1. Which character do you want to begin replacing at
    2. How many characters do you want to replace
    3. What string do you want to replace it with
* insert() - [Documentation](http://www.cplusplus.com/reference/string/string/insert/)
	* Inserts a substring into a string
	* 2 parameters
		1. Where do you want to begin inserting at
		2. What string do you want to insert

## Geeks for Geeks
* Finally, I used Geeks for Geeks recursive algorithm to implement the postorder traversal of a tree.
[Link](http://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/)