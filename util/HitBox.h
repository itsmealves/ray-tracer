//
// Created by calazans on 01/07/18.
//

#ifndef KDTREELIB_HITBOX_H
#define KDTREELIB_HITBOX_H

#include <armadillo>
#include "../engine/Hit.h"

#ifndef _TESTE
class Hit;
#else
class Hit {
private:
    bool      value_;
    arma::vec normal_;
    arma::vec point_;
    float     intensity_;
public:
    Hit(){value_ = false;}
    Hit(bool value,const arma::vec& normal,const arma::vec& point,float intensity):value_(value),normal_(normal),point_(point),intensity_(intensity){}

    const bool hadHitted()
    {
        return value_;
    }
    void setHitTrue(const arma::vec& point,const arma::vec& normal,float intensity)
    {
        this->value_ = true;
        this->normal_ = normal;
        this->point_ = point;
        this->intensity_ = intensity;
    }
    void setHitFalse()
    {
        this->value_ = false;
    }
    const arma::vec getNormal() const
    {
        return normal_;
    }
    const arma::vec getPoint() const
    {
        return point_;
    }
};
#endif

class HitBox {
private:
    bool hits_;
    arma::vec t_;
    float tmin_;
public:
    Hit hitPoint_;
    Thing *object;
    HitBox():hits_(false){}
    HitBox(bool hits,float t,float tmin,Hit hitPoint):
            hits_(hits),t_(t),tmin_(tmin),hitPoint_(hitPoint){}
    void setHits(bool hits){
        hits_ = hits;
    }
    void setT(arma::vec t){
        t_ = t;
    }
    void setTMin(float tmin){
        tmin_ = tmin;
    }
    void setHit(Hit hitpoint){
        hitPoint_ = hitpoint;
    }
    bool Hits(){
        return hits_;
    }

};


#endif //KDTREELIB_HITBOX_H
