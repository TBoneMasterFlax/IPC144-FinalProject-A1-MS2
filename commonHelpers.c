/*
    ==================================================
    Assignment #1 Milestone #2:
    ==================================================
    Name   : Tuan Nguyen
    ID     : 109062166
    Email  : tnguyen140@myseneca.ca
    Section: NFF
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "commonHelpers.h"

#include <time.h>

#include <string.h>

#include <stdlib.h>

// -----------------------------------------
// Function Definitions

// Uses the time.h library to obtain current year information
// Get the current 4-digit year from the system
int currentYear(void)
{
    time_t currentTime = time(NULL);
    return localtime(&currentTime)->tm_year + 1900;
}

// As demonstrated in the course notes: https://ict.senecacollege.ca//~ipc144/pages/content/formi.html#buf
// Empty the standard input buffer
void clearStandardInputBuffer(void)
{
    while (getchar() != '\n')
    {
        ; // On purpose: do nothing 
    }
}

int getInteger()
{
    int intValue;
    char newLine;
    scanf("%d%c", &intValue, &newLine);
    do
    {
        clearStandardInputBuffer();
        printf("ERROR: Value must be an integer: ");
        scanf("%d%c", &intValue, &newLine);
    } while (newLine != '\n');
    return intValue;
}

int getPositiveInteger()
{
    int intValue;
    scanf("%d", &intValue);
    do
    {
        printf("ERROR: Value must be a positive integer greater than zero: ");
        scanf("%d", &intValue);
        clearStandardInputBuffer();
    } while (intValue <= 0);
    return intValue;
}

double getDouble()
{
    double doubleValue;
    char newLine;
    scanf("%lf%c", &doubleValue, &newLine);
    do
    {
        clearStandardInputBuffer();
        printf("ERROR: Value must be a double floating-point number: ");
        scanf("%lf%c", &doubleValue, &newLine);
    } while (newLine != '\n');
    return doubleValue;
}

double getPositiveDouble()
{
    double doubleValue;
    scanf("%lf", &doubleValue);
    do
    {
        printf("ERROR: Value must be a positive double floating-point number: ");
        scanf("%lf", &doubleValue);
        clearStandardInputBuffer();
    } while (doubleValue <= 0);
    return doubleValue;
}

double getPositiveDouble2()
{
    double doubleValue;
    doubleValue = getDouble();
    do
    {
        printf("ERROR: Value must be a positive double floating-point number: ");
        scanf("%lf", &doubleValue);
        clearStandardInputBuffer();
    } while (doubleValue <= 0);
    return doubleValue;
}

int getIntFromRange(int lowerBound, int upperBound)
{
    int intValue;
    char newline;
    int flag = 0;
    do
    {
        flag = 0;
        scanf("%d%c", &intValue, &newline);
        if (newline != '\n')
        {
            clearStandardInputBuffer();
            printf("ERROR: Value must be an integer: ");
            flag = 1;
        }
        else if (intValue < lowerBound || intValue > upperBound)
        {
            printf("ERROR: Value must be between %d and %d inclusive: ", lowerBound, upperBound);
            flag = 1;
        }
    } while (flag == 1);
    return intValue;
}

char getCharOption(char string[])
{
    char ch[31];
    int i;
    int length = strlen(string);
    int flag = 1;
    do
    {
        scanf("%s", ch);
        if (strlen(ch) > 1)
        {
            // Do nothing, don't compare string[] and ch[]
        }
        else
        {
            for (i = 0; i < length; i++)
            {
                if (string[i] == ch[0])
                    flag = 0;
            }
        }
        if (flag == 1)
        {
            printf("ERROR: Character must be one of [%s]: ", string);
        }
        clearStandardInputBuffer();
    } while (flag);
    return ch[0];
}

void getCString(char* string, int lowerBound, int upperBound)
{
    char userString[30];
    int flag = 1;
    int i;
    int userLength;
    do
    {

        scanf("%30[^\n]", userString);
        userLength = strlen(userString);
        if (lowerBound == upperBound && userLength != lowerBound)
        {
            printf("ERROR: String length must be exactly %d chars: ", lowerBound);
        }
        else if (userLength > upperBound)
        {
            printf("ERROR: String length must be no more than %d chars: ", upperBound);
        }
        else if (userLength < lowerBound)
        {
            printf("ERROR: String length must be between %d and %d chars: ", lowerBound, upperBound);
        }
        else
        {
            for (i = 0; i < userLength + 1; i++)
            {
                if (i < userLength + 1)
                {
                    string[i] = userString[i];
                }
                /*else
                {
                    string[i] = '\0';
                }*/
            }
            flag = 0;
        }
        clearStandardInputBuffer();
    } while (flag);
}