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

struct Student { //���� �л��� �������� ������ ����ü
	char name[10];
	int kor;
	int math;
	int eng;
	int sum;
	int soohum;
};

void GetName(struct Student stu[]); // �л��� �̸��� 3~6�� �������� �Է¹޴� �Լ�
void GetKor(struct Student stu[]); // �л��� ������� ���� �Է¹޴� �Լ�
void GetEng(struct Student stu[]); // �л��� ������� ���� �Է¹޴� �Լ�
void GetMath(struct Student stu[]); // �л��� ���м����� ���� �Է¹޴� �Լ�
void GetSum(struct Student stu[]); // �л��� ������ ���� ������ �Է¹޴� �Լ�
void GetSooHum(struct Student stu[]); // �л��� �����ȣ�� �Է¹޴� �Լ�
void Sort(struct Student stu[]); // �л����� ������ �������� �������� �����ϴ� �Լ�
void PrintStu(struct Student stu[], int n); // �л��� ������ ����ϴ� �Լ�
void SucCandidate(struct Student stu[], struct Student winners[]);
// ���� �л��� ���� 30���� ����ϴ� �Լ�, �̶� �л��̸����� ���������� ����Ѵ�.(30��� �����ڵ� �հ��� ó��)
void B_S_Search(struct Student stu[], int sc); // ����ڰ� ������ �Է��ϸ�, �ش� ������ ���� �л��� ������ ���� ���

int main() {
	struct Student stu[1050]; struct Student winners[1000];
	int sc; int soonsuh = 1; char fin = 'y'; int temp = 0;
	srand((unsigned)time(NULL));
	GetSooHum(stu); GetName(stu); GetKor(stu); GetEng(stu); GetMath(stu); GetSum(stu); // �л��� ������ ���� �Է¹���
	Sort(stu); // �л����� ������ ����, ������������ ���Ľ�Ŵ
	printf("���� ���� ���� ��� (��������50��)\n");
	printf("-------------------------------\n");
	for (int i = 999, j = 1; i >= 950; i--, j++) { // ���� ���� 50���� ������ ���
		printf("%d���� ���� : \n", j);
		PrintStu(stu, i);
	}
	printf("-------------------------------\n\n");
	printf("���� ���� 30�� �հ��� ��� ��� (������ ó��, �հ��� �̸� �������迭)\n");
	printf("-------------------------------\n");

	while (1) { //30�� ������ ���� �л��� ��, ���� ���� ����� �л� �ε����� Ȯ��
		if (stu[temp].sum == stu[970].sum)break;
		temp++;
	}
	SucCandidate(stu, winners); //�հ��� ��,���� 30�� �л����� ����ϱ� ����, �л��̸��� �������� ������ ���Ľ�Ŵ
	while (temp < 1000) { //30��� �������� �л��� ��, ���� ����� ���� �л����� 1����� �̸��� ���������� ���
		printf("%d . \n", soonsuh); // �л� ���� ��������� �����ֱ� ����.
		PrintStu(winners, temp);
		temp++; soonsuh++;
	}
	printf("-------------------------------\n");

	do {
		printf("������ �Է��Ͽ� �л��� ã���ϴ�.\n");
		printf("���� �Է� : ");
		scanf("%d", &sc);
		B_S_Search(stu, sc); // ������ �Է��ϸ�, �ش� ������ �������� ������ �ִ� �л��� ã�� ����Ž�� �Լ� ����

		printf("�� �� �� ã���ðڽ��ϱ�??(y or n) : ");
		scanf(" %c", &fin);
	} while (fin == 'y');
	return 0;
}

void B_S_Search(struct Student stu[], int sc) {
	int high; int low; int middle; int temp; int temp2;
	high = 1000 - 1; low = 0; //1000���� �л��� 1000��° ��, ������ �л��� ����Ű�� �ε��� high�� 999, ù��° �л��� ����Ű�� �ε��� low�� 0
	while (low <= high) {
		middle = (high + low) / 2; // �������ε����� �����ε����� ��� �ε��� middle
		if (sc == stu[middle].sum) { // middle �ε����� ����Ű�� �ִ� �л��� �������� ����ڰ� �Է��� ������ ��ġ�Ұ��
			printf("���� %d ������ ���� �л��� ã�ҽ��ϴ�!!\n\n", sc);
			printf("�л� ���� ���\n");
			PrintStu(stu, middle); // �л��������
			temp = middle; temp2 = middle;
			/*�л��� �迭�� �̹� ���������� ������ �Ǿ� �ִ� �����̴�.
			���� �ش� ������ ������ �ִ� �л� ��, �ε��� middle�� ����Ű�� �ִ� ����,���� ��ó����
			�����ڰ� ���� �� �����Ƿ� �̸� Ž���Ѵ�.
			*/
			while (stu[middle].sum == stu[temp + 1].sum) { // �ش� ������ ���� �л��� ������ �л��� �߿��� �����ڸ� Ž���ϰ� ���̻� �����ڰ� �ƴ� �� ������ ���
				printf("���� %d ������ ���� �л��� ã�ҽ��ϴ�!!\n\n", sc);
				printf("�л� ���� ���\n");
				PrintStu(stu, temp + 1);
				temp++;
			}
			while (stu[middle].sum == stu[temp2 - 1].sum) {// �ش� ������ ���� �л��� ���� �л��� �߿��� �����ڸ� Ž���ϰ� ���̻� �����ڰ� �ƴ� �� ������ ���
				printf("���� %d ������ ���� �л��� ã�ҽ��ϴ�!!\n\n", sc);
				printf("�л� ���� ���\n");
				PrintStu(stu, temp2 - 1);
				temp2--;
			}
			return;
		}
		else if (sc < stu[middle].sum) high = middle - 1;
		// ����ڰ� �Է��� ������ middle�� ����Ű�� �ִ� �л��� ���������� ���� ��쿡 �������� ����Ű�� �ִ� high�ε����� middle���� 1���� �ε����� �ʱ�ȭ
		else low = middle + 1;
		// ����ڰ� �Է��� ������ middle�� ����Ű�� �ִ� �л��� ���������� ���� ��쿡 ������ ����Ű�� �ִ� low�ε����� middle���� 1���� �ε����� �ʱ�ȭ
	}
	printf("���� %d ���� ���� �л��� ã�� ���߽��ϴ�.\n ", sc);
	return;
}


void Sort(struct Student stu[]) { // �л����� ����������, ������������ �����ϴ� �Լ�
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

void PrintStu(struct Student stu[], int n) { // n��° �л��� ������ ����ϴ� �Լ�
	int i = 0;
	printf("�л� ���� ��ȣ : %d\n", stu[n].soohum);
	printf("�л� �̸� : ");
	while (stu[n].name[i] != '\0') { printf("%c", stu[n].name[i]); i++; }
	printf("\n");
	printf("���� ���� : %d\n", stu[n].kor);
	printf("���� ���� : %d\n", stu[n].eng);
	printf("���� ���� : %d\n", stu[n].math);
	printf("������ ���� : %d\n\n", stu[n].sum);


}

void SucCandidate(struct Student stu[], struct Student winners[]) { // ���� �հ��� ����30������� �л����� ���������� ���� �ϴ� �Լ�
	int least; int temp; char ntemp[10]; int temp2 = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 10; j++)winners[i].name[j] = stu[i].name[j];
		winners[i].kor = stu[i].kor;
		winners[i].eng = stu[i].eng;
		winners[i].math = stu[i].math;
		winners[i].sum = stu[i].sum;
		winners[i].soohum = stu[i].soohum;
	}
	while (1) { //30�� ������ ���� �л��� ��, ���� ���� ����� �л� �ε����� Ȯ��
		if (winners[temp2].sum == winners[970].sum)break;
		temp2++;
	}
	for (int i = temp2; i < 999; i++) { // 30��� ���� ������ ���� �л��� ��, ���� ���� ����� �л����� 1����� �̸��� �������� ������ ����
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

void GetSooHum(struct Student stu[]) { // �л��� �����ȣ�� �Է� �޴� �Լ�
	for (int i = 0; i < 1000; i++)stu[i].soohum = i + 1;
}

void GetName(struct Student stu[]) { // �л��� �̸��� 3~6���� ������ ���� �Է� �޴� �Լ�
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

void GetKor(struct Student stu[]) { // �л��� ���� ������ �Է� �޴� �Լ�, ������� ����� 55��
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

void GetEng(struct Student stu[]) { // �л��� ���� ������ �Է¹޴� �Լ�, ������� ����� 60��
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

void GetMath(struct Student stu[]) { // �л��� ���� ������ �Է¹޴� �Լ�, ���м����� ����� 60��
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

void GetSum(struct Student stu[]) { // �л��� ����,����,���� �������� ���������� �Է� �޴� �Լ�

	for (int i = 0; i < 1000; i++) {
		stu[i].sum = 0;
	}
	for (int i = 0; i < 1000; i++) {
		stu[i].sum = stu[i].kor + stu[i].eng + stu[i].math;
	}

}