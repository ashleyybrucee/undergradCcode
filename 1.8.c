// Program name: Required Exercise 1.8
  // 
  // Author: Ashley Bruce
  // Date: 08-28-19
  // Course:  Computer Science 217
  // 
  // 
  // Description: Creating a program to calculate the course effeciency at Cuesta
  //               
 
 #include <stdio.h>
 #include <stdlib.h>
 
int main (void)

{
	printf ("This program calculates a Cuesta class efficiency factor \n where 15 and above is considered eficient \n\n");
	
	const int OPTIMUM_EFFICIENCY = 15;
	float lec_hours, lab_hours;
	int student_number;
	
	printf ("Enter the number of weekly lecture hours > ");
	scanf ("%f", &lec_hours);
	printf ("Enter the number of weekly lab hours > ");
	scanf ("%f", &lab_hours);
	printf ("Enter the number of students in the class > ");
	scanf ("%i", &student_number);
	printf ("\n\n");
	
	float efficiency_coefficient_numerator, efficiency_coefficient_denominator, efficiency_coefficient;
	efficiency_coefficient_numerator = (1.0/2.0)*lec_hours + (2.0/3.0)*lab_hours;
	efficiency_coefficient_denominator = lec_hours + lab_hours;
	efficiency_coefficient = efficiency_coefficient_numerator / efficiency_coefficient_denominator;
	printf ("Course Efficiency Coefficient = %f \n", efficiency_coefficient);
	
	float efficiency_factor;
	efficiency_factor = efficiency_coefficient * student_number;
	printf ("Course Efficiency Factor = %f \n", efficiency_factor);
	
	float percent_efficiency;
	percent_efficiency = efficiency_factor / OPTIMUM_EFFICIENCY * 100;
	printf ("Course Percent Efficiency = %f \n", percent_efficiency);
	
	system ("PAUSE");
	return 0;
}