#include <iostream>
#include <KDTree/KDTree.h>
#include "MissingMethods.h"

#ifdef _TESTE
int main() {
    std::vector<const Object*> list;
    std::vector<const Object*> test;

    arma::vec c1 = {1,1,1};
    arma::vec c2 = {1,2,1};
    arma::vec c3 = {2,1,5};
    arma::vec c4 = {1,4,1};
    arma::vec c5 = {-1000000000,-100000003,-1000};

    Ray raio = Ray(c1,c4);

    auto o1 = new Object(c1,1);
    auto o2 = new Object(c2,2);
    auto o3 = new Object(c3,3);
    auto o4 = new Object(c4,4);
    auto o5 = new Object(c5,1);

    auto kd = new KDTree();

    list.push_back(o1);
    list.push_back(o2);
    list.push_back(o3);
    list.push_back(o4);
    list.push_back(o5);

    kd->insert(list);
    kd->ValidInfo();
    test = kd->hits(c1,c2);

    for (auto& obj: test) {
        printf("\n%s",obj->toString().c_str());

    }
    delete kd;

    delete o1;
    delete o2;
    delete o3;
    delete o4;
}
#endif