# xv6 Custom Scheduling and Processes.

To run this you need to install qemu first.
After getting it installed:
```
make
make qemu-nox
```

Also use the following command to make the folder clean again before compiling again:
```
make clean
```

To exit from non-graphical qemu (qemu-nox):
```
Ctrl+A x
```

### User syscalls:

##### ps:
Prints the pid, status, and priority of all processes.

##### xpri pid pri:
Changes priority of process with PID = `pid` to `pri`

##### new:
Crates new parent-child process that takes quite a long time to execute.

##### pinfo:
Prints `pid`, `runtime`, `number of runs` and `current queue` of all active/inuse processes.

### Other syscalls:

##### waitx:
Returns `wait time` and `run time` of the process.
Its just extension of predefined `wait syscall` but with two more arguments for returning the `wait time` and `run time` of process.

### Custom scheduling:

Default scheduler for xv6 is `ROUND ROBIN`, and to use this scheduler no new CLARG is to be passed.

For other schedulers following format should be used:
```
make qemu-nox SCHEDULER=VALUE
```
Where `VALUE` is:
```
DEFAULT : For Round Robin
FCFS    : For FCFS
PBS     : For Priority based
MLFQ    : For MLFQ scheduling
```

### Implementations:

#### FCFS:
During the development of waitx, three more attributes namely `ctime`, `rtime` and `etime` denoting creation time, run time, end time were created.
So for FCFS we look for process with smallest `ctime`.

Also this scheduling implemented here is non-preemptive. To implement this, we compare the `ctime` of currently running process, and that of smallest `ctime` and preemp only when the second is smaller than first.

### PBS:
Similar to FCFS but here comparing `priority` attribute of the process (Added to implement this). Default priority is set to `60`, lower the value of this attribute higher is the Process priority. Max value is set to 100.
To change the priority of a process use `xpri` user syscall.

### MLFQ:
The approach is simple 