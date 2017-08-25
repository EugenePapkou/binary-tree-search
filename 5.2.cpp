/* There're some numbers in the text file. Using a binary tree that program will display the numbers
from the text file sorted from the smallest to the largest.

task_02.06.2010 */

#include <stdio.h>
#include "stdafx.h"
#include <stdlib.h>
#include <allocators>

// Structure for a tree node
typedef struct item {
int data;
struct item *left;
struct item *right;
} Item;

typedef struct stack {
Item tree1;
Item *p;
} Stack;

void AddNode(int data, Item **node);
void LeftOrder(Item *node);
	
void main(void)
{
	char buffer[128];
	int i;
	Item *root = NULL; // root of tree
	FILE *fp = fopen("ex52.txt", "r");
	if (!fp) exit(1); // exit if the file opening is failed
	// reading values from the file
	while (fgets(buffer, 128, fp) != NULL)
	AddNode(atoi(buffer), &root); // adding nodes to the tree
	LeftOrder(root);
	fclose(fp);
	

	char c; // exit from the program
	puts ("\n\nEnter \"Y\" and press \"Enter\" for exit");
  	do
	    c = getchar();
	while (c != 'Y' && c != 'y');
}

void AddNode(int data, Item **node) // a functtion to add a node to the tree
{
	if (*node == NULL) 
	{
		*node = (Item *)calloc(1, sizeof(Item));
		(*node)->data = data;
		(*node)->left = (*node)->right = NULL;
	}
	else
	{
		if (data < (*node)->data)
			AddNode(data, &(*node)->left);
		else 
			if (data > (*node)->data)
				AddNode(data, &(*node)->right);
			//else
				//puts("There is such element in the tree");
	}
}

// Bypassing the tree on the left (in ascending order)
void LeftOrder(Item *node)
{
	if (node->left)
		LeftOrder(node->left);
	printf("%d ", node->data);
	if (node->right)
		LeftOrder(node->right);
}


