#pragma once
#include "PlayerBehaviour.hpp"
#include "AdvancedPlayer.hpp"

class Bambino
	: public PlayerBehaviour
{
public:
	void control(AdvancedPlayer& player, AdvancedGameState const& state) override {
		sim::Vector v1 = state.ball.position;
		player.set_pose(v1,0);
	}
};
