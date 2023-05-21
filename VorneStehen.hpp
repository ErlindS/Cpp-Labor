#pragma once
#include "PlayerBehaviour.hpp"
#include "AdvancedPlayer.hpp"
#include <optional>
#include "AdvancedGameState.hpp"

class Vornestehen
	: public PlayerBehaviour
{
public:
	
	
	void control(AdvancedPlayer& player, AdvancedGameState const& state) override;
};
