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
    bool isRed = 0;
    Node();
    Node(Node *parent, QString key);
    void paintRed();
    void paintBlack();
    void addDocument(QString document);
    bool isNew(QString document);
    Node *uncle();
    Node *grandParent();
};

#endif // NODE_H
