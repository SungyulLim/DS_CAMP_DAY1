#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data; // 들어오는 데이터
    struct Node* prev; // 왼쪽으로 이동
    struct Node* next; // 오른쪽으로 이동
};

struct Node* insertNode(struct Node* cursor, char c) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = c;
    
    newNode->prev = cursor; // 왼쪽 연결         
    newNode->next = cursor->next; // 오른쪽 연결
    
    if (cursor->next != NULL) {
        (cursor->next)->prev = newNode; // newNode의 오른쪽에 들어가는 부분이 가리키는 왼쪽을 연결
    }
    
    cursor->next = newNode; // 커서의 오른쪽을 연결

    return newNode;
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = NULL;
    head->prev = NULL;
    head->next = NULL;
    
    struct Node* cursor = head; // 커서를 생성

    //초기 문자 입력;
    char s[100005];
    scanf("%s", s);
    
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        cursor = insertNode(cursor,s[i]);
    }

    // 문자열의 길이를 입력;
    int num = 0;
    scanf("%d", &num);
    
    char cmd; // 입력받을 명령어
    for (int i = 0; i < num; i++) { 
        scanf(" %c", &cmd);

        if (cmd == 'L') {
            // 커서 왼쪽 이동
            if (cursor->prev != NULL) {
                 cursor = cursor->prev;
            }
        } 

        else if (cmd == 'D') {
            // 커서 오른쪽 이동
            if (cursor->next != NULL) {
                cursor = cursor->next;
            }
        }
         
        else if (cmd == 'B') {
            if (cursor->prev != NULL) {
                struct Node* target = cursor; // 삭제할 부분;

                cursor = target->prev; //커서를 왼쪽 부분으로 이동 ->
                cursor->next = target->next; // ->연결
                
                if (target->next != NULL) { //타켓이 마지막이 아니라면;
                    (target->next)->prev = cursor; // <-연결
                }

                free(target);
            }
        }

        else if (cmd == 'P') {
            char c;
            scanf(" %c", &c);

            cursor = insertNode(cursor, c);
        }
    }

    struct Node* curr = head->next;
    while (curr != NULL) {
        printf("%c", curr->data);
        curr = curr->next;
    }
    printf("\n");

    return 0;
}