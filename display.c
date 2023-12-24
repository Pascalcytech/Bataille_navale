#include "generation.h"

/**
 * @brief Display the game board based on the specified mode.
 *
 * @param board The game board to be displayed.
 * @param mode Display mode: 0 for initial boards, 1 for shooting mode (player's board), 2 for getting shot mode (computer's board).
 * @param second_board The second board (relevant for mode 2).
 */
void displayBoard(Board board, int mode, Board second_board){
	// Check parameters.
	if (mode < 0 || mode > 2){
		exit(4);
	}

	if (mode == 0){ // Mode 0 : display initial Boards.
		for (int i = 0; i < board.size_matrix; ++i){
			for (int j = 0; j < board.size_matrix; ++j){
				printf("%d ", board.matrix[i][j]);
			}
			printf("\n");
		}
	printf("\n");
	}
	
	if (mode == 1){ // Mode 1 : Shooting mode. Board belong to the Player
		for (int i = 0; i < board.size_matrix; ++i) { // Display a board, but with only water and shots done.
			for (int j = 0; j < board.size_matrix; ++j) {
				int water = 0;
				for(int k = 0; k<board.nb_water_shot; k++){ // Check if already shot.
					if (i==board.water_shot_x[k] && j==board.water_shot_y[k]){
						printf("%d ", WATER_SHOT);
						water = 1;
					}
				}
				for(int l = 0; l<board.nb_wreck_shot; l++){ // Check if already hit.
					if (i==board.wreck_shot_x[l] && j==board.wreck_shot_y[l]){
						printf("%d ", WRECK);
						water = 1;
					}
				}
				if (water == 0){
					printf("0 ");
				}
			}
			printf("\n");
		}
	}
	
	if (mode == 2){ // Mode 2 : Getting shot mode.
		for (int i = 0; i < board.size_matrix; ++i) { // Board belong to Computer, second board belong to the Player.
			for (int j = 0; j < board.size_matrix; ++j) { // Display the Player's board with his boats, but with the shots fired by the computer.
				int num_to_display = second_board.matrix[i][j];
				for(int k = 0; k<board.nb_water_shot; k++){ // Check if already shot.
					if (i==board.water_shot_x[k] && j==board.water_shot_y[k]){
						num_to_display = WATER_SHOT;
					}
				}
				for(int l = 0; l<board.nb_wreck_shot; l++){ // Check if already hit.
					if (i==board.wreck_shot_x[l] && j==board.wreck_shot_y[l]){
						num_to_display = WRECK;
					}
				}
				printf("%d ", num_to_display);
			}
			printf("\n");
		}
	}
}

