/*
 * sakusay.c
 * Sakurako says various things
 */

#include <stdio.h>
#include <unistd.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, "");

    char *saku[11];

    saku[0] = "░░░░░░░░░░░░▄▄▄▀▀▀▀▀▄▄  \n░░░░░░░░▄▄▀▀▒▒▒▒▒▒▒▒▒▒▀▀▄▄▄           \n░░░░░░▄▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▀▀▄       \n░░░░░█▐▒▒▒▐▐▒▒▒▌▐▒▒▌▌▒▒▌▒▒▒▒▀▄░▀▄     \n░░░█▐▄▒▒▒▌▌▒▒▌░▌▒▐▐▐▒▒▐▒▒▌▒▀▄▀▄    \n░░░█▐▒▒▀▀▌░▀▀▀░░▀▀▀░░▀▀▄▌▌▐▒▒▒▌▐      ______________\n░░▐▒▒▀▀▄▐░▀▀▄▄░░░░░░░░░░░▐▒▌▒▒▐░▌    /\n░░▐▒▌▒▒▒▌░▄▄▄▄█▄░░░░░░░▄▄▄▐▐▄▄▀     / ";
    saku[1] = "░░▌▐▒▒▒▐░░░░░░░░░░░░░▀█▄░░░░▌▌      | ";
    saku[2] = "▄▀▒▒▌▒▒▐░░░░░░░▄░░▄░░░░░▀▀░░▌▌     <  ";
    saku[3] = "▄▄▀▒▐▒▒▐░░░░░░░▐▀▀▀▄▄▀░░░░░░▌▌      ";
    saku[4] = "▄▄▀▀▄▒▒▐░░░░░░░▌▒▒▒▒▐░░░░░░▐▒▐      ";
    saku[5] = "░░░░█▌▒▒▌░░░░░▐▒▒▒▒▒▌░░░░░░▌▐▒▀▀▄   ";
    saku[6] = "░░▄▀▒▒▒▒▐░░░░░▐▒▒▒▒▐░░░░░▄█▄▒▐▒▒▒▌  ";
    saku[7] = "▄▀▒▒▒▒▒▄██▀▄▄░░▀▄▄▀░░▄▄▀█▄░█▀▒▒▒▒▐  ";
    saku[8] = "▐▒▒▒▄▄▀██▌░░░▀▀▀▀████░█░░▀█▄▒▒▒▄▀   ";
    saku[9] = "░▀▄▄▐▐▌▐██░░▄░░░▐███░█░░░░░█▄▄▒▌    ";
    saku[10] = "▀▄░░▀▄▀▄▀█▀▀▄▀▄▄██▀▄▀░░░░░▄▀▄░▐▒    ";

    printf("%s", saku[0]);
    
    char in, counter;

    counter = 1;

    while(read(STDIN_FILENO, &in, 1) > 0)
    {
        if(in == '\0')
            break;
        else if(in == '\n')
        {
            if(counter <= 10)
            {
                printf("\n%s", saku[counter++]);
                if(counter > 3)
                    printf("| ");
            }
            else
            {
                counter = 11;
                printf("\n                                    |");
            }
            
        }
            
        else
            printf("%c", in);
    }

    while(counter < 3)
        printf("\n%s", saku[counter++]);

    if(counter < 11)
        printf("\n%s", saku[counter++]);
    else if(counter == 11)
        printf("\n                                    ");
    else
        printf("\n                              ");

    printf("\\_______________");

    while(counter < 11)
        printf("\n%s", saku[counter++]);

    printf("\n");

}
