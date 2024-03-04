#ifndef BSTNODE_H
#define BSTNODE_H
#include "currency.cpp"

struct BstNode {
	Currency* data;
	BstNode* left;
	BstNode* right;

	BstNode();
	BstNode(Currency*);
	~BstNode();
};

BstNode::BstNode() {
	data = NULL;
	left = NULL;
	right = NULL;
}

BstNode::BstNode(Currency* data) {
	this->data = data;
	this->left = NULL;
	this->right = NULL;
}

#endif
