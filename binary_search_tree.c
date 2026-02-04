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

TreeNode* insertBST(TreeNode* root, int key){
    if(root == NULL) return createNode(key);

    if(key< root->data){
        root->left = insertBST(root->left,key);
    }
    else if(key > root->data){
        root->right = insertBST(root->right,key);
    }
}

TreeNode* searchBST(TreeNode* root, int key){
    if(root == NULL) return NULL;
    if(key == root->data) return root;

    if(key < root->data){
        return searchBST(root->left,key);
    }
    else{
        return searchBST(root->right,key);
    }
}

TreeNode* findMidNode(TreeNode* node){ // 최솟값 찾는 방법;
    TreeNode* current = node;
    //맨 왼쪽으로 내려가서 최솟값 갗기
    while(current&&current->left != NULL){
        current = current->left;
    }

    return current;
}

TreeNode* deleteBST(TreeNode* root, int key){
    if(root == NULL) return root;

    if(key < root->data){ // 삭제 하려는 값이 더 작은 경우
        root->left = deleteBST(root->left,key);
    }
    else if(key > root->data){ // 삭제 하려는 값이 더 큰 경우
        root->right = deleteBST(root->right,key);
    }
    else{ // 삭제하려는 값을 찾은 경우
        if(root->left == NULL){ // 왼쪽에 자식이 없는 경우
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right = NULL){ // 오른쪽에 자식이 없는 경우
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // 자식이 양쪽에 있는 경우
        TreeNode* temp = findMidNode(root->right);
        
        root->data = temp->data;
        root->right = deleteBST(root->right,temp->data);
    }
    return root;
}

// [전위 순회: Root -> L -> R]
void preorder(TreeNode* root){
    if(root == NULL) return;
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}

// [중위 순회: L -> Root -> R]
void inorder(TreeNode* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}

// [후위 순회: L -> R -> Root]
void postorder(TreeNode* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}

int main() {
    printf("=== Step 3: 전위, 중위, 후위 순회 ===\n\n");
    
    TreeNode* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(2);
    root->left->left = createNode(1);
    /*
    root->left->right = createNode(3);
    root->right->left = createNode(2);
    root->right->right = createNode(1);
    */

    printf("Pre-order (전위): ");
    preorder(root);
    printf("\n");

    printf("In-order  (중위): ");
    inorder(root);
    printf("\n");

    printf("Post-order(후위): ");
    postorder(root);
    printf("\n");

    return 0;
}

