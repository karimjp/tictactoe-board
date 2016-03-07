/**
 * @file main.cpp
 * @author  Karim Jana <karimjana@gmail.com>
 * @date	June, 2015.
 * @version 1.0
 * @details Proffesor Doug Ferguson - C++ class
 *
 * @section DESCRIPTION
 *
 * This is the main program that represents the interaction between
 * all objects of the TicTacToe Game.  The game feeds from user input
 * until he wins or loses to the random play based automated user.
 */

#include <iostream>

#include "TestDrive.h"
#include "TicTacToeBoard.h"
#include "Control.h"
#include "AutomatedUser.h"

using namespace std;

int main() {
	//TestDrive myTestDriver;

	//myTestDriver.test();
	//myTestDriver.controlTest();
	//myTestDriver.TicTacToeBoardTest();
	//myTestDriver.AutomatedUserTest();

	TicTacToeBoard gameBoard;
	Control controller;
	AutomatedUser computerUser;
	bool humanUserTurn = true;
	const int HUMAN_USER_VALUE = 1;
	gameBoard.drawBoard();

	while (!gameBoard.isGameOver()) {
		if (humanUserTurn) {
			cout << "HUMAN USER TURN: " << endl;
			controller.askUserInput();
			controller.setUserInput();
			gameBoard.setBoardValue(controller.getRow(), controller.getColumn(),
					HUMAN_USER_VALUE);
		} else {
			cout << "COMPUTER'S TURN: ";
			string computerPlay = computerUser.generateRandomBoardInput(
					gameBoard.getBoardPlays());
			cout << computerPlay << endl;
			controller.setUserInput(computerPlay);
			gameBoard.setBoardValue(controller.getRow(), controller.getColumn(),
					computerUser.getValue());
		}
		humanUserTurn = !(humanUserTurn); //negates the value as a switch
		gameBoard.drawBoard();
	}
	cout << "Game is over." << endl;

	return 0;
}
