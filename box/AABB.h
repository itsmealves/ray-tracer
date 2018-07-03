//
// Created by calazans on 23/06/18.
//

#ifndef KDTREE_AABB_H
#define KDTREE_AABB_H

#include <armadillo>
#include "../world/Thing.h"

class AABB {
private:
    Thing *value_;
    arma::vec  edges_[2];
    arma::vec  meanPoint_;
    void calculateMeanPoint();
public:
    AABB(Thing* value,const arma::vec& minCords,const arma::vec& maxCords): value_(value)
    {
        edges_[0] = (minCords);
        edges_[1] = (maxCords);
        calculateMeanPoint();
    }
    AABB(Thing* value,const arma::vec& minCords,const arma::vec& maxCords,const arma::vec& meanPoint): value_(value),meanPoint_(meanPoint)
    {
        edges_[0] = (minCords);
        edges_[1] = (maxCords);
    }
    const arma::vec getMin(){
        return edges_[0];
    }
    const arma::vec getMax(){
        return edges_[1];
    }

    const arma::vec getMean(){
        return meanPoint_;
    }

    Thing *getObject(){
        return value_;
    }

    bool intercepts(const Ray& point) const;

    double calculateDistance(const AABB* distanceObj);
};


#endif //KDTREE_AABB_H
