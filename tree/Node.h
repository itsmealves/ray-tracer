//
// Created by calazans on 23/06/18.
//

#ifndef KDTREE_NODE_H
#define KDTREE_NODE_H


#include <vector>
#include <armadillo>
#include <cfloat>
#include "../box/AABB.h"

class Node {
private:
    AABB *_box;
    Node *_left;
    Node *_right;

    int _cutDirection;
    double _cutThreshold;
public:

    Node(Node *left, Node *right, int cutDirection, double cutThreshold) :
        _left(left), _right(right), _box(nullptr), _cutDirection(cutDirection), _cutThreshold(cutThreshold) {

        _box = left->box()->join(right->box());
    }

    Node(std::vector<Thing *> things) :
            _left(nullptr), _right(nullptr), _box(nullptr) {

        arma::vec minBounds({DBL_MAX, DBL_MAX, DBL_MAX});
        arma::vec maxBounds({DBL_MIN, DBL_MIN, DBL_MIN});

        for(Thing *t : things) {
            arma::vec currentMin = t->minBounds();
            arma::vec currentMax = t->maxBounds();

            double xMin = std::min(minBounds.at(0), currentMin.at(0));
            double xMax = std::max(maxBounds.at(0), currentMax.at(0));

            double yMin = std::min(minBounds.at(1), currentMin.at(1));
            double yMax = std::max(maxBounds.at(1), currentMax.at(1));

            double zMin = std::min(minBounds.at(2), currentMin.at(2));
            double zMax = std::max(maxBounds.at(2), currentMax.at(2));

            minBounds = arma::vec({xMin, yMin, zMin});
            maxBounds = arma::vec({xMax, yMax, zMax});
        }

        _box = new AABB(minBounds, maxBounds, things);
    }

    ~Node() {
        if(_box)delete _box;
        if(_left) delete _left;
        if(_right) delete _right;
    }

    const bool isLeaf() const {
        return _left == nullptr && _right == nullptr;
    }

    AABB *box() const {
        return _box;
    }

    Node *left() const {
        return _left;
    }

    Node *right() const {
        return _right;
    }
};


#endif //KDTREE_NODE_H
