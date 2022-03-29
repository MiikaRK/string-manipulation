/***************************************************************************
 *   Copyright (C) 2022 by Miika Rinta-Korkeamäki   *
 *   miikark@nic.fi   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME

    String manipulation program

 2.  DESCRIPTION

    User can manipulate string by different commands

 3.  VERSIONS
       Original:
         15.3.2022 / MRK

       Version history:

**********************************************************************/

/*-------------------------------------------------------------------*
 *    HEADER FILES                                                    *
 *--------------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>

/*-------------------------------------------------------------------*
 *    GLOBAL VARIABLES AND CONSTANTS                                  *
 *--------------------------------------------------------------------*/
/* Control flags */

/* Global constants */
#define MAX_USER_INPUT 30

/* Global variables */

/* Global structures */

/*-------------------------------------------------------------------*
 *    FUNCTION PROTOTYPES                                             *
 *--------------------------------------------------------------------*/

char ask_command(void);
int count_vowels(char s[]);
int count_consonants(char s[]);
void to_upper(char s[]);
void to_lower(char s[]);
void print_string(char s[]);
void read_string(char s[]);
void read_file(char s[]);
void write_file(char s[]);
void display_menu(void);

/*********************************************************************
 *    MAIN PROGRAM                                                      *
 **********************************************************************/

int main(void)
{
    char string[MAX_USER_INPUT] = "Hello world";
    int cmd;

    printf("                              _ _ _     _                       _                                          \n");
    printf("                             | | | |___| |___ ___._ _ _ ___   _| |_ ___                                    \n");
    printf("                             | | | / ._| / | / . | ' ' / ._>   | | / . \\                                   \n");
    printf("                             |__/_/\\___|_\\_|_\\___|_|_|_\\___.   |_| \\___/                                   \n");
    printf(" ___    _       _                         _         _       _    _                                         \n");
    printf("/ __> _| |_ _ _<_._ _ ___  ._ _ _ ___._ _<_>___ _ _| |___ _| |_ <_>___._ _   ___ _ _ ___ ___ _ _ ___._ _ _ \n");
    printf("\\__ \\  | | | '_| | ' / . | | ' ' <_> | ' | | . | | | <_> | | |  | / . | ' | | . | '_/ . / . | '_<_> | ' ' |\n");
    printf("<___/  |_| |_| |_|_|_\\_. | |_|_|_<___|_|_|_|  _`___|_<___| |_|  |_\\___|_|_| |  _|_| \\___\\_. |_| <___|_|_|_|\n");
    printf("                     <___'                 |_|                              |_|         <___'              \n\n");

    display_menu();

    cmd = ask_command();

    while (cmd != 'X')
    {
        switch (cmd)
        {
        case 'A':
            printf("String has %d vowels\n", count_vowels(string));
            break;
        case 'B':
            printf("String has %d consonants\n", count_consonants(string));
            break;
        case 'C':
            to_upper(string);
            break;
        case 'D':
            to_lower(string);
            break;
        case 'E':
            print_string(string);
            break;
        case 'F':
            read_string(string);
            break;
        case 'G':
            read_file(string);
            break;
        case 'H':
            write_file(string);
            break;
        case 'M':
            display_menu();
            break;
        default:
            printf(", try again");
            break;
        }

        cmd = ask_command();
    }
} /* end of main */

/*********************************************************************
 *    FUNCTIONS                                                       *
 **********************************************************************/

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void display_menu(void)
 DESCRIPTION: Prints menu
    Input: none
    Output: none
  Used global variables: none
 REMARKS when using this function:
*********************************************************************/

void display_menu(void)
{
    printf("A) Count the number of vowels in the string");
    printf("\nB) Count the number of consonants in the string");
    printf("\nC) Convert the string to uppercase");
    printf("\nD) Convert the string to lowercase");
    printf("\nE) Display the current string");
    printf("\nF) Enter another string");
    printf("\nG) Read string from file");
    printf("\nH) Write string to file");
    printf("\n\nM) Display this menu");
    printf("\nX) Exit the program\n");
}

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: char ask_command(void)
 DESCRIPTION: Asks command from user to program
    Input: none
    Output: s[0]
  Used global variables: none
 REMARKS when using this function:
*********************************************************************/

char ask_command(void)
{
    char s[MAX_USER_INPUT];

    printf("\nEnter command: ");

    fgets(s, MAX_USER_INPUT, stdin);

    s[0] = toupper(s[0]);

    if ((s[0] >= 'A' && s[0] <= 'H') || (s[0] == 'M') || (s[0] == 'X'))
    {
        return s[0];
    }
    else
    {
        printf("Invalid character");
    }
}

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void print_string(char s[])
 DESCRIPTION: Prints stored string
    Input: s[]
    Output: none
  Used global variables: none
 REMARKS when using this function:
*********************************************************************/

void print_string(char s[])
{
    printf("%s", s);
}

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void read_string(char s[])
 DESCRIPTION: Asks new string from user
    Input: s[]
    Output: none
  Used global variables: none
 REMARKS when using this function:
*********************************************************************/

void read_string(char s[])
{
    printf("Give string: ");

    fgets(s, MAX_USER_INPUT, stdin);
}

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: int count_vowels(char s[])
 DESCRIPTION: Counts vowels from stored string
    Input: s[]
    Output: vowels
  Used global variables: none
 REMARKS when using this function:
*********************************************************************/

int count_vowels(char s[])
{
    int i, vowels = 0;

    for (i = 0; s[i] != '\0'; i++)
    {
        char up = toupper(s[i]);

        if (up == 'A' || up == 'E' || up == 'I' || up == 'O' || up == 'U' || up == 'Y')
        {
            vowels++;
        }
    }

    return vowels;
}

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: int count_consonants(char s[])
 DESCRIPTION: Counts consonants from stored string
    Input: s[]
    Output: consonants
  Used global variables: none
 REMARKS when using this function:
*********************************************************************/

int count_consonants(char s[])
{
    int i, consonants = 0;

    for (i = 0; s[i] != '\0'; i++)
    {
        char up = toupper(s[i]);

        if (up == 'B' || up == 'C' || up == 'D' || up == 'F' || up == 'G' || up == 'H' ||
            up == 'J' || up == 'K' || up == 'L' || up == 'M' || up == 'N' || up == 'P' ||
            up == 'Q' || up == 'R' || up == 'S' || up == 'T' || up == 'V' || up == 'W' ||
            up == 'X' || up == 'Z')
        {
            consonants++;
        }
    }

    return consonants;
}

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void to_upper(char s[])
 DESCRIPTION: Turns letters from stored string to uppercase
    Input: s[]
    Output: none
  Used global variables: none
 REMARKS when using this function:
*********************************************************************/

void to_upper(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        s[i] = toupper(s[i]);
    }

    printf("%s", s);
}

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void to_lower(char s[])
 DESCRIPTION: Turns letters from stored string to lowercase
    Input: s[]
    Output: none
  Used global variables:
 REMARKS when using this function:
*********************************************************************/

void to_lower(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        s[i] = tolower(s[i]);
    }

    printf("%s", s);
}

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void read_file(char s[])
 DESCRIPTION: Reads string from a file
    Input: s[]
    Output: none
  Used global variables: none
 REMARKS when using this function:
*********************************************************************/

void read_file(char s[])
{
    FILE *file_pointer;
    file_pointer = fopen("filename.txt", "r");
    fgets(s, MAX_USER_INPUT, file_pointer);
    fclose(file_pointer);
}

/*********************************************************************
    F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void write_file(char s[])
 DESCRIPTION: Writes string from program to a file
    Input: s[]
    Output: none
  Used global variables: none
 REMARKS when using this function:
*********************************************************************/

void write_file(char s[])
{
    FILE *file_pointer;
    file_pointer = fopen("filename.txt", "w");
    fprintf(file_pointer, "%s", s);
    fclose(file_pointer);
}