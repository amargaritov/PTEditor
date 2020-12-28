#include "../ptedit_header.h"
#include <time.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *const argv[]) {
    if(ptedit_init()) {
        printf("Could not initialize PTEditor, did you load the kernel module?\n");
        return 1;
    }

    int pid = atoi(argv[1]);
    void* vaddr = strtol(argv[2], NULL, 16);
    void* paddr = strtol(argv[3], NULL, 16);

    ptedit_entry_t vm = ptedit_resolve(vaddr, pid);

//    printf("pid = %d, addr = %zx\n", pid, addr);
    printf("%zx,%zx,%zx,%zx,%zx,%zx\n", vaddr, vm.pgd, vm.pud, vm.pmd, vm.pte, paddr);
    
    ptedit_cleanup();
    return 0;
}
