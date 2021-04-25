// gcc -g -fno-stack-protector -no-pie vegas.c -o vegas

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>

void setup();
void read_string(char* buffer, size_t len);
int read_int();
char* read_file(char *);
void give_flag();
void timeout();
void jackpot();
void play();
void reset();

char name[256];
unsigned long current_time;
int score = 0;

void setup()
{
    setvbuf(stdin,  NULL, _IONBF, 0);   // Switch off I/O buffering
    setvbuf(stdout, NULL, _IONBF, 0);   // Switch off I/O buffering
    setvbuf(stderr, NULL, _IONBF, 0);   // Switch off I/O buffering

    signal(SIGALRM, timeout);           // Set program to exit on timeout
    alarm(10);                          // Exit program after 10s
}

void play() {
    printf("\n=================== ALLOCATED A JACKPOT MACHINE ===================\n");
    printf("Give me a number between 1 and 100: ");

    int lucky = rand() % 100 + 1;
    if (lucky == read_int())
    {
        score++;
        printf("Lucky!");
    }
    else
    {
        score = 0;
        printf("Unlucky!\n");
    }

    printf("Score: %d\n", score);

    if (score == 7)
	    jackpot();

    printf("Thanks for playing!\n");
    return;
}

void reset()
{
    puts("Believe you can change your fate?");
    current_time = time(NULL);
    printf("Tell me your name: ");
    read_string(name, 256);
    srand(current_time);
}

int main(int argc, char *argv[])
{
    puts("");
    printf(" -----------------------------------------------------------------\n");
    printf(" * $ * $ * $ * WELCOME TO VEGAS, THE CITY OF LIGHTS * $ * $ * $ *\n");
    printf(" * $ * $ Guess correctly 7 times in a row to win a prize $ * $ *\n");
    printf(" -----------------------------------------------------------------\n");

    current_time = time(NULL);
    srand(current_time);

    printf("Before we start, tell me your name: ");
    read_string(name, 256);

    while(1)
    {
        printf(" ------------------ What do you want to do? ------------------\n");
        printf("1. Play \n");
        printf("2. Reset \n");
        printf("3. Exit \n");
        printf(" -------------------------------------------------------------\n");
        printf("> ");

        int choice = read_int();
        switch(choice)
        {
            case 1:
                play();
                break;
            case 2:
                reset();
                break;
            case 3:
                puts("Bye");
                exit(0);
                break;
            default:
                puts("Not sure what you are trying to do");
                break;
        }
    }

    return 0;
}

// read n bytes from user
void read_string(char* buffer, size_t len)
{
    fflush(stdout);
    int i = 0;
    for (; i < len; ++i)
    {
        read(0, &buffer[i], 1);
        if (buffer[i] == '\n')
        {
            buffer[i] = 0;
            return;
        }
    }
    buffer[i+1] = 0;
}

// read int from user
int read_int()
{
    char buffer[8];
    read_string(buffer, 5);
    return atoi(buffer);
}

void jackpot() {
    printf("\n\n$ $ $ KACHING! CONGRATULATIONS YOU HACKED THE JACKPOT!!! $ $ $\n");
    give_flag();
}

// Read contents of file and return a string containing the contents
char * read_file(char * filename)
{
    char * file_contents = malloc(4096 * sizeof(char));

    FILE * file;
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("\nUnable to open file!\n");
        exit(1);
    }

    fread(file_contents, 4096, sizeof(char), file);
    fclose(file);

    return file_contents;
}

// Print flag
void give_flag()
{
    printf("\n$ * $ * $ YOU'RE A MILLIONAIRE! $ * $ * $\n");
    printf("%s", read_file("/home/vegas/flag"));
}

// Exit program after 10s
void timeout()
{
    printf("\nToo slow... Vegas' security team is watching @.@\n");
    exit(1);
}
