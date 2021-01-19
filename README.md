# PTEditor
Initially, PTEditor is a small library to modify all page-table levels of all processes from user space for x86_64 and ARMv8.

# This branch contains a tool for dumping addresses of page talbe pages on AArch64.

## Installation
### Downloading sources
```bash
git clone https://github.com/amargaritov/PTEditor
cd PTEditor
export PTEDITOR_ROOT=$(pwd)
```
### Compilation
Dependancy: requires linux-headers package
```bash
sudo apt install linux-headers-$(uname-r)
cd $PTEDITOR_ROOT
./build_everything.sh
```

### Loading the module
```bash
cd $PTEDITOR_ROOT
./load_module.sh
```

## Dumping page table address of an application by PID
```bash 
cd $PTEDITOR_ROOT
./dump_pt.sh <PID>
```
The tool will output _kernel virtual addresses_ of page table pages and a physical address of the page with the data for all pages allocated by an applicaiton. Each line of the output lists the addresses corresponding to one page from allocated virtual address space (addresses are separated by commas). The fragment of the output is below:
```
PT_root,PT2,PT3,PT_leaf(PTE),PA_data
0xffff2a644000,0x2e6f410003,0x312f820003,0x2e114f9003,0xe0002d8e25efd3,0x2d8e25e000
0xffff2a645000,0x2e6f410003,0x312f820003,0x2e114f9003,0xe0002d8e25ffd3,0x2d8e25f000
0xffff2a646000,0x2e6f410003,0x312f820003,0x2e114f9003,0xe0002d8e260fd3,0x2d8e260000
0xffff2a647000,0x2e6f410003,0x312f820003,0x2e114f9003,0xe0002d8e261fd3,0x2d8e261000
0xffff2a648000,0x2e6f410003,0x312f820003,0x2e114f9003,0xe0002d8e262fd3,0x2d8e262000
0xffff2a649000,0x2e6f410003,0x312f820003,0x2e114f9003,0xe0002d8e263fd3,0x2d8e263000
```
```
