//**************TO DO **************************** GROUP NAME
//David moreno
//Roberto nivon
//christian mares
#include <cstdlib>
#include <iostream>
#include "Node.h"

using namespace std;


//This method creates the tree which is presented in the slide. I did the hard work :)
Node* create_tree_from_slides()
{
	Node* root = new Node(6);
	root->left = new Node(2);
	root->right = new Node(12);

	root->left->left = new Node(-1);
	root->left->right = new Node(4);

	root->right->left = new Node(9);
	root->right->right = new Node(16);

	root->left->left->left = new Node(-3);
	root->left->left->right = new Node(1);

	root->left->right->left = new Node(3);
	root->left->right->right = new Node(5);

	root->right->left->left = new Node(8);
	root->right->left->right = new Node(11);

	root->right->right->left = new Node(13);
	root->right->right->right = new Node(20);

	return root;
}




/*
 Given a tree and a sum, return true if there is a path from the root
 down to a leaf, such that adding up all the values along the path
 equals the given sum. 
*/

//**************TO DO ****************************
bool ThereisPath(Node* node, int sum) {
    
    if (node == nullptr) {
        return 0;
    }
    else if (node->left == nullptr && node->right == nullptr && sum == node->key) {
        return true;
    }
    else
    return ThereisPath(node->left, sum - node->key) || ThereisPath(node->right, sum - node->key);
    }

/*
 Change a tree so that the roles of the
 left and right pointers are swapped at every node.
 So the tree...
	   4
	  / \
	 2   5
	/ \
   1   3
 is changed to...
	   4
	  / \
	 5   2
		/ \
	   3   1
Hint: Go all the way down (recursively) and start swaping right and left child. 
	   */
//**************TO DO ****************************
void Reflection(Node* node) {
	
    if (node == NULL)
        return;
    else {
        Node* temp = new Node(0);

        Reflection(node->left);
        Reflection(node->right);
        
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}


void print_all(Node* root)
{
	// Base case
	if (root == nullptr)
		return;

	// Recursive case	
	print_all(root->left);
	cout << root->key << ' ';
	print_all(root->right);
}


int main()
{
	Node* root = create_tree_from_slides();
	
	
	if (ThereisPath(root, 15))
		cout << "Well Done!" << endl;
	else
		cout << "Something is wrong with your algorithm. THere is a path sum up to 15." << endl;

	if (!ThereisPath(root, 18))
		cout << "Well Done!" << endl;
	else
		cout << "Something is wrong with your algorithm. There is no path that sum up to 18." << endl;


	print_all(root);
	cout << endl;
	cout << " Mirror Reflection Tree (The order should be opposite) " << endl;
	Reflection(root);
	print_all(root);
	cout << endl;

	system("pause");
	return 0;
}
