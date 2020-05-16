#ifndef BALANCEDBINARYTREE_H
#define BALANCEDBINARYTREE_H
#include "node.h"

class BalancedBinaryTree
// This is an implementaiton of Red-Black Binary trees
{
private:
    Node *root = nullptr;
    void standardInsert(QString word, QString document);
public:
    BalancedBinaryTree();
    ~BalancedBinaryTree();
    void insert(QString word, QString document);
    QVector<QString> get(QString word);
};

#endif // BALANCEDBINARYTREE_H
