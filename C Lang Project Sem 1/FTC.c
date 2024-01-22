#include <stdio.h>

// Function Declarations
float BMI(float, float);
int MC(float);
void read_file(char *file);

// Global Variables
float wt, ht, bmi;

// Main Function
int main()
{
    // Part 1
    printf("********** Welcome to Fitness Tracking System **********\n\n");
    printf("Enter your name : ");
    char name[50];
    scanf("%s", name);
    printf("\nHello %s \n\n", name);

    // Part 2
    int num;
    float wt, ht, bmi, mc;

    do
    {
        printf("\t********** MENU **********\n\n");
        printf("1) What is this Fitness Tracking System and how to use it?\n");
        printf("2) To Calculate Body Mass Index(BMI)\n");
        printf("3) How to calculate your present Maintenance Calories?\n");
        printf("4) How to calculate calories of different foods\n");
        printf("5) How to follow Diet and Nutrition\n");
        printf("6) Which Physical activity can be Done?\n");
        printf("7) Exit Program\n\n");
        printf("Enter the respective number according to your choice : ");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            printf("1) \n");
            read_file("intro.txt");
            break;

        case 2:
            printf("2) ");
            bmi = BMI(wt, ht);
            break;

        case 3:
            printf("3) ");
            mc = MC(wt);
            break;

        case 4:
            printf("4)");
            FILE *fp2;
            fp2 = fopen("ccal.txt", "r");
            int ch;

            while ((ch = fgetc(fp2)) != EOF)
            {
                printf("%c", ch);
            }
            fclose(fp2);
            break;

        case 5:
            printf("5) ");
            FILE *fp3;
            fp3 = fopen("diet.txt", "r");
            int ch2;

            while ((ch2 = fgetc(fp3)) != EOF)
            {
                printf("%c", ch2);
            }
            fclose(fp3);
            break;

        case 6:
            printf("6) ");
            FILE *fp4;
            fp4 = fopen("exercise.txt", "r");
            int ch3;

            while ((ch3 = fgetc(fp4)) != EOF)
            {
                printf("%c", ch3);
            }
            fclose(fp4);
            break;

        case 7:
            printf("\n***** End of Program *****\n\n");
            break;

        default:
            printf("invalid choice, Enter a Valid number\n\n\n");
        }
    } while (num != 7);

    return 0;
}

// BMI Function
float BMI(float wt, float ht)
{
    float bmi;
    printf("\nEnter your weight in kg and height in meters\n");
    scanf("%f %f", &wt, &ht);
    bmi = wt / (ht * ht);

    if (bmi < 18.5)
    {
        printf("You are under weight\n\n");
    }

    else if (bmi > 18.5 && bmi < 24.9)

    {
        printf("Your Physique is Absolutely perfect\n\n");
    }
    else if (bmi > 25.0 && bmi < 29.9)

    {
        printf("You are OverWeight\n\n");
    }

    else if (bmi > 30.0 && bmi < 34.9)

    {
        printf("You are obese\n\n");
    }

    else if (bmi > 35.0 && bmi < 39.9)

    {
        printf("You are Heavily obese\n\n");
    }

    else

    {
        printf("You have severe morbid obesity\n\n");
    }
}

// Maintenance Calorie Calculator Function
int MC(float wt)
{
    int mc;
    printf("Enter your weight in kg and height in meters : ");
    scanf("%f%f", &wt, &ht);
    bmi = wt / (ht * ht);
    printf("Your weight in kg is %f\n", wt);
    wt = wt * 2.20462; // converting kg to pounds
    printf("Your weight in pounds is %f\n", wt);

    mc = wt * 15; // Calculating maintenance calories
    printf("Your present Maintenance Calories are %d\n", mc);
    printf("These are the calories that you should consume in a day\n");

    printf("Your current BMI is %f , So\n", bmi);

    if (bmi < 18.5)
    {
        printf("You should Gain Weight in order to stay healthy\n");
        mc = mc + 200;
        printf("To gain weight you should eat more than your maintenance calories\n");
        printf("So your Total calories to be consumed in a day are %d\n\n\n", mc);
    }
    else if (bmi > 18.5 && bmi < 25)
    {
        printf("You should Maintain your weight in order to stay healthy\n");
        printf("To Maintain your weight you should eat the same amount as your maintenance calories\n");
        printf("So your Total calories to be consumed in a day are %d\n\n\n", mc);
    }
    else
    {
        printf("You should Loose weight in order to stay healthy\n");
        mc = mc - 200;
        printf("To Loose weight you should eat less than your maintenance calories\n");
        printf("So your Total calories to be consumed in a day are %d\n\n\n", mc);
    }

    return mc;
}

// Introduction File Function 1
void read_file(char *file)
{
    FILE *fp1;
    fp1 = fopen("intro", "r");
    int ch;
    while ((ch = fgetc(fp1)) != EOF)
    {
        printf("%c", ch);
    }
    fclose(fp1);
}
