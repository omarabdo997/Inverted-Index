#include "balancedbinarytree.h"

void BalancedBinaryTree::standardInsert(QString word, QString document)
{
    if(root == nullptr)
    {
        root = new Node(nullptr, word);
        root->addDocument(document);
        root->paintRed();
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
    pointer->paintRed();
    if(parentPointer->key < word)
       parentPointer->right = pointer;
    else
       parentPointer->left =pointer;
}

BalancedBinaryTree::BalancedBinaryTree()
{

}

void BalancedBinaryTree::insert(QString word, QString document)
{
    standardInsert(word, document);
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
