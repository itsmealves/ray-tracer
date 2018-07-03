//
// Created by calazans on 23/06/18.
//
#include "KDTree.h"
#include "../box/AABB.h"
#include "../world/Thing.h"
#include "../util/MissingMethods.h"
#include <vector>
Node* makeBranchZ(std::vector<Node*> objects);
Node* makeBranchX(std::vector<Node*> objects);
Node* makeBranchY(std::vector<Node*> objects);

bool sortY(Node* i,Node* j){
    return i->getMeanPoint()[1] < j->getMeanPoint()[1];
}
Node* makeBranchY(std::vector<Node*> objects)
{
    if(objects.size() == 1){
        return objects[0];
    }else if (objects.empty()){
        return nullptr;
    }

    std::vector<Node*> right;
    std::vector<Node*> left;

    std::sort(objects.begin(),objects.end(),sortY);

    for (int i =0 ; i < objects.size()/2;++i) {
        left.push_back(objects[i]);
    }
    for (int i =objects.size()/2 ; i < objects.size();++i) {
        right.push_back(objects[i]);
    }

    return Node::intBranch(
            makeBranchZ(left),
            makeBranchZ(right)
    );
}

bool sortZ(Node* i,Node* j){
    return i->getMeanPoint()[2] < j->getMeanPoint()[2];
}
Node* makeBranchZ(std::vector<Node*> objects)
{
    if(objects.size() == 1){
        return objects[0];
    }else if (objects.empty()){
        return nullptr;
    }

    std::vector<Node*> right;
    std::vector<Node*> left;

    std::sort(objects.begin(),objects.end(),sortZ);

    for (int i =0 ; i < objects.size()/2;++i) {
        left.push_back(objects[i]);
    }
    for (int i =objects.size()/2 ; i < objects.size();++i) {
        right.push_back(objects[i]);
    }

    return Node::intBranch(
            makeBranchX(left),
            makeBranchX(right)
    );
}

bool sortX(Node* i,Node* j){
    return i->getMeanPoint()[0] < j->getMeanPoint()[0];
}
Node* makeBranchX(std::vector<Node*> objects)
{
    if(objects.size() == 1){
        return objects[0];
    }else if (objects.empty()){
        return nullptr;
    }

    std::vector<Node*> right;
    std::vector<Node*> left;

    std::sort(objects.begin(),objects.end(),sortX);

    for (int i =0 ; i < objects.size()/2;++i) {
        left.push_back(objects[i]);
    }
    for (int i =objects.size()/2 ; i < objects.size();++i) {
        right.push_back(objects[i]);
    }

    return Node::intBranch(
            makeBranchY(left),
            makeBranchY(right)
    );
}

//TODO: OPTIMIZE
void KDTree::insert(const std::vector<Thing *>& objects)
{
    std::vector<Node*> vec;
    AABB* aabbs;
    Node* newNode;
    Thing *elem;

    //Cria AABBS baseadas nos objetos
    for (int i = 0;i < objects.size(); i++)
    {
        elem = objects[i];
        aabbs = new AABB(elem, getMinBounds(elem),getMaxBounds(elem),getCenter(elem));
        newNode = new Node(aabbs);
        vec.push_back(newNode);
    }

    this->root = makeBranchX(vec);
}
//TODO: O(N)
//Busca em profundidade pelos elementos que acertaram
const std::vector<Thing*> KDTree::hits(const arma::vec& origin, const arma::vec& dir) const
{
    std::vector<Node*> nodes;
    std::vector<Thing*> rObjects;
    nodes.push_back(this->root);
    Node *currentElement;
    Ray interceptionRay = Ray(origin,dir);

    while(!nodes.empty())
    {
        currentElement = nodes[nodes.size() -1];
        nodes.pop_back();
        //Bateu no BoundBox Grande?
        //Seria uma otimização só perguntar para as folhas se bateu?
        if(currentElement->hits(interceptionRay)){
            Node* left = currentElement->getLeft();
            Node* right = currentElement->getRight();
            //Tem alguem a esquerda?
            if(left)
            {
                nodes.push_back(left);
            }
            //Tem alguem a direita?
            if(right)
            {
                nodes.push_back(right);
            }
            //É uma folha?
            if(!left && !right)
            {
                rObjects.push_back(currentElement->getObject());
            }
        }
    }
    return rObjects;
}

#ifdef _TESTE
int profundidade(const Node* elem){
    int value = 0;
    if(elem){
        if(elem->getRight() && elem->getLeft()){
            int r = profundidade(elem->getRight()) +1;
            int l = profundidade(elem->getLeft()) +1;
            value = std::max(r,l);
        }
        else if(elem->getRight()  && elem->getLeft()== NULL){
            value = profundidade(elem->getRight()) +1;
        }else if(elem->getRight()== NULL  && elem->getLeft()){
            value = profundidade(elem->getLeft()) +1;
        }else{
            value =  1;
        }
    }
    return value;
}

void KDTree::ValidInfo(){
    printf("%d",profundidade(this->root));
}
#endif