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
    Material material1(arma::vec({200, 200, 200}), 0);
    Material material2(arma::vec({120, 120, 120}), 10);

    Sphere sphere1(material2, arma::vec({10, 0, 10}), 3);
    Sphere sphere2(material2, arma::vec({-10, 0, 10}), 3);

    Plane plane1(material1, arma::vec({0, -5, 0}), arma::vec({0, 1, 0}));
    Triangle triangle1(material2, arma::vec({0,-4.5,7}), arma::vec({-13,-4.5,13}), arma::vec({13, -4.5, 13}));

    LightSource source1(arma::vec({0, 7, 5}), arma::vec({0.25, 0.25, 0.25}));
    LightSource source2(arma::vec({5, 5, 5}), arma::vec({0.25, 0.20, 0.05}));
    LightSource source3(arma::vec({-5, 5, 5}), arma::vec({0.05, 0.25, 0.20}));

    world.addThing(&plane1);
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