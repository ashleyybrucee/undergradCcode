// Program name: Required Exercise 2.0B
  // 
  // Author: Ashley Bruce
  // Date: 09-11-19
  // Course:  Computer Science 217
  // 
  // 
  // Description: Modifying the program to calculate the course effeciency at Cuesta
  //               
 
 #include <stdio.h>
 #include <stdlib.h>
 
int main (void)

{
	printf ("This program calculates a Cuesta class efficiency factor \n where 15 and above is considered eficient \n\n");
	
	
	#define OPTIMUM_EFFICIENCY 15
	#define TRUE 1
	#define FALSE 0
	
	float lec_hours, lab_hours;
	int student_number, repeat;
	char quit;
	
	TOP:
	
	repeat = TRUE;
	
	printf ("Enter the number of weekly lecture hours > ");
	scanf ("\n%f", &lec_hours);
	printf ("Enter the number of weekly lab hours > ");
	scanf ("%f", &lab_hours);
	printf ("Enter the number of students in the class > ");
	scanf ("%i", &student_number);
	if (lec_hours + lab_hours == 0) 
	{
		printf ("Lecture hours and lab hours can't add to 0 \n\n");
		goto TOP;
	}
	printf ("\n\n");
	
	float efficiency_coefficient_numerator, efficiency_coefficient_denominator, efficiency_coefficient;
	
	efficiency_coefficient_numerator = (1.0/2.0)*lec_hours + (2.0/3.0)*lab_hours;
	efficiency_coefficient_denominator = lec_hours + lab_hours;
	efficiency_coefficient = efficiency_coefficient_numerator / efficiency_coefficient_denominator;
	printf ("Course Efficiency Coefficient = %.2f \n", efficiency_coefficient);
	
	float efficiency_factor;
	
	efficiency_factor = efficiency_coefficient * student_number;
	printf ("Course Efficiency Factor = %.2f \n", efficiency_factor);
	
	float percent_efficiency;
	
	percent_efficiency = (efficiency_factor / OPTIMUM_EFFICIENCY )* 100;
	printf ("Course Percent Efficiency = %.2f \n\n", percent_efficiency);
	
	printf ("To quit enter Y > ");
	scanf ("\n%c", &quit);
	
	
	if (tolower(quit) == 'y')
	{
		repeat = FALSE;
	}
	if (repeat == TRUE)
	{
		goto TOP;
	}

	system ("PAUSE");
	return 0;

}

