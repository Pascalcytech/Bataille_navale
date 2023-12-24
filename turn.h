#ifndef TURN_H
	#define TURN_H 
	
	#include "generation.h"
	#include "display.h"
	#include "shots.h"
	
	/**
	 * @file turn.h
	 * @brief Header file for functions related to player and computer turns in the game.
	 */
	
	/**
	 * @brief Executes a turn for the player.
	 *
	 * @param p_tab_Board Pointer to the array of Board structures.
	 *
	 * The function executes the player's turn, displaying the board with shots fired
	 * by the player and handling the player's shot input.
	 */
	void player_turn(Board* p_tab_Board);
	
	/**
	 * @brief Executes a turn for the computer.
	 *
	 * @param p_tab_Board Pointer to the array of Board structures.
	 *
	 * The function executes the computer's turn, determining eligible cells for shooting,
	 * choosing a random cell, and handling the shot on the player's board.
	 */
	void computer_turn(Board* p_tab_Board);

#endif
