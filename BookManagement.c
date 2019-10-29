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

struct Book { // 책이 가진 정보의 집합인 구조체
	int number;
	char b_name[100];
	char writer[100];
	int year;
};


void InsertBook(struct Book book[]); // 책의 정보를 입력 받는 함수
void PrintB(const struct Book book[]); // 책의 정보를 출력 하는 함수
void Sorting_W(struct Book book[], struct Book temp[]); // 서고에 있는 책들을 작가이름순으로 정렬 하는 함수
void Sorting_N(struct Book book[], struct Book temp[]);// 서고에 있는 책들을 책번호순으로 정렬 하는 함수
void Find(struct Book book[], char findname[]); // 사용자가 입력 한 단어나 문장을 제목에 포함하고 있는 책을 찾아서 출력하는 함수

int index = -1; // 서고에 책이 한 권도 들어 있지 않은 상태를 표현하기 위해 인덱스를 전역변수 선언 및 -1로 초기화

int main() {
	struct Book book[100]; struct Book temp[100];
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
		if (pick == 1) InsertBook(book); // 사용자가 1번을 입력하면 책을 입력하는 함수 호출
		else if (pick == 2) {// 책을 출력할 때 책 번호순으로 출력 할 지, 저자이름의 사전순으로 출력 할 지 선택 후 출력
			printf("번호순으로 출력하고 싶으면 1번 \n");
			printf("저자순으로 출력하고 싶으면 2번 \n");
			printf("번호를 입력해주세요 : ");
			scanf("%d", &num);
			printf("\n");
			if (num == 1) {
				Sorting_N(book, temp); // 책 번호 순으로 정렬
				PrintB(temp); // 책의 정보를 출력
			}
			else if (num == 2) {
				Sorting_W(book, temp); // 저자이름 기준 사전순으로 정렬한다
				PrintB(temp); // 책의 정보를 출력
			}
		}
		else if (pick == 3) {
			printf("찾고자 하는 책의 제목이나 포함된 단어를 입력해주세요 : ");
			printf("\n");
			gets(findname); // 사용자로부터 찾고자 하는 책 제목에 포함된 단어 및 문장 입력
			gets(findname); // 남아있는 버퍼를 지우기 위해 gets함수를 한번 더 사용
			Find(book, findname); // 책을 찾는 함수 호출
		}
		else {
			printf("프로그램 종료\n");
			return 0;
		}
	}


	return 0;
}


void InsertBook(struct Book book[]) {
	int insert;
	while (1) {
		printf("책 입력은 1번\n");
		printf("책을 입력하지 않으려면 -1번 입력\n\n");
		printf("번호를 입력 해주세요 : ");
		scanf("%d", &insert);
		printf("\n");
		if (index > 19) { // 서고는 최대 20권을 보관 할 수 있게 설정(사실 더 가능)
			printf("서고가 꽉 차서 책을 더 이상 등록 할 수 없습니다.\n");
			return;
		}
		if (insert == -1)break;
		else if (insert == 1) {
			index++; // 책을 입력 받게 되었으면 index를 1씩 증가
			book[index].number = index + 1; // 책 번호는 가리키고 있는 인덱스보다 1큰 수를 저장
			printf("등록할 책 제목 입력 : ");
			gets(book[index].b_name); // 책 제목 입력
			gets(book[index].b_name); // 남아있는 버퍼 제거
			printf("\n");
			printf("책의 저자 입력 : ");
			gets(book[index].writer); // 저자 입력
			printf("\n");
			printf("출판 연도 입력 : ");
			scanf("%d", &book[index].year); // 책의 출판 연도 입력
			printf("\n");
		}
	}
}

void PrintB(struct Book book[]) { // 책의 정보를 출력
	if (index == -1) { // 초기 상태
		printf("등록된 책이 없습니다. 책을 등록해주세요!!\n");
		return;
	}
	for (int i = 0; i <= index; i++) {
		printf("책 번호 : %d\n", book[i].number);
		printf("책 제목 : %s\n", book[i].b_name);
		printf("책 저자 : %s\n", book[i].writer);
		printf("출판 연도 : %d\n\n", book[i].year);
	}
}

void Sorting_W(struct Book book[], struct Book temp[]) { // 서고에 있는 책들을 저자이름 기준 사전순으로 정렬
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

void Sorting_N(struct Book book[], struct Book temp[]) { // 서고에 있는 책들을 책 번호순으로 정렬
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

void Find(struct Book book[], char findname[]) { // 사용자가 입력 한 단어나 문장을 포함하고 있는, 제목 책을 찾는 함수
	int fin = -1;
	if (index == -1) { // 초기 상태
		printf("등록된 책이 존재 하지 않으므로 검색 불가!!\n");
		return;
	}
	for (int i = 0; i <= index; i++) { // 서고 내에 있는 모든 책들을 찾아본다
		if (strstr(book[i].b_name, findname)) { // strstr함수를 사용해서 사용자가 입력 한 단어 및 문장과 책의 제목을 비교
			printf("책 번호 : %d\n", book[i].number);
			printf("책 제목 : %s\n", book[i].b_name);
			printf("책 저자 : %s\n", book[i].writer);
			printf("출판 연도 : %d\n\n", book[i].year);
			fin++;
		}
	}
	if (fin == -1 && index != -1) { // 초기상태가아닌 즉, 서고에 책이 있는 상태 이지만 사용자가 입력 한 단어나 문장을 포함한 제목의 책을 찾지 못한 경우
		printf("일치하는 책이 존재하지 않습니다.\n");
		return;
	}

}