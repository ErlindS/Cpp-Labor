#include "VorneStehen.hpp"


void Vornestehen::control(AdvancedPlayer& player, AdvancedGameState const& state) {
	double x = -2.75; 
	double y = -1;
	
	if(state.our_side() == sim::Side::yellow){
		x *= -1;
		y = 1;
	}
	//falls der Roboter Blau ist dann ist y = -1. Falls er gelb ist, dann ist y = 1
	
	if(y== -1){
	
	if( state.ball.position.x < -1.5  && (state.ball.position.y < 1 ||  state.ball.position.y > -1)){
		player.advanced_targeting(state, sim::Vector{x, 0}, 0.3, 0.15, 0.15);
	} else{
		player.set_pose(sim::Vector{-1.7, 0}, 0);
		}
	}else{
	
	if( state.ball.position.x > 1.5 && (state.ball.position.y < 1 ||  state.ball.position.y > -1 )){
		player.advanced_targeting(state, sim::Vector{x, 0}, 0.3, 0.15, 0.15);
	} else{
			player.set_pose(sim::Vector{1.7, 0}, 0);
		} 
	}
	/*
	if( fabs(state.ball.position.x) < 1.5){
		player.set_pose(sim::Vector{1.25, -0.75}, 0);
	}
	*/
}
