 // Program name: Required Exercise 1.7
  // 
  // Author: Ashley Bruce
  // Date: 08-28-19
  // Course:  Computer Science 217
  // 
  // 
  // Description: Breaking down numbers using MOD
  //               

 
 #include <stdio.h>
 #include <stdlib.h>
 
int main (void)

{
	int number_one, number_two, fraction_whole, fraction_numerator;
	float floating_division;
	
	printf ("Divide two whole numbers \n\n");
	printf ("Enter number 1 > ");
	scanf ("%i", &number_one);
	printf ("Enter number 2 > ");
	scanf ("%i", &number_two);
	
	printf ("\n\n");
	
	floating_division = (float)number_one/number_two;
	
	printf ("The floating point result is %f \n", floating_division);
	
	fraction_whole = number_one/number_two;
	fraction_numerator = number_one%number_two;
	
	printf ("\n");
	printf ("The fractional result is %i and %i/%i \n\n", fraction_whole, fraction_numerator, number_two);
	
	system ("PAUSE");
	return 0;
	
}
