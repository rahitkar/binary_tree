#include <stdio.h>
#include <stdlib.h>

typedef void* Element;

typedef struct node
{
  Element value;
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

typedef Status (* Compare) (Element, Element);
typedef void (* Print) (Element);

Status int_compare(Element num1, Element num2)
{
  return *(int*)num1 > *(int*)num2;
}

Status is_int_equal(Element num1, Element num2)
{
  return *(int*)num1 == *(int*)num2;
}

void print_int(Element value)
{
  printf("%d ", *(int*)value);
}

Node_ptr create_node(Element value)
{
  Node_ptr node = malloc(sizeof(Node));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node_ptr insert_node(Node_ptr tree, Element value, Compare compare)
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
    if ((*compare)(p_walk->value, value))
    {
      p_walk = p_walk->left;
    }
    else
    {
      p_walk = p_walk->right;
    }
  }

  if ((*compare)(root->value, value))
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

Node_ptr create_tree(Element* list, int length)
{
  Node_ptr tree;
  tree = insert_node(NULL, list[0], int_compare);
  for (int i = 1; i < length; i++)
  {
    insert_node(tree, list[i], int_compare);
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

void print_in_order(Node_ptr tree, int hight, Print print)
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
     (*print)(roots[index]->value);
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

Status search(Node_ptr tree, Element value, Compare compare, Compare is_equal)
{
  Node_ptr p_walk = tree;
  while (p_walk != NULL)
  {
    if ((*is_equal)(p_walk->value, value))
    {
      return True;
    }

    if ((*compare)(p_walk->value, value))
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

Element create_void_array(Element array, int length, int element_size)
{
  Element* new_array = malloc(sizeof(Element) * length);

  for(int indx = 0; indx < length; indx++)
  {
    new_array[indx] = array + (indx * element_size);
  }
  return new_array;
}

int main(void)
{
  int list[] = {4, 8, 6, 1, 2};
  Node_ptr tree = create_tree(create_void_array(list, 5, sizeof(int)), 5);
  print_in_order(tree, 3, print_int);
  printf("\n");
  int value_to_be_searched = 2;
  search(tree, &value_to_be_searched, int_compare, is_int_equal) ? printf("True\n") : printf("False\n");

  return 0;
}