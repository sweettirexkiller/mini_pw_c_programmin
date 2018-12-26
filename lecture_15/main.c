// 
// Created by  Peter Yankievich on 25/12/2018.
//
#include<stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

typedef struct node nd;

nd *new_node(int item);

nd *insert(nd *node, int key);

void browse_inorder(nd *root);

void browse_preorder(nd *root);

void browse_postorder(nd *root);

void postorder_destroyer(nd *root);

int main() {
    nd *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    browse_preorder(root);
    printf("\n");

    browse_inorder(root);
    printf("\n");

    browse_postorder(root);
    printf("\n");

    postorder_destroyer(root);

    return 0;
}

nd *new_node(int item) {
    nd *tmp = (nd *) malloc(sizeof(nd));
    tmp->key = item;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

nd *insert(nd *node, int key) {
    if (node == NULL) return new_node(key);
    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if(key > node->key){
        node->left = insert(node->right, key);
    }
    return node;
}
//20,40,30,60,80,70,50
void browse_postorder(nd *root){
    if(root != NULL){
        browse_postorder(root->left);
        browse_postorder(root->right);
        printf("%d ", root->key);
    }
}
//20.30.40.50.60.70.80
void browse_inorder(nd *root){
    if(root != NULL){
        browse_inorder(root->left);
        printf("%d ", root->key);
        browse_inorder(root->right);
    }
}
//50,40,20,40,70,60,80
void browse_preorder(nd *root){
    if(root != NULL){
        printf("%d ", root->key);
        browse_preorder(root->left);
        browse_preorder(root->right);
    }
}

void postorder_destroyer(nd *root){
    if(root !=  NULL){
        postorder_destroyer(root->left);
        postorder_destroyer(root->right);
        free(root);
    }
}