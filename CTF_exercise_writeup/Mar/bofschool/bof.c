#include <stdio.h>

/* gcc -fno-stack-protector -no-pie ./bof.c -o bof */
char flag[] = "cs2107{real_flag_will_be_here_submit_this_one_got_no_use_so_dont_submit_this_ah}";
void win(){
	puts(flag);
    fflush(stdout);
}

int main(){
	char buf[32];
	gets(buf);
	return 0;
}
