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

void DispMaze(char arr[][12]); // 미로의 상황을 출력 해 줄 함수

int main() {
	char arr[12][12]; //12*12 정방행렬선언
	int count = 0; /* 20개의 랜덤 블록 생성 카운트와 치즈를 1000번 동안 찾는 횟수를 카운트 해줄 변수*/
	srand((unsigned)time(NULL));
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if ((i == 0) || (i == 11) || (j == 0) || (j == 11))arr[i][j] = 'b'; //미로의 바깥 벽에 블록으로 둘러싼다
			else arr[i][j] = '-';//벽 안쪽에는 '-'로 초기화
		}
	}
	DispMaze(arr); // 벽으로 둘러 쌓여 있는 미로를 출력 하여 보여줌
	arr[1][1] = '*'; //처음 쥐가 있는 곳
	arr[10][10] = '*'; // 치즈가 있는 마지막 장소
		while (count != 20) {
			int a = (rand() % 10) + 1; int b = (rand() % 10) + 1; /*벽이 존재 하지 않는 1~10행, 1~10열에 생성 하기 위한 랜덤 변수 초기화*/
			if (!((a == 1 && b == 1) || (a == 10 && b == 10))) { /*쥐와 치즈가 없는 곳에 블록을 생성 하기 위한 조건*/
				if (arr[a][b] != 'b') { //블록의 중복 생성을 막기 위한 조건
					arr[a][b] = 'b';
						count++; //블록이 생성 되면 카운트를 1씩 증가
				}
			}
		}
	DispMaze(arr); // 랜덤 블록 20개가 생성 되었음을 보여줌
	count = 0; //카운트를 0으로 초기화
	char temp = arr[1][1];
	int x = 1; int y = 1;

	while (count != 1000) { //쥐가 천번 동안 치즈를 찾지 못한다면 실패
		int a;
		if (x == 10 && y == 10) break; //치즈가 있는 곳 까지 도달했다면 성공
		a = rand() % 100;
		if (0 <= a && a < 30) { //30프로의 확률로 우측하단으로 이동
			if (arr[x + 1][y + 1] != 'b') { //가고자 하는 방향에 블록이 없을 경우에만 이동
				x++; y++;
				arr[x][y] = '*';//경로마킹
					count++; //블록이 없는 곳으로 이동하고 마킹했다면 카운트를 1씩 증가
			}
		}
		else if (30 <= a && a < 50) { //20프로의 확률로 우측으로 이동
			if (arr[x][y + 1] != 'b') {//가고자 하는 방향에 블록이 없을 경우에만 이동
				y++;
				arr[x][y] = '*';//경로마킹
					count++; //블록이 없는 곳으로 이동하고 마킹했다면 카운트를 1씩 증가
			}
		}
		else if (50 <= a && a < 70) {//20프로의 확률로 아래로 이동
			if (arr[x + 1][y] != 'b') {//가고자 하는 방향에 블록이 없을 경우에만 이동
				x++;
				arr[x][y] = '*';//경로마킹
					count++;//블록이 없는 곳으로 이동하고 마킹했다면 카운트를 1씩 증가
			}
		}
		else if (70 <= a && a < 80) {//10프로의 확률로 우측상단으로 이동
			if (arr[x - 1][y + 1] != 'b') {//가고자 하는 방향에 블록이 없을 경우에만 이동
				x--; y++;
				arr[x][y] = '*';//경로마킹
					count++;//블록이 없는곳으로 이동하고 마킹했다면 카운트를 1씩 증가
			}
		}
		else if (80 <= a && a < 90) {//10프로의 확률로 좌측 하단으로 이동
			if (arr[x + 1][y - 1] != 'b') {//가고자 하는 방향에 블록이 없을 경우에만 이동
				x++; y--;
				arr[x][y] = '*';//경로마킹
					count++;//블록이 없는곳으로 이동하고 마킹했다면 카운트를 1씩 증가
			}
		}
		else if (90 <= a && a < 94) {//4프로의 확률로 위로 이동
			if (arr[x - 1][y] != 'b') {//가고자 하는 방향에 블록이 없을 경우에만 이동
				x--;
				arr[x][y] = '*';//경로마킹
					count++;//블록이 없는곳으로 이동하고 마킹했다면 카운트를 1씩 증가
			}
		}
		else if (94 <= a && a < 98) {//4프로의 확률로 왼쪽으로 이동
			if (arr[x][y - 1] != 'b') {//가고자 하는 방향에 블록이 없을 경우에만 이동
				y--;
				arr[x][y] = '*';//경로마킹
					count++;//블록이 없는곳으로 이동하고 마킹했다면 카운트를 1씩 증가
			}
		}
		else if (98 <= a && a <= 99) {//2프로의 확률로 좌측상단으로 이동
			if (arr[x - 1][y - 1] != 'b') {//가고자 하는 방향에 블록이 없을 경우에만 이동
				x--; y--;
				arr[x][y] = '*';//경로마킹
					count++;//블록이 없는곳으로 이동하고 마킹했다면 카운트를 1씩 증가
			}
		}
	}
	DispMaze(arr);//쥐가 이동한 경로 출력
	if (x == 10 && y == 10) {//쥐가 최종적으로 이동한 경로가 치즈가 있는 곳이라면 성공
		printf("\a%d 번 만에 치즈를 찾는 데 성공했습니다.\n", count);
	}
	if (!(x == 10 && y == 10))printf("치즈를 찾는 데 실패 했습니다.\n");/*쥐가 최종적으로 이동한 경로가 치즈가 있는 곳이 아니라면 실패*/
}

void DispMaze(char arr[][12]) { //미로를 출력하는 함수
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
