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

// [전위 순회: Root -> L -> R]
void preorder(TreeNode* root);

// [중위 순회: L -> Root -> R]
void inorder(TreeNode* root);

// [후위 순회: L -> R -> Root]
void postorder(TreeNode* root);

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