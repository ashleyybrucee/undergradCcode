 // Program name: Required Exercise 1.6
  // 
  // Author: Ashley Bruce
  // Date: 08-26-19
  // Course:  Computer Science 217
  // 
  // 
  // Description: Using MOD to calculate change
  //               

 #include <stdio.h>
 #include <stdlib.h>
int main (void)

{
	
int int_number, hundreds, twenties, tens, fives, ones, change, quarters, dimes, nickles, pennies;
float float_number;

printf ("Calculate change\n");
printf ("Enter a number >");
scanf ("%f", & float_number);

int_number =float_number;
hundreds = int_number/100;
change = (float_number - int_number) * 100;
int_number = int_number%100;
twenties = int_number/20;
int_number = int_number%20;
tens = int_number/10;
int_number = int_number%10;
fives = int_number/5;
int_number = int_number%5;
ones = int_number;

quarters = change/25;
change = change%25;
dimes = change/10;
change = change%10;
nickles = change/5;
change = change%5;
pennies = change;

printf ("\n\nThe number of hundreds %i \n", hundreds);
printf ("The number of twenties %i \n", twenties);
printf ("The number of tens %i \n", tens);
printf ("The number of fives %i \n", fives);
printf ("The number of ones %i \n", ones);
printf ("The number of quarters %i \n", quarters);
printf ("The number of dimes %i \n", dimes);
printf ("The number of nickles %i \n", nickles);
printf ("The number of pennies %i \n", pennies);

return 0;
}
