#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node *left;
  struct node *right;
} Node;

typedef Node *Node_ptr;

typedef Node *Node_ptr;

typedef enum
{
  False,
  True
} Status;

Node_ptr create_node(int value)
{
  Node_ptr node = malloc(sizeof(Node));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node_ptr insert_node(Node_ptr tree, int value)
{
  if (tree == NULL)
  {
    return create_node(value);
  }

  Node_ptr p_walk = tree;
  Node_ptr root;
  while (p_walk != NULL)
  {
    root = p_walk;
    if (p_walk->value > value)
    {
      p_walk = p_walk->left;
    }
    else
    {
      p_walk = p_walk->right;
    }
  }

  if (root->value > value)
  {
    root->left = create_node(value);
    return tree;
  }
  root->right = create_node(value);
  return tree;
}

// Node_ptr insert_node(Node_ptr tree, int value) //recursion
// {
//   if (tree == NULL)
//   {
//     return create_node(value);
//   }
//   if (tree->value > value)
//   {
//     tree->left = insert_node(tree->left, value);
//     return tree;
//   }
//   tree->right = insert_node(tree->right, value);
//   return tree;
// }

Node_ptr create_tree(int *list, int length)
{
  Node_ptr tree;
  tree = insert_node(NULL, list[0]);
  for (int i = 1; i < length; i++)
  {
    insert_node(tree, list[i]);
  }
  return tree;
}

// void print_in_order(Node_ptr tree) //recursion
// {
//   if (tree == NULL)
//   {
//     return;
//   }
//   print_in_order(tree->left);
//   printf("%d", tree->value);
//   print_in_order(tree->right);
// }

void print_in_order(Node_ptr tree, int hight)
{
  Node_ptr *roots = malloc(sizeof(struct node*) * (hight - 1));
  Node_ptr p_walk = tree;
  int index = 0;

  while (index >= 0)
  {
   if (p_walk != NULL)
   {
     roots[index] = p_walk;
     index++;
     p_walk = p_walk->left;
   } else
   {
     index--;

     if (index < 0)
     {
       return;
     }
     printf("%d ", roots[index]->value);
     p_walk = roots[index]->right;
   }
  }
}

// void print_in_order(Node_ptr tree) // another_way_with_loop
// {
//   Node_ptr* roots = malloc(sizeof(struct node*) * 3);
//   roots[0] = tree;
//   int index = 1, counter = 0;
//   Node_ptr p_walk = tree->left;
//   while (counter < 5)
//   {
//     if (p_walk != NULL)
//     {
//       roots[index] = p_walk;
//       index++;
//       p_walk = p_walk->left;
//     } else
//     {
//       index--;
//       printf("%d", roots[index]->value);
//       counter++;
//       p_walk = roots[index]->right;
//     }
//   }
// }

// Status search(Node_ptr tree, int value) //recursion
// {
//   if (tree == NULL)
//   {
//     return False;
//   }
//   if (tree->value == value)
//   {
//     return True;
//   }
//   if (tree->value > value)
//   {
//     return search(tree->left, value);
//   }
//   return search(tree->right, value);
// }

Status search(Node_ptr tree, int value)
{
  Node_ptr p_walk = tree;
  while (p_walk != NULL)
  {
    if (p_walk->value == value)
    {
      return True;
    }

    if (p_walk->value > value)
    {
      p_walk = p_walk->left;
    }
    else
    {
      p_walk = p_walk->right;
    }
  }
  return False;
}

int main(void)
{
  int list[] = {4, 8, 6, 1, 2};
  Node_ptr tree = create_tree(list, sizeof(list) / sizeof(int));
  print_in_order(tree, 3);
  printf("\n");
  search(tree, 2) ? printf("True\n") : printf("False\n");

  return 0;
}