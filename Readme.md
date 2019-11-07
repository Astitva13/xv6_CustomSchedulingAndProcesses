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
> `Ctrl+A` x

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

For other schedulers following format should be used