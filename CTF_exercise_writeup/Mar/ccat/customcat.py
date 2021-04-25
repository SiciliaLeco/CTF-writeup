# pwntools is a very powerful library for doing exploitation
from pwn import *

# TODO: Update with actual values
HOST = "cs2107-ctfd-i.comp.nus.edu.sg"
PORT = 2779
BINARY = "./customcat"

r = remote(HOST, PORT)  # to open a connection to the remote service, aka the challenge
# r = process(BINARY)   # use process instead of remote to execute the local version of the program
pause()


# PADDING = "%9$s".encode()
# PAYLOAD = PADDING
# RETURN_ADDRESS = 0x08048000# should be the address for win() function
# PAYLOAD = PADDING + p64(RETURN_ADDRESS) # p64 converts an integer to 8-byte little endian bytestring format
# r.sendline(PAYLOAD)

# earlier, the script helps us send/receive data to/from the service
# with interactive, we can directly interact with the service
r.interactive()