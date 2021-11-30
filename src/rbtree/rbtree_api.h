//
// Created by seongchan-joe on 21. 10. 28..
//

#ifndef LINKED_LIST_TEST_MODULE_LINKED_LIST_API_H
#define LINKED_LIST_TEST_MODULE_LINKED_LIST_API_H

#include "../common/utilities.h"
#include "data_structure.h"

// function to make & init rb_root and return it.
struct rb_root *init_rb_root(void);

// function to make & init data_node and return it.
data_node *init_data_node(char* data);

// function to free data node.
void free_data_node(data_node *target);

// function to print all data_node in tree.
void print_all_node(struct rb_root *root);

// function to insert data_node.
void insert_node(struct rb_root *root, data_node *node);

// function to search data_node.
data_node *search_node(struct rb_root *root, char* data);

// function to delete data_node.
int delete_node(struct rb_root *root, char* data);

// function to delete rb_tree.
void delete_rb_tree(struct rb_root *root);

#endif //LINKED_LIST_TEST_MODULE_LINKED_LIST_API_H
