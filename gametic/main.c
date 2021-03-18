#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int x, o, d;
char buf[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
char posO[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
char posX[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
char table[] = {
	"|-----------|\n""|   |   |   |\n""|-----------|\n"
	"|   |   |   |\n""|-----------|\n"
	"|   |   |   |\n""|-----------|" };


int minimax(int status, int player){
	char finalScore = 0, maxScore, minScore, score[100];
	int r = 0;
	if (status == 1) return -10;
	if (status == 2) return 10;
	if (status == 3) return 0;
	if (status == 0){
		if (player == 1){
			for (int j = 0; j<9; j++){
				if (buf[j] == 0) {
					table[x] = 'x';
					posX[j] = 1;
					player++;
					finalScore += minimax(status, player);
					table[x] = ' ';
					posX[j] = 0;
					score[r++] = finalScore;
				}
				// printf("Nomer o: %i\n", buf[j]);
			}
			maxScore = big(score);
		}
		finalScore = 0;
		reload(score);
		r = 0;
		if (player == 2){
			for (int j = 0; j<9; j++){
				if (buf[j] == 0) {
					table[o] = 'o';
					posO[j] = 1;
					player--;
					finalScore += minimax(status, player);
					table[o] = ' ';
					posO[j] = 0;
					score[r++] = finalScore;
				}
				// printf("Nomer o: %i\n", buf[j]);
			}
			minScore = little(score);
		}
	}


}

int big(char scr[]){
	int i, mx;
	mx = 0;
	for (i = 0; i<sizeof(scr); i++) {
		if (scr[i] > scr[mx])
			mx = i;
	}
	return scr[mx];
}
int little(char scr[]){
	int i, mx;
	mx = 0;
	for (i = 0; i<sizeof(scr); i++) {
		if (scr[i] < scr[mx])
			mx = i;
	}
	return scr[mx];


}


int reload(char scr[]){
	for (int i = 0; i<sizeof(scr); i++) {
		scr[i] = 0;
	}
	return 0;
}



int main()
{

	int count = 0;
	int status = 0;
	char check = 0;
	int player = 0;
	char possition[] = { 16, 20, 24, 44, 48, 52, 72, 76, 80 };

	srand(time(NULL));
	//     system("cls");
	//    printf("%s\n",table);
	printf("\n");
	for (int i = 0; i<10; i += 2){
		system("cls");
		printf("%s\n", table);
		// printf("Nomer o: %i", o);
		while (check == 0){
			do{
				printf("Nomer x: ");
				scanf_s("%i", &o);
			} while ((o>9) || (o<1));

			o--;
			d = o;

			o = possition[o];
			for (int j = 0; j<9; j++){
				if (o == buf[j]) count++;
				// printf("Nomer o: %i\n", buf[j]);
			}
			if ((count == 0) || (i == 0)) { buf[i] = o; table[o] = 'o'; check = 1;   posO[d] = 1; }
			else { printf("Ne verney, vvedi esho raz"); }
			count = 0;

		}
		system("cls");
		printf("%s\n", table);
		if (((posO[0] == 1) && (posO[1] == 1) && (posO[2] == 1)) || ((posO[3] == 1) && (posO[4] == 1) && (posO[5] == 1)) || ((posO[6] == 1) && (posO[7] == 1) && (posO[8] == 1)) ||
			((posO[0] == 1) && (posO[3] == 1) && (posO[6] == 1)) || ((posO[1] == 1) && (posO[4] == 1) && (posO[7] == 1)) || ((posO[2] == 1) && (posO[5] == 1) && (posO[8] == 1)) ||
			((posO[0] == 1) && (posO[4] == 1) && (posO[8] == 1)) || ((posO[2] == 1) && (posO[4] == 1) && (posO[6] == 1))){
			status = 1;
			i = 12;
			system("cls");
			printf("%s\n", table);
			printf("WIN");
		}
		// count =0;
		check = 0;
		if (i<8){
			while (check == 0){
				x = rand() % 9;
				d = x;
				x = possition[x];
				for (int j = 0; j <= 9; j++){
					if (buf[j] == 0) {
						table[x] = 'x';
						posX[j] = 1;
						/*ÄÎÄÅËÀÉ ÌÈÍÈÌÀÊÑ ÃËÀÂÍÎÉ ÔÓÍÊÖÈÈ ÂÎÇÌÎÆÍÎ ÂÑÅ ÏÎ ÆÎÏÅ ÏÎØËÎ*/
					}
				}
				if (count == 0) { buf[i + 1] = x; table[x] = 'x'; check = 1; posX[d] = 1; }
				count = 0;

			}
			//for (i=0;i<9;i++){
			// }
			//printf("%s\n",table);
			check = 0;
		}
		
		if (((posX[0] == 1) && (posX[1] == 1) && (posX[2] == 1)) || ((posX[3] == 1) && (posX[4] == 1) && (posX[5] == 1)) || ((posX[6] == 1) && (posX[7] == 1) && (posX[8] == 1)) ||
			((posX[0] == 1) && (posX[3] == 1) && (posX[6] == 1)) || ((posX[1] == 1) && (posX[4] == 1) && (posX[7] == 1)) || ((posX[2] == 1) && (posX[5] == 1) && (posX[8] == 1)) ||
			((posX[0] == 1) && (posX[4] == 1) && (posX[8] == 1)) || ((posX[2] == 1) && (posX[4] == 1) && (posX[6] == 1))){
			status = 2;
			i = 12;
			system("cls");
			printf("%s\n", table);
			printf("Game over");
		}
	}
	if (status == 0){ printf("Ni tebe ni mne"); }
	getch();
	getch();

	return 0;
}



