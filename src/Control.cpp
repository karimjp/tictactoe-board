/**
 * @file Control.cpp
 * @author  Karim Jana <karimjana@gmail.com>
 * @date	June, 2015.
 * @version 1.0
 * @details Proffesor Doug Ferguson - C++ class
 *
 * @brief This is my Controller implementation file.  The controller handles the user input,
 * computer user input, and provides an interface for the game board to query data.
 */

#include <iostream>
#include "Control.h"
#include <string>
#include <array>

/**
 * Asks human user for row and column input as string
 */
void Control::askUserInput() {
	std::string userInput;
	std::cout << "Enter a row and column: ";
	getline(std::cin, userInput, '\n');
	this->setInput(userInput);

}
;

/**
 * Parses string user input selection and sets in object's attributes.
 */
void Control::setUserInput() {
	std::array<int, 2> row_column = this->parseUserInput();
	this->setRow(row_column[0]);
	this->setColumn(row_column[1]);
}

/**
 * Parses string user input selection and sets in object's attributes.
 *
 * @param userInput string most likely from automated user.
 */
void Control::setUserInput(std::string userInput) {
	this->setInput(userInput);
	this->setUserInput();
}

void Control::setInput(std::string input) {
	this->input = input;
}
;

std::string Control::getUserInput() {
	return this->input;
}
;

/**
 * Parses string user input selection
 *
 * @return userInput as 1-D array of row and column values
 */
std::array<int, 2> Control::parseUserInput() {
	std::array<int, 2> userInput;
	/*std::cout << "parsing row... " << this->input[0];
	 std::cout<<std::endl;
	 std::cout << "parsing column..." <<this->input[1];
	 std::cout<<std::endl;*/
	int row = this->input[0] - '0';
	int column = this->input[1] - '0';
	userInput[0] = row;
	userInput[1] = column;
	/*std::cout << "saving row... " << userInput[0];
	 std::cout<<std::endl;
	 std::cout << "saving column..." <<userInput[1];
	 std::cout<<std::endl;*/
	return userInput;
}
;

void Control::setColumn(int column) {
	this->column = column;
}
;

void Control::setRow(int row) {
	this->row = row;
}
;

int Control::getColumn() {
	return this->column;
}
;

int Control::getRow() {
	return this->row;
}
;
