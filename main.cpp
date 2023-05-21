
#include <iostream>
#include <cmath>
#include "AdvancedPlayer.hpp"
#include <robot.hpp>
#include "PlayerBehaviour.hpp"
#include "AdvancedGameState.hpp"
#include "Bambino.hpp"
#include "Goalkeeper.hpp"
//#include "Bambino.hpp"
//#include "Vektoren.hpp"
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
 
 
//advanced_targeting(&p1, v2, 0.03, 0.7, -0.7);

int main() {
	
	
	
	
	
	
	
	
	
	//AdvancedPlayer Spieler1("Team_C", "Erlind1");
	AdvancedPlayer Spieler1("Team", "Erlind1");
	Striker s1;
	Striker s2;
	//AdvancedPlayer Spieler4("Team2", "Erlind4");
	//AdvancedPlayer Spieler5("Team", "Erlind5");
	//AdvancedPlayer Spieler6("Team2", "Erlind6");
	//AdvancedPlayer Spieler7("Team2", "Erlind7");

	//Bambino p1;
	//Goalkeeper p1;
	//Vornestehen vs1;
	//Goalkeeper p2;
	//Striker s2;
	//sim::Side MeineSeite = state.our_side();
	//int ich = state.my_index;
	
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

		//Spieler5.execute(vs1);
		//Spieler1.execute(p1);
		Spieler1.execute(s1);
		//Spieler4.execute(p1);
		//Spieler1.execute(s1);
		//Spieler5.execute(vs1);
	}
	/*
	//Vorbereitungsaufgabe 10
	int x = 10;
	std::string str1 = "Fussball";
	std::string str2 = "Fussballl";
	std::string str3 = "Fussbazz";
	std::cout << str1[0] << std::endl;
	if(str1 < str3 ){
	std::cout << str1.size() << std::endl;}
	std::cout << str1 + str2 << std::endl;
	std::string k = std::to_string(x);
	sim::DebugString teststring{sim::Vector{0,0}, 0.5, sim::Color(0,0,0), str1};
	Spieler1.add_debug(teststring);
	Spieler1.draw_debug();
	
	//Vorbereitungsaufgabe 11
	std::vector<int> vi;
	vi.push_back(1);
	if(vi.empty()){
		
	}
	vi.front();
	vi.back();
	vi.size();
	for(int i : vi){
		vi[i];
	}
	std::sort(vi.begin(), vi.end());
	
	*/
	//Vorbereitungsaufgabe 12
	
	/*AdvancedGameState state(Spieler1);
		AdvancedGameState state2(Spieler2);
		AdvancedGameState state3(Spieler3);
		AdvancedGameState state4(Spieler4);*/
		



	//sim::Player p2;
	//AdvancedGameState state(Spieler);execute
	//std::cout << MeineSeite << std::endl;
	//sim::RobotState ich = robot();




	/* Loesung fuer Aufgabe 6
	Spieler.add_cross( v1, 0.1, sim::Color{0,255,0});
	Spieler.add_arrow( v1, v3, 0.25, 0.5, 1, sim::Color{0,0,0});
	Spieler.draw_debug();
	*/











	/* //Angreifer mit advanced_targeting
	while(true){
	AdvancedGameState state(Spieler);
	advanced_targeting(Spieler, v2, 0.03, 0.7, -0.7, ich);
	}

	*/



	/*//Testabwehrspieler der sich nach der y Koordinate des Balles bewegt
		* while(true){
	AdvancedGameState state(Spieler);
	double k = Spieler.game_state().ball.position.y;
	sim::Vector v{-2.75, k};
	if(k < -0.5){
		v.y = -0.5;
	}
	if(k > 0.5){
		v.y = 0.5;
	}
	Spieler.set_pose(v, 0);
	*/


	/* //Testabwehrspieler der nur nach unten und oben fährt
	if(MeineSeite == sim::Side::yellow){
			if(0.01 <     (Spieler.game_state().robots[ich].position.x - v1.x) *
							(Spieler.game_state().robots[ich].position.x - v1.x) +
							(Spieler.game_state().robots[ich].position.y - v1.y) *
							(Spieler.game_state().robots[ich].position.y - v1.y)
			){
				Spieler.set_pose(v1,0);
			} else {
				v1.y *= -1;
			}
			
		}
	}*/
}
