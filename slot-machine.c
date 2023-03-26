#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void slots();
int wallet(int *credit, int *bet);
int game_over(int credit, int *bet);

// Global Variables
int credit;
int prize;
int bet;
int is_game_over;

int main(void) {
	// Initial bet, after 1st round user can customize it
	bet = 20;
	// Prize = custom bet * 10
	prize = bet * 10;
	// start game w/ initial credit
	credit = 100;

	puts("if wanna stop, for bet type '0'");

	do {
		slots();
		wallet(&credit, &bet);
		is_game_over = game_over(credit, &bet);
	} while (!is_game_over);

	return (0);
}

int wallet(int *credit, int *bet) {
	*credit -= *bet;

	if (*credit <= 0)
		return (puts("0dh, Mab9a 7ta bx txd taxi"));

	printf("Fjibk : %d,  mizi xhal bghiti?\n", *credit);
	return *credit;
}

void slots() {
	// generate randum number from 0 to 2
	srand(time(0));
	int a = rand() % 3;
	int b = rand() % 3;
	int c = rand() % 3;

	char fruits[3][5] = {"\U0001F34F",	// apple emoji
						 "\U0001F353",	// straw emoji
						 "\U0001F347"}; // grape emoji

	printf("───────────────────────────────────\n");

	if (a == b && b == c) {
		credit += prize;
		printf("\U0001F389 ~WIN~ = +%d dh \U0001F389\n", prize);
	} else
		printf("  \u274C ~LOSE~ \u274C\n");

	printf("--> %s %s %s <--\n", fruits[a], fruits[b], fruits[c]);
	printf("───────────────────────────────────\n");
}

int game_over(int credit, int *bet) {
	// gameover if no credit
	if (credit <= 0)
		return (1);

	scanf("%d", &*bet);
	// clear \n from input buffer
	scanf("%*c");
	// warn user if type bet > credit
	if (*bet > credit) {
		printf("Ya lghder bda, 3ndk %ddh obaghi t7t %d\n", credit, *bet);
		game_over(credit, bet);
	}

	// gameover if user type num <= 0
	return (*bet <= 0);
}
