//Book Management System Using Linked_List
/*
It is a book management program that uses a linked list to enter books into the library.
It implements functions such as whether to enter a book into a library, 
print out the information of the books in the library, or navigate the book according to the number you enter. 
Repeat until the user wants to exit.
The user can decide whether to enter a book from the beginning to the next, followed by the next.
*/
/*
the main content
- to create a self-referencing structure that has information (book title, author name, publication year, link) as a member variable.
- The function of entering, printing, searching, and ending a book is based on the number that the user enters.
- Input function is implemented by deciding whether a book should be entered in front of the library or in the back of the library.
- output functionality, there is every book in the library of information output.
- and as part of the title of the sentences a word search function, users input and outputs for all the books.
*/
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct node { // å�� ������ ������ �ڱ���������ü
	char b_name[100];
	char writer[100];
	int year;
	struct node* link;
}Book;


int index = -1; // å�� ���� �� �ǵ� �Է� ���� ����, �ʱ� ���¸� �ǹ��ϴ� �ε���

int main() {
	Book* current = NULL;
	Book* head = NULL;
	Book* tail = NULL;
	Book* temp; Book* temp2;
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
		if (pick == 1) { // ����ڷκ��� 1�� �Է� ������ å�� �Է�
			printf("å�� �տ� �̾���̰� �����ø� 1�� \n");
			printf("å�� �ڿ� �̾���̰� �����ø� 2�� \n");
			printf("��ȣ�� �Է����ּ��� : ");
			scanf("%d", &num);
			if (num == 1) { // å�� �տ������� �̾� ���̱�� ��

				if (head == NULL) { // head�� NULL���̶�� ���� ���� �ѱǵ� �Է� ���� �ʾҴٴ� �ǹ�
					index++; // index 1��ŭ ����
					current = (Book*)malloc(sizeof(Book)); // current�� ���� �Ҵ�
					current->link = NULL; // ��ũ�� �ƹ��͵� ����Ű�� �ʴ� ����
					printf("����� å ���� �Է� : ");
					gets(current->b_name); // å ���� �Է�
					gets(current->b_name); // ���� �ִ� ���� ����
					printf("\n");
					printf("å�� ���� �Է� : ");
					gets(current->writer); // å�� ���� �̸� �Է�
					printf("\n");
					printf("���� ���� �Է� : ");
					scanf("%d", &(current->year)); // å�� ���� ���� �Է�
					printf("\n");
					head = tail = current; // å�� ó�� �Է� ���� �����̹Ƿ� head�� tail���� �����Ҵ��Ͽ� �Է¹��� current�� ����Ų��
				}
				else if (head != NULL) { // head�� NULL�� �ƴ϶�� ���� �̹� �Է� ���� å�� ���� ���
					index++; // index����
					current = (Book*)malloc(sizeof(Book)); // current�� ���� �Ҵ�
					current->link = NULL;// ��ũ�� �ƹ��͵� ����Ű�� �ʴ� ����
					printf("����� å ���� �Է� : ");
					gets(current->b_name);
					gets(current->b_name);
					printf("\n");
					printf("å�� ���� �Է� : ");
					gets(current->writer);
					printf("\n");
					printf("���� ���� �Է� : ");
					scanf("%d", &(current->year));
					printf("\n");
					/*å�� �տ� �̾�ٿ��� �ϹǷ� ���� ���� �Ҵ� ���� current ��带 ���� ���� ����Ű�� �ִ� head�� �ʱ�ȭ���ְ�
					���� head ��, ������ �ι�° å�� �Ǿ���� ��带 ���Ӱ� ���ǵ� head����� ��ũ�� ����Ű�� �ؼ� �� ���� ��带 �մ´�.
					*/
					temp = head; // �ι�° ��尡 �Ǿ���� head��带 �ӽ� temp�� ����Ű�� �ϰ�
					head = current; // ���Ӱ� �����Ҵ� ���� ��带 head�� �ʱ�ȭ ���ش�
					head->link = temp;// �׸����� head�� ��ũ�� �ι�° ���� �մ´�
				}
			}
			else if (num == 2) { // å�� �ڿ������� �̾� ���̱�� ��
				if (head == NULL) { // ��ũ�� �ƹ��͵� ����Ű�� �ʴ� ����
					index++; // index 1��ŭ ����
					current = (Book*)malloc(sizeof(Book)); // current�� ���� �Ҵ�
					current->link = NULL; // ��ũ�� �ƹ��͵� ����Ű�� �ʴ� ����
					printf("����� å ���� �Է� : ");
					gets(current->b_name);
					gets(current->b_name);
					printf("\n");
					printf("å�� ���� �Է� : ");
					gets(current->writer);
					printf("\n");
					printf("���� ���� �Է� : ");
					scanf("%d", &(current->year));
					printf("\n");
					head = tail = current; // å�� ó�� �Է� ���� �����̹Ƿ� head�� tail���� �����Ҵ��Ͽ� �Է¹��� current�� ����Ų��
				}
				else if (head != NULL) { // head�� NULL�� �ƴ϶�� ���� �̹� �Է� ���� å�� ���� ���
					index++; // index����
					current = (Book*)malloc(sizeof(Book)); // current�� ���� �Ҵ�
					current->link = NULL; // ��ũ�� �ƹ��͵� ����Ű�� �ʴ� ����
					printf("����� å ���� �Է� : ");
					gets(current->b_name);
					gets(current->b_name);
					printf("\n");
					printf("å�� ���� �Է� : ");
					gets(current->writer);
					printf("\n");
					printf("���� ���� �Է� : ");
					scanf("%d", &(current->year));
					printf("\n");
					/*
					������ �̾� �ٿ��� �ϹǷ� ���Ӱ� ���� �Ҵ� ���� ��带 tail�� �ʱ�ȭ�ϰ�, ������ tail��� ��, ������ �ι�° ����� ��ũ��
					���ο� tail��忡 �̾���δ�.
					*/
					temp = tail; // ������ �ι�° ��尡 �Ǿ���� tail��带 �ӽ� temp�� ����Ű�� �س���
					tail = current; // ���Ӱ� �����Ҵ� ���� ��带 tail�� �ʱ�ȭ
					temp->link = tail; // ������ �ι�° ����� ��ũ�� ���� �� ����� tail�� �մ´�
				}
			}
		}
		else if (pick == 2) {
			if (index == -1)printf("��ϵ� å�� �����ϴ�!!\n\n"); // �ʱ� ����
			else if (index != -1) { // ��ϵ� å�� ���� ���, ���� �ִ� å���� ������ ���
				temp = head; // ù��° ������ ����
				for (int i = 0; i <= index; i++) {
					printf("å ��ȣ : %d\n", i + 1);
					printf("å ���� : %s\n", temp->b_name);
					printf("å ���� : %s\n", temp->writer);
					printf("���� ���� : %d\n\n", temp->year);
					temp = temp->link; // �ش� ����� ��ũ�� �̾��� ���� ���� �̵�
				}
			}
		}
		else if (pick == 3) {
			int fin = -1;
			if (index == -1) { // �ʱ� ����
				printf("��ϵ� å�� ���� ���� �����Ƿ� �˻� �Ұ�!!\n\n");
			}
			else if (index != -1) {
				printf("ã���� �ϴ� å�� �����̳� �ܾ �Է����ּ��� : ");
				gets(findname); // ã���� �ϴ� å�� ������ ���� �ִ� �ܾ ������ �Է�
				gets(findname);
				temp2 = head; // ù��° ������ ����
				for (int i = 0; i <= index; i++) {
					if (strstr(temp2->b_name, findname)) {
						printf("å ��ȣ : %d\n", i + 1);
						printf("å ���� : %s\n", temp2->b_name);
						printf("å ���� : %s\n", temp2->writer);
						printf("���� ���� : %d\n\n", temp2->year);
						fin++;
					}
					temp2 = temp2->link; // �ش� ����� ��ũ�� �̾��� ���� ���� �̵�
				}
				if (fin == -1 && index != -1) { // å�� �Է� ���� ����������, ����ڰ� �Է��� �ܾ ����� ��ġ �ϴ� ������ ���� å�� ã�� ���� ���
					printf("��ġ�ϴ� å�� �������� �ʽ��ϴ�.\n");
				}
			}
		}
		else {
			printf("���α׷� ����\n");
			return 0;
		}
	}


	return 0;
}
