#include "types.h"
#include "user.h"
#include "syscall.h"


int main(int argc, char *argv[]) {
    printf(1, "Initial fork count %d\n", getcount(SYS_fork));

	if (fork() == 0) {
		printf(1, "Child fork count %d\n", getcount(SYS_fork));
		printf(1, "Child write count %d\n", getcount(SYS_write));
		printf(1, "Child process id:", getpid());
		printf(1, "Child wait count %d\n", getcount(SYS_wait));
		printf(1, "Child exit count %d\n", getcount(SYS_exit));
		printf(1, "Child pipe count %d\n", getcount(SYS_pipe));
		printf(1, "Child read count %d\n", getcount(SYS_read));
		printf(1, "Child kill count %d\n", getcount(SYS_kill));
		printf(1, "Child exec count %d\n", getcount(SYS_exec));
		printf(1, "Child fstat count %d\n", getcount(SYS_fstat));
		printf(1, "Child chdir count %d\n", getcount(SYS_chdir));
		printf(1, "Child dup count %d\n", getcount(SYS_dup));
		printf(1, "Child getpid count %d\n", getcount(SYS_getpid));
		printf(1, "Child sbrk count %d\n", getcount(SYS_sbrk));
		printf(1, "Child sleep count %d\n", getcount(SYS_sleep));
		printf(1, "Child uptime count %d\n", getcount(SYS_uptime));
		printf(1, "Child open count %d\n", getcount(SYS_open));
		printf(1, "Child write count %d\n", getcount(SYS_write));
		printf(1, "Child mknod count %d\n", getcount(SYS_mknod));
		printf(1, "Child unlink count %d\n", getcount(SYS_unlink));
		printf(1, "Child link count %d\n", getcount(SYS_link));
		printf(1, "Child mkdir count %d\n", getcount(SYS_mkdir));
		printf(1, "Child close count %d\n", getcount(SYS_close));
		printf(1, "Child getcount count %d\n", getcount(SYS_getcount));

    } else {
        wait();
        printf(1, "Parent fork count %d\n", getcount(SYS_fork));
        printf(1, "Parent write count %d\n", getcount(SYS_write));
        printf(1, "Parent process id:", getpid());
	printf(1, "Parent wait count %d\n", getcount(SYS_wait));
	printf(1, "Parent exit count %d\n", getcount(SYS_exit));
	printf(1, "Parent pipe count %d\n", getcount(SYS_pipe));
	printf(1, "Parent read count %d\n", getcount(SYS_read));
	printf(1, "Parent kill count %d\n", getcount(SYS_kill));
	printf(1, "Parent exec count %d\n", getcount(SYS_exec));
	printf(1, "Parent fstat count %d\n", getcount(SYS_fstat));
	printf(1, "Parent chdir count %d\n", getcount(SYS_chdir));
	printf(1, "Parent dup count %d\n", getcount(SYS_dup));
	printf(1, "Parent getpid count %d\n", getcount(SYS_getpid));
	printf(1, "Parent sbrk count %d\n", getcount(SYS_sbrk));
	printf(1, "Parent sleep count %d\n", getcount(SYS_sleep));
	printf(1, "Parent uptime count %d\n", getcount(SYS_uptime));
	printf(1, "Parent open count %d\n", getcount(SYS_open));
	printf(1, "Parent write count %d\n", getcount(SYS_write));
	printf(1, "Parent mknod count %d\n", getcount(SYS_mknod));
	printf(1, "Parent unlink count %d\n", getcount(SYS_unlink));
	printf(1, "Parent link count %d\n", getcount(SYS_link));
	printf(1, "Parent mkdir count %d\n", getcount(SYS_mkdir));
	printf(1, "Parent close count %d\n", getcount(SYS_close));
	printf(1, "Parent getcount count %d\n", getcount(SYS_getcount));

    }
    
    exit();
}
