//
// Created by seongchan-joe on 21. 10. 29..
//

#include "rbtree/rbtree_api.h"
#include "common/time_calculating.h"

#include <linux/syscalls.h>
#include <linux/fcntl.h>
#include <asm/uaccess.h>
#include <linux/string.h>
#include <linux/ctype.h>

MODULE_LICENSE ("GPL v2");

// function to measure time to insert 'str_num' strings to linked list.
unsigned long long measure_insert_time(struct rb_root *root, char **str_arr, int str_num) {
    struct timespec64 start_time, end_time;
    data_node *new_node = NULL;
    ktime_get_raw_ts64(&start_time);            // start.
    // insert 'str_num' nodes.
    for (int i = 0; i < str_num; i++) {
        new_node = init_data_node(str_arr[i]);  // make new node.
        insert_node(root, new_node);            // insert.
    }
    ktime_get_raw_ts64(&end_time);              // end.
    struct timespec64 spclock[2] = {start_time, end_time};
    unsigned long long time_diff = calclock3(spclock);
    return time_diff;
}

// function to measure time to find 'str_num' strings in the linked list.
unsigned long long measure_search_time(struct rb_root *root, char **str_arr, int str_num) {
    struct timespec64 start_time, end_time;
    ktime_get_raw_ts64(&start_time);            // start.
    data_node *search_result;
    int success_count = 0;
    for (int i = 0; i < str_num; i++) {
        search_result = search_node(root, str_arr[i]);  //  search.
        if (search_result != NULL) {
            // printk("#%llu element is found. val : %llu, node val : %llu\n", i, target_list[i], search_result->data);
            success_count++;
        }
    }
    if (success_count != str_num) {
        log("error.");
    }
    ktime_get_raw_ts64(&end_time);              // end.
    struct timespec64 spclock[2] = {start_time, end_time};
    unsigned long long time_diff = calclock3(spclock);
    return time_diff;
}

// function to measure time to remove item from the linked list.
// target item = One of the items in the target_list.
unsigned long long measure_delete_time(struct rb_root *root, char **str_arr, int str_num) {
    struct timespec64 start_time, end_time;
    ktime_get_raw_ts64(&start_time);        // start.
    int success_count = 0;
    for (int i = 0; i < str_num; i++) {
        success_count += delete_node(root, str_arr[i]);      // delete.
    }
    if (success_count != str_num) {
        log("error.");
    }
    ktime_get_raw_ts64(&end_time);          // end.
    struct timespec64 spclock[2] = {start_time, end_time};
    unsigned long long time_diff = calclock3(spclock);
    return time_diff;
}

void print_result(char *title, int item_num, unsigned long long elapsed_time) {
    printk("---Example of %s---\n", title);
    printk("Number of items : %d\n", item_num);
    printk("Elapsed time : %llu sec, %llu nsec\n", elapsed_time / BILLION, elapsed_time % BILLION);
    printk("\n");
}

void run(void) {
    struct rb_root *root = init_rb_root();
    int arr_len = 5;
    char *data_arr[5] = {"abc", "def", "ghi", "jkl", "mno"};
    int elapsed_time = measure_insert_time(root, data_arr, arr_len);
    print_result("insertion", arr_len, elapsed_time);
    shuffle(data_arr, arr_len);
    print_all_node(root);
    elapsed_time = measure_search_time(root, data_arr, arr_len);
    print_result("search", arr_len, elapsed_time);
    elapsed_time = measure_delete_time(root, data_arr, arr_len);
    print_result("deletion", arr_len, elapsed_time);
    print_all_node(root);
    delete_rb_tree(root);
    printk("End. Thank you.\n");
}

int __init

test_rb_tree_string_module_init(void) {
    run();
    return 0;
}

void __exit

test_rb_tree_string_module_cleanup(void) {
    printk("Module that tests the red-black tree in linux kernel.\n");
    printk("--------------------------------------------------\n");
    printk("LINUX SYSTEM AND ITS APPLICATIONS\n");
    printk("Subclass : 02\n");
    printk("ID : 20160570\n");
    printk("Name : Joe Seong-chan\n");
    return;
}

module_init(test_rb_tree_string_module_init);
module_exit(test_rb_tree_string_module_cleanup);

