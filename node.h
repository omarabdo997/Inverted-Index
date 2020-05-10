#ifndef NODE_H
#define NODE_H
#include <QString>
#include <QVector>


class Node
{
public:
    Node *parent;
    Node *left;
    Node *right;
    QString key;
    QVector<QString> documents;
    bool isRed;
    Node();
    void addDocument(QString document);
    bool isNew(QString document);
};

#endif // NODE_H
