#ifndef LINKNODE_H
#define LINKNODE_H
#include "currency.cpp"

struct LinkNode {
    Currency* data;
    LinkNode* next;

    LinkNode();
    LinkNode(Currency*);
    ~LinkNode();
  };

LinkNode::LinkNode() {
  data = NULL;
  next = NULL;
}

LinkNode::LinkNode(Currency* data) {
  this->data = data;
  this->next = NULL;
}

LinkNode::~LinkNode() {}

#endif
