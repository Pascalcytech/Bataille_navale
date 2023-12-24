#ifndef GAME_SEQUENCE_H
	#define GAME_SEQUENCE_H 
	
	#include "generation.h"
	#include "display.h"
	#include "shots.h"
	#include "turn.h"
	
	/**
	 * @file game_sequence.h
	 * @brief Header file for the main game sequence.
	 */

	/**
	 * @brief handles the turn by turn sequence.
	 *
	 * @param g_tab_Boards An array of Board structures representing the game boards.
	 *
	 * The function initiates and executes the main game sequence, alternating between
	 * the player's and the computer's turns, displaying the boards, and determining the winner.
	 */
	
	void game(Board* g_tab_Boards);
	
#endif
