#include <cmath>
#include <robot.hpp>

sim::Vector operator+(sim::Vector a, sim::Vector b);
sim::Vector operator*(sim::Vector a, double b);

sim::Vector operator*(double b, sim::Vector a);

sim::Vector operator-(sim::Vector a, sim::Vector b);


sim::Vector operator/(sim::Vector a, int b);

    
double operator*(sim::Vector a, sim::Vector b);

bool operator==(sim::Vector a, sim::Vector b);



