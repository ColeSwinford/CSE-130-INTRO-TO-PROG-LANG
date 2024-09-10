/*
	Cole Swinford
	Lab 7, Sec. 1
	March 3, 2022
	Phone Book 2
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

Contact* ContactBook;


int main()
{
    int run = 1;
    int ContactCount = 0;

    while (run == 1)
    {
        // Menu
        printf("\n\nPhone book application");
        printf("\n1) Add friend");
        printf("\n2) Delete friend");
        printf("\n3) Show phone book");
        printf("\n4) Alphabetize contacts (by first name)");
        printf("\n5) Search contacts");
        printf("\n6) Show random contact");
        printf("\n7) Delete all contacts\n");
        //printf("Number of contacts: %i\n", ContactCount);

        // Menu Input
        int Selection = 0;
        printf("Select an input: ");
        scanf("%i", &Selection);


        // Add friend
        if (Selection == 1)
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
        }

        // Delete friend
        if (Selection == 2)
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

        }

        // Show phone book
        if (Selection == 3)
        {
            // Print all contacts
            int k;
            for (k = 0; k < ContactCount; k++)
            {
                printf("\n%s %s\t%s", ContactBook[k].FirstName, ContactBook[k].LastName, ContactBook[k].Number);
            }
        }

		// Alphabetize
        if (Selection == 4)
        {
            printf("\nAlphabetized");
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
        }

        // Search
        if (Selection == 5)
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
        }

        // Randomly select and display contact
        if (Selection == 6)
        {
        	int RandomTime = rand() % ContactCount;
        	RandomTime;
        	printf("\n%s %s\t%s", ContactBook[RandomTime].FirstName, ContactBook[RandomTime].LastName, ContactBook[RandomTime].Number);
        }

        // Delete all contacts
        if (Selection == 7)
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
        }
    }
    return 0;
}