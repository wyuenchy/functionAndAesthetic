

#ifndef  AVLTREE_H
#define	AVLTREE_H
#include "Node.h"
#include "string.h"

class AVLTree{

public:
	AVLTree();
	Node* root;
	Node** fucking1DArray;
	void insert(Node* node, string* data);
	void addTo1d(Node* node);
	Node** get1dArray();
	void del1dArray();
	void searchShit(string key, Node* node, string constrain);
	Node* search(string key1,string key2);
	void inOrder(Node* node);
};


#endif 
