// area_two_ellipses.cpp : Defines the entry point for the console application.
//
//Calculate the area enclosed between the two ellipses, to 4 decimal places
// C++ program to implement Trapezoidal rule
#include "stdafx.h"
#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
// A function whose definite integral's
// approximate value is computed using Trapezoidal rule
float x1 = 0.2314;//first four digits of id
float x2 = 0.1168;//last four digits of id
//
float y1(float x)
{
	// Declaring the function f(x) = y=√((1 -(x-0.2314)^2)/2)  
	return sqrt((1-pow((x - x1),2))/2);
}

float y2(float x)
{
	// Declaring the function f(x) = y=√((1 -(x+0.1168)^2)/2)  
	return sqrt((1 - pow((x + x2), 2))/4);
}
// Function to evalute the value of integral
float trapezoidal_1(float a, float b, float n)
{
	// Grid spacing
	float h = (b - a) / n;

	// Computing sum of first and last terms
	// in above formula
	float s = y1(a) + y1(b);

	// Adding middle terms in above formula
	for (int i = 1; i < n; i++)
		s += 2 * y1(a + i * h);

	// h/2 indicates (b-a)/2n. Multiplying h/2
	// with s.
	return (h / 2)*s;
}

float trapezoidal_2(float a, float b, float n)
{
	// Grid spacing
	float h = (b - a) / n;

	// Computing sum of first and last terms
	// in above formula
	float s = y2(a) + y2(b);

	// Adding middle terms in above formula
	for (int i = 1; i < n; i++)
		s += 2 * y2(a + i * h);

	// h/2 indicates (b-a)/2n. Multiplying h/2
	// with s.
	return (h / 2)*s;
}
// Driver program to test above function
int main()
{
	float x1 = 0.2314;//first four digits of id
	float x2 = 0.1168;//last four digits of id
	// Range of definite integral
	float a1 = -0.7686;//[-0.7686, -0.535069]
	float b1 = -0.535069;

	float a2 = -0.535069;//[ -0.535069,0.8312]
	float b2 = 0.8312;

	// Number of grids. Higher value means
	// more accuracy
	int n = 6;
	for (int i = 10; i <= 1e4;i+=10) {
		cout << i << endl;

		printf("Value of integral_1 is %6.4f\n",
			trapezoidal_1(a1, b1, i));
		printf("Value of integral_2 is %6.4f\n",
			trapezoidal_2(a2, b2, i));
		printf("Value of (I1+I2)*2 is %6.4f\n",
			(trapezoidal_1(a1, b1, i)+trapezoidal_2(a2, b2, i))*2);
		printf("\n");
	}
	
	system("pause");
	return 0;
}