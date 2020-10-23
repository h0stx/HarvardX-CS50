#include <stdio.h>
#include <cs50.h>

//A program that ask the user for their  name and then say hello to them 
int main(void)
{
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}
