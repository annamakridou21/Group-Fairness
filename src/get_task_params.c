#include <linux/errno.h>
#include <linux/sched.h>
#include "linux/mystruct.h"
#include <linux/uaccess.h>
asmlinkage long sys_get_task_params(struct d_params* params) {
    struct task_struct *current_task; 
    struct d_params tmp;
    printk("ANNA MAKRIDOU 4934 get_task_params.\n");
    if (!access_ok(VERIFY_WRITE, params, sizeof(struct d_params))) {
        printk("INVALID MEMORY.\n");   /*periptwsh 1: elegxw an h mnhnh einai egkurh gia na grapsw*/
	return EINVAL;
    }
    if(params==NULL){
	printk("PARAMS IS NULL.\n");   /*periptwsh 2:elegxw an to argument einai null*/
	return EINVAL;
    }
    current_task=current; /*get current process*/
    tmp.group_name = current_task->group_name;
    tmp.member_id = current_task->member_id;  /*allazw ta pedia tou struct d_params me vash ta pedia tou task_struct ths trexousas diergasias*/
    if (copy_to_user(params, &tmp, sizeof(struct d_params))!=0)return EINVAL; /*copy back to user ta nea dedomena epeidh exoume arg by reference*/
    return 0; 
}
