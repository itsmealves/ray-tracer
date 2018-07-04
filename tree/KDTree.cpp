//
// Created by calazans on 23/06/18.
//
#include "KDTree.h"
#include "../engine/Hit.h"
#include "../engine/Ray.h"
#include "../box/AABB.h"
#include "../box/BoxHit.h"
#include <vector>
#include <cfloat>

bool sortInX(Thing *i, Thing *j){
    return i->massCenter().at(0) > j->massCenter().at(0);
}
bool sortInY(Thing *i, Thing *j){
    return i->massCenter().at(1) > j->massCenter().at(1);
}
bool sortInZ(Thing *i, Thing *j){
    return i->massCenter().at(2) > j->massCenter().at(2);
}
#ifdef __AABBTREE
struct ThingSortingClass {
    int cutDirection;
    bool operator() (Thing *i, Thing *j) {
        arma::vec iCenter = i->massCenter();
        arma::vec jCenter = j->massCenter();

        return iCenter.at(cutDirection) < jCenter.at(cutDirection);
    }
} thingSortingObject;
#endif
Node *KDTree::build(const std::vector<Thing *> things, int currentDirection) {
#ifdef __AABBTREE
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
#else
    Node* scene = new Node(things);
    Node* currentNode;
    std::vector<Node*> keys;
    std::map<Node* , std::vector<Thing*>> elems;
    std::vector<Thing*> left,right;
    elems.insert(new std::pair<Node*,std::vector<Thing*>>(scene,things));
    int dir;
    for(int i = 0;!keys.empty();i++)
    {
        currentNode = keys[keys.size() -1];
        keys.pop_back();
        dir = i%3;
        switch(dir){
            case X_DIR:
                std::sort(elems.begin(), elems.end(), sortInX);
                break;
            case Y_DIR:
                std::sort(elems.begin(), elems.end(), sortInY);
                break;
            case Z_DIR:
                std::sort(elems.begin(), elems.end(), sortInZ);
                break;
        }
        left = (elems.at(currentNode));
        right = (elems.at(currentNode));

    }
#endif
}

const std::vector<Thing *> KDTree::traverse(const Ray &ray) const {
    return traverse(ray, root);
}

const std::vector<Thing *> KDTree::traverse(const Ray &ray, Node *root) const {
    if(root->isLeaf())
    {
        return root->box()->things();
    }
    BoxHit hit = root->box()->intersectedBy(ray);

    if(hit.happened()) {
#ifdef __alvesDOIDO
        if(hit.nearest().at(root->cutDirection()) < root->cutThreshold()) {
            root = root->left();
        } else {
            root = root->right();
        }
#elif __alvesRLDOido
        std::vector<>
#else
        std::vector<Thing *> a = traverse(ray, root->left());
        std::vector<Thing *> b = traverse(ray, root->right());

        for(Thing *t : b) {
            a.push_back(t);
        }
#endif
        return a;
    } else {
        return std::vector<Thing *>();
    }
}
