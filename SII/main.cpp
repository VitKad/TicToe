#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

int map[9];   //������ ������� �������� ��������� � � �




void draw()   //���������� ����
{

	printf(" --------------------- \n");
	for (int i = 1; i <= 9; i++)
	{
		if (map[i] == 0) { printf("  |   "); };
		if (map[i] == 1) { printf("  |  0"); };
		if (map[i] == 2) { printf("  |  X"); };
		if ((i == 3) || (i == 6) || (i == 9)) {
			printf("  |\n"); 	
			printf(" --------------------- \n");
		}
			
	}
	

}

int checkWin()  //�������� �� ������
{
	
 
	for (int i = 1; i <= 2; i++){  //���� 1 �� ���������� �����, ���� 2 �� ���������
		//�����������
		if (map[1] == i && map[2] == i && map[3] == i) { return(i); }  
		if (map[4] == i && map[5] == i && map[6] == i) { return(i); }
		if (map[7] == i && map[8] == i && map[9] == i) { return(i); }

		//���������
		if (map[1] == i && map[4] == i && map[7] == i) { return(i); }
		if (map[2] == i && map[5] == i && map[8] == i) { return(i); }
		if (map[3] == i && map[6] == i && map[9] == i) { return(i); }

		//���������
		if (map[1] == i && map[5] == i && map[9] == i) { return(i); }
		if (map[3] == i && map[5] == i && map[7] == i) { return(i); }
	}
	
	return 0; //���� ��� ����������
}



int minimax(int status, int player){   //��������
	char finalScore = 0, scr;
	int fieldNumber = 0;  //������ �������
	if (status == 1) return -10;  //���� ������� �����
	if (status == 2) return 10;   //���� ������� ���������
	if (status == 3) return 0;
	if (status == 0){
		if (player == 2){
			for (int i = 1; i <= 9; i++){
				
				fieldNumber = i;
				
				if (map[fieldNumber] == 0 && (fieldNumber == 1 || fieldNumber == 2 || fieldNumber == 3 ||
					fieldNumber == 4 || fieldNumber == 5 || fieldNumber == 6 || 
					fieldNumber == 7 || fieldNumber == 8 || fieldNumber == 9)){
					
						map[fieldNumber] = 2;
						status = checkWin();

						scr = minimax(status, --player);
						map[fieldNumber] = 0;
						if (scr > finalScore) { finalScore = scr; }   //���� ������� ���� ������ ����������� �� �������� ���
				}
			}
			return(finalScore);
		}

		if (player == 1){
			finalScore = 1000;
			for (int i = 1; i <= 9; i++){
				
				fieldNumber = i;
				
				if (map[fieldNumber] == 0 && (fieldNumber == 1 || fieldNumber == 2 || fieldNumber == 3 || fieldNumber == 4 || fieldNumber == 5 || fieldNumber == 6 || fieldNumber == 7 || fieldNumber == 8 || fieldNumber == 9)){
					
					map[fieldNumber] = 1;
					status = checkWin();
					scr = minimax(status, ++player);
					map[fieldNumber] = 0;
					if (scr < finalScore) { finalScore = scr; }
					
				}
			}
			return(finalScore);
		}
	}
}


int main()
{
	int score = 0, maxScore = 0, i1 = 0;
	int stopGame = 0; //��� �����
	int player = 1; //1 - �����, 2- ���������
	int fieldNumber = 0; 
	int game=0;
	
	draw();
	while (game == 0)
	{
		int t = 0;
		while ( t == 0)  //��� ������
		{
			printf("\n Enter field number: \n");
			scanf_s("%d", &fieldNumber);
			system("cls");

			if (map[fieldNumber] == 0 && (fieldNumber == 1 || fieldNumber == 2 || fieldNumber == 3 
				|| fieldNumber == 4 || fieldNumber == 5 || fieldNumber == 6 
				|| fieldNumber == 7 || fieldNumber == 8 || fieldNumber == 9)) {
					(t = 1);
					map[fieldNumber] = 1;
			}
		}
		
		draw();
		system("cls");
		game = checkWin(); //�������� �� ������
		stopGame++;

		if (game == 0) //��� ������� ������
		{
			for (int i = 1; i <= 9; i++){

				fieldNumber = i;
				if (map[fieldNumber] == 0 && (fieldNumber == 1 || fieldNumber == 2 || fieldNumber == 3 ||
					fieldNumber == 4 || fieldNumber == 5 || fieldNumber == 6 ||
					fieldNumber == 7 || fieldNumber == 8 || fieldNumber == 9)){

						map[fieldNumber] = 2;
						game = checkWin();
						i1 = fieldNumber;

						//MINIMAX
						score = minimax(--player, game);
						fieldNumber = i1;
						map[fieldNumber] = 0;
						if (score > maxScore) { maxScore = score; i1 = fieldNumber;  }
				}
			}
			map[i1] = 2;  //� ���������� ������ ��������� �
			draw();
			
			game = checkWin();
			stopGame++;
			player = 1;  //������������ �� ������
			if (stopGame>9) { game = 3; }; 	//���� ����� ������ 9 ����� � ����� �� ������� �� �����
		}

	}

	if (game == 1) { printf("Win 0\n"); };
	if (game == 2) { printf("Win X\n"); };
	if (game == 3) { printf("No winner\n", &player); };

	_getch();

	return 0;
}