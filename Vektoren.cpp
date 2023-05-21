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

// D.x*D.x + D.y*D.y < eps * eps
// sqrt(D.x*D.x + D.y*D.y) < sqrt(eps * eps)
// sqrt(D.x*D.x + D.y*D.y) < eps
    
double operator*(sim::Vector a, sim::Vector b){
	return( a.x*b.x +a.y*b.y);
}

bool operator==(sim::Vector a, sim::Vector b){
	sim::Vector D = b-a;
	double eps = 0.01;
	return D*D < eps *eps;
	// D.x*D.x + D.y*D.y < eps * epsmain.cpp:85:41: warning: ‘sim::RobotState sim::Player::robot()’ is deprecated: Ab Versuch 3 nicht mehr verwenden! [-Wdeprecated-declarations]
	// sqrt(D.x*D.x + D.y*D.y) < sqrt(eps * eps)
	// sqrt(D.x*D.x + D.y*D.y) < eps
	// return D.length() < eps;
	//return false;
}
/*
sim::Vector orthogonaler_Vector(sim::Vector a){
    a.x *= -1;
    return a;
} */

// double Vector_laenge(sim::Vector a){
// 	return sqrt(a.x * a.x + a.y * a.y);
// }

