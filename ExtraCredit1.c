// Program name: Extra Credit 1.0
  // 
  // Author: Ashley Bruce
  // Date: 09-04-19
  // Course:  Computer Science 217
  // 
  // 
  // Description: Determining if 2 small boxes fit in 1 large box
  //               
 
 #include <stdio.h>
 #include <stdlib.h>
 
int main (void)

{
	int large_box_height, large_box_width;
	int box_A_height, box_A_width;
	int box_B_height, box_B_width;
	
	printf ("Find if 2 small boxes fit in a large box \n\n");
	
	printf ("Enter large box height > ");
	scanf ("%i", &large_box_height);
	printf ("Enter large box width > ");
	scanf ("%i", &large_box_width);
	printf ("\n");
	
	printf ("Enter box A height > ");
	scanf ("%i", &box_A_height);
	printf ("Enter box A width > ");
	scanf ("%i", &box_A_width);
	printf ("\n");
	
	printf ("Enter box B height > ");
	scanf ("%i", &box_B_height);
	printf ("Enter box B width > ");
	scanf ("%i", &box_B_width);
	printf ("\n");
	
	if (((large_box_height >= box_A_height + box_B_height ) && (large_box_width >= box_A_width + box_B_width )) || ((large_box_height >= box_A_width + box_B_height ) && (large_box_width >= box_A_height + box_B_width )))
	{ 
		printf ("They fit ");
		
		if (large_box_height == box_A_height || large_box_height == box_B_height)
		{
			printf ("if box A is above/below box B ");
		}
		
		if (large_box_width = box_A_width || large_box_width == box_B_width)
		{
			printf ("if box A is beside box B ");
		}
		
		if ((box_A_width == box_A_height) && (box_B_width != box_B_height))
		{
			printf (" and if you rotate box B 90 degrees");
		
		}
		
		if ((box_A_width != box_A_height) && (box_B_width == box_B_height))
		{
			printf ("and if you rotate box B 90 degrees");
		}
	}
	else 
	{
		printf ("They don't fit");
	}
	
	printf ("\n");
	system ("PAUSE");
	return 0;

}
