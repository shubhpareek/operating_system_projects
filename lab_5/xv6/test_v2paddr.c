#include "types.h"
#include "user.h"
#include "syscall.h"
#include "memlayout.h"
int b;
int main(int argc, char *argv[])
{
    int a=10;
    printf(1,"virtual address 0x%x to physical address 0x%x \n",&a,v2paddr(&a));
    printf(1,"virtual address 0x%x to physical address 0x%x \n",KERNBASE + 0x555,v2paddr(KERNBASE + 0x555));//this is not valid
    printf(1,"virtual address 0x%x to physical address 0x%x \n",&b,v2paddr(&b));
    
    
}