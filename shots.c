#include "shots.h"
#include "generation.h"

/**
 * @brief Checks if a water shot has been fired at the given coordinates on the board.
 *
 * @param newBoard A pointer to the Board structure representing the game board.
 * @param x_to_compare The x-coordinate to check.
 * @param y_to_compare The y-coordinate to check.
 * @return 0 if a water shot has been fired at the coordinates, 1 otherwise.
 */
int is_water_shot(Board* newBoard, int x_to_compare, int y_to_compare){
	// Check parameters
	if (newBoard == NULL){
		exit(10);
	}
	int pos_max = newBoard->size_matrix-1;
	if (x_to_compare < 0 || x_to_compare > pos_max){
		exit(11);
	}
	if (y_to_compare < 0 || y_to_compare > pos_max){
		exit(12);
	}
	
	// Check if a shot has been fired at these coordinates.
	for(int k = 0; k<newBoard->nb_water_shot; k++){
		if (x_to_compare==newBoard->water_shot_x[k] && y_to_compare==newBoard->water_shot_y[k]){
			return 0;
		}
	}
	return 1;
}

/**
 * @brief Checks if a wreck shot has been fired at the given coordinates on the board.
 *
 * @param newBoard A pointer to the Board structure representing the game board.
 * @param x_to_compare The x-coordinate to check.
 * @param y_to_compare The y-coordinate to check.
 * @return 0 if a wreck shot has been fired at the coordinates, 1 otherwise.
 */
int is_wreck_shot(Board* newBoard, int x_to_compare, int y_to_compare){
	// Check parameters
	if (newBoard == NULL){
		exit(13);
	}
	int pos_max = newBoard->size_matrix-1;
	if (x_to_compare < 0 || x_to_compare > pos_max){
		exit(14);
	}
	if (y_to_compare < 0 || y_to_compare > pos_max){
		exit(15);
	}
	
	// Almost same function as before, but with hits.
	for(int l = 0; l<(newBoard->nb_wreck_shot); l++){
		if (x_to_compare==newBoard->wreck_shot_x[l] && y_to_compare==newBoard->wreck_shot_y[l]){
			return 0;
		}
	}
	return 1;
}

/**
 * @brief Check if hit or not at the given coordinates.
 *
 * @param myBoard A pointer to the Board structure representing the shooting player's board.
 * @param opponentBoard A pointer to the Board structure representing the opponent's board.
 * @param x_to_compare The x-coordinate of the shot.
 * @param y_to_compare The y-coordinate of the shot.
 */
void boat_or_water_shot(Board* myBoard, Board* opponentBoard, int x_to_compare, int y_to_compare){
	// Check parameters
	if (myBoard == NULL || opponentBoard == NULL){
		exit(16);
	}
	int pos_max = myBoard->size_matrix-1;
	if (x_to_compare < 0 || x_to_compare > pos_max){
		exit(17);
	}
	if (y_to_compare < 0 || y_to_compare > pos_max){
		exit(18);
	}
	
	// See for each boat if the shot hit them.
	for (int i=0; i<opponentBoard->current_nb_boats; i++){
		// Will depends on the size of the boat.
		int size_boat = opponentBoard->tab_boats[i].size;
		for (int a=0; a<size_boat; a++){
		// Check each cell of each boat.
			if(x_to_compare == opponentBoard->tab_boats[i].tab_cell_x[a] && y_to_compare == opponentBoard->tab_boats[i].tab_cell_y[a]){
				printf("\nHit !");
				opponentBoard->tab_boats[i].hit += 1;
				// Size = hitpoint, is number of hit reaches size, boat is destroyed.
				if (opponentBoard->tab_boats[i].hit == opponentBoard->tab_boats[i].size){
					printf("\nShip destroyed !");
					// Decrease number of active boats by 1.
					opponentBoard->current_nb_boats -= 1;
					printf("\nRemaining ships : %d\n", opponentBoard->current_nb_boats);
					return;
				}
				// Add 1 to the number of successfull hits.
				myBoard->wreck_shot_x[myBoard->nb_wreck_shot] = x_to_compare;
				myBoard->wreck_shot_y[myBoard->nb_wreck_shot] = y_to_compare;
				myBoard->nb_wreck_shot += 1;
				return;
			}
		}
	}
	// Else add 1 to the number of missed shots.
	printf("\nWater shot !\n");
	myBoard->water_shot_x[myBoard->nb_water_shot] = x_to_compare;
	myBoard->water_shot_y[myBoard->nb_water_shot] = y_to_compare;
	myBoard->nb_water_shot += 1; // Game is not over.
	return;
}
