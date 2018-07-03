//
// Created by calazans on 23/06/18.
//

#include "AABB.h"
#define min(x, y) ((x) < (y) ? (x) : (y))
//#define min3(x, y, z) min(x, min(y,z))
#define max(x, y) ((x) > (y) ? (x) : (y))
//#define max3(x, y,z ) max(x, max(y,z))

void AABB::calculateMeanPoint(){
    this->meanPoint_ =  (this->edges_[0] - this->edges_[1]) / 2;
}
/*Links:
    https://tavianator.com/fast-branchless-raybounding-box-intersections/
    https://www.siggraph.org//education/materials/HyperGraph/raytrace/rtinter3.htm
 */
/**   \fn bool AABB::intercepts(const Ray& point)
      \param point Raio saido da origem em qualquer direção a BoundBox.
      \return Retorna se o raio interseptou ou não a boundbox
 **/
bool AABB::intercepts(const Ray& point) const{
    /**
    Considerando a equação da reta \f$ Point(T) = Origin + T * Direction\f$
    ao isolamos o t temos:
    \f$ T = ( Point(T) - Origin ) / Direction\f$
    **/
    double tx1 = (this->edges_[1][0] - point.point()[0]) * point.inverseOfDirection()[0];
    double tx2 = (this->edges_[0][0] - point.point()[0]) * point.inverseOfDirection()[0];
    double tmin = min(tx1, tx2);
    double tmax = max(tx1, tx2);

    double ty1 = (this->edges_[1][1] - point.point()[1]) * point.inverseOfDirection()[1];
    double ty2 = (this->edges_[0][1] - point.point()[1]) * point.inverseOfDirection()[1];

    tmin = max(tmin, min(min(ty1, ty2), tmax));
    tmax = min(tmax, max(max(ty1, ty2), tmin));

    double tz1 = (this->edges_[1][2] - point.point()[2]) * point.inverseOfDirection()[2];
    double tz2 = (this->edges_[0][2] - point.point()[2]) * point.inverseOfDirection()[2];


    tmin = max(tmin, min(min(tz1, tz2), tmax));
    tmax = min(tmax, max(max(tz1, tz2), tmin));
    return tmax >= tmin;
}

double AABB::calculateDistance(const AABB* distanceObj){
    arma::vec midPoint = this->meanPoint_;
    arma::vec distanceMidPoint = distanceObj->meanPoint_;
    double distance = pow(midPoint[0] - distanceMidPoint[0],2.0) +
                      pow(midPoint[1] - distanceMidPoint[1],2.0) +
                      pow(midPoint[2] - distanceMidPoint[2],2.0);

    return distance;//std::sqrt(distance);
}