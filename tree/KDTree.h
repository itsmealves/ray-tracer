//
// Created by calazans on 23/06/18.
//

#ifndef KDTREE_KDTREE_H
#define KDTREE_KDTREE_H

#include "Node.h"
#include "../util/HitBox.h"
#include "../world/Thing.h"

class KDTree {

private:
    Node *root;
    Node *build(std::vector<Thing *> things, int currentDirection);
    const std::vector<Thing *> traverse(const Ray &ray, Node *root) const;
public:
    KDTree(const std::vector<Thing *> &things) {
        root = build(things, 0);
    }

    ~KDTree() {
        delete root;
    }

    const std::vector<Thing *> traverse(const Ray &ray) const;
};


#endif //KDTREE_KDTREE_H
