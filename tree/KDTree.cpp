//
// Created by calazans on 23/06/18.
//
#include "KDTree.h"
#include "../engine/Hit.h"
#include "../engine/Ray.h"
#include "../box/AABB.h"
#include "../util/MissingMethods.h"
#include "../box/BoxHit.h"
#include <vector>
#include <cfloat>

struct ThingSortingClass {
    int cutDirection;
    bool operator() (Thing *i, Thing *j) {
        arma::vec iCenter = i->massCenter();
        arma::vec jCenter = j->massCenter();

        return iCenter.at(cutDirection) < jCenter.at(cutDirection);
    }
} thingSortingObject;

Node *KDTree::build(const std::vector<Thing *> things, int currentDirection) {
    if(things.size() <= 1) {
        return new Node(things);
    } else {
        int half = (int) (things.size() / 2);
        std::vector<Thing *> sorted;

        for(Thing *t : things) {
            sorted.push_back(t);
        }

        thingSortingObject.cutDirection = currentDirection;
        std::sort(sorted.begin(), sorted.end(), thingSortingObject);

        std::vector<Thing *> lowerThings; std::vector<Thing *> upperThings;
        for(int i = 0; i < half; i++) lowerThings.push_back(sorted.at(i));
        for(int i = half; i < things.size(); i++) upperThings.push_back(sorted.at(i));

        arma::vec firstUpper = upperThings.at(0)->massCenter();
        arma::vec lastLower = lowerThings.at(lowerThings.size() - 1)->massCenter();
        double cutThreshold = (firstUpper.at(currentDirection) + lastLower.at(currentDirection)) / 2.0;

        int nextDirection = (currentDirection + 1) % 3;
        Node *left = build(lowerThings, nextDirection);
        Node *right = build(upperThings, nextDirection);
        return new Node(left, right, currentDirection, cutThreshold);
    }
}

const std::vector<Thing *> KDTree::traverse(const Ray &ray) const {
    return traverse(ray, root);
}

const std::vector<Thing *> KDTree::traverse(const Ray &ray, Node *root) const {
    if(root->isLeaf()) return root->box()->things();
    BoxHit hit = root->box()->intersectedBy(ray);

    if(hit.happened()) {
        std::vector<Thing *> a = traverse(ray, root->left());
        std::vector<Thing *> b = traverse(ray, root->right());

        for(Thing *t : b) {
            a.push_back(t);
        }

        return a;
    } else {
        return std::vector<Thing *>();
    }
}
