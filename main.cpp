#include <iostream>
#include <armadillo>
#include "things/Sphere.h"
#include "world/LightSource.h"
#include "world/World.h"
#include "engine/Renderer.h"
#include "things/Triangle.h"


int main(int argc, char *argv[]) {
    std::cout << "Ray tracer!" << std::endl;

    if(argc != 6) {
        std::cout << "Argumentos insuficientes. Saindo." << std::endl;
        return 1;
    }

    double f = std::stod(argv[1]);
    int windowWidth = std::stoi(argv[2]);
    int windowHeight = std::stoi(argv[3]);
    int imageWidth = std::stoi(argv[4]);
    int imageHeight = std::stoi(argv[5]);

    World world(arma::vec({50, 50, 50}));
    Material material(arma::vec({200, 200, 200}), arma::vec({200, 200, 200}), 10);

    Sphere sphere1(material, arma::vec({10, 0, 10}), 3);
    Sphere sphere2(material, arma::vec({-10, 0, 10}), 3);

    Triangle triangle1(material, arma::vec({0,-3,12}), arma::vec({-2,2,10}), arma::vec({2, 2, 10}));

    LightSource source1(arma::vec({0, 5, 5}), arma::vec({0.3, 0.05, 0.05}));
    LightSource source2(arma::vec({5, -5, 5}), arma::vec({0.05, 0.3, 0.05}));
    LightSource source3(arma::vec({-5, -5, 5}), arma::vec({0.05, 0.05, 0.3}));

    world.addThing(&sphere1);
    world.addThing(&sphere2);
    world.addThing(&triangle1);
    world.addLightSource(source1);
    world.addLightSource(source2);
    world.addLightSource(source3);

    Renderer renderer(windowWidth, windowHeight, imageWidth, imageHeight, f);
    renderer.render(world, "out.ppm");

    std::cout << std::endl << "Fim" << std::endl;
    return 0;
}