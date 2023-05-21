#include <cmath>
#include <robot.hpp>

sim::Vector operator+(sim::Vector a, sim::Vector b);
sim::Vector operator*(sim::Vector a, double b);

sim::Vector operator*(double b, sim::Vector a);

sim::Vector operator-(sim::Vector a, sim::Vector b);


sim::Vector operator/(sim::Vector a, int b);

// D.x*D.x + D.y*D.y < eps * eps
// sqrt(D.x*D.x + D.y*D.y) < sqrt(eps * eps)
// sqrt(D.x*D.x + D.y*D.y) < eps
    
double operator*(sim::Vector a, sim::Vector b);

bool operator==(sim::Vector a, sim::Vector b);
/*
sim::Vector orthogonaler_Vector(sim::Vector a){
    a.x *= -1;
    return a;
} */

// double Vector_laenge(sim::Vector a);


