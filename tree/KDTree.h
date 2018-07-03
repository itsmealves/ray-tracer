//
// Created by calazans on 23/06/18.
//

#ifndef KDTREE_KDTREE_H
#define KDTREE_KDTREE_H

#include "Node.h"

class KDTree {
private:
    Node* root;
public:
    KDTree(){}
    virtual ~KDTree(){
        delete root;
    }
    void insert(const std::vector<Thing*>& objects);

    const std::vector<Thing *> hits(const arma::vec& origin, const arma::vec& dir) const;

    #ifdef _TESTE
        void ValidInfo();
    #endif
};


#endif //KDTREE_KDTREE_H
