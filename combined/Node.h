#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

class Node{
public:
	string key;
	int height;
	Node* left;
	Node* right;
	
	string title, surname, givenName, gender, dateOfBirth;
	string	address, city, stateFull, zipCode, Country, teleCountryCode, phoneNumber, emailAddress, occupation, company;
	//constructor
	Node(string* data);


	
	int getHeight(Node* node);
	int max(int left, int right);
	Node* rightRotate(Node* y);
	Node* leftRotate(Node* x);
	
	int getBalance(Node* node);
	Node* insert(Node* node, string* data,string key);
	Node* minValueNode(Node* node);
	Node* deleteN(Node* node);
	Node* search(string key1,string key2,Node* node);



};


#endif