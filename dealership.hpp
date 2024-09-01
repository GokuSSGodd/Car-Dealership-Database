/*
dealership.hpp
Murtaza Amjad 
3/30/2023
This is where the Car model class is defined. 
All the functions are here. 
*/

#pragma once
#include <iostream>
#include <string>
#include <iomanip> 
#include <fstream> 

using namespace std; 

//stores data about the car 
class Car{

//private data members of class Car 
private:
  string model; 
  string condition;
  string color;
  int year; 
  double price;
  string day_month_year;
  bool date;

  //public function accessible to the world 0
public:
  Car() = default; //default constructor 
  Car(string itsmodel, string itscondition, double itsprice, string       
  itscolor, int itsyear, string dateofpurchase); //Car constructor with data 

  bool isDate(string dateofpurchase); //checks to see if the dates are the same. 
  string toString(); //contains data to print the object to the console
  string toFile(); //stores string containing data formatted into a file "data.txt"
  double salePrice(double price, string condition); //changes the price depending on condition of car. Ex - used, new, etc... 

};
