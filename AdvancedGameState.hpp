#pragma once
#include <robot.hpp>
#include <vector>
#include "Vektoren.hpp"
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string_view>
#include <map>

#if 1
struct YellowAnnouncement {
	sim::RefereeAnnouncement value;
};
struct BlueAnnouncement {
	sim::RefereeAnnouncement value;
};

#else
// alternativ:
template<sim::Side>
struct TaggedAnnouncement {
	sim::RefereeAnnouncement value;
};
using YellowAnnouncement = TaggedAnnouncement<sim::Side::yellow>;
using BlueAnnouncement   = TaggedAnnouncement<sim::Side::blue>;
#endif


class AdvancedGameState
	: public sim::GameState
{
private:
	bool is_our_special_state(
		  YellowAnnouncement yellow_state
		, BlueAnnouncement   blue_state
	) const {
		if(announcement == yellow_state.value
			&& our_side() == sim::Side::yellow
		) {
			return true;
		}
		if(announcement == blue_state.value
			&& our_side() == sim::Side::blue
		) {
			return true;
		}
		return false;
	}
public:
	AdvancedGameState(sim::Player& player);
	
	sim::RobotState const& robot() const;
	
	sim::Side our_side() const;
	
	sim::Goal our_goal() const;
	
	sim::Goal their_goal() const;
	
	sim::Side their_side() const;
	
	std::vector<sim::RobotState> get_team(sim::Side side) const;
	
	std::vector<sim::RobotState> our_robots() const;
	
	std::vector<sim::RobotState> their_robots() const;
	
	std::vector<sim::RobotState> sort_robots_by_distance(
		  sim::Vector const& position
		, std::vector<sim::RobotState> robots
	) const;
	
	std::vector<sim::RobotState> sort_robots_by_distance2(
		  sim::Vector const& position
		, std::vector<sim::RobotState> robots
	) const;
	
	sim::RobotState closest_to(
		  sim::Vector const& position
		, std::vector<sim::RobotState> robots
	) const;
	
	std::vector<sim::RobotState> Erlindos() const;
	
	bool is_our_corner_kick() const {
		using A = sim::RefereeAnnouncement;
		return is_our_special_state(
			  YellowAnnouncement{A::corner_kick_yellow}
			, BlueAnnouncement{  A::corner_kick_blue}
		);
	}
	bool is_our_throw_in() const {
		using A = sim::RefereeAnnouncement;
		return is_our_special_state(
			  YellowAnnouncement{A::throw_in_yellow}
			, BlueAnnouncement{  A::throw_in_blue}
		);
	}
	/*
	kickoff_blue
	, kickoff_yellow
	, throw_in_blue
	, throw_in_yellow
	, corner_kick_blue
	, corner_kick_yellow
	, goal_kick_blue
	, goal_kick_yellow
	, normal
	*/
	
	bool is_our_goal_in() const {
		using A = sim::RefereeAnnouncement;
		return is_our_special_state(
			  YellowAnnouncement{A::goal_kick_yellow}
			, BlueAnnouncement{  A::goal_kick_blue}
		);
	}
	
	bool is_our_kickoff() const {
		using A = sim::RefereeAnnouncement;
		return is_our_special_state(
			  YellowAnnouncement{A::kickoff_yellow}
			, BlueAnnouncement{  A::kickoff_blue}
		);
	}

};
 
