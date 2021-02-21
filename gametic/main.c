#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int x, o;
	int count = 0;
	char check = 0;
	char possition[] = { 16, 20, 24, 44, 48, 52, 72, 76, 80 };
	char buf[9];
	char table[] = {
		"|-----------|\n""|   |   |   |\n""|-----------|\n"
		"|   |   |   |\n""|-----------|\n"
		"|   |   |   |\n""|-----------|" };
	srand(time(NULL));
	printf("%s\n", table);
	printf("\n");
	for (int i = 0; i<11; i += 2){
		while (check == 0){
			printf("Nomer o: ");
			scanf_s("%i", &o);
			o--;
			o = possition[o];
			for (int j = 0; j <= 9; j++){
				if (o == buf[j]) count++;
			}
			if ((count == 0) || (i == 0)) { buf[i] = o; table[o] = 'o'; check = 1; }
			else printf("Ne verney, vvedi esho raz");
			count = 0;
		}
		
		check = 0;
		//printf("%s\n", table);
		while (check == 0){
			x = rand() % 9;

			//scanf("%i",&x);
			x = possition[x];
			//  getchar();
			//     getchar();
			//   printf("%i",x);
			for (int j = 0; j <= 9; j++){
				if (x == buf[j]) count++;
				//  getchar();
				//  getchar();
				//  printf("buf:%i, x:%i",buf[j],x);
			}
			if (count == 0) { buf[i + 1] = x; table[x] = 'x'; check = 1; }
			count = 0;
		}
		//  table[x]='x';
		printf("%s\n", table);
		count = 0;
		check = 0;

	}
	return 0;
}
