#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "myheader.h"

int main() {
    struct d_params *params;
    long set, get;
    /*SWSTH EKTELESH: SWSTA ARGS, SWSTH MNHMH*/
    params=malloc(sizeof(struct d_params));
    set=set_task_params('A', 21);
    if (set!=0) {
        perror("Error in set_task_params.\n");
        exit(EXIT_FAILURE);
    }

    get=get_task_params(params);
    if (get!=0) {
        perror("Error in get_task_params.\n");
        exit(EXIT_FAILURE);
    }
    printf("Group Name: %c\n", params->group_name);
    printf("Member ID: %d\n", params->member_id);

    free(params);

    /*LATHOS EKTELESH: PARAMS IS NULL*/
    params = NULL;
    set=set_task_params('B',7);
    if(set!=0){
        perror("Error in set_task_params.\n");
        exit(EXIT_FAILURE);
    }

    get=get_task_params(params);
    if(get != 0){
        perror("Error in get_task_params.\n");
        exit(EXIT_FAILURE); /*edw tha termatisei o kwdikas kai to printk tha mas pei oti to error einai sto params pou einai null*/
    }
    printf("Group Name: %c\n", params->group_name);
    printf("Member ID: %d\n", params->member_id);
    return 0;
}
