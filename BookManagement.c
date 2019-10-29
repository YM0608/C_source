//Book Management Program
/*
It is a book management program that accepts books in the library. 
It implements functions such as whether to enter a book into a library, 
print out the information of the books in the library, 
or navigate the book according to the number you enter. 
Repeat until the user wants to exit.
*/
/*
the main content
- To create a structure that has the information of a book (book number, book title, author name, publication year) as a member.
- The function of entering, printing, searching, and ending a book is based on the number that the user enters.
- Some of the input functions include asking if you want to enter more books or stop them immediately after you have entered the book.
- To print out the information in a book, ask if you want to print it in the order of the number of the book or the name of the author of the book, and print it as you like.
- In the search function, the user finds and outputs all of the books that contain a word or sentence that they enter in the title.
*/

#include <stdio.h>
#include <string.h>

struct Book { // å�� ���� ������ ������ ����ü
	int number;
	char b_name[100];
	char writer[100];
	int year;
};


void InsertBook(struct Book book[]); // å�� ������ �Է� �޴� �Լ�
void PrintB(const struct Book book[]); // å�� ������ ��� �ϴ� �Լ�
void Sorting_W(struct Book book[], struct Book temp[]); // ���� �ִ� å���� �۰��̸������� ���� �ϴ� �Լ�
void Sorting_N(struct Book book[], struct Book temp[]);// ���� �ִ� å���� å��ȣ������ ���� �ϴ� �Լ�
void Find(struct Book book[], char findname[]); // ����ڰ� �Է� �� �ܾ ������ ���� �����ϰ� �ִ� å�� ã�Ƽ� ����ϴ� �Լ�

int index = -1; // ���� å�� �� �ǵ� ��� ���� ���� ���¸� ǥ���ϱ� ���� �ε����� �������� ���� �� -1�� �ʱ�ȭ

int main() {
	struct Book book[100]; struct Book temp[100];
	int pick; int num;
	char findname[50];
	while (1) {
		printf("å �Է� : 1�� \n");
		printf("å ��� : 2�� \n");
		printf("å �˻� : 3�� \n");
		printf("���� : 4�� \n");
		printf("��ȣ�� �Է����ּ��� : ");
		scanf("%d", &pick);
		printf("\n");
		if (pick == 1) InsertBook(book); // ����ڰ� 1���� �Է��ϸ� å�� �Է��ϴ� �Լ� ȣ��
		else if (pick == 2) {// å�� ����� �� å ��ȣ������ ��� �� ��, �����̸��� ���������� ��� �� �� ���� �� ���
			printf("��ȣ������ ����ϰ� ������ 1�� \n");
			printf("���ڼ����� ����ϰ� ������ 2�� \n");
			printf("��ȣ�� �Է����ּ��� : ");
			scanf("%d", &num);
			printf("\n");
			if (num == 1) {
				Sorting_N(book, temp); // å ��ȣ ������ ����
				PrintB(temp); // å�� ������ ���
			}
			else if (num == 2) {
				Sorting_W(book, temp); // �����̸� ���� ���������� �����Ѵ�
				PrintB(temp); // å�� ������ ���
			}
		}
		else if (pick == 3) {
			printf("ã���� �ϴ� å�� �����̳� ���Ե� �ܾ �Է����ּ��� : ");
			printf("\n");
			gets(findname); // ����ڷκ��� ã���� �ϴ� å ���� ���Ե� �ܾ� �� ���� �Է�
			gets(findname); // �����ִ� ���۸� ����� ���� gets�Լ��� �ѹ� �� ���
			Find(book, findname); // å�� ã�� �Լ� ȣ��
		}
		else {
			printf("���α׷� ����\n");
			return 0;
		}
	}


	return 0;
}


void InsertBook(struct Book book[]) {
	int insert;
	while (1) {
		printf("å �Է��� 1��\n");
		printf("å�� �Է����� �������� -1�� �Է�\n\n");
		printf("��ȣ�� �Է� ���ּ��� : ");
		scanf("%d", &insert);
		printf("\n");
		if (index > 19) { // ����� �ִ� 20���� ���� �� �� �ְ� ����(��� �� ����)
			printf("���� �� ���� å�� �� �̻� ��� �� �� �����ϴ�.\n");
			return;
		}
		if (insert == -1)break;
		else if (insert == 1) {
			index++; // å�� �Է� �ް� �Ǿ����� index�� 1�� ����
			book[index].number = index + 1; // å ��ȣ�� ����Ű�� �ִ� �ε������� 1ū ���� ����
			printf("����� å ���� �Է� : ");
			gets(book[index].b_name); // å ���� �Է�
			gets(book[index].b_name); // �����ִ� ���� ����
			printf("\n");
			printf("å�� ���� �Է� : ");
			gets(book[index].writer); // ���� �Է�
			printf("\n");
			printf("���� ���� �Է� : ");
			scanf("%d", &book[index].year); // å�� ���� ���� �Է�
			printf("\n");
		}
	}
}

void PrintB(struct Book book[]) { // å�� ������ ���
	if (index == -1) { // �ʱ� ����
		printf("��ϵ� å�� �����ϴ�. å�� ������ּ���!!\n");
		return;
	}
	for (int i = 0; i <= index; i++) {
		printf("å ��ȣ : %d\n", book[i].number);
		printf("å ���� : %s\n", book[i].b_name);
		printf("å ���� : %s\n", book[i].writer);
		printf("���� ���� : %d\n\n", book[i].year);
	}
}

void Sorting_W(struct Book book[], struct Book temp[]) { // ���� �ִ� å���� �����̸� ���� ���������� ����
	int least; int tmp; char tempn[100];
	for (int i = 0; i <= index; i++) {
		temp[i].number = book[i].number;
		temp[i].year = book[i].year;
		for (int w = 0; w < 100; w++) {
			temp[i].b_name[w] = book[i].b_name[w];
			temp[i].writer[w] = book[i].writer[w];
		}
	}
	for (int i = 0; i < index; i++) {
		least = i;
		for (int j = i + 1; j <= index; j++) {
			if (strcmp(temp[j].writer, temp[least].writer) < 0) { least = j; }
			tmp = temp[i].number;
			temp[i].number = temp[least].number;
			temp[least].number = tmp;
			tmp = temp[i].year;
			temp[i].year = temp[least].year;
			temp[least].year = tmp;
			for (int w = 0; w < 100; w++) {
				tempn[w] = temp[i].writer[w];
				temp[i].writer[w] = temp[least].writer[w];
				temp[least].writer[w] = tempn[w];
				tempn[w] = temp[i].b_name[w];
				temp[i].b_name[w] = temp[least].b_name[w];
				temp[least].b_name[w] = tempn[w];
			}
		}
	}
}

void Sorting_N(struct Book book[], struct Book temp[]) { // ���� �ִ� å���� å ��ȣ������ ����
	int least; int tmp; char tempn[100];
	for (int i = 0; i <= index; i++) {
		temp[i].number = book[i].number;
		temp[i].year = book[i].year;
		for (int w = 0; w < 100; w++) {
			temp[i].b_name[w] = book[i].b_name[w];
			temp[i].writer[w] = book[i].writer[w];
		}
	}
	for (int i = 0; i < index; i++) {
		least = i;
		for (int j = i + 1; j <= index; j++) {
			if (temp[j].number < temp[least].number) { least = j; }
			tmp = temp[i].number;
			temp[i].number = temp[least].number;
			temp[least].number = tmp;
			tmp = temp[i].year;
			temp[i].year = temp[least].year;
			temp[least].year = tmp;
			for (int w = 0; w < 100; w++) {
				tempn[w] = temp[i].writer[w];
				temp[i].writer[w] = temp[least].writer[w];
				temp[least].writer[w] = tempn[w];
				tempn[w] = temp[i].b_name[w];
				temp[i].b_name[w] = temp[least].b_name[w];
				temp[least].b_name[w] = tempn[w];
			}
		}
	}
}

void Find(struct Book book[], char findname[]) { // ����ڰ� �Է� �� �ܾ ������ �����ϰ� �ִ�, ���� å�� ã�� �Լ�
	int fin = -1;
	if (index == -1) { // �ʱ� ����
		printf("��ϵ� å�� ���� ���� �����Ƿ� �˻� �Ұ�!!\n");
		return;
	}
	for (int i = 0; i <= index; i++) { // ���� ���� �ִ� ��� å���� ã�ƺ���
		if (strstr(book[i].b_name, findname)) { // strstr�Լ��� ����ؼ� ����ڰ� �Է� �� �ܾ� �� ����� å�� ������ ��
			printf("å ��ȣ : %d\n", book[i].number);
			printf("å ���� : %s\n", book[i].b_name);
			printf("å ���� : %s\n", book[i].writer);
			printf("���� ���� : %d\n\n", book[i].year);
			fin++;
		}
	}
	if (fin == -1 && index != -1) { // �ʱ���°��ƴ� ��, ���� å�� �ִ� ���� ������ ����ڰ� �Է� �� �ܾ ������ ������ ������ å�� ã�� ���� ���
		printf("��ġ�ϴ� å�� �������� �ʽ��ϴ�.\n");
		return;
	}

}