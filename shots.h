#ifndef SHOTS_H
	#define SHOTS_H 
	
	#include "generation.h"
	
	/**
	 * @file shots.h
	 * @brief Header file for functions related to handling shots in the game.
	 */
	
	/**
	 * @brief Checks if a water shot has been fired at the specified coordinates.
	 *
	 * @param newBoard Pointer to the Board structure.
	 * @param x_to_compare X-coordinate to compare.
	 * @param y_to_compare Y-coordinate to compare.
	 * @return 0 if water shot, 1 otherwise.
	 */
	int is_water_shot(Board* newBoard, int x_to_compare, int y_to_compare);
	
	/**
	 * @brief Checks if a wreck shot has been fired at the specified coordinates.
	 *
	 * @param newBoard Pointer to the Board structure.
	 * @param x_to_compare X-coordinate to compare.
	 * @param y_to_compare Y-coordinate to compare.
	 * @return 0 if wreck shot, 1 otherwise.
	 */
	int is_wreck_shot(Board* newBoard, int x_to_compare, int y_to_compare);
	
	/**
	 * @brief Handles a shot on the game board, marking it as a hit or a miss.
	 *
	 * @param myBoard Pointer to the player's Board structure.
	 * @param opponentBoard Pointer to the opponent's Board structure.
	 * @param x_to_compare X-coordinate to compare.
	 * @param y_to_compare Y-coordinate to compare.
	 *
	 * The function determines if the shot is a hit or a miss and updates the players data
	 */
	void boat_or_water_shot(Board* myBoard, Board* opponentBoard, int x_to_compare, int y_to_compare);
	
#endif
