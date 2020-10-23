#include <stdio.h> //declare STDIO library
#include <cs50.h> //declare CS50 library

void mario_pyramid(int x);

// ask for the mario pyramid height
int main(void)
{
    int height = 0;
    // ask  for height with a condition : (height is correct number between 1 and 8)
    do
    {
        height = get_int("Height: ");
    }
    //this is the height number condition
    while (!(height >= 1 && height <= 8));

    mario_pyramid(height);
}

// generates a ramp of hashes x tall and as large as the line number (i)
void mario_pyramid(int x)
{
    for (int i = 0; i < x; i++)
    {
        // in the first , print just emty spaces
        for (int a = x - i - 2; a >= 0; a--) //"a" is the number of " "
        {
            printf(" ");
        }
        // then the hashes
        for (int b = 0; b <= i; b++) //"b" is the number of "#"
        {
            printf("#");
        }
        // make a backlines
        printf("\n");
    }
}
