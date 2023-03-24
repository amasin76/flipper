#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void slots();

// Global Variables
int credit;
int prize;

int main(void)
{
	// Cash Prize
	prize = 50;
	// start game w/ initial credit
	credit = 30;
	// Ask user if still wanna play
	char keep_play = ' ';
	// over if credit = 0 OR user type 'n'
	int is_game_over = 0;

	do
	{
		slots();
		credit -= 10;

		if (credit <= 0)
			return (
				puts("Mab9a 3dk 7ta ryal, ma3ndk 7ta bx txd taxi"));

		printf("fjibk : %d  tzid tmizi : 10dh (y/n)?\n", credit);
		scanf("%c", &keep_play);
		scanf("%*c"); // clear \n from input buffer

		is_game_over = credit <= 0 || tolower(keep_play != 'y');

	} while (!is_game_over);

	return (0);
}

// int wallet(int credit)
// {
// 	return credit;
// }

void slots()
{
	srand(time(0));
	int a = rand() % 3;
	int b = rand() % 3;
	int c = rand() % 3;

	char fruits[3][5] = {
		"\U0001F34F",  // apple emoji
		"\U0001F353",  // straw emoji
		"\U0001F347"}; // grape emoji

	printf("───────────────────────────────────\n");

	if (a == b && b == c)
	{
		credit += 50;
		printf("\U0001F389 ~WIN~ = +%d dh \U0001F389\n", prize);
	}
	else
		printf("  \u274C ~LOSE~ \u274C\n");

	printf("--> %s %s %s <--\n", fruits[a], fruits[b], fruits[c]);
	printf("───────────────────────────────────\n");
}
