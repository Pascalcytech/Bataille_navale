#include "positioning.h"
#include "generation.h"

/**
 * @brief Positions boats on the game board randomly.
 *
 * @param newBoard A pointer to the Board structure representing the game board.
 */
void positioning(Board* newBoard){
	// Check parameters.
	if (newBoard == NULL){
		exit(9);
	}

	// Recovery of the list of boat sizes.
	int nbsize = newBoard->s_nb_size_boats;
	
	// For each size.
	for (int i=0; i<nbsize; i++){
		int tempsize = newBoard->s_tab_boat_size[i];
		int temp_nb_boats = newBoard->s_tab_nb_boats[i]; // Number of boats of this size.
		// For each boat.
		for (int j=0; j<temp_nb_boats; j++){
			// Orientation is random : 0 is horizontal : start of boat on the left. 1 is vertical : start on the top.
			int random01 = rand() % 2;
			
			// Determination of eligibles cells.
			
			// Temporary list for the coordinates x of such eligible cells.
			int* temptableau_x = malloc(sizeof(int)*(newBoard->size_matrix)*(newBoard->size_matrix));
			if (temptableau_x == NULL){
				exit(12);
			}
			for (int _i = 0; _i<(newBoard->size_matrix)*(newBoard->size_matrix); _i++){
				temptableau_x[_i] = -1; // Initiated with int : -1.
			}
			
			// Same for the y coordinates.
			int* temptableau_y = malloc(sizeof(int)*(newBoard->size_matrix)*(newBoard->size_matrix));
			if (temptableau_y == NULL){
				exit(13);
			}
			for (int _j = 0; _j<(newBoard->size_matrix)*(newBoard->size_matrix); _j++){
				temptableau_y[_j] = -1; //tableau initialisé à -1
			}
			
			// Count for such cells.
			int count = 0;
				
			// Check for each cell of the board.
			for (int l = 0; l < newBoard->size_matrix; ++l) {
				for (int c = 0; c < newBoard->size_matrix; ++c) {
					int issue= 0; // if at least one issue, cell is not eligible.
					if (random01==0){ // Horizontal.
						// Cells that would be occupied if boat was in [l],[c].
						for (int e=c; e<c+tempsize; e++){
							if (e >= newBoard->size_matrix){ // Cannot be out of bounds.
								issue=1;
							}
							else if(newBoard->matrix[l][e]==BOAT){ // Cannot overlap with another boat.
								issue=1;
							}
						}
					}
					else{ // Vertical.
						for (int e=l; e<l+tempsize; e++){
							if (e >= newBoard->size_matrix){
								issue=1;
							}
							else if(newBoard->matrix[e][c]==BOAT){
								issue=1;
							}
						}
					}
					if (issue == 0){ // If no issue, cell is eligible.
						temptableau_x[count] = l;
						temptableau_y[count] = c;
						count = count + 1;
					}
				}
			}
			// Cell is chosen randomly.
			int randomint = rand() % (count);
			
			// Boat is added to the board.
			ajouter_bateau(newBoard, temptableau_x[randomint], temptableau_y[randomint], tempsize, random01);
			newBoard->current_nb_boats += 1;
			
			// Temporary lists are freed.
			free(temptableau_x);
			free(temptableau_y);
		}
	}
}

