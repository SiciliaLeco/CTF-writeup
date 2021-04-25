from pwn import *

HOST = "cs2107-ctfd-i.comp.nus.edu.sg"
PORT = 2774
BINARY = "./addressbook"
r = remote(HOST, PORT)

r.interactive()