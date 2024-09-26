#define MAX 100
#include <stdio.h>
#include <stdlib.h>

int index = 0;
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
    return node;
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
    list[index++] = val;
    printf("Now entering value for left child of current node %d\n",node->value);
    node->left_ptr = create_recursively();
    printf("Now entering value for right child of current node %d\n",node->value);
    node->right_ptr = create_recursively();
    return node;
}



void traverse1(struct node* node){
    if(!node) return;
    printf("%d ",node->value);
    traverse1(node->left_ptr);
    traverse1(node->right_ptr);
    /*
    after running it this would be preorder traversal
    */
}


void traverse2(struct node* node){
    if(!node) return;
    traverse2(node->left_ptr);
    printf("%d ",node->value);
    traverse2(node->right_ptr);
    /*
    after running it this would be inorder traversal
    */
}


void traverse3(struct node* node){
    if(!node) return;
    traverse3(node->left_ptr);
    traverse3(node->right_ptr);
    printf("%d ",node->value);

    /*
    after running it this would be postorder traversal
    */
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

    // printf("The root value is %d\n",root->value);
    // printf("The root_lc value is %d\n",root->left_ptr->value);
    // printf("The root_rc value is %d\n",root->right_ptr->value);

    /////////////////////////////////////////////////////////////////////////////////////////

    struct node* root_r = create_recursively();
    printf("There are a total of %d nodes in the tree.\n",index);

    // for(int i = 0 ; i < index; i++){
    //     printf("%d ",list[i]);
    // }
    // printf("\n");

    // traverse(root);

    traverse1(root_r);printf("\n");
    traverse2(root_r);printf("\n");
    traverse3(root_r);printf("\n");


    return 0;
}