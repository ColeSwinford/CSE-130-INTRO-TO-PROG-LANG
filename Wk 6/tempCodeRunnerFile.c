    // Input
    int Selection = 0;
    scanf()

    struct Contact c[1];
    int i;
    for (i = 0; i < 1; i++)
    {
        printf("Enter name: ");
        scanf("%s", &c[i].Name);
//        printf("Name: %s", c[i].Name);

        printf("\nEnter phone number: ");
        scanf("%s", &c[i].Number);
//        printf("Number: %s", c[i].Number);
        printf("\n%s    %s", c[i].Name, c[i].Number);
    }