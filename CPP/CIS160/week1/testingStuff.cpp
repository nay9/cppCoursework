//CIS 160 Object-Oriented Programming
//Program #1
//Rene Garcia
//1/18/2021
//Take in an input file of data, process averages of that data and return results

//preprocessor directives

#include <string>
#include <iostream>
#include <fstream>
using namespace std;




//main function
int main()
{
    //declare variables
    string gender = "";
    string line = "";

    // all the arrays will follow this format:
    // {count, total height, total weight}
    int age = 0;
    int height = 0;
    int weight = 0;
    // i will be used for iterating thorugh each word in the file
    // i = 0 is gender, 1 is age, 2 is height, 3 is weight
    int i = 0;


    ifstream myFile;
    myFile.open("WgtHgtData.txt");
    if (!myFile) {
        std::cout << "Could not open the file";
    };

    while (myFile >> line)
    {
        switch (i) {
        case 0:
            gender = line;
            i++;
            break;
        case 1:
            age = std::stoi(line);
            i++;
            break;
        case 2:
            height = std::stoi(line);
            i++;
            break;
        case 3:
            weight = std::stoi(line);
            i = 0;
            break;
        }
    }

    std::cout << gender << age << height << weight << '\n';
    std::cout << "program terminated";
    return 0;
};

//    for(int i=0; i < peopleData.size(); i++)
//    {
//     vector<string> vector_out;
//     split(peopleData[i], ' ', vector_out);
//     stringstream i_age(vector_out[1]);
//     stringstream i_height(vector_out[2]);
//     stringstream i_weight(vector_out[3]);
//     i_age >> age;
//     i_height >> height;
//     i_weight >> weight;
//     
//     
//      if(vector_out[0] == "m")
//        {     
//        if(age <= 18)
//           {
//           maleEighteenUnder[0] = maleEighteenUnder[0] + 1;
//           maleEighteenUnder[1] = maleEighteenUnder[1] + height;
//           maleEighteenUnder[2] = maleEighteenUnder[2] + weight;
//           }
//         else if(age > 18 && age < 36){
//           maleNineteenToThirtyFive[0] = maleNineteenToThirtyFive[0] + 1;
//           maleNineteenToThirtyFive[1] = maleNineteenToThirtyFive[1] + height;
//           maleNineteenToThirtyFive[2] = maleNineteenToThirtyFive[2] + weight;
//           }
//         else
//           {
//           maleThirtySixOver[0] = maleThirtySixOver[0] + 1;
//           maleThirtySixOver[1] = maleThirtySixOver[1] + height;
//           maleThirtySixOver[2] = maleThirtySixOver[2] + weight;
//           }
//        }
//        else if(vector_out[0] == "f")
//        {
//        if(age <= 18)
//           {
//           femaleEighteenUnder[0] = femaleEighteenUnder[0] + 1;
//           femaleEighteenUnder[1] = femaleEighteenUnder[1] + height;
//           femaleEighteenUnder[2] = femaleEighteenUnder[2] + weight;
//           }
//         else if(age > 18 && age < 36){
//           femaleNineteenToThirtyFive[0] = femaleNineteenToThirtyFive[0] + 1;
//           femaleNineteenToThirtyFive[1] = femaleNineteenToThirtyFive[1] + height;
//           femaleNineteenToThirtyFive[2] = femaleNineteenToThirtyFive[2] + weight;
//           }
//         else
//           {
//           femaleThirtySixOver[0] = femaleThirtySixOver[0] + 1;
//           femaleThirtySixOver[1] = femaleThirtySixOver[1] + height;
//           femaleThirtySixOver[2] = femaleThirtySixOver[2] + weight;
//           }
//        }
//     };
//     
//     ofstream outFile;
//     outFile.open("out.txt");
//     outFile << "Age" << '\t' << "Average Height" << '\t' << "Average Height" << '\t' << "Average Weight" << '\t' << "Average Weight" << '\n';
//     outFile << " " << '\t' << "for Men (in)" << '\t' << "for Women (in)" << '\t' << "for Men (lb)" << '\t' << "for Women (lb)" << '\n';
//     outFile << "0-18" << '\t' << '\t' << averageCalculation(maleEighteenUnder[0], maleEighteenUnder[1]) << '\t' << averageCalculation(femaleEighteenUnder[0], femaleEighteenUnder[1]) << '\t' << averageCalculation(maleEighteenUnder[0], maleEighteenUnder[2]) << '\t' << averageCalculation(femaleEighteenUnder[0], femaleEighteenUnder[2]) << '\n';
//     outFile << "19-35" << '\t' << '\t' << averageCalculation(maleNineteenToThirtyFive[0], maleNineteenToThirtyFive[1]) << '\t' << averageCalculation(femaleNineteenToThirtyFive[0], femaleNineteenToThirtyFive[1]) << '\t' << averageCalculation(maleNineteenToThirtyFive[0], maleNineteenToThirtyFive[2]) << '\t' << averageCalculation(femaleNineteenToThirtyFive[0], femaleNineteenToThirtyFive[2]) << '\n';
//     outFile << "36 and over " << '\t' << averageCalculation(maleThirtySixOver[0], maleThirtySixOver[1]) << '\t' << averageCalculation(femaleThirtySixOver[0], femaleThirtySixOver[1]) << '\t' << averageCalculation(maleThirtySixOver[0], maleThirtySixOver[2]) << '\t' << averageCalculation(femaleThirtySixOver[0], femaleThirtySixOver[2]) << '\n';
//      
//    outFile.close();
//    

   //get data


   //process data


   //output results


   //complete program




double averageCalculation(int count, double total)
{
    return total / count;

}