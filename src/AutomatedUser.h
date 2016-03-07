/**
 * @file AutomatedUser.h
 * @author  Karim Jana <karimjana@gmail.com>
 * @date	June, 2015.
 * @version 1.0
 * @details Proffesor Doug Ferguson - C++ class
 *
 *
 * @brief This is my AutomatedUser definition file.
 */
#include <iostream>
#include <array>
#include <vector>

class AutomatedUser {
public:
	//void setBoardInput();
	std::string generateRandomBoardInput(std::vector<std::string> boardPlays);
	int getValue();
private:
	const int VALUE = 2;

};

//#endif /* AUTOMATEDUSER_H_ */
