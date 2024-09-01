/*
dealership.cpp
Murtaza Amjad & Richard Hurley
3/31/2023
This is where the Constructor is initialzed and where the functions are made
using the class.
*/

#include "dealership.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

#define OUTF "output.txt"

using namespace std;

/*
Murtaza Amjad
Constructor Car(string itsmodel, string itscondition, double itsprice, string
itscolor, int itsyear, string dateofpurchase).
This constructor initializes Car object with model of the car, condition of the
car, price of the car, color of the car, the year that car was made, and the
date the car was purchased.
*/
Car::Car(string itsmodel, string itscondition, double itsprice, string itscolor,
         int itsyear, string dateofpurchase) {

  model = itsmodel;

  condition = itscondition;

  price = itsprice;

  color = itscolor;

  year = itsyear;

  day_month_year = dateofpurchase;
}

// Richard Hurley
// function isDate(string dateofpurchase)
// compares date of the purchase and the day the car was bought, it is used in
// the search function to find a car based on the date the car was bought, the
// function returns dateofpurcahse == day_month_year
bool Car::isDate(string dateofpurchase) {
  return dateofpurchase == day_month_year;
}

// Richard Hurley
// function toString()
// combines all the information of the car, model, condition, price, color, the
// year, and date it was purchased into the string variable called str, the
// returns the variable str.
string Car::toString() {

  char prices[10];

  snprintf(prices, sizeof(prices), "%.2f", price);

  string str = model + " " + condition + " " + prices + " " + color + " " +
               to_string(year) + " " + day_month_year;

  return str;
}

/*
Murtaza Amjad
Function toFile().
This function writes the features of the car to the file and then it returns it
as a string.The price is set to show only 2 decimal places. The function has no
parameters and returns a string.
*/
string Car::toFile() {

  char prices[10];

  sprintf(prices, "%.2f", price);

  string str = "Model : " + model + ", Condition : " + condition +
               ", Price : " + prices + ", Color : " + color +
               ", Year : " + to_string(year) +
               ", Date of Purchase : " + day_month_year;

  return str;
}

/*
Murtaza Amjad
Function salePrice (double price, string condition).
This function checks to see if the condition of the car is old or new. If
it is new then the function will add $1000 to the base price of the car.
If the condition is old then the function will decrease the base price of
the car by $1500. The Function has two parameters, double price, and
string condition. It also returns the new price of the car in the variable
price.
*/
double Car::salePrice(double price, string condition) {

  if (condition == "new" || condition == "New") {

    price += 1000.00;

  } else {

    price -= 1500.00;
  }

  return price;
}
