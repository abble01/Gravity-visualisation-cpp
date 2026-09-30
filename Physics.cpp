#include "Physics.h"
#include <cmath>

namespace
{
    constexpr double Gravconstant = 6.6743e-11;
}
// f = G[(m1.m2)/r^2
void Physics::update(std::vector<Body>& bodies, double dt) {

    std::vector<sf::Vector2<double>> accelerations(
        bodies.size(),
        {0.0, 0.0}
    );

    for (std::size_t i = 0; i < bodies.size(); ++i)
    {
        for (std::size_t j = i + 1; j < bodies.size(); ++j)
        {
           const sf::Vector2<double> displacement = bodies[j].getPosition() - bodies[i].getPosition();
           const double distsquared = displacement.x * displacement.x +
               displacement.y * displacement.y;

           if (distsquared == 0.0) 
           {
               continue;
          
           }
           const double distance = std::sqrt(distsquared);
            
           const sf::Vector2<double> unitDirection = displacement / distance;
           const double accelmagnI = (Gravconstant * bodies[j].getMass()) / distsquared;
           accelerations[i] += unitDirection * accelmagnI;

           const double accelmagnJ =
               (Gravconstant * bodies[i].getMass()) / distsquared;
           accelerations[j] -= unitDirection * accelmagnJ;
        }

    }

    for (std::size_t i = 0; i < bodies.size(); ++i) 
    {
        bodies[i].applyAcceleration(accelerations[i], dt);
    }

    for (std::size_t i = 0; i < bodies.size(); ++i)
    {
        bodies[i].updatePosition(dt);
    }

}