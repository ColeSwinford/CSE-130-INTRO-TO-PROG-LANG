/*
	Cole Swinford
	Lab 8, Sec. 1
	March 10, 2022
	Phone Book 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char FirstName[100];
    char LastName[100];
    char Number[100];
}Contact;

int run = 1;
int Menu = 1;
int Selection = 0;
int ContactCount = 0;
Contact* ContactBook;


// Menu
int MenuFunct()
{
    // Menu
    printf("\n\n\\\\Phone book application");
    printf("\n1) Add friend");
    printf("\n2) Delete friend");
    printf("\n3) Show phone book\n");
    
    // Menu Input
    printf("Select an input: ");
    scanf("%i", &Selection);
}

// Add friend
int Selection1()
{
    Contact TempContact;

    // Take user inputs
    printf("First Name: ");
    scanf("%s", TempContact.FirstName);

    printf("Last Name: ");
    scanf("%s", TempContact.LastName);

    printf("Phone Number: ");
    scanf("%s", TempContact.Number);

    // Increase array ContactCount
    ContactCount += 1;

    // Reallocate memory
    ContactBook = realloc(ContactBook, ContactCount * sizeof(Contact));
    ContactBook[ContactCount - 1] = TempContact;

    return 0;
}

// Delete friend
int Selection2()
{
    // Enter Name
    printf("First Name: ");
    char SearchFirstName[100];
    scanf("%s", SearchFirstName);

    char SearchLastName[100];
    printf("Last Name: ");
    scanf("%s", SearchLastName);

    // Search for FirstName string
    int f;
    for (f = 0; f < ContactCount; f++)
    {
        if (!strcmp(SearchFirstName, ContactBook[f].FirstName)) 
        {
            break;
        }
    }

    // Search for LastName string
    int L;
    for (L = 0; L < ContactCount; L++)
    {
        if (!strcmp(SearchLastName, ContactBook[L].LastName))
        {
            break;
        }
    }

    // If FirstName is found
    int FirstFound = 0;
    int FirstLocation;
    if (f != ContactCount)
    {
        //printf("%s is present in the array at row %d", SearchFirstName, f);
        FirstFound = 1;
        FirstLocation = f;
        //printf("\n%i", FirstLocation);
    }
    else
    {
        FirstFound = 2;
    }

    // If LastName is found
    int LastFound = 0;
    int LastLocation;
    if (f != ContactCount)
    {
        //printf("\n%s is present in the array at row %d", SearchLastName, L);
        LastFound = 1;
        LastLocation = L;
        //printf("\n%i", LastLocation);
    }
    else 
    {
        LastFound = 2;
    }

    // Act on search results
    if (FirstFound && LastFound == 1)
    {
        // If the First and Last name are found to be in the same element
        if (FirstLocation == LastLocation)
        {
            int remove;
            for (remove = FirstLocation; remove < ContactCount; remove++)
            {
                ContactBook[remove] = ContactBook[remove + 1];
                ContactCount--;
            }

            printf("\nRecord deleted from the phone book");
        }
        
        // If the First and Last name are found to be in different elements
        else
        {
            printf("\nContact not found");
        }
    }

    // If no name is found
    else
    {
        printf("\nContact not found");
    }

    return 0;
}

// Show phone book
int Selection3()
{
    // Print all contacts
    int k;
    for (k = 0; k < ContactCount; k++)
    {
        printf("\n%s %s\t%s", ContactBook[k].FirstName, ContactBook[k].LastName, ContactBook[k].Number);
    }

    return 0;
}                

int main()
{
    while (run == 1)
    {
        // call to Menu
        if(Menu == 1)
        {
            MenuFunct();
        }

        // Call to Selection1
        if (Selection == 1)
        {
            Selection1();
        }

        // Call to Selection2
        if (Selection == 2)
        {
            Selection2();
        }

        // Call to Selection3
        if (Selection == 3)
        {
            Selection3();
        }

    }
    return 0;
}
