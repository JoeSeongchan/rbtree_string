//
// Created by seongchan-joe on 21. 10. 28..
//
#include "rbtree_api.h"

// function to make & init root rb_node and return it.  [test complete]
struct rb_root *init_rb_root(void) {
    struct rb_root *root = (struct rb_root *) kmalloc(sizeof(struct rb_root), GFP_KERNEL);
    *root = RB_ROOT;
    return root;
}

// function to make & init data_node and return it.  [test complete]
data_node *init_data_node(char *data) {
    data_node *new_node = (data_node *) kmalloc(sizeof(data_node), GFP_KERNEL);
    new_node->data = data;
    return new_node;
}

// function to free data node.  [test complete]
void free_data_node(data_node *target) {
    kfree(target);
}

// function to print all data_node in tree.  [test complete]
void print_all_node(struct rb_root *root) {
    struct rb_node *cur_rnode;
    int i = 0;
    for (cur_rnode = rb_first(root); \
        cur_rnode != NULL; \
        cur_rnode = rb_next(cur_rnode)) {
        log("# %d data : %s", ++i, get_container_of(cur_rnode)->data);
    }
}

// function to insert data_node.  [test complete]
void insert_node(struct rb_root *root, data_node *new_dnode) {
    struct rb_node **cur_rnode = &(root->rb_node);
    struct rb_node *parent = NULL;
    data_node *cur_dnode;
    int result = 0;
    // figure out where to put new node.
    while (*cur_rnode) {
        cur_dnode = get_container_of(*cur_rnode);
        result = strcmp(new_dnode->data, cur_dnode->data);
        parent = *cur_rnode;
        if (result < 0)
            cur_rnode = &((*cur_rnode)->rb_left);
        else if (result > 0)
            cur_rnode = &((*cur_rnode)->rb_right);
        else {
            // when data is already existed in tree.
            return;
        }
    }
    // add new node and rebalance tree.
    rb_link_node(&new_dnode->node, parent, cur_rnode);
    rb_insert_color(&new_dnode->node, root);
}

// function to search data_node.  [test complete]
data_node *search_node(struct rb_root *root, char *data) {
    struct rb_node *cur_rnode = root->rb_node;
    data_node *cur_dnode;
    int result = 0;
    while (cur_rnode) {
        // find current data node.
        cur_dnode = get_container_of(cur_rnode);
        // compare data and find next data node.
        result = strcmp(data, cur_dnode->data);
        if (result < 0) {
            cur_rnode = cur_rnode->rb_left;
        } else if (result > 0) {
            cur_rnode = cur_rnode->rb_right;
        } else {
            // when we find target.
            return cur_dnode;
        }
    }
    // when we can't find target.
    return NULL;
}

// function to delete data_node.  [test complete]
int delete_node(struct rb_root *root, char *data) {
    // find target data_node.
    data_node *target = search_node(root, data);
    if (target == NULL) {
        return 0;
    }
    // log("target data : %d", target->data);
    // erase target data_node.
    rb_erase(&target->node, root);
    free_data_node(target);
    return 1;
}

// function to delete rb_tree.  [test complete]
void delete_rb_tree(struct rb_root *root) {
    struct rb_node *cur_rnode;
    for (cur_rnode = rb_first(root); \
        cur_rnode != NULL; \
        cur_rnode = rb_next(cur_rnode)) {
        rb_erase(cur_rnode, root);
        free_data_node(get_container_of(cur_rnode));
    }
    kfree(root);
}