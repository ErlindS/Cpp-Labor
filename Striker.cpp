#include "Striker.hpp"


void Striker::control(AdvancedPlayer& player, AdvancedGameState const& state) {
	double x = -2.75;
	
	if(state.our_side() == sim::Side::yellow){
		x *= -1;
	}
	if(state.is_our_corner_kick()) {
		if(corner_kick_machine.state == AdvancedPlayer::CornerKickMachine::State::INVALID) {
			double abs_x = sim::Pitch::length() / 2.0 + 0.33;
			double abs_y = sim::Pitch::width()  / 2.0 + 0.33;
			double x = state.ball.position.x < 0.0 ? -abs_x : abs_x;
			double y = state.ball.position.y < 0.0 ? -abs_y : abs_y;
			sim::Vector target{x, y};
			sim::Vector temp{state.robot().position.x, y};
			//sim::Vector temp{x, state.robot().position.y};
			corner_kick_machine = AdvancedPlayer::CornerKickMachine{temp, target};
		}
		if(corner_kick_machine.process(player, state) == AdvancedPlayer::CornerKickMachine::State::DONE) {
			sim::Vector v1{x,0};
			
			player.advanced_targeting(state, v1, 0.3, 0.7, -0.7);
		}
	}/* else if(state.is_our_throw_in()) {
		corner_kick_machine.invalidate();*/
	else {
		corner_kick_machine.invalidate();
		sim::Vector v1{x,0};
		player.advanced_targeting(state, v1, 0.3, 0.3, 0.3);
		
	}
	
	if(state.is_our_throw_in()){
		if(throw_in_machine.state == AdvancedPlayer::ThrowInMachine::State::INVALID) {
			
			
		double x1 = state.ball.position.x;
		double y1 = state.ball.position.y;
		double ky = 0.5;
		double kx = 0.5;
		if(state.ball.position.y > 0){
			ky *= -1;
		}
		if(state.ball.position.x > 0){
			kx *= -1;
		}
		
		sim::Vector Pos1{x1, y1+ky};
		sim::Vector Pos2{x1+ kx, y1};
		sim::Vector Pos3{x1, y1-(ky* 1/2)};
		
		throw_in_machine = AdvancedPlayer::ThrowInMachine{Pos1, Pos2, Pos3};
		}
		 
		if(throw_in_machine.process(player, state) == AdvancedPlayer::ThrowInMachine::State::DONE) {
			sim::Vector v1{x,0};
			player.advanced_targeting(state, v1, 0.07, 0.5, -0.5);
		}
		
	} else if(state.is_our_corner_kick()) {
		throw_in_machine.invalidate();
	} else {
		throw_in_machine.invalidate();
		sim::Vector v1{x,0};
		player.advanced_targeting(state, v1, 0.3, 0.3, 0.3);
																											
	}
}

void Striker2::control(AdvancedPlayer& player, AdvancedGameState const& state) {
	double x = -2.75;
	
	if(state.our_side() == sim::Side::yellow){
		x *= -1;
	}
	if(state.is_our_corner_kick()) {
		if(corner_kick_machine.state == AdvancedPlayer::CornerKickMachine::State::INVALID) {
			double abs_x = sim::Pitch::length() / 2.0 + 0.33;
			double abs_y = sim::Pitch::width()  / 2.0 + 0.33;
			double x = state.ball.position.x < 0.0 ? -abs_x : abs_x;
			double y = state.ball.position.y < 0.0 ? -abs_y : abs_y;
			sim::Vector target{x, y};
			sim::Vector temp{state.robot().position.x, y};
			//sim::Vector temp{x, state.robot().position.y};
			corner_kick_machine = AdvancedPlayer::CornerKickMachine{temp, target};
		}
		if(corner_kick_machine.process(player, state) == AdvancedPlayer::CornerKickMachine::State::DONE) {
			sim::Vector v1{x,0};
			player.advanced_targeting(state, v1, 0.3, 0.7, -0.7);
		}
	}/* else if(state.is_our_throw_in()) {
		corner_kick_machine.invalidate();*/
	else {
		corner_kick_machine.invalidate();
		sim::Vector v1{x,0};
		player.advanced_targeting(state, v1, 0.5, 0.5, 0.5);
		
	}
	
	if(state.is_our_throw_in()){
		if(throw_in_machine.state == AdvancedPlayer::ThrowInMachine::State::INVALID) {
			
		double x1 = state.ball.position.x;
		double y1 = state.ball.position.y;
		double ky = 0.5;
		double kx = 0.5;
		if(state.ball.position.y > 0){
			ky *= -1;
		}
		if(state.ball.position.x > 0){
			kx *= -1;
		}
		
		sim::Vector Pos1{x1, y1+ky};
		sim::Vector Pos2{x1+ kx, y1};
		sim::Vector Pos3{x1, y1-(ky* 1/2)};
		
		throw_in_machine = AdvancedPlayer::ThrowInMachine{Pos1, Pos2, Pos3};
		}
		 
		if(throw_in_machine.process(player, state) == AdvancedPlayer::ThrowInMachine::State::DONE) {
			sim::Vector v1{x,0};
			player.advanced_targeting(state, v1, 0.07, 0.5, -0.5);
		}
		
	} else if(state.is_our_corner_kick()) {
		throw_in_machine.invalidate();
	} else {
		throw_in_machine.invalidate();
		sim::Vector v1{x,0};
		player.advanced_targeting(state, v1, 0.5, 0.5, 0.5);
																											
	}
}
	

	
	
