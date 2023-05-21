#pragma once
#include "AdvancedGameState.hpp"
#include <robot.hpp>

/**
  * Deklaration der Klasse "AdvancedPlayer".
  * Die Headerdatei "AdvancedPlayer.hpp" kann hier nicht
  * inkludiert werden, da sich sonst eine zyklische Abhaengigkeit
  * ergeben wuerde.
  *
  * Da der Typ "AdvancedPlayer" in der Schnittstelle der Klasse
  * "PlayerBehaviour" aber benoetigt wird, erfolgt hier
  * eine Deklaration.
  */
class AdvancedPlayer;


/**
  * Basisklasse der Verhalten von Spielern.
  */
class PlayerBehaviour {
public:
	/**
	 * Dieses Methode muss in einer abgeleiteten Klasse ueberschrieben werden.
	 * Die Methode wird innerhalb von "AdvancedPlayer::execute" mit dem aktuellen
	 * Spielzustand "state" ausgefuehrt.
	 *
	 * Der Parameter "player" wird uebergeben, damit Aktionen ausgefuehrt werden
	 * koennen (configure_kick, set_pose, add_debug, ...)
	 */
	virtual void control(AdvancedPlayer& player, AdvancedGameState const& state) = 0; 
};
 
