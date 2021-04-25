Intro
=====
As you have learnt in the lecture, stack buffer overflows could result in memory corruption in a program. Exploitation usually involves leveraging a vulnerability to lead a program into unwanted behaviour. A dangerous case would be to overwrite the return address stored in the stack, allowing the attacker to control the execution flow of a program. This challenge demonstrates such a scenario.

Challenge
=========
The challenge service runs the `bof` executable. You are given the source code in `bof.c`. Read the documentation of `gets` if you are not sure what to do/you can do.

Usually when doing binary exploitation, it is important to have a debugger like GDB (with extensions like GEF, peda, pwndbg) to inspect the program's internal state (registers and memory). Anyways, for this introductory challenge, this is not compulsory. We've prepared a custom made program `bofschool` that shows you the program's (`bof`) interal state according to your input. (You can ignore it if you are already comfortable with binary exploitation.)

**Note that the server runs `bof` instead of `bofschool`. `bofschool` is just a side program to help you learn better.**

```
Controls:
`q`          - Quit the program
`<Backspce>` - Delete character
`<Enter>     - Send payload
Use `\xXX` to send hex encoded characters (useful for unprintable characters), e.g. "\x44\x41\x42" is equivalent to "DAB"
```

Also, for doing binary exploitation, there is an amazing python library called pwntools, and you are highly recommended to use it. We have provided a script `xpl.py` that contains some code that you will find helpful.

Reality
=======
In real life, this is not so straightforward, due to many mitigations by the operating system, e.g. ASLR, PIE, DEP, stack canary. However, for this challenge, the executable was compiled without any of these mitigations (except ASLR which is enforced by the kernel itself).