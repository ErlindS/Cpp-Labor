#include "AdvancedPlayer.hpp"

AdvancedPlayer::AdvancedPlayer(char const* team_name, char const* robot_name)
	: sim::Player{team_name, robot_name}
{}

void AdvancedPlayer::execute(PlayerBehaviour& behaviour) {
	behaviour.control(*this, AdvancedGameState{*this});
	draw_debug();
}

double linear_interpolation(double x, double x_min, double y_min, double x_max, double y_max) {
	double m = (y_max - y_min)/(x_max - x_min);
	double n = y_min - m * x_min;
	return m * x + n;
}

void AdvancedPlayer::advanced_targeting(
	  AdvancedGameState const& game_state
	, sim::Vector              Z
	, double                   k_1_min
	, double                   k_1_max
	, double                   k_2_max
){
	//prepare_kick(0.9, kick_energy_max());
	configure_kick(kick_energy_max(), 0.7);
	sim::Vector RB = game_state.ball.position - game_state.robot().position;
	sim::Vector BZ = Z - game_state.ball.position;
	RB  = RB * (1.0 / (RB.length() + 1e-6));
	//std::cout << RB.x << "<- Das ist x" << RB.y << "<- Das ist y\n" << std::endl;
	sim::Vector v_1 = BZ * (1.0 / (BZ.length() + 1e-6));
	sim::Vector v_2 = v_1.orthogonal();
	double cosalpha = v_1 * RB;
	if(cosalpha > 0.97){
		k_1_min = 0.1;
	}
	//std::cout << v_1.x << "<- Das ist x" << v_1.y << "<- Das ist y\n" << std::endl;
	double k_1 = linear_interpolation(cosalpha, 1, k_1_min, 0.4, k_1_max);
	double k_2 = linear_interpolation(cosalpha, 1, 0      , 0.0, k_2_max);
	if( v_2 * RB < 0){
		k_2 = -k_2;
	}
	sim::Vector P = game_state.ball.position - v_1 * k_1 - v_2 * k_2;
	//std::cout << P.x << "<- Das ist x" << P.y << "<- Das ist y\n" << std::endl;

	double phi =  v_1.orientation();
	set_pose(P, phi);
	return;
}
/*
void AdvancedPlayer::add_cross(
	  sim::Vector position
	, double size
	, sim::Color color
){
	sim::Vector v1 = position;
	sim::Vector v2 = position;
	sim::Vector v3 = position;
	sim::Vector v4 = position;
	v1.x += 0.20;
	v2.x -= 0.20;
	v3.y += 0.20;
	v4.y -= 0.20;
	add_line(position, v1, color, size);
	add_line(position, v2, color, size);
	add_line(position, v3, color, size);
	add_line(position, v4, color, size);
};


void AdvancedPlayer::add_arrow(
	  sim::Vector start
	, sim::Vector end
	, double arrow_head_length
	, double arrow_head_width
	, double size
	, sim::Color color
){
	sim::Vector d = end - start;
	sim::Vector n = d.orthogonal() * 0.5 * arrow_head_width / d.length();
	sim::Vector C = start + d* (1.0 - arrow_head_length / d.length());
	sim::Vector A = C + n;
	sim::Vector B = C - n;
	add_line(start, C, color, 0.1);
	add_line(end, A, sim::Color(255,255,255), 0.1);
	add_line(end, B, sim::Color(255,255,255), 0.1);
	add_line(A, B, sim::Color(255,255,255), 0.1);
};
*/
