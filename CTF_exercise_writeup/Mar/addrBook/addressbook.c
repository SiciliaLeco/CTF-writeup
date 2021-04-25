// gcc -g -fno-stack-protector -no-pie addressbook.c -o addressbook
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact
{
    char name[20];
    char phone_number[20];
};

int is_premium_user = 0;

int num_contacts = 0;
struct Contact contacts[20];

// don't worry about this, just some code to disable IO buffering
void setup()
{
    setvbuf(stdin, 0LL, 2, 0LL);
    setvbuf(stdout, 0LL, 2, 0LL);
    setvbuf(stderr, 0LL, 2, 0LL);
}

void banner()
{
    puts("_______  ______   ______   ______    _______  _______  _______    _______  _______  _______  ___   _ ");
    puts("|   _   ||      | |      | |    _ |  |       ||       ||       |  |  _    ||       ||       ||   | | |");
    puts("|  |_|  ||  _    ||  _    ||   | ||  |    ___||  _____||  _____|  | |_|   ||   _   ||   _   ||   |_| |");
    puts("|       || | |   || | |   ||   |_||_ |   |___ | |_____ | |_____   |       ||  | |  ||  | |  ||      _|");
    puts("|       || |_|   || |_|   ||    __  ||    ___||_____  ||_____  |  |  _   | |  |_|  ||  |_|  ||     |_ ");
    puts("|   _   ||       ||       ||   |  | ||   |___  _____| | _____| |  | |_|   ||       ||       ||    _  |");
    puts("|__| |__||______| |______| |___|  |_||_______||_______||_______|  |_______||_______||_______||___| |_|");
    puts("");
    puts("Actually I'm not an address book. I just like address book projects. CS2103/CS2113 people know what I mean ;)");
    puts("");
}

void menu()
{
    puts("==========*****==========");
    puts("1. List contacts");
    puts("2. Add contact");
    puts("3. Delete contact");
    puts("4. Delete many contacts");
    puts("==========*****==========");
    puts("");
}

int read_int()
{
    char choice[20];
    fgets(choice, 20, stdin);
    return atoi(choice);
}

int get_choice()
{
    printf("> ");
    return read_int();
}

void trim(char* str)
{
    int len = strlen(str);
    if (str[len - 1] == '\n') str[len - 1] = 0;
}

void list_contacts()
{
    printf("]] %d contacts found.\n", num_contacts);
    for (int i = 0; i < num_contacts; ++i)
    {
        struct Contact *contact = &contacts[i];
        printf(" - %s => %s\n", contact->name, contact->phone_number);
    }
    puts("");
}

void add_contact()
{
    if (num_contacts == 50)
    {
        puts("]] Contact book is full. Delete some contacts to make room.");
        return;
    }
    struct Contact *contact = &contacts[num_contacts++];
    printf("Enter name: ");
    fgets(contact->name, 20, stdin);
    trim(contact->name);
    printf("Enter phone number: ");
    fgets(contact->phone_number, 20, stdin);
    trim(contact->phone_number);
    puts("]] Successfully added contact.");
}

void delete_contact()
{
    if (num_contacts > 0)
    {
        num_contacts--;
        puts("]] Successfully deleted last contact.");
        return;
    }

    puts("]] You don't have any contacts to delete.");
}

void delete_many_contacts()
{
    printf("How many contacts would you like to delete? ");
    int delete_num = read_int();

    if (delete_num > num_contacts)
    {
        puts("]] You don't have that many friends.");
        return;
    }

    num_contacts -= delete_num;
    printf("]] Successfully deleted %d contacts.\n", delete_num);
}

void premium_feature()
{
    system("cat /home/addressbook/flag");
}

void invalid_option()
{
    puts("]] What?");
}

int main()
{
    setup();
    banner();
    memset(contacts, 0, sizeof(contacts));

    while (1)
    {
        menu();
        int choice = get_choice();

        switch(choice)
        {
        case 1:
            list_contacts();
            break;
        case 2:
            add_contact();
            break;
        case 3:
            delete_contact();
            break;
        case 4:
            delete_many_contacts();
            break;
        case 999:
            if (is_premium_user)
                premium_feature();
            else
                invalid_option();
            break;
        default:
            invalid_option();
            break;
        }
    }
    return 0;
}
