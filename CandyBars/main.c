// Sharon Tender
// May 8, 2015
// Final Project
// Requirements: Design your own program. Make sure the program includes the 
// following concepts of C language:
// Variable declaration; Data types: integer, float, character, CONSTANTS
// One dimensional Array
// User defined functions. Make sure you have at least ONE of the following:
// Function that accepts array as an argument, 
// Function that does not return a value,
// Function that does return a value
// Structures: Selection, Repeat, Definite, Indefinite. Switch Statement

#include <stdio.h>
#include <ctype.h>
#define LBS_TO_KG 0.45

// function prototype
int caloriesCalc(int, float, float);

// function that returns a value
int calorieCalc(int caloriesInteger, float metFloat, float weightInKgFloat) {
    int minutesInteger;
    minutesInteger = (caloriesInteger * 200) / (metFloat * 3.5 * weightInKgFloat);
    return (minutesInteger);
}

int main() {
    // variable declaration
    int weight, counter=0, calories, caloriesArray[counter], items;
    int numMinutes;
    float weightInKg, met;
    char selection;

    // Describe the program to the user
    // prompt user to enter number of sweet foods to calculate for
    printf("\n  -------------- BURNING CALORIES ---------------");
    printf("\n  This program will calculate the number ");
    printf("\n  of minutes you need to exercise in ");
    printf("\n  order to burn off the calories in ");
    printf("\n  a candy bar or dessert.");
    printf("\n  -----------------------------------------------\n");
    printf("\n  Enter the number of sweets you would ");
    printf("\n  like to calculate the values for --> ");
    scanf("%d", &items);

    // loop through number of sweets user specified above to prompt for
    // the number of calories in each one. Store results into an array.
    for (counter=0; counter < items; counter++) {
        printf("\n  Enter the number of calories sweet #%d has --> ", counter+1);
        scanf("%d", &caloriesArray[counter]);
    }

    // prompt user for weight to determine which metabolic rate to use
    // in calculating exercise routine.
    printf("\n  Enter your weight: ");
    scanf("%d", &weight);

    // Error handling for invalid user input
    if ((weight >=100) && (weight<=300)) {
            weightInKg = weight * LBS_TO_KG;
    } else {
            do {
                    printf("\n  Your weight is out of range. Please enter a weight ");
                    printf("\n  that is between 100 to 300lbs: ");
                    scanf("%d", &weight);
                    weightInKg = weight * LBS_TO_KG;
            } while (weight < 100 || weight > 300);
    }

    // Prompt use for selecting an activity to participate in for the switch stmt.
    printf("\n  Which activity would you rather participate in?");
    printf("\n  Please enter the letter next to activity. ");
    printf("\n  A) Running - 4 mph");
    printf("\n  B) Walking - 2 mph");
    printf("\n  C) Bowling");
    printf("\n  D) Quiditch\n");
    printf("\n  Your Selection is --> ");
    scanf("\n%c", &selection);
    selection = toupper(selection);
    
    // Switch statement for determining which metabolic rate to use
    switch (selection) {
            case 'A':
                    met = 6.0;
                    break;
            case 'B':
                    met = 2.8;
                    break;
            case 'C':
                    met = 3.8;
                    break;
            case 'D':
                    met = 8.0;
                    break;
            default:
                    printf("\n  Since you made an invalid selection, ");
                    printf("\n  the computer has made a choice of ");
                    printf("\n  Quiditch for you.");
                    met = 8.0;
                    break;
    }

    // loop through each sweet to display the number of minutes user would 
    // have to exercise to burn off the calories
    counter = 0;
    while (counter < items) {
            calories = caloriesArray[counter];
            numMinutes = calorieCalc(calories, met, weightInKg);
            printf("\n  Sweet #%d has %d calories. You will ", counter +1, calories);
            printf("\n  need to workout for %d minutes.\n", numMinutes);
            counter++;
    }
    printf("\n  ------------------- end ------------------------\n");

    return 0;
}