//CIS 160 Object-Oriented Programming
//Program #1
//Rene Garcia
//1/18/2021
//Take in an input file of data, process averages of that data and return results

//preprocessor directives#include <string>
#include <iostream>
#include <fstream>
using namespace std;


double averageCalculation(int count, double total)
{
    return total / count;
};



//main function
int main()
{
    //declare variables
    char gender = 'a';
    std::stringstream convert;

    // all the arrays will follow this format:
    // {count, total height, total weight}
    int age = 0;
    double height = 0;
    double weight = 0;
    int male18UnderCount = 0;
    double male18UnderHeight = 0;
    double male18UnderWeight = 0;
    int male19To35Count = 0;
    double male19To35Height = 0;
    double male19To35Weight = 0;
    int male36OverCount = 0;
    double male36OverHeight = 0;
    double male36OverWeight = 0;
    int female18UnderCount = 0;
    double female18UnderHeight = 0;
    double female18UnderWeight = 0;
    int female19To35Count = 0;
    double female19To35Height = 0;
    double female19To35Weight = 0;
    int female36OverCount = 0;
    double female36OverHeight = 0;
    double female36OverWeight = 0;    
  
    ifstream myFile;
    myFile.open("WgtHgtData.txt");
    if (!myFile) {
      cout << "could not open file";
    };
   while(!myFile.eof()){
   
      myFile >> gender >> age >> height >> weight;
      if(gender == 'm')
        {     
        if(age <= 18)
           {
           male18UnderCount++;
           male18UnderHeight += height;
           male18UnderWeight += weight;
           }
         else if(age > 18 && age < 36){
           male19To35Count++;
           male19To35Height += height;
           male19To35Weight += weight;
           }
         else
           {
           male36OverCount++;
           male36OverHeight += height;
           male36OverWeight += weight; 
           }
        }
        else if(gender == 'f')
        {
        if(age <= 18)
           {
           female18UnderCount++;
           female18UnderHeight += height;
           female18UnderWeight += weight;
           }
         else if(age > 18 && age < 36){
           female19To35Count++;
           female19To35Height += height;
           female19To35Weight += weight;
           }
         else
           {
           female36OverCount++;
           female36OverHeight += height;
           female36OverWeight += weight; 
           }
        }
     };
       cout << male18UnderHeight;   
         
     ofstream outFile;
     outFile.open("out.txt");
     outFile << "Age" << '\t' << "Average Height" << '\t' << "Average Height" << '\t' << "Average Weight" << '\t' << "Average Weight" << '\n';
     outFile << " " << '\t' << "for Men (in)" << '\t' << "for Women (in)" << '\t' << "for Men (lb)" << '\t' << "for Women (lb)" << '\n';
     outFile << "0-18" << '\t' << '\t' << averageCalculation(male18UnderCount, male18UnderHeight) << '\t' << averageCalculation(female18UnderCount, female18UnderHeight) << '\t' << averageCalculation(male18UnderCount, male18UnderWeight) << '\t' << averageCalculation(female18UnderCount, female18UnderWeight) << '\n';
     outFile << "19-35" << '\t' << '\t' << averageCalculation(male19To35Count, male19To35Height) << '\t' << averageCalculation(female19To35Count, female19To35Height) << '\t' << averageCalculation(male19To35Count, male19To35Weight) << '\t' << averageCalculation(female19To35Count, female19To35Weight) << '\n';
     outFile << "36 and over " << '\t' << averageCalculation(male36OverCount, male36OverHeight) << '\t' << averageCalculation(female36OverCount, female36OverHeight) << '\t' << averageCalculation(male36OverCount, male36OverWeight) << '\t' << averageCalculation(female36OverCount, female36OverWeight) << '\n';
      
    outFile.close();

    return 0;
};
