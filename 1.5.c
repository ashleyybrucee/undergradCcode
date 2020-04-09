 // Program name: Required Exercise 1.5
  // 
  // Author: Ashley Bruce
  // Date: 08-26-19
  // Course:  Computer Science 217
  // 
  // 
  // Description: Using alignment operators to calculate the sum of Atomic Weights
  //               

 
 #include <stdio.h>
 #include <stdlib.h>
 
int main (void)

{
	const double OXYGEN_WEIGHT = 15.99940;
	const double CARBON_WEIGHT = 12.01100;
	const double NITROGEN_WEIGHT = 14.00674;
	const double SULFUR_WEIGHT = 32.06600;
	const double HYDROGEN_WEIGHT = 1.00794;
	
	double total_weight;
	total_weight = OXYGEN_WEIGHT + CARBON_WEIGHT + NITROGEN_WEIGHT + SULFUR_WEIGHT + HYDROGEN_WEIGHT;
	
	printf ("This program calculates the total atomic weight \n based on the number of atoms of each element \n\n");
	
	int oxygen_atoms, carbon_atoms, nitrogen_atoms, sulfur_atoms, hydrogen_atoms;
	
	printf ("Enter the number of oxygen atoms > ");
	scanf ("%i", &oxygen_atoms);
	printf ("Enter the number of carbon atoms > ");
	scanf ("%i", &carbon_atoms);
	printf ("Enter the number of nitrogen atoms > ");
	scanf ("%i", &nitrogen_atoms);
	printf ("Enter the nuber of sulfur atoms > ");
	scanf ("%i", &sulfur_atoms);
	printf ("Enter the number of hydrogen atoms > ");
	scanf ("%i", &hydrogen_atoms);
	printf ("\n");
	
	int total_atoms;
	total_atoms = oxygen_atoms + carbon_atoms + nitrogen_atoms + sulfur_atoms + hydrogen_atoms;
	
	double subtotal_oxygen, subtotal_carbon, subtotal_nitrogen, subtotal_sulfur, subtotal_hydrogen;
	subtotal_oxygen = oxygen_atoms * OXYGEN_WEIGHT;
	subtotal_carbon = carbon_atoms * CARBON_WEIGHT;
	subtotal_nitrogen = nitrogen_atoms * NITROGEN_WEIGHT;
	subtotal_sulfur = sulfur_atoms * SULFUR_WEIGHT;
	subtotal_hydrogen = hydrogen_atoms * HYDROGEN_WEIGHT;
	
	double subtotal_weight;
	subtotal_weight = subtotal_oxygen + subtotal_carbon + subtotal_nitrogen + subtotal_sulfur + subtotal_hydrogen;
	
	
	
	printf ("Element \t Atomic Weight \t No# of Atoms \t\t Subtotals \n");
	printf ("__________________________________________________________________\n");
	printf ("Oxygen \t\t %10f \t      %i \t\t %9.5f \n", OXYGEN_WEIGHT, oxygen_atoms, subtotal_oxygen);
	printf ("Carbon \t\t %10f \t      %i \t\t %9.5f \n", CARBON_WEIGHT, carbon_atoms, subtotal_carbon);
	printf ("Nitrogen \t %10f \t      %i \t\t %9.5f \n", NITROGEN_WEIGHT, nitrogen_atoms, subtotal_nitrogen);
	printf ("Sulfur \t\t %10f \t      %i \t\t %9.5f \n", SULFUR_WEIGHT, sulfur_atoms, subtotal_sulfur);
	printf ("Hydrogen \t %10f \t      %i \t\t %9.5f \n", HYDROGEN_WEIGHT, hydrogen_atoms, subtotal_hydrogen);
	printf ("__________________________________________________________________ \n");
	printf ("Totals \t\t %10f \t      %i \t\t %9.5f \n\n", total_weight, total_atoms, subtotal_weight);
	system ("PAUSE");
	
	return 0;
}

