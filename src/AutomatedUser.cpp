/**
 * @file Control.cpp
 * @author  Karim Jana <karimjana@gmail.com>
 * @date	June, 2015.
 * @version 1.0
 * @details Proffesor Doug Ferguson - C++ class
 *
 * @brief This is my AutomatedUser implementation file.  This code creates a random play selector
 * to act as a virtual user.
 */
#include <iostream>
#include <random>
#include <array>
#include "AutomatedUser.h"

/**
 * Get the random play from the available moves in the game board.
 *
 * @param boardPlays A list of possible moves.
 * @return A string row and column pair selection.
 * @reference http://en.cppreference.com/w/cpp/algorithm/random_shuffle
 */
std::string AutomatedUser::generateRandomBoardInput(
		std::vector<std::string> boardPlays) {
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(boardPlays.begin(), boardPlays.end(), g);
	/*std::cout << "shuffled plays: " <<std::endl;
	 for(int i=0; i < boardPlays.size(); i++){
	 std::cout << "move: "<<boardPlays[i] << "-- number: "<< i << std::endl;
	 }*/
	return boardPlays[0];
}

/**
 * Gets default value to insert when AutomatedUser instance plays.
 *
 * @return constant VALUE
 */
int AutomatedUser::getValue() {
	return this->VALUE;
}
