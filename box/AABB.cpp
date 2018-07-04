//
// Created by calazans on 23/06/18.
//

#include <cfloat>
#include "AABB.h"
#include "../engine/Ray.h"
#include "BoxHit.h"

BoxHit AABB::intersectedBy(const Ray &ray) const {

    double tMax = INFINITY;
    double tMin = -INFINITY;

    int numDirections = 3;

    for(int i = 0; i < numDirections; i++) {
        bool checkForParallelism = ray.direction().at(i) == 0.0;

        if(checkForParallelism) {
            bool outOfBox = ray.point().at(i) < minBounds().at(i) || ray.point().at(i) > maxBounds().at(i);
            if(outOfBox) return BoxHit();
        }

        double t1 = (minBounds().at(i) - ray.point().at(i)) * ray.inverseOfDirection().at(i);
        double t2 = (maxBounds().at(i) - ray.point().at(i)) * ray.inverseOfDirection().at(i);

        double currentMin = std::min(t1, t2);
        double currentMax = std::max(t1, t2);

        if(currentMin > tMin) tMin = currentMin;
        if(currentMax < tMax) tMax = currentMax;
        if(tMin > tMax) return BoxHit();
        if(tMax < 0) return BoxHit();
    }

    arma::vec nearest = ray.point() + tMin * ray.direction();
    arma::vec farthest = ray.point() + tMax * ray.direction();
    return BoxHit(nearest, farthest);
}

AABB *AABB::join(AABB *otherBox) const {
    double xMin = std::min(minBounds().at(0), otherBox->minBounds().at(0));
    double xMax = std::max(maxBounds().at(0), otherBox->maxBounds().at(0));

    double yMin = std::min(minBounds().at(1), otherBox->minBounds().at(1));
    double yMax = std::max(maxBounds().at(1), otherBox->maxBounds().at(1));

    double zMin = std::min(minBounds().at(2), otherBox->minBounds().at(2));
    double zMax = std::max(maxBounds().at(2), otherBox->maxBounds().at(2));

    arma::vec minBounds({xMin, yMin, zMin});
    arma::vec maxBounds({xMax, yMax, zMax});
    return new AABB(minBounds, maxBounds);
}
