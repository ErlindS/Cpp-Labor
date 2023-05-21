#pragma once
#include "PlayerBehaviour.hpp"
#include "AdvancedPlayer.hpp"


class Goalkeeper
	: public PlayerBehaviour
{
public:
    void control(AdvancedPlayer& player, AdvancedGameState const& state)override{
		double k = state.ball.position.y;
		sim::Side s = state.our_side();
		double x = -2.75;

		if(state.our_side() == sim::Side::blue) {
			x *= -1;
		}

		k = state.ball.position.y; 
		sim::Vector v{x, k};
		if(k < -0.5) {
			v.y = -0.5;
		}
		if(k > 0.5) {
			v.y = 0.5;
		}
		player.set_pose(v, 0);
	}
};
