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
The tool will output _kernel virtual addresses_ of page table pages and a physical address of the page with the data for all pages allocated by an applicaiton. 
