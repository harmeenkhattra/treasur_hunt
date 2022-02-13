#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_LIVES 10
#define MIN_LIVES 1
#define MAX 70
// CHECK SPACING ERROR ONCE

struct PlayerInfo     // struct playerinfo defined 
{
	char name;
	int lives;
	int NUM_TREASURE;
	int PLY_HISTORY[MAX];
};

struct GameInfo       // struct gameinfo defined 
{
	int pathLength;
	int moves;
	int BOMB[MAX];
	int TREASURE[MAX];
};

int main(void)
{
	int flag = 1, i = 5, MIN_MOVES = 0, MAX_MOVES = 0, lives = 0, pathlength = 0, moves = 0, j = 0, k = 0, l = 0, nextMove = 0;


	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n\n");

	printf("PLAYER Configuration\n");
	printf("--------------------\n");

	struct PlayerInfo player =                     // struct initialized
	{
		'@',
		0	
	};


	printf("Enter a single character to represent the player: ");
	scanf(" %c", &player.name);

	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &lives);
		if (!(lives >= MIN_LIVES && lives <= MAX_LIVES))
		{
			printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
		}
		else
		{
			player.lives = lives;
			flag = 0;
		}
	} while (flag);

	printf("Player configuration set-up is complete\n\n");
	flag = 1;

	struct GameInfo game =                     // struct initialized
	{
		1,1, {1,1}, {1,1}
	};

	printf("GAME Configuration\n");
	printf("------------------\n");

	do
	{
		printf("Set the path length (a multiple of %d between 10-70): ", i);
		scanf("%d", &pathlength);
		if (((pathlength % i) != 0) || (pathlength > 70 || pathlength < 10))
		{
			printf("     Must be a multiple of %d and between 10-70!!!\n", i);
		}
		else
		{
			game.pathLength = pathlength;
			flag = 0;
		}
	} while (flag);


	flag = 1;
	MIN_MOVES = player.lives;
	MAX_MOVES = 0.75 * game.pathLength;
	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &moves);
		if (!(moves >= MIN_MOVES && moves <= MAX_MOVES))
		{
			printf("    Value must be between %d and %d\n", MIN_MOVES, MAX_MOVES);
		}
		else
		{
			game.moves = moves;
			flag = 0;
		}
	} while (flag);
	printf("\n");
	printf("BOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of %d where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n", i);
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

	for (j = 0; j < game.pathLength; j += i)                       // user input positions
	{
		printf("   Positions [%2d-%2d]: ", j + 1, j + 5);

		for (k = 0; k < i; k++)                                    // reading values inputed
		{
			scanf("%d", &game.BOMB[k + l]);
		}
		l += 5;


	}


	printf("BOMB placement set\n\n");

	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of %d where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n", i);
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
	i = 5; j = 0; k = 0; l = 0;
	for (j = 0; j < game.pathLength; j += i)
	{
		printf("   Positions [%2d-%2d]: ", j + 1, j + 5);

		for (k = 0; k < i; k++)
		{
			scanf("%d", &game.TREASURE[k + l]);
		}
		l += 5;

	}



	printf("TREASURE placement set\n\n");
	printf("GAME configuration set-up is complete...\n\n");
	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", player.name);
	printf("   Lives      : %d\n", player.lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");
	printf("Game:\n");
	printf("   Path Length: %d\n", game.pathLength);

	printf("   Bombs      : ");
	for (i = 0; i < game.pathLength; i++)
	{
		printf("%d", game.BOMB[i]);

	};
	printf("\n");


	printf("   Treasure   : ");
	for (i = 0; i < game.pathLength; i++)
	{
		printf("%d", game.TREASURE[i]);

	};
	printf("\n\n");


	printf("====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");

	// PART 2

	char PREV_POSN[] = { "--------------------" };
	char MAJ_RULER[] = { "||||||||||||||||||||" };
	int MIN_RULER[] = {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0};
	
	int m = 0;
	printf("\n");
	printf("  ");
	
	for (m = 0; m <= (game.pathLength - 1); m++)
	{
		printf("%c", PREV_POSN[m]);
	}

	printf("\n");
	printf("  ");

	for (m = 0; m < game.pathLength; m++)
	{
		printf("%c", MAJ_RULER[m]);

		if (MAJ_RULER[9] == '|')
		{
			MAJ_RULER[9] = '1';
		}
		else if (MAJ_RULER[19] == '|')
		{
			MAJ_RULER[19] = '2';
		}

	}
	printf("\n");
	printf("  ");

	for (m = 0; m <= (game.pathLength - 1); m++)
	{
		printf("%d", MIN_RULER[m]);
	}

	printf("\n");

	printf("+---------------------------------------------------+\n");
	printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.NUM_TREASURE, game.moves);
	printf("+---------------------------------------------------+\n");
	flag = 1;
	int FLAG = 1;
	do
	{
		do
		{
			printf("Next Move [1-%d]: ", game.pathLength);
			scanf("%d", &nextMove);
			if (nextMove >= 1 && nextMove <= game.pathLength)
				FLAG = 0;

			else
				printf("  Out of Range!!!\n");
		} while (FLAG);

		
		
			
			printf("\n");
			if (player.PLY_HISTORY[nextMove - 1] == 1)
			{
				printf("===============> Dope! You've been here before!\n\n");
			}
			else
			{
				player.PLY_HISTORY[nextMove - 1] = 1;
				game.moves -= 1;

				if ((game.BOMB[nextMove - 1] == 1) && (game.TREASURE[nextMove - 1] == 1))
				{
					player.lives -= 1;
					player.NUM_TREASURE += 1;
					printf("===============> [&] !!! BOOOOOM !!! [&]\n===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
				}


				else if (game.BOMB[nextMove - 1] == 1)
				{
					player.lives -= 1;
					printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");

				}

				else if (game.TREASURE[nextMove - 1] == 1)
				{
					player.NUM_TREASURE += 1;
					printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");

				}

				else if ((game.BOMB[nextMove - 1] == 0) && (game.TREASURE[nextMove - 1] == 0))

				{
					printf("===============> [.] ...Nothing found here... [.]\n\n");
				}
				if (game.moves == 0 || player.lives == 0)
				{
					printf("No more LIVES remaining!\n\n");
					flag = 0;
				}
			}
			
				printf("  ");
				for (m = 0; m < (nextMove - 1); m++)
				{
					printf(" ");
				}

				printf("%c", player.name);

				int n;
				for (n = 0; n < (game.pathLength - nextMove); n++)
				{
					printf(" ");
				}
				printf("\n");
				printf("  ");

				while (PREV_POSN[0] == '-' && nextMove == 1)      // FOR INCLUDING 1ST MOVE
				{
					if (game.BOMB[nextMove - 1] == 0 && game.TREASURE[nextMove - 1] == 0)
						PREV_POSN[0] = '.';

					else if (game.BOMB[nextMove - 1] == 0 && game.TREASURE[nextMove - 1] == 1)
						PREV_POSN[0] = '$';

					else if (game.BOMB[nextMove - 1] == 1 && game.TREASURE[nextMove - 1] == 0)
						PREV_POSN[0] = '!';

					else if (game.BOMB[nextMove - 1] == 1 && game.TREASURE[nextMove - 1] == 1)
						PREV_POSN[0] = '&';
				}

				for (i = 0; i < game.pathLength; i++)
				{
					printf("%c", PREV_POSN[i]);

					if (game.BOMB[nextMove - 1] == 0 && game.TREASURE[nextMove - 1] == 0)
					{
						PREV_POSN[nextMove - 1] = '.';
					}

					else if (game.BOMB[nextMove - 1] == 0 && game.TREASURE[nextMove - 1] == 1)
					{
						PREV_POSN[nextMove - 1] = '$';
					}

					else if (game.BOMB[nextMove - 1] == 1 && game.TREASURE[nextMove - 1] == 0)
					{
						PREV_POSN[nextMove - 1] = '!';
					}

					else if (game.BOMB[nextMove - 1] == 1 && game.TREASURE[nextMove - 1] == 1)
					{
						PREV_POSN[nextMove - 1] = '&';
					}
				}
				printf("\n");
				printf("  ");
			
					

				for (i = 0; i < game.pathLength; i++)
				{
					

					printf("%c", MAJ_RULER[i]);

					if (MAJ_RULER[9] == '|')
					{
						MAJ_RULER[9] = '1';
					}
					else if (MAJ_RULER[19] == '|')
					{
						MAJ_RULER[19] = '2';
					}

				}
				printf("\n");
				printf("  ");

				for (m = 0; m <= (game.pathLength - 1); m++)
				{
					printf("%d", MIN_RULER[m]);
				}

				printf("\n");

				printf("+---------------------------------------------------+\n");
				printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.NUM_TREASURE, game.moves);
				printf("+---------------------------------------------------+\n");
			
		

		
	}while (flag);

	printf("\n##################\n");
	printf("#   Game over!   #\n");
	printf("##################\n\n");
	printf("You should play again and try to beat your score!\n");

	return 0;


}
