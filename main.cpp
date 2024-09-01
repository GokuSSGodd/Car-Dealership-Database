/*
main.cpp
Murtaza Amjad & Richard Hurley
3/30/2023
Car Dealership
This program will open a file and have values inputted into the file. At the
beginning there will be nothing in the file. The console will show a menu where
you can add an car object into the vector of cars called Carlist. The list will
also allow you to search for cars that were purchased on certain days and print
them to the out. The menu also allows you to print out all of the Cars that are
in storage/ in the vector Carlist. At the end, the program will print out the
vector Carlist, that contains all the cars, into the ouput file called
"output.txt". At the beginning this file had nothing in it but now it will have
anything you add into it during the program.
*/

#include "dealership.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define INF "data.txt"
#define OUTF "output.txt"

int hashit(string dateofpurchase);

/*
Function main().
This function makes a vector called Carlist. It opens a file that has nothing in
it. The program will then continue. It has a menu where you can see all the
options. You can add a car to the list with the add option. The salePrice
function is used when you are adding a car to see if the base price of the car
goes up or down depending on the condition of the car. You can search for cars
that were purchased on certain days and have all of them printed out to the
console. The print option allows you to print out what is in the file at he
moment. For example, can be 3 different cars or 1 car. The quit options there
for anyone who wants to quit, it will close the program. At the end of the
program the program will output the cars added into to the output file, so that
when you re-run the program it will have the all the cars already in it allowing
you to print them out when you re-run the program. The main function does not
have a parameter and has an int return type.
*/
int main() {

  // Murtaza Amjad

  vector<Car> Carlist[67];

  Car car;
  string line;
  string loop = "Yes";
  string userChoice;
  string model;
  string condition;
  double price;
  string color;
  int year;
  string day_month_year;
  string dateofpurchase;
  bool date;
  int row;
  int col;
  string targetdate;
  int index;

  cout << "Car Dealership" << endl;

  ifstream inputFile(INF);

  if (!inputFile) {

    cerr << "Can't open " << INF << " for input" << endl;
  }

  while (inputFile >> model >> condition >> price >> color >> year >> ws) {

    getline(inputFile, day_month_year);

    Car car(model, condition, price, color, year, day_month_year);

    index = hashit(day_month_year);

    Carlist[index].push_back(car);
  }

  inputFile.close();

  // Richard Hurley
  // runs a loop to ask the user what they want to do, add, search or print or
  // just exit the program
  cout << endl << "Menu" << endl;

  while (loop == "Yes" || loop == "yes") {

    cout << endl

         << "What do you want to do:" << endl

         << "Add a new object, type Add" << endl

         << "Search for objects, type Search" << endl

         << "Print all the objects, type Print" << endl

         << "if you want to exit type, Exit" << endl;

    cin >> userChoice;

    // takes the users inputs of a new vechile into the list of sold cars .
    // aslks for the model, condion, price, colro, year, and the date the car
    // was purchased, the  it adds it to the carlist vector
    if (userChoice == "Add" || userChoice == "add") {

      cout << "What car are you adding for?" << endl;

      cin >> model;

      cout << "What is the condition of the car you are adding?" << endl;

      cin >> condition;

      cout << "What is the price of the car you are adding?" << endl;

      cin >> price;

      cout << "What is the color of the car you are adding?" << endl;

      cin >> color;

      cout << "What is the year of the car you are adding?" << endl;

      cin >> year;

      cout << "When was the car bought? (input as DD MM YYYY)" << endl;

      cin.ignore();

      getline(cin, day_month_year);

      price = car.salePrice(price, condition);

      Car car(model, condition, price, color, year, day_month_year);

      index = hashit(day_month_year);

      Carlist[index].push_back(car);

    }

    // asks the user to input a date they want to search with, the it goes
    // through each line in the vector and will compare the dates, if the
    // dates match, it will print out the cars information, if the does not
    // match, it will print ouit the date does not match this car
    else if (userChoice == "Search" || userChoice == "search") {

      cout << "When did you buy the car(type as DD MM YYYY)" << endl;

      cin.ignore();

      getline(cin, dateofpurchase);

      index = hashit(dateofpurchase);

      for (col = 0; col < Carlist[index].size(); col++) {

        if (Carlist[index][col].isDate(dateofpurchase) == true) {

          cout << "The date matches this car: "
               << Carlist[index][col].toString() << endl;
        }
      }
    }
    // prints out each car in the vector
    else if (userChoice == "Print" || userChoice == "print") {

      cout << endl << "Here are all the cars:" << endl;

      for (int row = 0; row < 67; row++) {

        for (int col = 0; col < Carlist[row].size(); col++) {
          cout << Carlist[row][col].toString() << endl;
        }
      }
    }

    // stops the loop if the user does not want to pick 1 of the other 3
    // options
    else {

      exit(1);
    }

    cout << endl << "Do you want to go again? Yes or No?" << endl;

    cin >> loop;
  }

  // Murtaza Amjad
  ofstream outputFile(OUTF);

  if (!outputFile) {

    cerr << "Can't open " << OUTF << " for output";

    exit(1);

  }

  else {

    for (row = 0; row < 67; row++) {

      for (col = 0; col < Carlist[row].size(); col++) {

        outputFile << Carlist[row][col].toFile() << endl;
      }
    }
  }

  outputFile.close();

  cout << "Thank you for your time";

  return 0;
}

/*
Murtaza Amjad
Function hashit(string dateofpurchase)
This function takes in an argument of a date and then splits the date into 3
different sections. Day, month, and year. It then turns the string variables
day, month, year into type int. A variable long int key is initialized as the
year squared + day and temp is initialized as 0. The for loop uses a mask to
get the 5 leftmost bits of key and save them into temp. It will then shift the
5 leftmost bits to the 5 rightmost bits. Later the last letter of the month is
saved into key as an int type. This repeats for all the letters of the month,
and then the function returns index which is key moduled the size of the
array. The hashit function has one parameter, string targetdate. It also has an
return type of int and returns the int variable index.
*/
int hashit(string dateofpurchase) {

  string day = dateofpurchase.substr(0, 2);

  string month = dateofpurchase.substr(3, 2);

  string year = dateofpurchase.substr(6, 4);

  int day_int = stoi(day);

  int month_int = stoi(month);

  int year_int = stoi(year);

  long int key = (year_int * year_int) + day_int;

  long int temp = 0;

  for (int index = month.length() - 1; index >= 0; index--) {

    temp = (key & 0xF8000000) >> 27;

    temp <<= 27;

    key <<= 5;

    key |= temp;

    char monthletter = month[index];

    int Monthletter_int = (int)monthletter;

    key ^= Monthletter_int;
  }

  int index = key % 67;

  return index;
}
