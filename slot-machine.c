#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(0));
	int a = rand() % 3;
	int b = rand() % 3;
	int c = rand() % 3;

	char fruits[3][5] = {
		"\U0001F34F",  // apple emoji
		"\U0001F353",  // straw emoji
		"\U0001F347"}; // grape emoji

	if (a == b && b == c)
		printf("  \U0001F389 ~WIN~ \U0001F389\n");
	else
		printf("  \u274C ~LOSE~ \u274C\n");

	printf("--> %s %s %s <--\n", fruits[a], fruits[b], fruits[c]);
	printf("───────────────────────────────────\n");

	return (0);
}
