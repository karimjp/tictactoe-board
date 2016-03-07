/**
 * @file TicTacToeBoard.h
 * @author  Karim Jana <karimjana@gmail.com>
 * @date	June, 2015.
 * @version 1.0
 * @details Proffesor Doug Ferguson - C++ class
 *
 * @brief This is the tic tac toe board definition file.
 */
#include <iostream>
#include <array>
#include <vector>

class TicTacToeBoard {
public:
	TicTacToeBoard();
	void setBoardValue(int row, int column, int value);
	std::array<std::array<int, 3>, 3> getBoard();
	std::vector<std::string> getBoardPlays();
	char getUserMoveIcon();
	char getAutomatedPlayerMoveIcon();
	void drawBoard();
	bool isGameOver();
private:
	std::array<std::array<int, 3>, 3> board;
	char userMoveIcon = 'X';
	char automatedPlayerMoveIcon = 'O';
	const int ROWS = 3;
	const int COLUMNS = 3;

};

//#endif /* TICTACTOEBOARD_H_ */
