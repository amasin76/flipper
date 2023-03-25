#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void slots();
int wallet(int *credit, int *bet);
int game_over(int credit, char keep_play);

// Global Variables
int credit;
int prize;
int bet;
int is_game_over;

int main(void)
{
	// TODO: let user customize bet
	bet = 10;
	// TODO: prize = custom bet * 10
	prize = 100;
	// start game w/ initial credit
	credit = 100;
	// Ask user if still wanna play
	char keep_play = ' ';

	do
	{
		slots();
		wallet(&credit, &bet);
		is_game_over = game_over(credit, keep_play);

	} while (!is_game_over);

	return (0);
}

int wallet(int *credit, int *bet)
{
	*credit -= *bet;

	if (*credit <= 0)
		return (
			puts("0dh, Mab9a 7ta bx txd taxi"));

	printf("fjibk : %d  tzid tmizi : 10dh (y/n)?\n", *credit);
	return *credit;
}

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
		credit += prize;
		printf("\U0001F389 ~WIN~ = +%d dh \U0001F389\n", prize);
	}
	else
		printf("  \u274C ~LOSE~ \u274C\n");

	printf("--> %s %s %s <--\n", fruits[a], fruits[b], fruits[c]);
	printf("───────────────────────────────────\n");
}

int game_over(int credit, char keep_play)
{
	credit;
	scanf("%c", &keep_play);
	// clear \n from input buffer
	scanf("%*c");

	// gameover if no credit left, OR user type !'y'
	return (credit <= 0 || tolower(keep_play != 'y'));
}
