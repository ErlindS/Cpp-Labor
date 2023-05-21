#include "AdvancedGameState.hpp"

AdvancedGameState::AdvancedGameState(sim::Player& player)
	: sim::GameState{player.game_state()}
{}
sim::RobotState const& AdvancedGameState::robot() const {
	return robots[my_index];
}
sim::Side AdvancedGameState::our_side() const {
	return robot().side;
}
sim::Goal AdvancedGameState::our_goal() const {
	if(our_side() == sim::Side::blue) {
		return sim::Goal::blue();
	} else {
		return sim::Goal::yellow();
	}
}
sim::Goal AdvancedGameState::their_goal() const {
	if(our_side() == sim::Side::blue) {
		return sim::Goal::yellow();
	} else {
		return sim::Goal::blue();
	}
}

sim::Side AdvancedGameState::their_side() const {
	if(our_side() == sim::Side::blue) {
		return sim::Side::yellow;
	} else {
		return sim::Side::blue;
	}
}

/*
#include <algorithm>
#include <iostream>

int main(){
    int x[] {
        3, 6, 1, 7, 19
    };
    int m = 5;
    auto cmp = [
		&// das hier ist m
	](int a, int b) {
        int da = a - m;
        int db = b - m;
        return std::abs(da) < std::abs(db);
    };
    std::sort(
        std::begin(x)
        , std::end(x)
        , cmp
    );
    for(auto v : x) {
        std::cout << v << '\n';
    }
    return 0;
} 
*/

std::vector<sim::RobotState> AdvancedGameState::sort_robots_by_distance2(
		  sim::Vector const& position
		, std::vector<sim::RobotState> robots
	) const{/*
		auto cmp = [position](std::vector<sim::RobotState> robots){
			double v1 = (position - robots[x].position).length();
			double v2 = (position - robots[x+1].position).length();
			return std::abs(v1) < std::abs(v2);
		};*/
		std::sort(
			  robots.begin()
			, robots.end()
			, [position](sim::RobotState a, sim::RobotState b){
				double v1 = (position - a.position).length();
				double v2 = (position - b.position).length();
				return std::abs(v1) < std::abs(v2);
			}
		);
		
		return robots;
	}

std::vector<sim::RobotState> AdvancedGameState::sort_robots_by_distance(
		  sim::Vector const& position
		, std::vector<sim::RobotState> robots
	) const{
	//sim::Vector pos = position;
	//std::map<int, std::vector<sim::RobotState>> m;
	//sim::RobotState temp;
	double len[robots.size()];
	for(int i = 0; i < robots.size(); i++){
		len[i] = (robots[i].position - position).length();
		//m.insert( std::pair<int, std::vector<sim::RobotState>>(robots[i].position - position).length(), robots[i]);
		std::cout << len[i] << " das sind die Unterschiedlichen laengen von den Robotern " << robots[i].name  << std::endl;
	}
	//bis hier hin klappt es 
	
	//std::vector<sim::RobotState, int> k;
	double test;
	sim::RobotState temp;
	for(int j = 0; j < robots.size()-1; j++){
	for(int i = 0; i < robots.size()-1; i++){
			if(len[i] < len[i+1]){
				test = len[i+1];
				temp = robots[i+1];
				
				len[i+1] = len[i];
				robots[i+1] = robots[i];
				
				len[i] = test;
				robots[i] = temp;
		}
	}
	}
	for(int i = 0; i < robots.size(); i++){
	//	len[i] = (robots[i].position - position).length();
		//m.insert( std::pair<int, std::vector<sim::RobotState>>(robots[i].position - position).length(), robots[i]);
		std::cout << len[i] << " das sind die Unterschiedlichen laengen von den Robotern aber sortiert" << std::endl;
	}
	/*
	for(int i = 0; i < robots.size()-1; i++){
		for(int j = 0; j < robots.size()-1;j++){
			if(len[j] > len[i+1]){
				temp = robots[i+1];
				robots[i+1] = robots[j];
				robots[j] = temp;
			};
		}
	}
	*/
	//std::sort(m.begin(), m.end(), m[1]);
	return robots;
};

sim::RobotState AdvancedGameState::closest_to(
		  sim::Vector const& position
		, std::vector<sim::RobotState> robots
	) const{
		std::vector<sim::RobotState> M = sort_robots_by_distance(position, robots); 
		return M[1];
	};

std::vector<sim::RobotState> AdvancedGameState::get_team(sim::Side side) const{
	std::vector<sim::RobotState> v1 = robots;
	std::vector<sim::RobotState> v2;
	int x = 0;
	for(int i = 0; i < robots.size(); i++){
		if(v1[i].side == side){
			v2.push_back(v1[i]);
			//v2[x] = v1[i];
			x++;
		}
	}
	return 	v2;
};

std::vector<sim::RobotState> AdvancedGameState::our_robots() const{
	sim::Side s = our_side();
	std::vector<sim::RobotState> v1 = robots;
	std::vector<sim::RobotState> v2;
	int x = 0;
	for(int i = 0; i < robots.size(); i++){
		if(v1[i].side == s){
			v2.push_back(v1[i]);
			x++;
		}
	}
	return 	v2;
};

std::vector<sim::RobotState> AdvancedGameState::their_robots() const{
	sim::Side s = their_side();
	std::vector<sim::RobotState> v1 = robots;
	std::vector<sim::RobotState> v2;
	int x = 0;
	for(int i = 0; i < robots.size(); i++){
		if(v1[i].side == s){
			v2.push_back(v1[i]);
			x++;
		}
	}
	return 	v2;
};


std::vector<sim::RobotState> AdvancedGameState::Erlindos() const{
	std::vector<sim::RobotState> v1 = robots;
	std::vector<sim::RobotState> v2;
	for(int i = 0; i < robots.size(); i++){
		if(v1[i].name == "Erlind1"){
			v2.push_back(v1[i]);
		}
	}
	return 	v2;
};



