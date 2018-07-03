//
// Created by calazans on 23/06/18.
//

#include "Node.h"
#include "../util/Globals.h"

Node* Node::intBranch(Node* left, Node* right) {
    Node *value = nullptr;
    if(right && left)
    {
        auto minCordsLeft = left->boundBox_->getMin();
        auto minCordsRight = right->boundBox_->getMin();
        arma::vec minCords = {
                std::min(minCordsLeft[0],minCordsRight[0]) - Globals::getPadding(),
                std::min(minCordsLeft[1],minCordsRight[1]) - Globals::getPadding(),
                std::min(minCordsLeft[2],minCordsRight[2]) - Globals::getPadding()
        };
        auto maxCordsLeft = left->boundBox_->getMax();
        auto maxCordsRight = right->boundBox_->getMax();
        arma::vec maxCords = {
                std::min(maxCordsLeft[0],maxCordsRight[0]) + Globals::getPadding(),
                std::min(maxCordsLeft[1],maxCordsRight[1]) + Globals::getPadding(),
                std::min(maxCordsLeft[2],maxCordsRight[2]) + Globals::getPadding()
        };

        auto boundbox = new AABB(NULL,minCords,maxCords);
        value =  new Node(left,right,boundbox);
    }
    else if(left && right == nullptr)
    {
        value = left;
    }
    else if(right && left == nullptr)
    {
        value = right;
    }
     return  value;
}