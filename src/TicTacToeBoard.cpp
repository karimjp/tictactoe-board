/**
 * @file TicTacToeBoard.cpp
 * @author  Karim Jana <karimjana@gmail.com>
 * @date	June, 2015.
 * @version 1.0
 * @details Proffesor Doug Ferguson - C++ class
 *
 * @brief This is the tic tac toe board implentation file.
 */

#include <iostream>
#include <array>
#include "TicTacToeBoard.h"
#include <vector>

/**
 * Constructor that initializes all the tic tac toe board spaces to 0
 */
TicTacToeBoard::TicTacToeBoard() {
	std::cout
			<< "Welcome to Tic Tac Toe! You can select your cell choosing a row and column from 1-3.";
	std::cout << std::endl;

	const int INITIALIZE = 0;
	for (int r = 1; r <= this->ROWS; r++) {
		for (int c = 1; c <= this->COLUMNS; c++) {
			this->setBoardValue(r, c, INITIALIZE);
		}
	}
}
;

/**
 * Allows access to tic tac toe board array to modify values
 */

void TicTacToeBoard::setBoardValue(int row, int column, int value) {
	/*if (row == 0 or column == 0){
	 std::cout <<"There is no value 0 . Try from 1 to 3";
	 break;
	 }*/
	row = row - 1;
	column = column - 1;
	this->board[row][column] = value;
}
;

std::array<std::array<int, 3>, 3> TicTacToeBoard::getBoard() {
	return this->board;
}
;

/**
 * Generates a list of all possible plays in the board.
 *
 * @return possiblePlays
 */
std::vector<std::string> TicTacToeBoard::getBoardPlays() {
	std::array<std::array<int, 3>, 3> board = this->getBoard();
	std::vector<std::string> possiblePlays;
	int i = 0;
	for (int r = 0; r < this->ROWS; r++) {
		for (int c = 0; c < this->COLUMNS; c++) {
			if (board[r][c] == 0) {
				possiblePlays.push_back(
						std::to_string(r + 1) + std::to_string(c + 1));
				i++;
			}
		}
	}
	return possiblePlays;
}
;

char TicTacToeBoard::getUserMoveIcon() {
	return this->userMoveIcon;
}
;

char TicTacToeBoard::getAutomatedPlayerMoveIcon() {
	return this->automatedPlayerMoveIcon;
}
;

/**
 * Draws board with 'X' and 'O' based on the user's values in the table.
 */

void TicTacToeBoard::drawBoard() {
	std::array<std::array<int, 3>, 3> board = this->getBoard();
	for (int r = 0; r < this->ROWS; r++) {
		for (int c = 0; c < this->COLUMNS; c++) {
			if (board[r][c] == 1) {
				std::cout << this->getUserMoveIcon() << '|';
			} else if (board[r][c] == 2) {
				std::cout << this->getAutomatedPlayerMoveIcon() << '|';
			} else {
				std::cout << " |";
			}
		}
		std::cout << std::endl;
	}
}
;

/**
 * Determines if human user or automated user is a winner and how it won.
 *
 * @return boolean - true = game over, false = game not over
 */
bool TicTacToeBoard::isGameOver() {
	std::array<std::array<int, 3>, 3> board = this->getBoard();
	int humanUser = 0;
	int automatedUser = 0;
	// checking row wins
	for (int r = 0; r < this->ROWS; r++) {
		humanUser = 0;
		automatedUser = 0;
		for (int c = 0; c < this->COLUMNS; c++) {
			// checking rows
			if (board[r][c] == 1) {
				humanUser += 1;
				if (humanUser == 3) {
					std::cout << "Human User Wins by rows!" << std::endl;
					return true;
				}
			}
			if (board[r][c] == 2) {
				automatedUser += 2;
				if (automatedUser == 6) {
					std::cout << "Automated User Wins by rows!" << std::endl;
					return true;
				}
			}
		}
	}
	// checking column wins
	for (int c = 0; c < this->COLUMNS; c++) {
		humanUser = 0;
		automatedUser = 0;
		for (int r = 0; r < this->ROWS; r++) {
			if (board[c][r] == 1) {
				humanUser += 1;
				if (humanUser == 3) {
					std::cout << "Human User Wins by columns! " << std::endl;
					return true;
				}
			}
			if (board[c][r] == 2) {
				automatedUser += 2;
				if (automatedUser == 6) {
					std::cout << "Automated User Wins by columns!" << std::endl;
					return true;
				}
			}
		}
	}

	//checking diagonals
	//left-right
	int traverse = 0;
	humanUser = 0;
	automatedUser = 0;
	while (traverse < this->ROWS) {
		if (board[traverse][traverse] == 1) {
			humanUser++;
			if (humanUser == 3) {
				std::cout << "Human User Wins by diagonal!" << std::endl;
				return true;
			}
		}
		if (board[traverse][traverse] == 2) {
			automatedUser += 2;
			if (automatedUser == 6) {
				std::cout << "AutomatedUser Wins by diagonal!" << std::endl;
				return true;
			}
		}
		traverse++;
	}

	//right-left
	int traverse_c = this->ROWS - 1;
	int traverse_r = 0;
	humanUser = 0;
	automatedUser = 0;
	while (traverse_c >= 0) {
		if (board[traverse_r][traverse_c] == 1) {
			humanUser++;
			if (humanUser == 3) {
				std::cout << "Human User Wins by diagonal!" << std::endl;
				return true;
			}
		}
		if (board[traverse_r][traverse_c] == 2) {
			automatedUser += 2;
			if (automatedUser == 6) {
				std::cout << "AutomatedUser Wins by diagonal!" << std::endl;
				return true;
			}
		}
		traverse_c--;
		traverse_r++;
	}

	if ((this->getBoardPlays()).size() == 0) {
		std::cout << "It's a tie!" << std::endl;
		return true;
	}
	return false;

}
;

