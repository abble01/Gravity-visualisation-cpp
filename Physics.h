#pragma once

#include <vector>
#include "Body.h"

const double Gravconst = 6.6743e-11;

class Physics
{
public:
    void update(std::vector<Body>& bodies, double dt);
};