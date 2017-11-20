#include <cstdlib>
#include <iostream>
#include "SimpleBST.h"
/**
 * Test Program to make sure the isProper() function works as expected
 *
 * \authors <Charley Burtwistle, Ashby Mullin>
 * \date <November 1, 2017>
 */
int main() {
	using namespace std;

	SimpleBST<char> tree;

	cout << "Here's a inorder traversal of the (empty) tree: " << tree << endl;
	cout << "the tree " << (tree.isProper() ? "is" : "is not") << " proper." << endl;

	cout << "\ninserting D, B, F, A, C, E, G..." << endl;

	tree.insert('D'); tree.insert('B'); tree.insert('F'); 
	tree.insert('A'); tree.insert('C'); tree.insert('E'); 
	tree.insert('G'); 

	cout << "Here's an inorder traversal of the tree: " << tree << endl;
	cout << "the tree " << (tree.isProper() ? "is" : "is not") << " proper." << endl;

	cout << "\ndeleting C..." << endl;
	tree.remove('C');

	cout << "Here's an inorder traversal of the tree: " << tree << endl;
	cout << "the tree " << (tree.isProper() ? "is" : "is not") << " proper." << endl;

	cout << "\ndeleting A..." << endl;
	tree.remove('A');

	cout << "Here's an inorder traversal of the tree: " << tree << endl;
	cout << "the tree " << (tree.isProper() ? "is" : "is not") << " proper." << endl;

	cout << "\nadding A, C, H..." << endl;
	tree.insert('A'); tree.insert('C'), tree.insert('H');

	cout << "Here's an inorder traversal of the tree: " << tree << endl;
	cout << "the tree " << (tree.isProper() ? "is" : "is not") << " proper." << endl;

	cout << "\ndeleting A, C, E, G, H..." << endl;
	tree.remove('H');
	tree.remove('G');
	tree.remove('E');
	tree.remove('C');
	tree.remove('A');

	cout << "Here's an inorder traversal of the tree: " << tree << endl;
	cout << "the tree " << (tree.isProper() ? "is" : "is not") << " proper." << endl;

	cout << "\ndeleting B..." << endl;
	tree.remove('B');

	cout << "Here's an inorder traversal of the tree: " << tree << endl;
	cout << "the tree " << (tree.isProper() ? "is" : "is not") << " proper." << endl;

	cout << "\ndeleting D..." << endl;
	tree.remove('D');

	cout << "Here's an inorder traversal of the tree: " << tree << endl;
	cout << "the tree " << (tree.isProper() ? "is" : "is not") << " proper." << endl;


	return EXIT_SUCCESS;
}