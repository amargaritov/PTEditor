#!/usr/bin/python 

from ctypes import *
import sys
so_file="/disk/local/neuralwalkers/linux/kmodules/PTEditor/test/ptdump.so" 
pteedit_funcs = CDLL(so_file) 

pteedit_funcs.ptedit_init()

#print("Initialized")

for line in sys.stdin:
  pid, vaddr, paddr = line.strip().split()
#  print(pid, vaddr, paddr)
  pid   = int(pid, 10)
  vaddr = int(vaddr, 16)
  paddr = int(paddr, 16)
#  print(pid, vaddr, paddr)
#  print(pid, hex(vaddr), hex(paddr))
  pteedit_funcs.my_ptedit_resolve(c_size_t(vaddr), c_size_t(paddr), pid)

pteedit_funcs.ptedit_cleanup()
