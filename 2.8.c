// Header


# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main (void) 
{
	float fahr_low, fahr_high, steps, fahr_increment, fahr, degrees_cels, degrees_rank;
	
	printf ("This program converts degrees Fahrenheit to Celsius and Rankin over a range. \n\n");
	printf ("Enter the temperature low range in degrees Fahrenheit: ");
	scanf ("%f", &fahr_low);
	printf ("Enter the temperature high range in degrees Fahrenheit: ");
	scanf ("%f", &fahr_high);
	printf ("Enter the number of calculation steps over the range: ");
	scanf ("%f", &steps);
	
	fahr_increment = (fahr_high - fahr_low) / (steps - 1.0);
	
	printf ("Degrees:   Fahrenheit \t Celsius \t Rankin \n");
	printf ("\t ----------------------------------------------------- \n");
	
	for (fahr = fahr_low; fahr <= fahr_high; fahr += fahr_increment) {
		degrees_cels = (5.0 / 9.0) * (fahr - 32.0);
		degrees_rank = fahr + 459.67;
		
		printf ("\t %7.3f \t %7.3f \t %7.3f \n", fahr, degrees_cels, degrees_rank);
		
	}
	
	
	printf ("\n\n");
	system ("PAUSE");
	return (0);
}
