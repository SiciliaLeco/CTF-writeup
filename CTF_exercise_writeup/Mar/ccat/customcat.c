#include <dirent.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char * read_file(char * filename) {
  char * file_contents = malloc(4096 * sizeof(char));

  FILE * file;
  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Unable to open file!\n");
    _exit(1);
  }

  fread(file_contents, 4096, sizeof(char), file);
  fclose(file);

  return file_contents;
}

char * read_flag() {
  return read_file("/home/customcat/flag.txt");  // outside of current working directory ;)
}

// Exit program after 10s
void timeout() {
  printf("\nToo slow!\n");
  _exit(1);
}

int i;
DIR * directory;
struct dirent * directory_entry;

int main(int argc, char* argv[]) {
  setvbuf(stdin,  NULL, _IONBF, 0);   // Switch off I/O buffering
  setvbuf(stdout, NULL, _IONBF, 0);   // Switch off I/O buffering
  setvbuf(stderr, NULL, _IONBF, 0);   // Switch off I/O buffering

  signal(SIGALRM, timeout);           // Set program to exit on timeout
  alarm(10);                          // Exit program after 10s

  //Change directory to folder
  chdir("./home/customcat/file");

  char * flag = read_flag();
  char input_filename[40];

  printf("Current working directory is: ");
  system("pwd");    // print current working directory
  system("ls -1");  // list every file in current directory on a new line

  printf("Enter a filename to print the contents of the file => ");
  scanf("%39s", input_filename);

  // Disallow n in user input because why not?
  for (i = 0; i < 40; i++) {
    if (input_filename[i] == 'n') {
      printf("This cat doesn't like the alphabet 'n' :/\n");
      return 1;
    }
  }

  // Open current directory
  directory = opendir("/home/customcat/file");
  if (directory == NULL) {
    printf("Unable to open current directory to list files!\n");
    return 1;
  }
  
  // This cat is already nice enough to load the flag file for you.
  // Don't expect it to print it out for you! :>
  if (false) {
    printf("Flag is: %s", flag);
  }

  // Check if user input filename exists in current directory
  while ((directory_entry = readdir(directory)) != NULL) {
    // print the contents of the file to the user!
    if (strcmp(input_filename, directory_entry->d_name) == 0) {
      printf("File contents:\n");
      printf("%s\n", read_file(input_filename));

      return 0;
    }
  }

  // User supplied filename does not exist
  printf(input_filename);
  printf(" cannot be found in the current directory.\n");
  printf("Hint: Flag is at %p\n", (void*) &flag[0]);
  free(flag);
  return 1;
}
