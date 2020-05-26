#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "node.h"

class BinaryTree
// This is an implementaiton of Red-Black Binary trees
{
private:
    Node *root = nullptr;
    void standardInsert(QString word, QString document);
public:
    BinaryTree();
    ~BinaryTree();
    void insert(QString word, QString document);
    QVector<QString> get(QString word);
};

#endif // BINARYTREE_H
