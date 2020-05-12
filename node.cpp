#include "node.h"

Node::Node()
{

}

Node::~Node()
{
delete parent;
delete left;
delete right;
}

Node::Node(Node *parent, QString key)
{
    this->parent = parent;
    this->key = key;
}

/*void Node::paintRed()
{
    this->isRed = 1;
}*/

/*
void Node::paintBlack()
{
  this->isRed=0;
 }
*/

void Node::addDocument(QString document)
{
    documents.push_back(document);
}

bool Node::isNew(QString document)
{
    if(documents.empty())
        return true; //new
    else
    {
        int last = documents.size() - 1;

        if(documents[last] == document)
            return false;//not new
        else
            return true;// new

    }
}
/*
Node *Node::uncle()
{
    if(this == parent->left)
        return parent->right;
    else
        return parent->left;
}
*/
/*
    Node *Node::grandParent()
{
    return parent->parent;
}
*/
