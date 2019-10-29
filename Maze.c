// Maze Program in which rats find cheese.
/*
There are rats and cheese in a hundred-room maze, and there are blocks on every side of the maze. 
The mouse tries to move every time it finds the cheese. Attempts to move in the direction of the block will fail. 
At this time, the mouse can smell the cheese, so it moves in the direction of the cheese on the move, at a relatively high probability.
In addition to blocks that are blocked in all directions, 20 blocks are created randomly in the maze, 
which also fails to move when the blocks are present. Mice will try to move for 1000 times, and the path they move will be marked with a *mark
If the cheese is reached within 1000 times, print out the success and travel route and print out how many times you have found it. 
If the cheese has not been reached within 1000 times, print the path of movement and print out the failure.
*/
/*
<The main content>.
- 12 * 12 to initialize the wall in all over the block, and to create a matrix and output around to see it.
- A mouse is produced on the inside, top left of the wall, cheese on the bottom right, 
   20 blocks randomly in the remaining labyrinths, except these two compartments, and output to show the maze situation to date.
- 30% chance to the bottom right, 20% chance to the right, 10% chance to the right or the bottom, 4% chance to the top left, 2% chance to the top left.
-  If a block exists where the mouse wants to move, the mouse should not move.
- Repeat the above process 1000 times and print out if the mouse has reached the place where the cheese is, then it is a success, and only a few times has been reached.
- If the mouse did not reach the cheese area during 1000 movements, print the path that was moved and the failure.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void DispMaze(char arr[][12]); // �̷��� ��Ȳ�� ��� �� �� �Լ�

int main() {
	char arr[12][12]; //12*12 ������ļ���
	int count = 0; /* 20���� ���� ��� ���� ī��Ʈ�� ġ� 1000�� ���� ã�� Ƚ���� ī��Ʈ ���� ����*/
	srand((unsigned)time(NULL));
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if ((i == 0) || (i == 11) || (j == 0) || (j == 11))arr[i][j] = 'b'; //�̷��� �ٱ� ���� ������� �ѷ��Ѵ�
			else arr[i][j] = '-';//�� ���ʿ��� '-'�� �ʱ�ȭ
		}
	}
	DispMaze(arr); // ������ �ѷ� �׿� �ִ� �̷θ� ��� �Ͽ� ������
	arr[1][1] = '*'; //ó�� �㰡 �ִ� ��
	arr[10][10] = '*'; // ġ� �ִ� ������ ���
		while (count != 20) {
			int a = (rand() % 10) + 1; int b = (rand() % 10) + 1; /*���� ���� ���� �ʴ� 1~10��, 1~10���� ���� �ϱ� ���� ���� ���� �ʱ�ȭ*/
			if (!((a == 1 && b == 1) || (a == 10 && b == 10))) { /*��� ġ� ���� ���� ����� ���� �ϱ� ���� ����*/
				if (arr[a][b] != 'b') { //����� �ߺ� ������ ���� ���� ����
					arr[a][b] = 'b';
						count++; //����� ���� �Ǹ� ī��Ʈ�� 1�� ����
				}
			}
		}
	DispMaze(arr); // ���� ��� 20���� ���� �Ǿ����� ������
	count = 0; //ī��Ʈ�� 0���� �ʱ�ȭ
	char temp = arr[1][1];
	int x = 1; int y = 1;

	while (count != 1000) { //�㰡 õ�� ���� ġ� ã�� ���Ѵٸ� ����
		int a;
		if (x == 10 && y == 10) break; //ġ� �ִ� �� ���� �����ߴٸ� ����
		a = rand() % 100;
		if (0 <= a && a < 30) { //30������ Ȯ���� �����ϴ����� �̵�
			if (arr[x + 1][y + 1] != 'b') { //������ �ϴ� ���⿡ ����� ���� ��쿡�� �̵�
				x++; y++;
				arr[x][y] = '*';//��θ�ŷ
					count++; //����� ���� ������ �̵��ϰ� ��ŷ�ߴٸ� ī��Ʈ�� 1�� ����
			}
		}
		else if (30 <= a && a < 50) { //20������ Ȯ���� �������� �̵�
			if (arr[x][y + 1] != 'b') {//������ �ϴ� ���⿡ ����� ���� ��쿡�� �̵�
				y++;
				arr[x][y] = '*';//��θ�ŷ
					count++; //����� ���� ������ �̵��ϰ� ��ŷ�ߴٸ� ī��Ʈ�� 1�� ����
			}
		}
		else if (50 <= a && a < 70) {//20������ Ȯ���� �Ʒ��� �̵�
			if (arr[x + 1][y] != 'b') {//������ �ϴ� ���⿡ ����� ���� ��쿡�� �̵�
				x++;
				arr[x][y] = '*';//��θ�ŷ
					count++;//����� ���� ������ �̵��ϰ� ��ŷ�ߴٸ� ī��Ʈ�� 1�� ����
			}
		}
		else if (70 <= a && a < 80) {//10������ Ȯ���� ����������� �̵�
			if (arr[x - 1][y + 1] != 'b') {//������ �ϴ� ���⿡ ����� ���� ��쿡�� �̵�
				x--; y++;
				arr[x][y] = '*';//��θ�ŷ
					count++;//����� ���°����� �̵��ϰ� ��ŷ�ߴٸ� ī��Ʈ�� 1�� ����
			}
		}
		else if (80 <= a && a < 90) {//10������ Ȯ���� ���� �ϴ����� �̵�
			if (arr[x + 1][y - 1] != 'b') {//������ �ϴ� ���⿡ ����� ���� ��쿡�� �̵�
				x++; y--;
				arr[x][y] = '*';//��θ�ŷ
					count++;//����� ���°����� �̵��ϰ� ��ŷ�ߴٸ� ī��Ʈ�� 1�� ����
			}
		}
		else if (90 <= a && a < 94) {//4������ Ȯ���� ���� �̵�
			if (arr[x - 1][y] != 'b') {//������ �ϴ� ���⿡ ����� ���� ��쿡�� �̵�
				x--;
				arr[x][y] = '*';//��θ�ŷ
					count++;//����� ���°����� �̵��ϰ� ��ŷ�ߴٸ� ī��Ʈ�� 1�� ����
			}
		}
		else if (94 <= a && a < 98) {//4������ Ȯ���� �������� �̵�
			if (arr[x][y - 1] != 'b') {//������ �ϴ� ���⿡ ����� ���� ��쿡�� �̵�
				y--;
				arr[x][y] = '*';//��θ�ŷ
					count++;//����� ���°����� �̵��ϰ� ��ŷ�ߴٸ� ī��Ʈ�� 1�� ����
			}
		}
		else if (98 <= a && a <= 99) {//2������ Ȯ���� ����������� �̵�
			if (arr[x - 1][y - 1] != 'b') {//������ �ϴ� ���⿡ ����� ���� ��쿡�� �̵�
				x--; y--;
				arr[x][y] = '*';//��θ�ŷ
					count++;//����� ���°����� �̵��ϰ� ��ŷ�ߴٸ� ī��Ʈ�� 1�� ����
			}
		}
	}
	DispMaze(arr);//�㰡 �̵��� ��� ���
	if (x == 10 && y == 10) {//�㰡 ���������� �̵��� ��ΰ� ġ� �ִ� ���̶�� ����
		printf("\a%d �� ���� ġ� ã�� �� �����߽��ϴ�.\n", count);
	}
	if (!(x == 10 && y == 10))printf("ġ� ã�� �� ���� �߽��ϴ�.\n");/*�㰡 ���������� �̵��� ��ΰ� ġ� �ִ� ���� �ƴ϶�� ����*/
}

void DispMaze(char arr[][12]) { //�̷θ� ����ϴ� �Լ�
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
