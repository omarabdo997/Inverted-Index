#include "node.h"

Node::Node()
{

}

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
