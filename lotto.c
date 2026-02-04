#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insertLotto(TreeNode* root, int key){
    if(root == NULL) return createNode(key);
    
    if(key == root->data){
        printf("%d는 이미 존재하는 값입니다.\n", key);
        return root;
    }

    if(key < root->data){
        root->left = insertLotto(root->left, key);
    }
    else{
        root->right = insertLotto(root->right, key);
    }
    
    return root;
}

void printSorted(TreeNode* root){
    if(root == NULL) return;
    printSorted(root->left);
    printf("%d", root->data);
    printSorted(root->right);
}

int main() {
    TreeNode* root = NULL;
    int input;

    printf("=== 로또 번호 자동 정렬기 (BST) ===\n");
    printf("1~45 사이의 숫자를 입력하세요.\n");
    printf("중복된 숫자는 걸러지며, -1을 입력하면 결과를 보여줍니다.\n\n");

    while (1) {
        printf("번호 입력: ");
        scanf("%d", &input);

        if (input == -1) break; // 종료 조건

        // 범위 체크 (선택 사항)
        if (input < 1 || input > 45) {
            printf(" -> [오류] 1~45 사이의 숫자만 가능합니다.\n");
            continue;
        }

        root = insertLotto(root, input);
    }

    printf("\n--------------------------\n");
    printf("최종 결과 (오름차순 정렬): ");
    printSorted(root);
    printf("\n--------------------------\n");

    return 0;
}