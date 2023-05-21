#pragma once
#include "PlayerBehaviour.hpp"
#include "AdvancedPlayer.hpp"
#include <optional>
#include "AdvancedGameState.hpp"

class Striker
	: public PlayerBehaviour
{
public:
	AdvancedPlayer::CornerKickMachine corner_kick_machine{};
	AdvancedPlayer::ThrowInMachine	  throw_in_machine{};
	
	void control(AdvancedPlayer& player, AdvancedGameState const& state) override;
};

class Striker2
	: public PlayerBehaviour
{
public:
	AdvancedPlayer::CornerKickMachine corner_kick_machine{};
	AdvancedPlayer::ThrowInMachine	  throw_in_machine{};
	
	void control(AdvancedPlayer& player, AdvancedGameState const& state) override;
};
