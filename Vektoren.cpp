#include "Vektoren.hpp"

sim::Vector operator+(sim::Vector a, sim::Vector b){
	return (sim::Vector(a.x + b.x,a.y + b.y));
}

sim::Vector operator*(sim::Vector a, double b){
	return( sim::Vector(a.x*b, a.y*b));
}

sim::Vector operator*(double b, sim::Vector a){
	return( sim::Vector(a.x*b, a.y*b));
}

sim::Vector operator-(sim::Vector a, sim::Vector b){
	return( sim::Vector(a.x - b.x, a.y - b.y));
}


sim::Vector operator/(sim::Vector a, int b){
	return( sim::Vector(a.x/b, a.y/b));
}

    
double operator*(sim::Vector a, sim::Vector b){
	return( a.x*b.x +a.y*b.y);
}

bool operator==(sim::Vector a, sim::Vector b){
	sim::Vector D = b-a;
	double eps = 0.01;
	return D*D < eps *eps;
	
}

