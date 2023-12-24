#ifndef POSITIONING_H
	#define POSITIONING_H

	#include "generation.h"
	
	/**
 	* @file positioning.h
 	* @brief Header file for functions related to positioning boats on the game board.
 	*/
 	
 	/**
	 * @brief Positions boats randomly on the game board.
	 *
 	* @param newBoard Pointer to the Board structure.
 	*
 	* The function randomly positions boats on the game board based on the provided
 	* boat sizes and their corresponding numbers.
 	*/
	
	void positioning(Board* newBoard);
	
#endif
