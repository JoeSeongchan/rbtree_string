//
// Created by seongchan-joe on 21. 11. 8..
//
#include "utilities.h"

// function to log.
void logFn(const char *caller_name, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    printk("-----------------------\n"
           "FN : %s\n"
           "MSG : ", caller_name);
    vprintk(fmt, args);
    va_end(args);
}

// function to mix the sequence of the array.
void shuffle(char **str_arr, int arr_len){
    char* temp;
    unsigned int random_number;
    unsigned int val = 0;
    for (int i = 0; i < arr_len - 1; i++) {
        get_random_bytes(&val, sizeof(unsigned int));
        random_number = (unsigned int) (val % (arr_len - i) + i); // Pick a number randomly from i ~ arr_length-1.
        // swap.
        temp = str_arr[i];
        str_arr[i] = str_arr[random_number];
        str_arr[random_number] = temp;
    }
}