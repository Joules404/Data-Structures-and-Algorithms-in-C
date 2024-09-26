#define MAX 100
#include <stdio.h>
#include <stdlib.h>

int counter = 0;
int list[MAX];



struct node{
    int value;
    struct node* left_ptr;
    struct node* right_ptr;
};


struct node* create(int val){
    struct node* node;
    node = (struct node*) malloc(sizeof(struct node));
    node->value =val;
    node->left_ptr = NULL;
    node->right_ptr = NULL;
}

struct node* create_recursively(){
    // counter++;
    struct node* node;
    node = (struct node*) malloc(sizeof(struct node));
    if(!node) {
        printf("Failed to allocate mem.\n");
        return NULL;
    }
    node->left_ptr = NULL;
    node->right_ptr = NULL;
    int val;
    printf("Enter value(-1 for no node): ");
    scanf("%d",&val);
    if(val == -1) return NULL;
    else printf("Node will contain value: %d\n",val);
    node->value = val;
    counter++;
    printf("Now entering value for left child of current node %d\n",node->value);
    node->left_ptr = create_recursively();
    printf("Now entering value for right child of current node %d\n",node->value);
    node->right_ptr = create_recursively();
    return node;
}



void traverse(struct node* node){
    if(!node) return;
    printf("%d ",node->value);
    traverse(node->left_ptr);
    traverse(node->right_ptr);
    // printf("")
}

int main(int argc, char** argv){
    struct node* root;
    root = create(5);

    struct node* root_lc = create(3);
    struct node* root_rc = create(6);

    struct node* root_lc_lc = create(1);
    struct node* root_lc_rc = create(2);

    struct node* root_rc_lc = create(6);
    struct node* root_rc_rc = create(8);

    root->left_ptr = root_lc;
    root->right_ptr = root_rc;

    printf("The root value is %d\n",root->value);
    printf("The root_lc value is %d\n",root->left_ptr->value);
    printf("The root_rc value is %d\n",root->right_ptr->value);

    /////////////////////////////////////////////////////////////////////////////////////////

    struct node* root_r = create_recursively();
    printf("There are a total of %d nodes in the tree.\n",counter);

    for(int i = 0 ; i < counter; i++){
        printf("%d ",list[i]);
    }
    printf("\n");

    traverse(root);

    return 0;
}