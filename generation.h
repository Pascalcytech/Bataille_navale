#ifndef GENERATION_H
	#define GENERATION_H
	
	#include <stdlib.h>
	#include <stdio.h>
	#include <time.h>
	
	/**
	 * @file generation.h
	 * @brief Header file for functions related to game board generation.
	 */

	/**
	 * @brief Enumeration representing the possible states of a cell on the game board.
	 */
	
	typedef enum{
	WATER = 0,
	BOAT,
	WATER_SHOT,
	WRECK,
	} State;
	
	/**
	 * @brief Structure representing a boat in the game.
	 */
	
	typedef struct{
	int size;
	int hit;
	int x; // (0,0) On the top left corner.
	int y;
	int* tab_cell_x; // For each cell (x,y) of the boat, x in tab_cell_x, y in tab_cell_y. cell
	int* tab_cell_y;
	int orientation; // 0 -> Horizontal -> début bateau à gauche. 1 -> Vertical -> début bateau en haut.
	} Boat;
	
	/**
	 * @brief Structure representing the game board.
	 */
	
	typedef struct{
	int** matrix; // State for each cell.
	int size_matrix; // Size of matrix
	int s_nb_size_boats; // Number of different size of boats.
	int* s_tab_boat_size; // List of possible size.
	int* s_tab_nb_boats; // Corresponding number of boats for each size.
	int b_total_nb_boats; // Initial number of boats.
	int current_nb_boats; // Current number of boats.
	
	int nb_water_shot; // Number of watershot.
	int* water_shot_x; // Array of X-coordinates for water shots.
	int* water_shot_y; // Array of Y-coordinates for water shots.
	int nb_wreck_shot; // Number of hit.
	int* wreck_shot_x; // Array of X-coordinates for wrecked boats.
	int* wreck_shot_y; // Array of Y-coordinates for wrecked boats.
	
	Boat* tab_boats; // List boats belonging to the player.

	} Board;
	
	/**
	 * @brief Generates a game board with boats placed randomly.
	 *
	 * @param size The size of the game board.
	 * @param tab_boat_size Array of boat sizes.
	 * @param tab_boats Array of the corresponding number of boats for each size.
	 * @param g_nb_size_boat Number of different boat sizes.
	 * @param total_nb_boat Total number of boats on the board.
	 * @return The generated Board structure.
	 */
	Board generate_Board(int size, int* tab_boat_size, int* tab_boats, int g_nb_size_boat, int _total_nb_boat);
	
	/**
	 * @brief Adds a boat to the game board at the specified position.
	 *
	 * @param newBoard Pointer to the Board structure.
	 * @param posx X-coordinate of the boat's starting position.
	 * @param posy Y-coordinate of the boat's starting position.
	 * @param a_size_boat Size of the boat.
	 * @param a_orientation Orientation of the boat (0 for horizontal, 1 for vertical).
	 */
	void ajouter_bateau(Board* newBoard, int posx, int posy, int a_size_boat, int a_orientation);
	
#endif
