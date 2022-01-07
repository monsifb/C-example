/*
HW2_G01182704.c -- This program will compute the sum of the individual digits
contained within a user-specified integer and will divide this sum by 9 to
determine whether or not the (user-specified) integer is divisible by 9.

AUTHOR: Monsif Bouzana
DATE: 09/20/2021
*/

#include <stdio.h>

int get_input()
{
   int val; //This part prompts the user to enter an integer in the given boundary
   printf("Enter an integer [1,999999]: ");
   scanf("%d",&val);
   return val;
}

void display(int val)
{
    while(val !=0 && val + 0 != 0)
    {
       printf("%d\n",val%10);  //this removes the numbers that are needed and prints them on top of each other accordingly
       val=val/10;
	}
}
void divisibilityCheck(int val) //This part of the code checks if the code is divisible by 9 or not
{ 
   int valcheck=val;
   int val1=0;
   while(val>0 && val != 0)
   {
       val1+=val%10;
       val=val/10; //This is the part that extracts the number and places it in order from bottom to top
   }
   if(val1%9==0)
       printf("%d is divisible by 9\n",valcheck);
   else
       printf("%d is not divisible by 9\n",valcheck);
}

int main()
{
   int val=get_input(); //If the number is out of the bounds of this input, a message will appear
   if(val<1 || val>999999)
   {
       printf("This number is invalid. Please try again.");
       return 0;
   }
   else
   {
       display(val); //This gives the display part and the voided divisibility check access
       divisibilityCheck(val);
   }
}