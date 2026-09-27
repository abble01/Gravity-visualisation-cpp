#pragma once

#include <vector>
#include "Body.h"

const double Gravconst = 6.6743e-11;

class Physics
{
public:
    void update(std::vector<Body>& bodies, double dt){
    
        std::vector<sf::Vector2<double>> accelerations(
            bodies.size(),
            { 0.0, 0.0 }
        );

        for (std::size_t i = 0; i < bodies.size(); ++i) {

            for (std::size_t j = i + 1; i < bodies.size(); ++i) {

            }

        }
    
    };
};