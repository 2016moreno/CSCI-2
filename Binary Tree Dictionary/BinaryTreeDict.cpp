#include <iostream>
#include <fstream>
#include <string>


using namespace std;

//Node class used to create node
class Node {
public:
    
    Node(string newkeydata) {
        key = newkeydata;
        left = right = nullptr;
    };
    
    string key;
    int count = 1;
    Node *left;
    Node *right;
};

//Used to create binary tree, such as insertion, delete and display
class bintree {
public:
    
    Node *temp; //creation of the temp we're always gonna mess with
    
    bintree(string keydata) {
        temp = new Node(keydata);
    };
    
    ~bintree() { //learned this in class!
        delete temp;
    };
    
    void insert(string data, Node *&binarytree);
    void display(Node *tree);
};

//function used to make tree alphabetical
void bintree::insert(string key, Node *&binarytree) {

	if (binarytree == nullptr) {
		binarytree = new Node(key);
	}
	else if (key < binarytree->key) { //less than go left
		insert(key, binarytree->left);
	}
	else if (key > binarytree->key) { //greater than go right
		insert(key, binarytree->right);
	}
	else if (key == binarytree->key) { //add to the count if key is same
		binarytree->count++;
	}

}

//just follow inorder
void bintree::display(Node *binarytree) {

	if (binarytree != nullptr) {

		display(binarytree->left);
		cout << binarytree->key << " " << binarytree->count << endl; //start from the bottom and keep going until it reaches the right
		display(binarytree->right);
	}
}

int main()
{
	string words;
	bintree binarytree("");
	ifstream inFile;
	inFile.open("whale.txt");

	while (inFile)
	{
        if(inFile.fail()) {
            cout << "File failed to open." << endl;
        }
        else {
		inFile >> words;
		binarytree.insert(words, binarytree.temp);
        }
	}

	binarytree.display(binarytree.temp);
    
	system("pause");
	return 0;
}
