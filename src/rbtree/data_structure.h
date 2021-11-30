//
// Created by seongchan-joe on 21. 11. 9..
//

#ifndef RB_TREE_TEST_MODULE_DATA_STRUCTURE_H
#define RB_TREE_TEST_MODULE_DATA_STRUCTURE_H

#include <linux/rbtree.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/random.h>
#include <linux/module.h>
#include <linux/limits.h>


typedef struct _data_node {
    struct rb_node node;
    char* data;
} data_node;

data_node *get_container_of(struct rb_node *ptr);

#endif //RB_TREE_TEST_MODULE_DATA_STRUCTURE_H
