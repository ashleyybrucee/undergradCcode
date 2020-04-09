// Program name: Required Exercise 1.9
  // 
  // Author: Ashley Bruce
  // Date: 09-11-19
  // Course:  Computer Science 217
  // 
  // 
  // Description: Using linear interpolation on flight path table data
  //               
 
 #include <stdio.h>
 #include <stdlib.h>
 
int main (void)

{
	float angle_one, lift_coefficient_one, angle_two, lift_coefficient_two, new_angle, new_lift_coefficient;
	
	printf ("This program uses linear interpolation to compute the \n");
	printf ("coefficient of lift for an angle from a wind tunnel test \n\n");
	printf ("Use degrees for all angle measurements. \n\n");
	
	printf ("Enter first angle > ");
	scanf ("%f", &angle_one);
	printf ("Enter first lift coefficient > ");
	scanf ("%f", &lift_coefficient_one);
	printf ("Enter second angle > ");
	scanf ("%f", &angle_two);
	printf ("Enter second lift coefficient > ");
	scanf ("%f", &lift_coefficient_two);
	printf ("Enter new angle > ");
	scanf ("%f", &new_angle);
	
	new_lift_coefficient = lift_coefficient_one + (new_angle - angle_one) / (angle_two - angle_one) * (lift_coefficient_two - lift_coefficient_one);
	
	printf ("New lift coefficient: %7.3f \n\n", new_lift_coefficient);
	
	system ("PAUSE");
	return 0;
	
}
