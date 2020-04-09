#include <stdio.h>
#include <stdlib.h>

int main(void)

{
	float degrees_celsius, degrees_farenheit, degrees_rankin;
	
	printf ("This program converts degrees Celsius to degrees Rankin \n\n");
	printf ("Enter the temperature in degrees Celsius > ");
	scanf ("%f", &degrees_celsius);
	
	degrees_farenheit = (9.0/5.0) * degrees_celsius + 32;
	degrees_rankin = degrees_farenheit + 459.67;
	
	printf ("\n");
	printf ("%.3f degrees Celsius = %.3f degrees Rankin", degrees_celsius, degrees_rankin);
	printf ("\n\n");
	
	system ("PAUSE");
	return 0;
	
}
