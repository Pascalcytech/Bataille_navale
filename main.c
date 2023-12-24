#include "generation.h"
#include "positioning.h"
#include "display.h"
#include "shots.h"
#include "turn.h"
#include "game_sequence.h"

/**
 * @brief Main function.
 */
int main(){
	int size_of_matrix;
	int nb_size_boat; // Number of different size of boats.
	int* tab_size_boats; // List of different sizes.
	int* tab_boats; // Corresponding number of boats.
	int winner; // Number indicates the winner.
	
	srand(time(NULL)); // For random placement.
	
	// List of the two boards.
	Board* tabBoard = malloc(sizeof(Board)*2);
	if (tabBoard == NULL){
		exit(5);
	}
	
	// User is asked how many sizes of boats he wants.
	int flag0 = 0;
	while (flag0 == 0){
		printf("\nNombre de taille de bateaux : ");
		if (scanf("%d", &nb_size_boat) != 1 || nb_size_boat<0){
			printf("\nMust be a positive integer\n");
			flag0 = 0;
		}
		else{
			flag0 = 1;
		}
		int empty;
		while ((empty = getchar()) != '\n');
		
	}
	tab_boats = malloc(sizeof(int)*nb_size_boat);
	if (tab_boats == NULL){
		exit(9);
	}
	tab_size_boats = malloc(sizeof(int)*nb_size_boat);
	if (tab_size_boats == NULL){
		exit(10);
	}
	
	
	// Filling of previous lists.
	for (int i=0;i<nb_size_boat;i++){
		int temp_size;
		int temp_nb;
		
		// User is asked the size and the corresponding number of boats for each size.
		int flag1 = 0;
		while(flag1 == 0){
			printf("\nValeur de la taille de bateau n° %d : ", i+1);
			if (scanf("%d", &temp_size) != 1 || temp_size<0){
				printf("\nMust be a positive integer\n");
				flag1 = 0;
			}
			else{
				flag1 = 1;
			}
			int empty;
			while (empty = getchar() != '\n');
		}
		tab_size_boats[i] = temp_size;
		
		int flag3 = 0;
		while(flag3 == 0){
			printf("\nNombre de bateau de cette taille : ");
			if (scanf("%d", &temp_nb) != 1 || temp_nb<0){
				printf("\nMust be a positive integer\n");
				flag3 = 0;
			}
			else{
				flag3 = 1;
			}
			int empty;
			while (empty = getchar() != '\n');
		}
		tab_boats[i] = temp_nb;
	}
	
	// Total number of boats.
	int total_nb_boats = 0;
	for (int i=0; i<nb_size_boat; i++){
		total_nb_boats += tab_boats[i];
	}
	
	// Boards creation.
	int flag4 = 0;
	int max_boat_size = 0;// Can't enter a matrix size to small.
	for (int m=0; m<nb_size_boat; m++){
		if (max_boat_size < tab_size_boats[m]){
			max_boat_size = tab_size_boats[m];
		}
	}
	
	// User is asked the size of the board, which should be big enough to fit all the ships.
	while(flag4 == 0){
		printf("\nTaille de la matrice : ");
		if (scanf("%d", &size_of_matrix) != 1 || size_of_matrix<max_boat_size){
			printf("\nMust be a positive integer of at least : %d\n", max_boat_size);
			flag4 = 0;
		}
		else{
			flag4 = 1;
		}
		int empty;
		while (empty = getchar() != '\n');
	}
	
	// Generates the boards.
	tabBoard[0] = generate_Board(size_of_matrix, tab_size_boats, tab_boats, nb_size_boat, total_nb_boats);
	tabBoard[1] = generate_Board(size_of_matrix, tab_size_boats, tab_boats, nb_size_boat, total_nb_boats);
	
	//Check pointers.
	Board* p1 = &tabBoard[0];
	if (p1 == NULL){
		exit(36);
	}
	else{
		p1 = &tabBoard[0];
	}
	Board* p2 = &tabBoard[1];
	if (p1 == NULL){
		exit(37);
	}
	else{
		p2 = &tabBoard[1];
	}
	
	// Put the boats on the boards.
	positioning(p1);
	positioning(p2);
	
	// Player can see his board at the start of the game.
	printf("\nPlayer's Board :\n");
	displayBoard(tabBoard[0], 0, tabBoard[1]);
	
	printf("###################");
	
	// Game begins.
	game(tabBoard);
	
	// Memory is explicitely freed at the end of the game.
	free(tabBoard);
	free(tab_boats);
	free(tab_size_boats);
	
	return 0;
}


