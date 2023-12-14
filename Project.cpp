// Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int GetPrice(int number);
void OpenFile();
string GetName(int item);
void WriteToFile(int itemchoice);
void DisplayShoppingCart();

int main() {
       int itemchoice, itemprice = 0, finalprice = 0;
       char continuechoice;
       string itemname;

       OpenFile();
       do
       {
              cout << "Would you like to buy anything? y/n" << endl; 
              cin >> continuechoice;
              cout << endl;
              if (continuechoice == 'y')
              {
                     cout << "What would you like to buy? Pick using 1/2/3." << endl; 
                     cin >> itemchoice;
                     cout << endl;
                     WriteToFile(itemchoice);
                     itemprice = GetPrice(itemchoice);
                     finalprice = finalprice + itemprice;
                     itemname = GetName(itemchoice);
                     cout << itemname << "," << endl;
                     cout << "The price is " << itemprice << " BHD." << endl; cout << "Your total is " << finalprice << " BHD.\n" << endl;
                     OpenFile();
              }
              else
                     break;

       }
       while (continuechoice == 'y');
              if (finalprice == 0)
                     return 0;
              else
              {
                     DisplayShoppingCart();
                     cout << "Your final total is " << finalprice << " BHD." << endl; 
                     remove("List.txt");
                     return 0;

              } 
}


void OpenFile()
{
       int i = 0;
       string strdata;
       ifstream infile;
       cout << "Here are all the items for sale: \n"; 

       infile.open("Items.txt");
       if (infile.is_open())
       {
              while (getline(infile, strdata))
              {
                     ++i;
                     cout << i << ". " << setw(20) << left << strdata; 
                     cout << " - " << GetPrice(i) << " BHD." << endl;
              } 
       }
       else
              cout << "File was not opened." << endl;
       infile.close();
}

int GetPrice(int item)
{
       int i = 1, price = 0, a[4];
       ifstream infile;
       infile.open("Price.txt");
       while (infile >> a[i])
       {
              ++i;
       }
       infile.close();
       return a[item];
}

string GetName(int item)
{
       int i = 1, price = 0;
       string a[4], strdata;
       ifstream infile;

       infile.open("Items.txt");

       if (infile.is_open())
       {
              while (getline(infile, strdata))
              {
                     a[i] = strdata;
                     ++i; 
              }
       }
       infile.close();
       return a[item];
}

void WriteToFile(int itemchoice)
{
       ofstream outfile;
       outfile.open("List.txt", ios_base::app);
       outfile << GetName(itemchoice) << endl;
       outfile.close();
}

void DisplayShoppingCart()
{
       int i = 0;
       string strdata;
       ifstream infile;
       cout << "Here is your shopping cart: \n"; 

       infile.open("List.txt");

       if (infile.is_open())
       {
              while (getline(infile, strdata))
              {
                     ++i;
                     cout << i << ". " << strdata << endl;
              } 
       } 
       else
              cout << "File was not opened." << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
// 5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file