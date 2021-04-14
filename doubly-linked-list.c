/*
 *  doubly-linked-list.c
 *	작성자 : 박도영
 *  작성일자 : 2021/04/14
 *  Doubly Linked List
 *
 *  Data Structures
 *  Department of Computer Science
 *  at Chungbuk National University
 *
 */



#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
 /* 필요한 헤더파일 추가 if necessary */


typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;



typedef struct Head {
	struct Node* first;
}headNode;

/* 함수 리스트 */

/* note: initialize는 이중포인터를 매개변수로 받음
		 singly-linked-list의 initialize와 차이점을 이해 할것 */
int initialize(headNode** h); /*반환할 때 주소를 반환하지 않는다. singly-linked-list의 initialize 함수에서 만약 h= (headNode*)malloc(sizeof(headNode));
하게 된다면 함수를 빠져나올때 힙영역에 할당은 되었는데 h가 함수의 종료와 함께 소멸됨으로써 main함수에 있던 headnode가 동적할당 된 곳을 가리키지도 않게되고,
동적 할당 된 것은 아무 기능도 하지 못한 채 있게 된다. 그걸 극복하기위해 여기선 더블포인터를 사용했다*/

/* note: freeList는 싱글포인터를 매개변수로 받음
		- initialize와 왜 다른지 이해 할것
		- 이중포인터를 매개변수로 받아도 해제할 수 있을 것 */
int freeList(headNode* h);

int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int insertFirst(headNode* h, int key);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);


int main()
{
	printf("2018038077 Do young park\n");
	char command;
	int key;
	headNode* headnode = NULL;

	do {
		printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'z': case 'Z':
			initialize(&headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}


int initialize(headNode** h) { //h는 headnode의 주소를 받는다
	//headnode 가 NULL이 아니면 freeList를 호출하여 할당해제
	if (*h != NULL)
		freeList(*h);

	// headNode에 대한 메모리를 할당하고 할당된 곳의 주소를 *h에 대입한다
	headNode *temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	*h = temp;
	
	return 1;
}

int freeList(headNode* h) {
	/* h와 연결된 listNode 메모리 해제
	 * headNode도 해제되어야 함.
	 */
	listNode* p = h->first; //포인터 p가 first가 가리키고있는 노드를 가리키게한다
	p->llink->rlink = NULL; //마지막에 할당 해제 할 때 last노드가 무의미한 곳을 가리키면 끝났는지 알 수없기 때문에 last노드의 rlink는 NULL을 가리키도록 한다

	listNode* prev = NULL;
	while (p != NULL) { //포인터 p가 NULL이 아니라면 (반복문을 빠져 나올때 first가 가리키고 있는 노드는 없는 상태)
		prev = p; // p가 가리키는 곳을 prev이 가리킨다
		p = p->rlink; //p는 다음 노드를 가리킨다
		free(prev); // prev이 가리키는 곳을 할당 해제 한다
	}
	free(h); //h가 가리키고 있는 힙 영역의 공간을 해제한다
	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if (h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while (p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->rlink;
		i++;
	}

	printf("  items = %d\n", i);
}




/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {

	return 0;
}



/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {


	return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {
	return 0;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {

	return 0;
}



/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {

	return 0;
}



/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {

	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {

	return 1;
}


