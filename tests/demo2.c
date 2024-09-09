#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "myheader.h"
int main(){
    struct d_params *params;
    long set,get;
    /*LATHOS EKTELESH: H MNHMH EINAI EGKURH, ALLA TO CHAR STO SET EINAI MIKRO OXI KEFALAIO*/
    params=malloc(sizeof(struct d_params));
    set=set_task_params('b',17);
    if(set!=0)
        perror("Error in set_task_params.\n");
        exit(EXIT_FAILURE);  /*edw to programma tha termatisei epeidh to b einai mikro kai to printk tha mas pei oti dwsame mikro kai oxi capital letter*/
    }
    get=get_task_params(params);
    if(get!=0){
        perror("Error in get_task_params.\n");
        exit(EXIT_FAILURE);
    }
    printf("Group Name: %c\n", params->group_name);
    printf("Member ID: %d\n", params->member_id);
    free(params);
    return 0;
}
