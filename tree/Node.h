//
// Created by calazans on 23/06/18.
//

#ifndef KDTREE_NODE_H
#define KDTREE_NODE_H


#include <vector>
#include <armadillo>
#include "../box/AABB.h"
#include "../engine/Ray.h"
#include "../world/Thing.h"

class Node {
private:
    Node*  left_    ;
    Node*  right_   ;
    AABB*  boundBox_;

    Node(){};
    Node(Node* left, Node* right, AABB* boundBox):boundBox_(boundBox),right_(right),left_(left){};
public:
    Node(AABB* boundBox):boundBox_(boundBox)
    {
        left_ = nullptr;
        right_ = nullptr;
    };

    virtual ~Node(){
        if(left_)
        {
            delete left_;
        }
        if(right_)
        {
            delete right_;
        }
        if(boundBox_)
        {
            delete boundBox_;
        }
    }

    static Node* intBranch(Node* left, Node* right);

    const bool hits(const Ray& point) const
    {
        return this->boundBox_->intercepts(point);
    }

    Node* getLeft() const
    {
        return left_;
    }
    const arma::vec getMeanPoint() const
    {
        return this->boundBox_->getMean();
    }
    Node* getRight() const
    {
        return right_;
    }

    Thing *getObject()
    {
        return this->boundBox_->getObject();
    }
};


#endif //KDTREE_NODE_H
