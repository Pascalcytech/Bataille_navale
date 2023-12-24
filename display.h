#ifndef DISPLAY_H
	#define DISPLAY_H
	
	#include "generation.h"
	
	/**
	 * @file display.h
	 * @brief Header file for functions related to displaying the game board.
	 */

	/**
	 * @brief Displays the game board based on the specified mode.
	 *
	 * @param board The Board structure to be displayed.
	 * @param mode The mode indicating how the board should be displayed.
	 * @param second_board The second Board structure used in specific display modes.
	 *
	 * The function displays the game board based on the specified mode. The mode
	 * determines whether to display the initial boards, shooting mode, or getting shot mode.
	 */
	
	void displayBoard(Board board, int mode, Board second_board);
	
#endif
