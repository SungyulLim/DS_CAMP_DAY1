#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char name[100];         
    int priority;           
    struct TreeNode* left;  
    struct TreeNode* right; 
} TreeNode;

// [1] 노드 생성 함수
TreeNode* createNode(char* name, int priority) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newNode->name, name);
    newNode->priority = priority; 
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// [2] 노드 삽입 함수
TreeNode* insertTask(TreeNode* root, TreeNode* newNode) {
    if (root == NULL) {
        return newNode;
    }

    if (newNode->priority < root->priority) {
        root->left = insertTask(root->left, newNode);
    } 
    else if (newNode->priority > root->priority) {
        root->right = insertTask(root->right, newNode);
    }
    
    return root;
}

// [중복 확인] 우선순위 검색 함수
TreeNode* searchNode(TreeNode* root, int key) {
    if (root == NULL) return NULL; 

    if (root->priority == key) {
        return root; 
    }

    if (key < root->priority) {
        return searchNode(root->left, key);
    } else {
        return searchNode(root->right, key);
    }
}

// [보조] 최솟값 찾기
TreeNode* findMinNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// [3] 노드 삭제 함수
TreeNode* deleteTask(TreeNode* root, int key) {
    if (root == NULL) return root;

    if (key < root->priority) {
        root->left = deleteTask(root->left, key);
    }
    else if (key > root->priority) {
        root->right = deleteTask(root->right, key);
    }
    else { 
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = findMinNode(root->right); 
        root->priority = temp->priority;
        strcpy(root->name, temp->name);
        root->right = deleteTask(root->right, temp->priority);
    }
    return root;
}

// [4] 전체 출력 (화면 예시: " [중요도 1] 집가기")
void printInOrder(TreeNode* root) {
    if (root != NULL) {
        printInOrder(root->left);
        // 출력 포맷을 요청하신 예시에 맞춤
        printf(" [중요도 %d] %s\n", root->priority, root->name);
        printInOrder(root->right);
    }
}

// [UI] 메뉴 출력 함수
void printMenu() {
    printf("\n------------------------------------------------------------\n");
    printf("[ ToDoList ] (1:추가 | 2:삭제 | 3:목록보기 | 0:종료) \n");
    printf("------------------------------------------------------------\n");
    printf(" > 메뉴를 선택하세요 > ");
}

int main() {
    TreeNode* root = NULL;
    int menu = 0;
    
    while (1) {
        printMenu();
        scanf("%d", &menu);

        if (menu == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        char name[100];
        int priority;

        switch (menu) {
            case 1: // 추가
                printf("할 일을 입력하세요: ");
                scanf("%s", name); 
                
                // 요청하신 긴 문구 적용
                printf("우선순위를 입력하세요(숫자가 작을 수록 중요한 일정입니다!): ");
                scanf("%d", &priority);
                
                if (searchNode(root, priority) != NULL) {
                    printf(">> 이미 존재하는 우선순위입니다. 다시 입력해주세요.\n");
                } 
                else {
                    root = insertTask(root, createNode(name, priority)); 
                    printf(">> 등록되었습니다.\n");
                }
                break;

            case 2: // 삭제
                printf("삭제할 우선순위를 입력하세요: ");
                scanf("%d", &priority);
                
                if (searchNode(root, priority) == NULL) {
                     printf(">> 해당 우선순위의 할 일이 없습니다.\n");
                } else {
                    root = deleteTask(root, priority);
                    // 요청하신 문구 적용
                    printf(">> 삭제되었습니다.\n");
                }
                break;

            case 3: // 목록 보기
                printf("\n--- 할 일 목록 (우선순위 순) ---\n");
                if (root == NULL) {
                    // 목록이 비었을 때 아무것도 안 찍히거나 메시지를 띄움
                    // 예시에는 없지만 비어있을 경우를 위해 남겨둠 (출력은 안 됨)
                }
                else {
                    printInOrder(root);
                }
                break;

            default: 
                printf("잘못된 메뉴입니다.\n");
        }
    }
    return 0;
}