#xv6 Custom Scheduling and Processes.

To run this you need to install qemu first.
After getting it installed:
> make
> make qemu

### User syscalls:

##### ps:
Prints the pid, status, and priority of all processes.

##### xpri <pid> <pri>:
Changes priority of process with PID = 'pid' to 'pri'