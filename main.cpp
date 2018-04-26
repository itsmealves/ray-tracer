#include <iostream>
#include <armadillo>
#include "things/Sphere.h"
#include "world/LightSource.h"
#include "world/World.h"
#include "engine/Renderer.h"

std::string toHex(int v) {
    std::stringstream stream;
    stream << std::hex << v;
    return stream.str();
}

std::string hexColor(arma::vec color) {
    return "#" + toHex(color(0)) + toHex(color(1)) + toHex(color(2));
}

int main(int argc, char *argv[]) {
    std::cout << "Ray tracer!" << std::endl;

    if(argc != 6) {
        std::cout << "Argumentos insuficientes. Saindo." << std::endl;
        return 1;
    }

    std::cout << "Configurações do motor de geração de imagem:" << std::endl;

    double f = std::stod(argv[1]);
    int windowWidth = std::stoi(argv[2]);
    int windowHeight = std::stoi(argv[3]);
    int imageWidth = std::stoi(argv[4]);
    int imageHeight = std::stoi(argv[5]);

    std::cout << "\t* Distância focal: " << f << std::endl;
    std::cout << "\t* Dimensões da janela de projeção: " << windowWidth << "x" << windowHeight << std::endl;
    std::cout << "\t* Dimensões da imagem final: " << imageWidth << "x" << imageHeight << std::endl << std::endl;

    World world(arma::vec({100, 100, 100}));
    std::cout << "Mundo criado com cor ambiente " << hexColor(world.ambientColor()) << std::endl;

    Sphere sphere1(arma::vec({255, 255, 255}), arma::vec({10, 0, 10}), 3);
    Sphere sphere2(arma::vec({255, 255, 255}), arma::vec({-10, 0, 10}), 3);
    std::cout << "Esfera instanciada:" << std::endl;
    std::cout << "\t* Cor: " << hexColor(sphere1.color()) << std::endl;
    std::cout << "\t* Centro: (" << sphere1.center()(0) << "," << sphere1.center()(1) << "," << sphere1.center()(2) << ")" << std::endl;
    std::cout << "\t* Raio: " << sphere1.r() << std::endl << std::endl;

    LightSource source1(arma::vec({0, 7, 5}), arma::vec({0.3, 0.05, 0.05}));
    LightSource source2(arma::vec({7, -7, 0}), arma::vec({0.05, 0.3, 0.05}));
    LightSource source3(arma::vec({-7, -7, 0}), arma::vec({0.05, 0.05, 0.3}));
    std::cout << "Fonte de luz criada em (" << source1.position()(0) << "," << source1.position()(1) << "," << source1.position()(2) << ")" << " com intensidade " << source1.intensity().t();
    std::cout << "Fonte de luz criada em (" << source2.position()(0) << "," << source2.position()(1) << "," << source2.position()(2) << ")" << " com intensidade " << source2.intensity().t();
    std::cout << "Fonte de luz criada em (" << source3.position()(0) << "," << source3.position()(1) << "," << source3.position()(2) << ")" << " com intensidade " << source3.intensity().t();

    world.addThing(&sphere1);
    world.addThing(&sphere2);
    world.addLightSource(source1);
    world.addLightSource(source2);
    world.addLightSource(source3);

    std::cout << "Adicionando elementos ao mundo" << std::endl;

    Renderer renderer(windowWidth, windowHeight, imageWidth, imageHeight, f);
    std::cout << "Motor iniciado" << std::endl;

    renderer.render(world, "out.ppm");
    std::cout << "Imagem out.ppm pronta" << std::endl;

    return 0;
}