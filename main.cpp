
#include <iostream>
#include <cmath>
#include "AdvancedPlayer.hpp"
#include <robot.hpp>
#include "PlayerBehaviour.hpp"
#include "AdvancedGameState.hpp"
#include "Bambino.hpp"
#include "Goalkeeper.hpp"
#include "Striker.hpp"
#include <vector>
#include <algorithm>
#include <array>
#include <functional>
#include <string_view>
#include "VorneStehen.hpp"
 

bool Am_I_First(sim::GameState const & state){
	for(int i = 0; i < state.robots.size(); i++)
	{
		if(state.robots[i].name == "Erlind1"){
			return i == state.my_index;
		}
	}
	return false;
}


int main() {
	AdvancedPlayer Spieler1("Team", "Erlind1");
	Striker s1;
	Striker s2;
	
	
	sim::GameState Gstate = Spieler1.game_state();
	if(Am_I_First(Gstate)){
		while(true){
		Spieler1.execute(s2);
		}
	}else{
		while(true){
		Spieler1.execute(s1);
		}
	}
	
	
	while(true){
		Spieler1.execute(s1);
	}
	
