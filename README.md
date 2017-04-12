# extra10
Simple C++ program to print postorder traversal from preorder and inorder traversals

## string functions
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