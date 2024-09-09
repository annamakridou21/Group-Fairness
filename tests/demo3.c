#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "myheader.h"
int main(){
    struct d_params *params;
    long set,get;
    /*LATHOS EKTELESH, DWSAME ARNHTIKO MEMBER ID*/
    params=malloc(sizeof(struct d_params));
    set=set_task_params('N',-3);
    if(set!=0){
        perror("Error in set_task_params.\n");
        exit(EXIT_FAILURE);
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
