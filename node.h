#ifndef NODE_H
#define NODE_H
#include <QString>
#include <QVector>


class Node
{
public:
    Node *parent = nullptr;
    Node *left = nullptr;
    Node *right = nullptr;
    QString key;
    QVector<QString> documents;

    Node();
    Node(Node *parent, QString key);

    void addDocument(QString document);
    bool isNew(QString document);

};

#endif // NODE_H
