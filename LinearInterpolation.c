// Program Name: Extra Credit Exercise 4.0
// Author: Ashley Bruce
// Date: 12-8-19
// Description: Using linear interpolation from tunnel.txt

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 22

int search (float array [SIZE], float value);
void linearInterpolation (float lift_angle [SIZE], float lift_coefficient [SIZE], float userAngle);

int main (void) {
	
	#define FILENAME "tunnel.txt"
	#define FOREVER 1
	
	float lift_angle [SIZE];
	float lift_coefficient [SIZE];
	float angle, userAngle;
	float coefficient, foundCoefficient;
	
	FILE *tunnel;
	tunnel = fopen (FILENAME, "r");
	
	int i = 0;
	
	while (!feof (tunnel)) {
		fscanf (tunnel, "%f %f", &angle, &coefficient);
		lift_angle [i] = angle;
		lift_coefficient [i] = coefficient;
		i++;
	}
	
	while (FOREVER == 1) {
		printf ("Enter lift angle between -4 and 18 degrees > ");
		scanf ("%f", &userAngle);
		
		if (userAngle < -4 || userAngle > 18) {
			printf ("Lift angle out of range, cannot interpolate. \n\n");
		}
		
		else {
			int index = search (lift_angle, userAngle);
			if (index >=0) {
				foundCoefficient = lift_coefficient [index];
				printf ("Inputted angle %g and Coefficient of lift %.3f \n\n", userAngle, foundCoefficient);
			}
			else {
				linearInterpolation (lift_angle, lift_coefficient, userAngle);
			}
		}
		
	}
	
	return (0);
}

int search (float array [SIZE], float value) {
	int i;
	for (i=0; i < SIZE; i++) {
		if (array [i] == value)
			return i;
	}
	return -1;	
}

void linearInterpolation (float lift_angle [SIZE], float lift_coefficient [SIZE], float userAngle) {
	int i;
	int lowerI, upperI;
	for (i = 0; i < SIZE -1; i ++) {
		if (userAngle > lift_angle [i] && userAngle < lift_angle [i+1]) {
			lowerI = i;
			upperI = i+1;
		}
	}
	
	float upperAngle = userAngle - lift_angle [lowerI];
	float lowerAngle = lift_angle[upperI] - lift_angle [lowerI];
	
	float calcCoefficient = lift_coefficient [lowerI] + (upperAngle/lowerAngle) * (lift_coefficient[upperI] - lift_coefficient [lowerI]);
	
	printf ("Interpolated Angle between %g and %g - Coefficient of lift %.3f \n\n", lift_angle[lowerI], lift_angle[upperI], calcCoefficient);
		
}
