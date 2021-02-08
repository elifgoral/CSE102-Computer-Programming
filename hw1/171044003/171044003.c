#include <stdio.h>
#include <math.h>
#define PI 3.14


double circle_area(double radius);
double calc_hypotenuse(int side1,int side2);
double calc_radius_of_smallest_circle(int side1, int side2);
double calc_radius_of_largest_circle(int side1, int side2);
double calc_area_of_smallest_circle(int side1, int side2);
double calc_area_of_largest_circle(int side1,int side2);
double calc_area_of_smallest_square(int side1,int side2);
double calc_area_of_largest_square(int side1, int side2);
double calc_area_of_square(int side);
void display_results(double largest_circle, double largest_square, double smallest_circle, double smallest_square);

int main()
{
   int side1,side2;
   double largest_circle,largest_square,smallest_circle,smallest_square;

   printf("Enter first side of rectangle : ");
   scanf("%d",&side1);
   printf("Enter second side of rectangle: ");
   scanf("%d",&side2);
   largest_circle  = calc_area_of_largest_circle(side1,side2);
   largest_square  = calc_area_of_largest_square(side1,side2);
   smallest_circle = calc_area_of_smallest_circle(side1,side2);
   smallest_square = calc_area_of_smallest_square(side1,side2);

   display_results(largest_circle,largest_square,smallest_circle,smallest_square);

   return 0;

}

double circle_area(double radius)
{
   double area;
   area = PI * pow(radius,2);
   return area;
}

double calc_hypotenuse(int side1,int side2)
{
   double hypotenuse= sqrt(pow(side1,2)+pow(side2,2));
   return hypotenuse;
}


double calc_radius_of_smallest_circle(int side1,int side2)
{
   double hypotenuse = calc_hypotenuse(side1,side2);
   double radius= hypotenuse/2;
   return radius;
}


double calc_radius_of_largest_circle(int side1, int side2) 
{
   double radius;
   if(side1<=side2)
   {
       radius= side1/2.0;
   }

   else if(side2<side1)
   {
       radius= side2/2.0;
   }

   return radius;
}


double calc_area_of_smallest_circle(int side1, int side2)
{
   double radius= calc_radius_of_smallest_circle(side1,side2);
   double area= circle_area(radius);
   return area;
}


double calc_area_of_largest_circle(int side1,int side2)
{
   double radius;
   if(side1<=side2)
   {
       radius= calc_radius_of_largest_circle(side1,side2);
   }

   else if(side2<side1)
   {
       radius= calc_radius_of_largest_circle(side1,side2);
   }

   double area= circle_area(radius);
   return area;
}



double calc_area_of_smallest_square(int side1,int side2)
{
   double area;
   if(side2>side1)
   {
      area= calc_area_of_square(side2);
   }

   else if(side1>side2)
   {
      area= calc_area_of_square(side1);
   }
   return area;
}

double calc_area_of_largest_square(int side1, int side2)
{
   double area;
   if(side1<side2)
   {
      area= calc_area_of_square(side1);
   }

   else if(side1>side2)
   {
      area= calc_area_of_square(side2);
   }
   return area;
}

double calc_area_of_square(int side)
{
   double area=pow(side,2);
   return area;
}

void display_results(double largest_circle, double largest_square, double smallest_circle, double smallest_square)
{
   printf("The area of the largest circle that fits inside a rectangle:		 %.2lf\n",largest_circle);
   printf("The area of the largest square that fits inside a rectangle:		 %.2lf\n",largest_square);
   printf("The area of the smallest circle that surrounds the same rectangle:	 %.2lf\n",smallest_circle);
   printf("The area of the smallest square that surrounds the same rectangle: 	 %.2lf\n",smallest_square);

}
