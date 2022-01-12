#include<stdio.h>
#include<malloc.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
void print_preorder(struct node *root);
void print_inorder(struct node *root);
void print_postorder(struct node *root);
struct node* createNode(int data);
int find_height(struct node* root);
void print_tree_form(struct node *root, int space);
void main() {
    struct node *root= createNode(15);  // create root node

    // children to root node
    root->left= createNode(8);
    root->right= createNode(10);

    // grendchildren of root node
    root->left->left= createNode(13);
    root->left->right= createNode(14);
    root->right->left= createNode(16);
    root->right->right= createNode(17);
	
	root->left->left->left=createNode(33);
	
	int height;
    height=find_height(root);
    printf("Height of Tree: %d\n",height);
    printf("\nPRE-ORDER: \n");
    print_preorder(root);

    printf("\n\nIN-ORDER: \n");
    print_inorder(root);

    printf("\n\nPOST-ORDER: \n");
    print_postorder(root);
    
    printf("\n\n\nTree:\n");
    print_tree_form(root,10);
    
   
}



void print_preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        print_preorder(root->left);
        print_preorder(root->right);
    }
    else
        return;
}

void print_inorder(struct node *root) {
    if(root != NULL)
    {
        print_inorder(root->left);
        printf("%d ", root->data);
        print_inorder(root->right);
    }
    else
    return;
}

void print_postorder(struct node *root) {
    if(root != NULL)
    {
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%d ",root->data);
    }
    else
    return;
}
struct node* createNode(int data) {
    // this function will return the pointer for the new node
    struct node *newNode= (struct node *)malloc(sizeof(struct node));
    newNode->data= data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int find_height(struct node* root)
{
    if (root == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = find_height(root->left);
        int rDepth = find_height(root->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
void print_tree_form(struct node *root, int space)
{
	int i=10;
    if (root == NULL)
        return;
    space += 10;
    print_tree_form(root->right, space);
    printf("\n");
    for(i ; i<space; i++)
	{
		printf(" ");
	}
    printf("%d\n", root->data);
    print_tree_form(root->left, space);
}
