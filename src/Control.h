/**
 * @file Control.h
 * @author  Karim Jana <karimjana@gmail.com>
 * @date	June, 2015.
 * @version 1.0
 * @details Proffesor Doug Ferguson - C++ class
 *
 * @brief This is my Controller definition file.
 */

#include <iostream>
#include <string>
#include <array>

class Control {
public:
	void askUserInput();
	void setInput(std::string input);
	void setUserInput();
	void setUserInput(std::string userInput);
	std::string getUserInput();
	std::array<int, 2> parseUserInput();
	void setRow(int row);
	int getRow();
	void setColumn(int column);
	int getColumn();

private:
	int row;
	int column;
	std::string input;
};

//#endif /* CONTROLS_H_ */
