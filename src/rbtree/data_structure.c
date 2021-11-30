//
// Created by seongchan-joe on 21. 11. 9..
//

#include "data_structure.h"

// function to get container (=data_node) ptr. [test complete]
data_node* get_container_of(struct rb_node *ptr){
    return (data_node*)container_of(ptr,data_node,node);
}

