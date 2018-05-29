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

    World world = World::from("world.rt");
    Renderer renderer(windowWidth, windowHeight, imageWidth, imageHeight, f);
    renderer.render(world, "out.ppm");

    std::cout << std::endl << "Fim" << std::endl;
    return 0;
}