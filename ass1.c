/*
Author: Sharon Lee
Assignment 1: To input sales info for each salesman
   and the amount of products sold. The costs or
   purchases are dynamic numbers.
*/

//Standard library inclusion
#include<stdio.h>

//Constants for the arrays
#define SALESPERSON 4
#define PRODUCT 5

//Defined method to get sales information
void getSalesInfo(float salesInfo[SALESPERSON][PRODUCT]);
//Defined method to calculate product sales amount
void productCal(float salesInfo[SALESPERSON][PRODUCT]);
//Defined method to print result
void printSales(float salesInfo[SALESPERSON][PRODUCT]);

//The main function of the entire program
int main() 
{

   //The primary array for all sales data initialized
   float salesInfo[SALESPERSON][PRODUCT]={{0},{0},{0},{0}};
   
   //Method to get all of the sales data from the array above
   getSalesInfo(salesInfo);
   
   //Method for printing all of the arrays data
   printSales(salesInfo);
   return 0;

}

//Method to get all of the sales data from the array
void getSalesInfo(float salesInfo[SALESPERSON][PRODUCT])
{

   //size_t to use an unsigned integer type
   size_t row, col;

   //First prompt for product purchases
   puts("\nPlease Enter Total sales values for each salesperson and each produce \n");

   //For loop to iterate over inputting of values
	for (row = 0; row < SALESPERSON; row++)
	   {
	      for (col = 0; col < PRODUCT; col++)
	      {

	    //Prompt to represent sales person and prdouct selling
	    printf("SalesPerson %Zu Product %Zu : ", row, col);
	    scanf("%f", &salesInfo[row][col]);
	      }
	   }
	puts(" ");
}

//Calculates product sales through the productAmount variable
void productCal(float salesInfo[SALESPERSON][PRODUCT])
{
   //size_t to use an unsigned integer type
   size_t row, col;

   //variable for total product amount
   float productAmount;

   //For loop to add to itself
   for (col = 0; col < PRODUCT; col++)
   {

      //Initializing variable product amount
      productAmount = 0;

      // calculate each product sales amount
      for (row = 0; row < SALESPERSON; row++)
      {
         productAmount = productAmount + salesInfo[row][col];
      }
     
      //Prints amount with two decimal places
      printf("\t%.2f", productAmount);

   }
   puts(" ");	
}

//Method for printing results to the screen
void printSales(float salesInfo[SALESPERSON][PRODUCT])
{

   //size_t to use an unsigned integer type
   size_t row, col;

   //Float variable for personal amount of sales
   float personAmount;
   puts("The total sales for each salespersn are displayed at the end of each row, and the total sales for each product are displayed at the bottom of each column.");
   puts(" ");
   
   //Loop for printing each product title
   for (col = 0; col < PRODUCT; col++)
   {
      printf("\t%d", col);
   }
   puts(" ");

   //Loop for printing results
   for (row = 0; row < SALESPERSON; row++)
   {
      personAmount = 0;
      printf("%Zu: \t", row);
      for (col=0; col<PRODUCT; col++)
      {

         //Loop for printing results
         printf("%.2f \t", (double)salesInfo[row][col]);
	 // calculate sales amount for each salesperson
         personAmount = personAmount + salesInfo[row][col];
      }
        
      //Formatting to two decimal places to print out each person amount
      printf("%.2f", personAmount);
      puts(" ");
   }

   //Method for calculating sums of sales by product
   productCal(salesInfo);
   puts(" ");	
}

