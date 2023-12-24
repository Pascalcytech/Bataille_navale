#include "generation.h"
#include "display.h"
#include "shots.h"
#include "turn.h"

/**
 * @brief function that handles the turn by turn sequence.
 *
 * @param g_tab_Boards An array of Board structures representing the game boards.
 *		       Here :
 *                     Index 0 is the player's board, and index 1 is the computer's board.
 */
void game(Board* g_tab_Boards){ // Game sequence.
	// Check parameters
	if (g_tab_Boards == NULL){
		exit(20);
	}
	
	int g_winner = -1; // Winner will be 0 if player, and 1 if computer.
	int current_player = 0; //Board0 = Player, Board1 = Computer, Board0 plays first.
	while (g_winner == -1){
		printf("\nPlayer's turn : ");
		player_turn(g_tab_Boards);
		// before computer's turn, check if player won.
		if (g_tab_Boards[1].current_nb_boats == 0){
			g_winner = 0;
		}
		else{
			printf("\n\nComputer's turn : \n");
			computer_turn(g_tab_Boards);
			printf("\n\nPlayer's Board\n");
			
			// Display the player's board after getting shot.
			displayBoard(g_tab_Boards[1], 2, g_tab_Boards[0]);
			if (g_tab_Boards[0].current_nb_boats == 0){
				g_winner = 1;
			}
			printf("\n##################\n");
		}
		
	}
	if (g_winner == 0){
		printf("\nPlayer wins !\n");
	}
	if (g_winner == 1){
		printf("\nComputeur wins !\n");
	}
}
