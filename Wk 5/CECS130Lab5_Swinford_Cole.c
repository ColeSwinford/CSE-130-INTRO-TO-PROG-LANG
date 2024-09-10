/*
	Cole Swinford
	Lab 5, Sec. 1
	January 10, 2022
	Interactive Story
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Get name
    char name[100];
    printf("What is your name? ");
    scanf("%s", name);

    // Get age
    int age;
    printf("\nHow old are you? ");
    scanf("%i", &age);

    // Get favorite color
    char color[100];
    printf("\nWhat's your favorite color? ");
    scanf("%s", color);

    // Get favorite car
    char car[100];
    printf("\nWhat's your favorite car company? ");
    scanf("%s", car);

    // Get location
    char location[100];
    printf("\nWhere do you live? ");
    scanf("%s", location);

    // Sentence 1
    char *beginninng1[3] = {"Once upon a time, there was a brave traveler named", "Once upon a midnight dreary, there was a strange homeowner named", "Before there were such things as computers or the internet, we had"};
    srand(time(0));
    int randChoice1 = rand() % 3;

    char *following1[3] = {"who would constantly flaunt their affinity for the color", "who loved their spouse less than the color", "who insisted that the entire earth be painted"};
    int randChoice2 = rand() % 3;

    printf("\n%s %s, %s %s.", beginninng1[randChoice1], name, following1[randChoice2], color);

    // Sentence 2
    char *beginning2[2] = {"Despite being at the ripe old of age of", "At"};
    int randChoice3 = rand() % 2;

    char *following2[2] = {"they bought their first car!", "they conquered the world with nothing but chopsticks, then spent the newly-found riches on a car!"};
    int randChoice4 = rand() % 2;

    printf("\n%s %i, %s ", beginning2[randChoice3], age, following2[randChoice4]);

    // Sentence 3
    char *beginning3[2] = {"One day, their brand new", "However, things would go downhill fast. Their sparkling new"};
    int randChoice5 = rand() % 2;

    char *following3[2] = {"would succumb to the ocean after a miscalculation.", "was stolen by a gang of poor college students!"};
    int randChoice6 = rand() % 2;

    printf("%s %s %s ", beginning3[randChoice5], car, following3[randChoice6]);

    printf("So, they retired and went into hiding, in %s, where they now reside for eternity.", location);
/*
    char *card[4] = {"Club", "Diamond", "Heart", "Spade"};

    srand(time(0));

    int randChoice = rand() % 4;
    printf("Hi, %s, you got a %s!", name, card[randChoice]);
*/

    return 0;
}
