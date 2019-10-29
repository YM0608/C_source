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

typedef struct node { // 책의 정보의 집합인 자기참조구조체
	char b_name[100];
	char writer[100];
	int year;
	struct node* link;
}Book;


int index = -1; // 책을 서고에 한 권도 입력 받지 않은, 초기 상태를 의미하는 인덱스

int main() {
	Book* current = NULL;
	Book* head = NULL;
	Book* tail = NULL;
	Book* temp; Book* temp2;
	int pick; int num;
	char findname[50];
	while (1) {
		printf("책 입력 : 1번 \n");
		printf("책 출력 : 2번 \n");
		printf("책 검색 : 3번 \n");
		printf("종료 : 4번 \n");
		printf("번호를 입력해주세요 : ");
		scanf("%d", &pick);
		printf("\n");
		if (pick == 1) { // 사용자로부터 1을 입력 받으면 책을 입력
			printf("책을 앞에 이어붙이고 싶으시면 1번 \n");
			printf("책을 뒤에 이어붙이고 싶으시면 2번 \n");
			printf("번호를 입력해주세요 : ");
			scanf("%d", &num);
			if (num == 1) { // 책을 앞에서부터 이어 붙이기로 함

				if (head == NULL) { // head가 NULL값이라는 것은 아직 한권도 입력 받지 않았다는 의미
					index++; // index 1만큼 증가
					current = (Book*)malloc(sizeof(Book)); // current에 동적 할당
					current->link = NULL; // 링크는 아무것도 가리키지 않는 상태
					printf("등록할 책 제목 입력 : ");
					gets(current->b_name); // 책 제목 입력
					gets(current->b_name); // 남아 있는 버퍼 제거
					printf("\n");
					printf("책의 저자 입력 : ");
					gets(current->writer); // 책의 저자 이름 입력
					printf("\n");
					printf("출판 연도 입력 : ");
					scanf("%d", &(current->year)); // 책의 출판 연도 입력
					printf("\n");
					head = tail = current; // 책이 처음 입력 받은 상태이므로 head와 tail전부 동적할당하여 입력받은 current를 가리킨다
				}
				else if (head != NULL) { // head가 NULL이 아니라는 것은 이미 입력 받은 책이 있을 경우
					index++; // index증가
					current = (Book*)malloc(sizeof(Book)); // current에 동적 할당
					current->link = NULL;// 링크는 아무것도 가리키지 않는 상태
					printf("등록할 책 제목 입력 : ");
					gets(current->b_name);
					gets(current->b_name);
					printf("\n");
					printf("책의 저자 입력 : ");
					gets(current->writer);
					printf("\n");
					printf("출판 연도 입력 : ");
					scanf("%d", &(current->year));
					printf("\n");
					/*책을 앞에 이어붙여야 하므로 현재 동적 할당 받은 current 노드를 가장 앞을 가리키고 있는 head로 초기화해주고
					이전 head 즉, 이제는 두번째 책이 되어버린 노드를 새롭게 정의된 head노드의 링크가 가리키게 해서 두 개의 노드를 잇는다.
					*/
					temp = head; // 두번째 노드가 되어버릴 head노드를 임시 temp가 가리키게 하고
					head = current; // 새롭게 동적할당 받은 노드를 head로 초기화 해준다
					head->link = temp;// 그리고나서 head의 링크가 두번째 노드와 잇는다
				}
			}
			else if (num == 2) { // 책을 뒤에서부터 이어 붙이기로 함
				if (head == NULL) { // 링크는 아무것도 가리키지 않는 상태
					index++; // index 1만큼 증가
					current = (Book*)malloc(sizeof(Book)); // current에 동적 할당
					current->link = NULL; // 링크는 아무것도 가리키지 않는 상태
					printf("등록할 책 제목 입력 : ");
					gets(current->b_name);
					gets(current->b_name);
					printf("\n");
					printf("책의 저자 입력 : ");
					gets(current->writer);
					printf("\n");
					printf("출판 연도 입력 : ");
					scanf("%d", &(current->year));
					printf("\n");
					head = tail = current; // 책이 처음 입력 받은 상태이므로 head와 tail전부 동적할당하여 입력받은 current를 가리킨다
				}
				else if (head != NULL) { // head가 NULL이 아니라는 것은 이미 입력 받은 책이 있을 경우
					index++; // index증가
					current = (Book*)malloc(sizeof(Book)); // current에 동적 할당
					current->link = NULL; // 링크는 아무것도 가리키지 않는 상태
					printf("등록할 책 제목 입력 : ");
					gets(current->b_name);
					gets(current->b_name);
					printf("\n");
					printf("책의 저자 입력 : ");
					gets(current->writer);
					printf("\n");
					printf("출판 연도 입력 : ");
					scanf("%d", &(current->year));
					printf("\n");
					/*
					꼬리에 이어 붙여야 하므로 새롭게 동적 할당 받은 노드를 tail로 초기화하고, 이전의 tail노드 즉, 끝에서 두번째 노드의 링크로
					새로운 tail노드에 이어붙인다.
					*/
					temp = tail; // 끝에서 두번째 노드가 되어버릴 tail노드를 임시 temp가 가리키게 해놓고
					tail = current; // 새롭게 동적할당 받은 노드를 tail로 초기화
					temp->link = tail; // 끝에서 두번째 노드의 링크로 가장 끝 노드인 tail을 잇는다
				}
			}
		}
		else if (pick == 2) {
			if (index == -1)printf("등록된 책이 없습니다!!\n\n"); // 초기 상태
			else if (index != -1) { // 등록된 책이 있을 경우, 서고에 있는 책들의 정보를 출력
				temp = head; // 첫번째 노드부터 시작
				for (int i = 0; i <= index; i++) {
					printf("책 번호 : %d\n", i + 1);
					printf("책 제목 : %s\n", temp->b_name);
					printf("책 저자 : %s\n", temp->writer);
					printf("출판 연도 : %d\n\n", temp->year);
					temp = temp->link; // 해당 노드의 링크로 이어진 다음 노드로 이동
				}
			}
		}
		else if (pick == 3) {
			int fin = -1;
			if (index == -1) { // 초기 상태
				printf("등록된 책이 존재 하지 않으므로 검색 불가!!\n\n");
			}
			else if (index != -1) {
				printf("찾고자 하는 책의 제목이나 단어를 입력해주세요 : ");
				gets(findname); // 찾고자 하는 책의 제목이 갖고 있는 단어나 문장을 입력
				gets(findname);
				temp2 = head; // 첫번째 노드부터 시작
				for (int i = 0; i <= index; i++) {
					if (strstr(temp2->b_name, findname)) {
						printf("책 번호 : %d\n", i + 1);
						printf("책 제목 : %s\n", temp2->b_name);
						printf("책 저자 : %s\n", temp2->writer);
						printf("출판 연도 : %d\n\n", temp2->year);
						fin++;
					}
					temp2 = temp2->link; // 해당 노드의 링크로 이어진 다음 노드로 이동
				}
				if (fin == -1 && index != -1) { // 책을 입력 받은 상태이지만, 사용자가 입력한 단어나 문장과 일치 하는 제목을 가진 책을 찾지 못한 경우
					printf("일치하는 책이 존재하지 않습니다.\n");
				}
			}
		}
		else {
			printf("프로그램 종료\n");
			return 0;
		}
	}


	return 0;
}
