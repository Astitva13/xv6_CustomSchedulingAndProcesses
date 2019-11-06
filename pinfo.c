#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  struct proc_stat* px = 0 ;

  getpinfo(px);
  printf(1,"PID\tINUSE\tRUNTIME\tNUM_RUN\tCURR_Q");
  for (int i = 0; i < 64; i++)
  {
    printf(1,"%d\t%d\t%d\t%d\t%d",px->pid[i],px->inuse[i],px->runtime[i],px->num_run[i],px->current_queue[i]);
  }
  
  exit();
}