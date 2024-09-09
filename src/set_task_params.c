#include <linux/kernel.h>
#include <linux/sched.h> /*modified gia na periexei ta nea pedia group_name,member_id*/ο
#include <linux/errno.h>
asmlinkage long sys_set_task_params(char group_name,int member_id){
    struct task_struct *current_task;
    printk("ANNA MAKRIDOU 4934 set_task_params.\n");
    if((group_name<'A' || group_name>'Z') && member_id<=0){
	printk("GROUP NAME NOT CAPITAL LETTER AND MEMBER ID NEGATIVE.\n");
	return EINVAL;   /*periptwsh 1: kai ta 2 arguments einai lathos*/
    }
    if (group_name<'A' || group_name>'Z') {
        printk("GROUP NAME NOT CAPITAL LETTER.\n");
        return EINVAL;     /*periptwsh 2: to 1 argument einai lathos, to char den einai kefalaio*/
    }
    if (member_id<=0) {
        printk("MEMBER ID NEGATIVE.\n");   /*periptwsh 3: to 2 argument einai lathos, to id einai arnhtiko*/
        return EINVAL;
    }
    current_task=current;    /*get current process*/
    current_task->group_name=group_name; /*allazw tis times twn antistoixwn pediwn sto task_struct*/   
    current_task->member_id=member_id;
    return 0;  
}
