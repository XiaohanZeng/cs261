#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"
#include <assert.h>
#include <math.h>


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	/* FIXME: You will write this function */

	double  i = 0;
	double t = 0;
	double sum = 0;
	assert(sizeDynArr(stack) >= 2);
	i = topDynArr(stack);
	popDynArr(stack);
	t =topDynArr(stack);
	popDynArr(stack);
	sum = i+t;
	pushDynArr(stack, sum);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double i = 0;
	double t = 0;
	double sub = 0;
	assert(sizeDynArr(stack) >= 2);
	i = topDynArr(stack);
	popDynArr(stack);
	t =topDynArr(stack);
	popDynArr(stack);
	sub = t-i;
	pushDynArr(stack, sub);

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double i = 0;
	double t = 0;
	double div  = 0;
	assert(sizeDynArr(stack) >= 2);
	i = topDynArr(stack);
	popDynArr(stack);
	t =topDynArr(stack);
	popDynArr(stack);
	div = t / i;
	pushDynArr(stack, div);

}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;
	char *error;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];
		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			/* FIXME: replace printf with your own function */
		{	
			double i = 0;
			double t = 0;
			double multi  = 0;
			if(sizeDynArr(stack) >= 2)
			{
				i = topDynArr(stack);
				popDynArr(stack);
				t =topDynArr(stack);
				popDynArr(stack);
				multi = t*i;
				pushDynArr(stack, multi);
				printf("Multiplying\n");
			}
			else
			{
				error = "not enough number for miltiplying";
			}
		}
		else if(strcmp(s, "^") == 0)
			/* FIXME: replace printf with your own function */
		{
			double i = 0;
			double t = 0;
			double power  = 0;
			if(sizeDynArr(stack) >= 2)
			{
				i = topDynArr(stack);
				popDynArr(stack);
				t =topDynArr(stack);
				popDynArr(stack);
				power = pow(t,i);
				pushDynArr(stack, power);
				printf("Power\n");
			}
			else
			{
				error = "not enough number for Power";
	
			}

		}
		else if(strcmp(s, "^2") == 0)
			/* FIXME: replace printf with your own function */
		{
			double i = 0;
			double squ  = 0;
			assert(sizeDynArr(stack) >= 1);
			i = topDynArr(stack);
			popDynArr(stack);
			squ = pow(i,2);
			pushDynArr(stack, squ);
			printf("Squaring\n");
		}
		else if(strcmp(s, "^3") == 0)
			/* FIXME: replace printf with your own function */
		{
			double i = 0;
			double cub  = 0;
			assert(sizeDynArr(stack) >= 1);
			i = topDynArr(stack);
			popDynArr(stack);
			cub = pow(i,3);
			pushDynArr(stack, cub);
			printf("Cubing\n");
		}
		else if(strcmp(s, "abs") == 0)
			/* FIXME: replace printf with your own function */
		{
			double i = 0;
			double absNumber  = 0;
			assert(sizeDynArr(stack) >= 1);
			i = topDynArr(stack);
			popDynArr(stack);
			absNumber = abs(i);
			pushDynArr(stack, absNumber);
			printf("Absolute value\n");
		}
		else if(strcmp(s, "sqrt") == 0)
			/* FIXME: replace printf with your own function */
		{
			double i = 0;
			double sqrtNumber  = 0;
			assert(sizeDynArr(stack) >= 1);
			i = topDynArr(stack);
			popDynArr(stack);
			sqrtNumber = sqrt(i);
			pushDynArr(stack, sqrtNumber);
			printf("Square root\n");
		}
		else if(strcmp(s, "exp") == 0)
			/* FIXME: replace printf with your own function */
		{
			double i = 0;
			double exp  = 0;
			assert(sizeDynArr(stack) >= 1);
			i = topDynArr(stack);
			popDynArr(stack);
			exp = pow(i,2.7182818);
			pushDynArr(stack, exp);
			printf("Exponential\n");
		}
		else if(strcmp(s, "ln") == 0)
			/* FIXME: replace printf with your own function */
		{
  			double i = 0;
			double ln  = 0;
			assert(sizeDynArr(stack) >= 1);
			i = topDynArr(stack);
			popDynArr(stack);
			ln = log(i);
			pushDynArr(stack, ln);
			printf("Natural Log\n");
		}
		else if(strcmp(s, "log") == 0)
			/* FIXME: replace printf with your own function */
		{
	 		double i = 0;
			double log  = 0;
			assert(sizeDynArr(stack) >= 1);
			i = topDynArr(stack);
			popDynArr(stack);
			log = log10(i);
			pushDynArr(stack, log);
			printf("Log\n");
		}
		else 
		{
			// FIXME: You need to develop the code here (when s is not an operator)
			// Remember to deal with special values ("pi" and "e")
			double add = 0;
			if(strcmp(s, "pi"))
			{
				add = 3.14159265;
			}
			else if(strcmp(s, "e"))
			{
				add = 2.7182818;
			}
			else
			{
				assert( isNumber(s, &add)> 0);
				
			}
			pushDynArr(stack,add);
		}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
	
	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	calculate(argc,argv);
	return 0;
}
