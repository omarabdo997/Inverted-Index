#include "balancedbinarytree.h"

BalancedBinaryTree::BalancedBinaryTree()
{

}

void BalancedBinaryTree::insert(QString word, QString document)
{
       if(root == nullptr)
    {
        root = new Node(nullptr, word);
        root->addDocument(document);
        return;
    }
    Node *pointer = root;
    Node *parentPointer = nullptr;
    while(pointer != nullptr)
    {
        if(pointer->key == word)
        {
            if(pointer->isNew(document))
                pointer->addDocument(document);
            return;
        }
        else if(pointer->key < word)
        {
            parentPointer = pointer;
            pointer = pointer->right;
        }
        else
        {
            parentPointer = pointer;
            pointer = pointer->left;
        }
    }
    pointer = new Node(parentPointer, word);
    pointer->addDocument(document);
    if(parentPointer->key < word)
       parentPointer->right = pointer;
    else
       parentPointer->left =pointer;
}
void deleteTree( Node *root)
{
    if(root==nullptr)return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

BalancedBinaryTree::~BalancedBinaryTree()
{
  deleteTree(this->root);
}
QVector<QString> BalancedBinaryTree::get(QString word)
{
    Node* pointer = root;
    while(pointer != nullptr)
    {
        if(pointer->key == word)
            return pointer->documents;
        else if(pointer->key < word)
            pointer = pointer->right;
        else
            pointer = pointer->left;
    }
    return QVector<QString>();
}
