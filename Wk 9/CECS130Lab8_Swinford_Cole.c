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
int ExitDialogue = 1;
Contact* ContactBook;


// Menu
int MenuFunct()
{
    // Menu
    printf("\n\n|Phone book");
    printf("\n1) Add friend");
    printf("\n2) Delete friend");
    printf("\n3) Show contacts");
    printf("\n4) Show contacts from file");
    printf("\n5) Alphabetize contacts (by first name)");
    printf("\n6) Search contacts");
    printf("\n7) Show random contact");
    printf("\n8) Delete all contacts");
    printf("\n9) Exit application\n");
    
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

// Show phone book from existing file
int Selection4()
{
    printf("\nFilename (ex. 'contacts.txt'): ");
    char importFile[100];
    scanf("%s", importFile);

    FILE* existingFile = fopen(importFile,"r");
    char f = getc(existingFile);
    while(f != EOF)
    {
        printf("%c",f);
        f = fgetc(existingFile);
    }

    //fclose(importFile);

    return 0;
}

// Alphabetize
int Selection5()
{
    int a = 0;
    int z = 0;
    char tempFirst[ContactCount];
    char tempLast[ContactCount];
    char tempNum[ContactCount];

    // Alphabetize function
    for(a = 0; a < ContactCount -1; a++)
    {
        for(z = a+1; z < ContactCount; z++)
        {
            if(strcmp(ContactBook[a].FirstName, ContactBook[z].FirstName) > 0)
            {
                // Swap
                strcpy(tempFirst, ContactBook[a].FirstName);
                strcpy(tempLast, ContactBook[a].LastName);
                strcpy(tempNum, ContactBook[a].Number);
                strcpy(ContactBook[a].FirstName, ContactBook[z].FirstName);
                strcpy(ContactBook[a].LastName, ContactBook[z].LastName);
                strcpy(ContactBook[a].Number, ContactBook[z].Number);
                strcpy(ContactBook[z].FirstName, tempFirst);
                strcpy(ContactBook[z].LastName, tempLast);
                strcpy(ContactBook[z].Number, tempNum);
            }
        }
    }
    printf("\nAlphabetized");

    return 0;
}

// Search
int Selection6()
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
            printf("\n%s %s: %s", ContactBook[FirstLocation].FirstName, ContactBook[LastLocation].LastName, ContactBook[LastLocation].Number);
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

// Randomly select and display contact
int Selection7()
{
    int RandomTime = rand() % ContactCount;
    RandomTime;
    printf("\n%s %s\t%s", ContactBook[RandomTime].FirstName, ContactBook[RandomTime].LastName, ContactBook[RandomTime].Number);

    return 0;
}

// Delete all contacts
int Selection8()
{
    int del;
    for (del = 0; del < ContactCount; del++)
    {
        memset(ContactBook[del].FirstName, 0, ContactCount);
        memset(ContactBook[del].LastName, 0, ContactCount);
        memset(ContactBook[del].Number, 0, ContactCount);
    }

    int con;
    for (con = 0; con < del; con++)
    {
        ContactCount--;				
    }

    free(ContactBook);
    printf("\nAll contacts deleted");

    return 0;
}

char FileName[200];
char txt[] = ".txt";
char DefaultName[] = "output.txt";
int CustomName = 0;

// Create ContactsFile
int StoreFile() 
{
    FILE* inFile = fopen("input.txt","r");
    FILE* outFile = fopen(FileName,"w");

    int x, numOfLines, i = 0;

    if(inFile != NULL && outFile != NULL)
    {

        fscanf(inFile, "%d", &ContactCount);
        for(i = 0; i < ContactCount; i++)
        {
            fscanf(inFile, "%d", &x);
            fprintf(outFile, "%s %s\t%s\n", ContactBook[i].FirstName, ContactBook[i].LastName, ContactBook[i].Number);
        }
        printf("\n%d lines were written to output file", i);
    }

    else
    {
        printf("\nCannot open one of the files");
    }

    fclose(inFile);
    fclose(outFile);

    return 0;
}

// Exit Application
int Selection9()
{
    Menu = 0;
    printf("\nWould you like to save your contacts list?\n1) Yes\n2) No\n");
    int QuitSelect;
    printf("Select an input: ");
    scanf("%i", &QuitSelect);

    if(QuitSelect == 1)
    {
        printf("\nWould you like to name your save file?\n1) Yes\n2) No\n");
        int SaveSelect;
        printf("Select an input: ");
        scanf("%i", &SaveSelect);

        if(SaveSelect == 1)
        {
            printf("Enter your desired file name: ");
            scanf("%s", FileName);
            printf("You have chosen filename '%s'", FileName);
            strcat(FileName, txt);
            StoreFile();
            printf("\nGoodbye");
            exit(0);
        }
        if(SaveSelect == 2)
        {
            strcpy(FileName, DefaultName);
            StoreFile();
            printf("\nGoodbye");
            exit(0);
        }
    }

    if(QuitSelect == 2)
    {
        printf("\nGoodbye");
        exit(0);
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

		// Call to Selection4
        if (Selection == 4)
        {
            Selection4();
        }

        // Call to Selection5
        if (Selection == 5)
        {
            Selection5();
        }

        // Call to Selection6
        if (Selection == 6)
        {
            Selection6();
        }

        // Call to Selection7
        if (Selection == 7)
        {
            Selection7();
        }

        // Call to Selection8
        if (Selection == 8)
        {
            Selection8();
        }

        // Call to Selection9
        if (Selection == 9)
        {
            Selection9();
        }

    }
    return 0;
}
