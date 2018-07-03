//
// Created by calazans on 23/06/18.
//

#ifndef KDTREE_GLOBALS_H
#define KDTREE_GLOBALS_H


class Globals {
private:
    static double padding_;
public:
    static void definePadding(double padding){
        padding_ = padding;
    }
    static double getPadding(){
        return padding_;
    }
};


#endif //KDTREE_GLOBALS_H
