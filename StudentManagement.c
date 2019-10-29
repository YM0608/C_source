//Student Performance Management Program
/*
Random names and grades of students to input the name of 1,000 people and 
sort by scores and grades to identify internal affairs of the top 50.Top grades got 30 of the final successful applicants, 
and to print student oldest to do, advance the name of the output information.
Also add the Binary search function, 
consistent with the grades they get input from users who all outputs and information.
*/
/*
the main content
- A structure shall be constructed in which the student's information (Test number, name, national, English, math grades, and total scores of subjects) is taken as a member variable.
- Student names have a random length of between 3 and 6 characters.
- The average score and percentage of each subject are set and the scores are entered randomly based on this. In other words, students' grades generally follow the regular distribution.
- After students have received all the information, they are sorted in ascending order based on the total score to show the internal assessment log. Then, the top 50 scores are printed.
- The successful candidates are ranked 30th in the top grades, but all students who are ranked 30th and tied will be treated as successful. 
	Print out information by arranging accepted students in alphabetical order of names, not in order of grades.
- When a user enters a grade, the binary search function is implemented, which finds and outputs all students with total scores. 
	Repeat until the user says he won't look for it.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Student { //지원 학생의 정보들의 집합인 구조체
	char name[10];
	int kor;
	int math;
	int eng;
	int sum;
	int soohum;
};

void GetName(struct Student stu[]); // 학생의 이름은 3~6자 랜덤으로 입력받는 함수
void GetKor(struct Student stu[]); // 학생의 국어성적을 랜덤 입력받는 함수
void GetEng(struct Student stu[]); // 학생의 영어성적을 랜덤 입력받는 함수
void GetMath(struct Student stu[]); // 학생의 수학성적을 랜덤 입력받는 함수
void GetSum(struct Student stu[]); // 학생의 국영수 총합 점수를 입력받는 함수
void GetSooHum(struct Student stu[]); // 학생의 수험번호를 입력받는 함수
void Sort(struct Student stu[]); // 학생들을 총점수 기준으로 오름차순 정렬하는 함수
void PrintStu(struct Student stu[], int n); // 학생의 정보를 출력하는 함수
void SucCandidate(struct Student stu[], struct Student winners[]);
// 지원 학생중 상위 30명을 출력하는 함수, 이때 학생이름기준 사전순으로 출력한다.(30등과 동점자도 합격자 처리)
void B_S_Search(struct Student stu[], int sc); // 사용자가 성적을 입력하면, 해당 성적을 가진 학생의 정보를 전부 출력

int main() {
	struct Student stu[1050]; struct Student winners[1000];
	int sc; int soonsuh = 1; char fin = 'y'; int temp = 0;
	srand((unsigned)time(NULL));
	GetSooHum(stu); GetName(stu); GetKor(stu); GetEng(stu); GetMath(stu); GetSum(stu); // 학생의 정보를 전부 입력받음
	Sort(stu); // 학생들을 총점수 기준, 오름차순으로 정렬시킴
	printf("내부 사정 대장 출력 (상위성적50명)\n");
	printf("-------------------------------\n");
	for (int i = 999, j = 1; i >= 950; i--, j++) { // 상위 성적 50명의 정보를 출력
		printf("%d등의 정보 : \n", j);
		PrintStu(stu, i);
	}
	printf("-------------------------------\n\n");
	printf("상위 성적 30명 합격자 명단 출력 (동점자 처리, 합격자 이름 사전순배열)\n");
	printf("-------------------------------\n");

	while (1) { //30등 성적을 가진 학생들 중, 가장 낮은 등수의 학생 인덱스를 확인
		if (stu[temp].sum == stu[970].sum)break;
		temp++;
	}
	SucCandidate(stu, winners); //합격자 즉,상위 30명 학생들을 출력하기 전에, 학생이름을 기준으로 사전순 정렬시킴
	while (temp < 1000) { //30등과 동점자인 학생들 중, 낮은 등수를 가진 학생부터 1등까지 이름의 사전순으로 출력
		printf("%d . \n", soonsuh); // 학생 수를 명시적으로 보여주기 위함.
		PrintStu(winners, temp);
		temp++; soonsuh++;
	}
	printf("-------------------------------\n");

	do {
		printf("총점을 입력하여 학생을 찾습니다.\n");
		printf("점수 입력 : ");
		scanf("%d", &sc);
		B_S_Search(stu, sc); // 점수를 입력하면, 해당 점수를 총점수로 가지고 있는 학생을 찾는 이진탐색 함수 실행

		printf("한 번 더 찾으시겠습니까??(y or n) : ");
		scanf(" %c", &fin);
	} while (fin == 'y');
	return 0;
}

void B_S_Search(struct Student stu[], int sc) {
	int high; int low; int middle; int temp; int temp2;
	high = 1000 - 1; low = 0; //1000명의 학생중 1000번째 즉, 마지막 학생을 가리키는 인덱스 high는 999, 첫번째 학생을 가리키는 인덱스 low는 0
	while (low <= high) {
		middle = (high + low) / 2; // 오른쪽인덱스와 왼쪽인덱스의 가운데 인덱스 middle
		if (sc == stu[middle].sum) { // middle 인덱스가 가리키고 있는 학생의 총점수가 사용자가 입력한 점수와 일치할경우
			printf("총점 %d 점수를 가진 학생을 찾았습니다!!\n\n", sc);
			printf("학생 정보 출력\n");
			PrintStu(stu, middle); // 학생정보출력
			temp = middle; temp2 = middle;
			/*학생의 배열은 이미 성적순으로 정렬이 되어 있는 상태이다.
			따라서 해당 점수를 가지고 있는 학생 즉, 인덱스 middle이 가리키고 있는 좌측,우측 근처에도
			동점자가 있을 수 있으므로 이를 탐색한다.
			*/
			while (stu[middle].sum == stu[temp + 1].sum) { // 해당 점수를 가진 학생의 오른쪽 학생들 중에서 동점자를 탐색하고 더이상 동점자가 아닐 시 루프문 벗어남
				printf("총점 %d 점수를 가진 학생을 찾았습니다!!\n\n", sc);
				printf("학생 정보 출력\n");
				PrintStu(stu, temp + 1);
				temp++;
			}
			while (stu[middle].sum == stu[temp2 - 1].sum) {// 해당 점수를 가진 학생의 왼쪽 학생들 중에서 동점자를 탐색하고 더이상 동점자가 아닐 시 루프문 벗어남
				printf("총점 %d 점수를 가진 학생을 찾았습니다!!\n\n", sc);
				printf("학생 정보 출력\n");
				PrintStu(stu, temp2 - 1);
				temp2--;
			}
			return;
		}
		else if (sc < stu[middle].sum) high = middle - 1;
		// 사용자가 입력한 점수가 middle이 가리키고 있는 학생의 총점수보다 낮을 경우에 오른쪽을 가리키고 있던 high인덱스를 middle보다 1낮은 인덱스로 초기화
		else low = middle + 1;
		// 사용자가 입력한 점수가 middle이 가리키고 있는 학생의 총점수보다 높을 경우에 왼쪽을 가리키고 있던 low인덱스를 middle보다 1높은 인덱스로 초기화
	}
	printf("총점 %d 점을 가진 학생을 찾지 못했습니다.\n ", sc);
	return;
}


void Sort(struct Student stu[]) { // 학생들을 총점수기준, 오름차순으로 정렬하는 함수
	int least; int temp; char ntemp[10];
	for (int i = 0; i < 1000 - 1; i++) {
		least = i;
		for (int j = i + 1; j < 1000; j++) {
			if (stu[j].sum < stu[least].sum) { least = j; }
			temp = stu[i].sum;
			stu[i].sum = stu[least].sum;
			stu[least].sum = temp;
			temp = stu[i].soohum;
			stu[i].soohum = stu[least].soohum;
			stu[least].soohum = temp;
			temp = stu[i].kor;
			stu[i].kor = stu[least].kor;
			stu[least].kor = temp;
			temp = stu[i].eng;
			stu[i].eng = stu[least].eng;
			stu[least].eng = temp;
			temp = stu[i].math;
			stu[i].math = stu[least].math;
			stu[least].math = temp;
			for (int x = 0; x < 10; x++) {
				ntemp[x] = stu[i].name[x];
				stu[i].name[x] = stu[least].name[x];
				stu[least].name[x] = ntemp[x];
			}

		}
	}
}

void PrintStu(struct Student stu[], int n) { // n번째 학생의 정보를 출력하는 함수
	int i = 0;
	printf("학생 수험 번호 : %d\n", stu[n].soohum);
	printf("학생 이름 : ");
	while (stu[n].name[i] != '\0') { printf("%c", stu[n].name[i]); i++; }
	printf("\n");
	printf("국어 성적 : %d\n", stu[n].kor);
	printf("영어 성적 : %d\n", stu[n].eng);
	printf("수학 성적 : %d\n", stu[n].math);
	printf("성적의 총합 : %d\n\n", stu[n].sum);


}

void SucCandidate(struct Student stu[], struct Student winners[]) { // 최종 합격자 상위30등까지의 학생들을 사전순으로 정렬 하는 함수
	int least; int temp; char ntemp[10]; int temp2 = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 10; j++)winners[i].name[j] = stu[i].name[j];
		winners[i].kor = stu[i].kor;
		winners[i].eng = stu[i].eng;
		winners[i].math = stu[i].math;
		winners[i].sum = stu[i].sum;
		winners[i].soohum = stu[i].soohum;
	}
	while (1) { //30등 성적을 가진 학생들 중, 가장 낮은 등수의 학생 인덱스를 확인
		if (winners[temp2].sum == winners[970].sum)break;
		temp2++;
	}
	for (int i = temp2; i < 999; i++) { // 30등과 같은 성적을 가진 학생들 중, 가장 낮은 등수의 학생부터 1등까지 이름을 기준으로 사전순 정렬
		least = i;
		for (int j = i + 1; j < 1000; j++) {
			if (strcmp(winners[j].name, winners[least].name) < 0) { least = j; }
			temp = winners[i].sum;
			winners[i].sum = winners[least].sum;
			winners[least].sum = temp;
			temp = winners[i].soohum;
			winners[i].soohum = winners[least].soohum;
			winners[least].soohum = temp;
			temp = winners[i].kor;
			winners[i].kor = winners[least].kor;
			winners[least].kor = temp;
			temp = winners[i].eng;
			winners[i].eng = winners[least].eng;
			winners[least].eng = temp;
			temp = winners[i].math;
			winners[i].math = winners[least].math;
			winners[least].math = temp;
			for (int x = 0; x < 10; x++) {
				ntemp[x] = winners[i].name[x];
				winners[i].name[x] = winners[least].name[x];
				winners[least].name[x] = ntemp[x];
			}
		}
	}
}

void GetSooHum(struct Student stu[]) { // 학생의 수험번호를 입력 받는 함수
	for (int i = 0; i < 1000; i++)stu[i].soohum = i + 1;
}

void GetName(struct Student stu[]) { // 학생의 이름을 3~6글자 사이의 랜덤 입력 받는 함수
	int per; char randomalpha;
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 10; j++)
			stu[i].name[j] = '\0';

	for (int i = 0; i < 1000; i++) {
		per = rand() % 4 + 3;
		for (int j = 0; j < per; j++) {
			randomalpha = (char)(rand() % 26 + 97);
			stu[i].name[j] = randomalpha;
		}
	}

}

void GetKor(struct Student stu[]) { // 학생의 국어 성적을 입력 받는 함수, 국어성적의 평균은 55점
	int korM = 55;
	int per;

	for (int i = 0; i < 1000; i++) {
		per = rand() % 100 + 1;
		if (per >= 1 && per <= 50) {
			stu[i].kor = rand() % 11 + korM - 5;
		}
		else if (per >= 51 && per <= 68) {
			stu[i].kor = rand() % 11 + korM + 5;
		}
		else if (per >= 69 && per <= 86) {
			stu[i].kor = korM - 5 - (rand() % 11);
		}
		else if (per >= 87 && per <= 91) {
			stu[i].kor = rand() % 11 + korM + 5 + 10;
		}
		else if (per >= 92 && per <= 96) {
			stu[i].kor = korM - 5 - 10 - (rand() % 11);
		}
		else if (per >= 97 && per <= 98) {
			stu[i].kor = rand() % 11 + korM + 5 + 10 + 10;
		}
		else if (per >= 99 && per <= 100) {
			stu[i].kor = korM - 5 - 10 - 10 - (rand() % 11);
		}
	}

}

void GetEng(struct Student stu[]) { // 학생의 영어 성적을 입력받는 함수, 영어성적의 평균은 60점
	int engM = 60;
	int per;

	for (int i = 0; i < 1000; i++) {
		per = rand() % 100 + 1;
		if (per >= 1 && per <= 50) {
			stu[i].eng = rand() % 11 + engM - 5;
		}
		else if (per >= 51 && per <= 68) {
			stu[i].eng = rand() % 11 + engM + 5;
		}
		else if (per >= 69 && per <= 86) {
			stu[i].eng = engM - 5 - (rand() % 11);
		}
		else if (per >= 87 && per <= 91) {
			stu[i].eng = rand() % 11 + engM + 5 + 10;
		}
		else if (per >= 92 && per <= 96) {
			stu[i].eng = engM - 5 - 10 - (rand() % 11);
		}
		else if (per >= 97 && per <= 98) {
			stu[i].eng = rand() % 11 + engM + 5 + 10 + 10;
		}
		else if (per >= 99 && per <= 100) {
			stu[i].eng = engM - 5 - 10 - 10 - (rand() % 11);
		}
	}
}

void GetMath(struct Student stu[]) { // 학생의 수학 성적을 입력받는 함수, 수학성적의 평균은 60점
	int mathM = 60;
	int per;

	for (int i = 0; i < 1000; i++) {
		per = rand() % 100 + 1;
		if (per >= 1 && per <= 50) {
			stu[i].math = rand() % 11 + mathM - 5;
		}
		else if (per >= 51 && per <= 68) {
			stu[i].math = rand() % 11 + mathM + 5;
		}
		else if (per >= 69 && per <= 86) {
			stu[i].math = mathM - 5 - (rand() % 11);
		}
		else if (per >= 87 && per <= 91) {
			stu[i].math = rand() % 11 + mathM + 5 + 10;
		}
		else if (per >= 92 && per <= 96) {
			stu[i].math = mathM - 5 - 10 - (rand() % 11);
		}
		else if (per >= 97 && per <= 98) {
			stu[i].math = rand() % 11 + mathM + 5 + 10 + 10;
		}
		else if (per >= 99 && per <= 100) {
			stu[i].math = mathM - 5 - 10 - 10 - (rand() % 11);
		}
	}
}

void GetSum(struct Student stu[]) { // 학생의 국어,영어,수학 성적들의 총합점수를 입력 받는 함수

	for (int i = 0; i < 1000; i++) {
		stu[i].sum = 0;
	}
	for (int i = 0; i < 1000; i++) {
		stu[i].sum = stu[i].kor + stu[i].eng + stu[i].math;
	}

}