/**
 * @file TestDrive.cpp
 * @author  Karim Jana <karimjana@gmail.com>
 * @date	June, 2015.
 * @version 1.0
 * @details Proffesor Doug Ferguson - C++ class
 *
 * @brief This is my test drive program implentation file. A test for each of the classes
 * is defined in the functions.
 */
#include <iostream>
#include <array>
#include <vector>
#include "TestDrive.h"
#include "Control.h"
#include "TicTacToeBoard.h"
#include "AutomatedUser.h"

void TestDrive::test() {

	std::cout << "Test 1: Drive in memory." << std::endl;
}
;

void TestDrive::controlTest() {
	std::cout << "Test 2: Control Input." << std::endl;
	Control myControl;
	myControl.askUserInput();

	std::cout << "Test 2a: Control get user input: " << myControl.getUserInput()
			<< std::endl;

	std::cout << "Test 2b: Parse user input: " << std::endl;
	std::array<int, 2> row_column = myControl.parseUserInput();
	std::cout << "checking return value..." << row_column[0] << row_column[1];
	std::cout << std::endl;
	myControl.setRow(row_column[0]);
	myControl.setColumn(row_column[1]);
	std::cout << "Row: " << myControl.getRow() << " and Column: "
			<< myControl.getColumn() << std::endl;

}
;

void TestDrive::TicTacToeBoardTest() {

	std::cout << "Test 3: Initialize TicTacToeBoard:" << std::endl;
	TicTacToeBoard myBoard;
	std::cout << "Test 3a: Draw empty board: " << std::endl;
	myBoard.drawBoard();
	std::cout << "Test 3b: Modify board and draw it: " << std::endl;
	myBoard.setBoardValue(2, 1, 1);
	myBoard.setBoardValue(2, 2, 2);
	myBoard.drawBoard();
	std::cout << "Test 3c: Get Board Plays: " << std::endl;
	std::vector<std::string> plays;
	plays = myBoard.getBoardPlays();
	for (int i = 0; i < plays.size(); i++) {
		std::cout << "move: " << plays[i] << "-- number: " << i << std::endl;
	}
}
;

void TestDrive::AutomatedUserTest() {

	std::cout << "Test 4: Initialize AutomatedUser:" << std::endl;
	AutomatedUser myUser;
	std::cout << "Test 4a: Generate Random User Input: " << std::endl;
	TicTacToeBoard myBoard;
	myBoard.setBoardValue(3, 1, 1);
	myBoard.setBoardValue(2, 2, 1);
	myBoard.setBoardValue(1, 3, 2);
	myBoard.setBoardValue(1, 1, 1);
	myBoard.setBoardValue(2, 2, 2);
	myBoard.setBoardValue(2, 3, 1);
	myBoard.setBoardValue(1, 2, 2);
	myBoard.setBoardValue(2, 1, 2);
	//myBoard.setBoardValue(3,2,1);
	std::vector<std::string> plays;
	plays = myBoard.getBoardPlays();
	std::string result = myUser.generateRandomBoardInput(plays);
	std::cout << "Random returned play: " << result << std::endl;

	std::cout << "Test 4b: Insert Random User Input in game board."
			<< std::endl;
	Control myControl;
	myControl.setUserInput(result);
	myBoard.setBoardValue(myControl.getRow(), myControl.getColumn(),
			myUser.getValue());
	myBoard.drawBoard();

	std::cout << "Test 4c: Is game over." << std::endl;
	if (myBoard.isGameOver()) {
		std::cout << "Game is over." << std::endl;
	} else {
		std::cout << "Game is not over.. continue playing." << std::endl;
	}

}
;

