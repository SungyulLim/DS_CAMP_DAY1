#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person{
    char name[50];
    int age;
    float height;

    struct Person* left;
    struct Person* right;
}Person;

Person* createNode(char name[], int age, float height){
    Person* newPerson = (Person*)malloc(sizeof(Person));
    strcpy(newPerson->name,name);
    newPerson->age = age;
    newPerson->height = height;

    newPerson->left = NULL;
    newPerson->right = NULL;    

    return newPerson;
}

int main(void){

    Person *root = createNode("Jian",25,175.5);
    Person *lChild = createNode("John",30,160.5);
    Person *rChild = createNode("Alice",28,150);

    root->left = lChild;
    root->right = rChild;

    
    return 0;
}