#pragma once
#include <robot.hpp>
#include "AdvancedGameState.hpp"
#include "PlayerBehaviour.hpp"
#include "Vektoren.hpp"
#include <iostream>


class AdvancedPlayer
	: public sim::Player
{
public:
	AdvancedPlayer(char const* team_name, char const* robot_name);
	void execute(PlayerBehaviour& behaviour);

	void add_cross(
		  sim::Vector position
		, double size
		, sim::Color color
	);

	void add_arrow(
		  sim::Vector start
		, sim::Vector end
		, double arrow_head_length
		, double arrow_head_width
		, double size
		, sim::Color color
	); 

	void advanced_targeting(AdvancedGameState const& game_state, sim::Vector Z, double k_1_min, double k_1_max, double k_2_max);

	//Die ganze CornerKickMachine ist fuer die Ecken zustaendig 
	
	struct CornerKickMachine {
		enum class State {
			  MOVES_TO_POS_1
			, MOVES_TO_POS_2
			, DONE
			, INVALID
		};
		State       state;
		sim::Vector position_1{};
		sim::Vector position_2{};
		
		CornerKickMachine(
			  sim::Vector const& position_1
			, sim::Vector const& position_2
		)
			: state{State::MOVES_TO_POS_1}
			, position_1{position_1}
			, position_2{position_2}
		{}
		
		CornerKickMachine()
			: state{State::INVALID}
		{}
		
		// ??
		void invalidate() {
			state = State::INVALID;
		}
		
		State process(AdvancedPlayer& player, AdvancedGameState const& state) {
			auto has_arrived_at_position = [&](sim::Vector const& target) {
				double eps = 5e-2;
				sim::Vector R = state.robot().position;
				
				player.set_pose(target, (state.ball.position - R).orientation());
				
				return (R - target).length() < eps;
			};

			
			if(this->state == State::MOVES_TO_POS_1) {
				std::cout << "State::MOVES_TO_POS_1\n";
				if(has_arrived_at_position(position_1)) {
					this->state = State::MOVES_TO_POS_2;
				}
			}
			else if(this->state == State::MOVES_TO_POS_2) {
				std::cout << "State::MOVES_TO_POS_2\n";
				if(has_arrived_at_position(position_2)) {
					this->state = State::DONE;
				}
			} else if(this->state == State::DONE) {
				std::cout << "State::DONE\n";
			} else {
				std::cout << "State::INVALID\n";
// 				has_arrived_at_position(position_2);
				// Gebe Warnung auf konsole aus...
			}
			return this->state;
		}
	};
	
	struct ThrowInMachine {
		enum class State {
			  MOVES_TO_POS_1
			, MOVES_TO_POS_2
			, MOVES_TO_POS_3
			, DONE
			, INVALID
		};
		
		State       state;
		sim::Vector position_1{};
		sim::Vector position_2{};
		sim::Vector position_3{};
	
		ThrowInMachine(
			  sim::Vector const& position_1
			, sim::Vector const& position_2
			, sim::Vector const& position_3
		)
			: state{State::MOVES_TO_POS_1}
			, position_1{position_1}
			, position_2{position_2}
			, position_3{position_3}
		 {}
		 
		ThrowInMachine()
			: state{State::INVALID}
		{}
		
		void invalidate() {
			state = State::INVALID;
		}
			
		State process(AdvancedPlayer& player, AdvancedGameState const& state) {
			auto has_arrived_at_position = [&](sim::Vector const& target) {
				double eps = 5e-2;
				sim::Vector R = state.robot().position;
				//Hier wird gesagt, dass der Roboter sich zu der Position hinbewegen soll.
				player.set_pose(target, (state.ball.position - R).orientation());
				//der Lambda ausdruck wird verlassen, wenn die Distanz zwischen Ball und Roboter sehr klein ist
				return (R - target).length() < eps;
			};
			if(this->state == State::MOVES_TO_POS_1) {
				std::cout << "Pos1\n";
				if(has_arrived_at_position(position_1)) {
					this->state = State::MOVES_TO_POS_2;
				}
			}
			else if(this->state == State::MOVES_TO_POS_2) {
				std::cout << "Pos2\n";
				if(has_arrived_at_position(position_2)) {
					this->state = State::MOVES_TO_POS_3;
				}
			} else if(this->state == State::MOVES_TO_POS_3) {
				std::cout << "Pos3\n";
				if(has_arrived_at_position(position_3)) {
					this->state = State::DONE;
				}
			
			} else if(this->state == State::DONE) {
				std::cout << "State::DONE\n";
			} else {
				std::cout << "State::INVALID\n";
// 				has_arrived_at_position(position_2);
				// Gebe Warnung auf konsole aus...
			}
			return this->state;
		}
	};
};
 
