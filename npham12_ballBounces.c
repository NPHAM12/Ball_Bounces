/* Ball Bounces
   Billy Pham*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 21	/*Size of an array*/

int catch[SIZE];

void histogram();
void get_balls();
int set_balls();

int num, i, j, k;
int number_balls;	/*numbers of balls*/
int hole = 10; 		/*numbers of holes fill balls*/
int counter = 10;	/*numbers of bounces*/

/*calling main function*/
int main()
{
	histogram();
	
return 0;	
}

/* create a number of balls function*/
int set_balls()
{
	/*Asking input*/
	while(number_balls <= 0)
	{
		printf("How many ball to drop?\n");
		scanf("%d", &number_balls); // get numbers of balls
		if(number_balls <= 0)// condition input balls
			printf("Must drop at least one ball\n");
	}
	return number_balls;
}

/*create bounces function to calculate which holes have balls*/
void get_balls()
{	
	set_balls();
	/*Initialize random seed*/
	srand(time(NULL));
	/*get a ball at a hole after 10 times*/
	for(i = 1; i <= number_balls; i++)
	{
		while(counter !=0)
		{
			/* Generate random number to */
			num = rand()%10+1;
			printf("num: %d\n", num); 
			if (num %2 == 0)  /* the ball goes to right*/
			{	
				hole++;
				counter--;
			}
			else /* the ball goes to left*/
			{
				hole--;
				counter--;
			}
			if(counter == 0) /*store the ball in a slot at final bounce*/
			{
				catch[hole]++;
			}
		}
		counter = 10;	/*reset counter*/
		hole = 10;	/*reset hole*/
	}	
}

/*create a bar index*/
void histogram()
{
	get_balls();
	for(i = 0; i < SIZE; i++)
	{
		if (i%2 == 0)
		{
			int j = i - 10;
			printf("%3d: ", j);	// print line by line (even lines)
			if(catch[i] != 0)
				for(k = 0; k<catch[i]; k++)
					printf("o"); // add characters in the current line
			printf("\n");
		}	
	}
}
	
