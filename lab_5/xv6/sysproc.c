#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int sys_v2paddr(void)
{
    unsigned int  *virtualAddress;
    if(argptr(0,(void*) &virtualAddress, sizeof(*virtualAddress)) < 0)
    {
        cprintf("This is not valid.\n",virtualAddress);
        return -1;
    }
    struct proc *presentProcess = myproc();
    pde_t *pageDirectory = presentProcess->pgdir;
    pde_t *pageDirectoryEntry = &pageDirectory[PDX(virtualAddress)];
    if(!(*pageDirectoryEntry & PTE_P))
    {
        cprintf("page directory entry is not valid.\n");
        return -1;
    }
    if(!(*pageDirectoryEntry & PTE_U))
    {
        cprintf("user can't access page directory entry.\n");
        return -1;
    }
    pde_t *pageTable = (pte_t *)P2V(PTE_ADDR(*pageDirectoryEntry));
    pde_t *pageTableEntry = &pageTable[PTX(virtualAddress)];
    if(!(*pageTableEntry & PTE_P))
    {
        cprintf("pagetable entry is not valid.\n");
        return -1;
    }
    if(!(*pageTableEntry & PTE_U))
    {
        cprintf("user can't access page directory entry.\n");
        return -1;
    }
    return PTE_ADDR(*pageTableEntry) | PTE_FLAGS(virtualAddress);
}
