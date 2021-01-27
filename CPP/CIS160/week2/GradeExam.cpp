//CIS 160 
//Program #2
//Rene Garcia
//1/23/21
//Takes an input file of test answers and outputs the scores and percentages of the students

//preprocessor directives
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


//prototypes
double getPercentage(double num, int divider);

//main function
int main()
{
   //declare variables
   const arrSize = 23;
   string gradesArr[arrSize];
   int score[22] = {0};
   double percent[22] = {0};
   char letterGrade[22];
   string names[22] = {""};
   int i = 0;
   double classMean = 0.0;
   double numOfFs = 0;
   double numOfDs = 0; 
   double numOfCs = 0;
   double numOfBs = 0; 
   double numOfAs = 0; 
    
   //get data
    //open the file
    ifstream grades;
    grades.open("GradeExamData.txt");
    // if file can't be opened
    if (!grades) {
      cout << "could not open file";
    };
    //while the file hasn't ended
    while(!grades.eof())
   {
      getline(grades, gradesArr[i]);
      i++;
   };
      //process data
      
      
      
      //first loop loops over each person/answers in gradesArr, start at 1 because 0 is not a student
      for(int i = 1; i < 23; i++) {
      //second loop loops over the individual answer in the gradesArr[i] row        
         int scoreIterator = (i - 1);
         for(int j = 0; j < 30; j++)
         {
         // if the answer matches we add to the corresponding student score
            if(gradesArr[0][j] == gradesArr[i][j])
            {
            score[scoreIterator] += 1;
            }
         }// end second loop
         
         //set up temporary value to hold score
         double tempScore = score[scoreIterator];
         
         //do math for grade on scale of 100 and assign to tempScore
         tempScore = getPercentage(tempScore, 30);
                  
         //assign tempScore to corresponding spot in percent array
         percent[scoreIterator] = tempScore;
                  
         // add to classMean for latter
         classMean += tempScore;
         
         //get our letter grade and assign to corresponding spot in letterGrade array
         if(tempScore < 60){
            letterGrade[scoreIterator] = 'F';
             numOfFs++;
            } else if(tempScore < 70){
             letterGrade[scoreIterator] = 'D';
             numOfDs++;
            } else if(tempScore < 80){
             letterGrade[scoreIterator] = 'C';
             numOfCs++;
            } else if(tempScore < 90){
             letterGrade[scoreIterator] = 'B';
             numOfBs++;
            } else{
             letterGrade[scoreIterator] = 'A';
             numOfAs++;
            }

         // set up a variable to store name in
         string name = "";
         //third loop to grab name letter by letter
         for(int n = 29; n < 40; n++){
            name += gradesArr[i][n];            
          }
          //end third loop
          //put name in the corresponding spot in array
          names[scoreIterator] = name;
        };
       //end of first loop
       
        //get the class mean
        classMean = classMean / 22;
        
        //set up int for standardDeviation
        double standardDeviation = 0;
        //loop to get standard deviation
        for(i=0; i < 22; i++){
        double placeHolder = 0;
        placeHolder = (percent[i] - classMean);
         standardDeviation += pow(placeHolder,2);
        }
        //divide by total number of students, square, then format with ceil
        standardDeviation /= 22;
        standardDeviation = sqrt(standardDeviation);
        standardDeviation = ceil(standardDeviation * 100) / 100;
        
        //get percentages for A,B,C,D,F
        numOfAs = getPercentage(numOfAs, 22);
        numOfBs = getPercentage(numOfBs, 22);
        numOfCs = getPercentage(numOfCs, 22);
        numOfDs = getPercentage(numOfDs, 22);
        numOfFs = getPercentage(numOfFs, 22);
         
        
        
     //start writting to our file
     ofstream outFile;
     //open / create a out.txt file
     outFile.open("out.txt");
        
        //start filling up file
      outFile << "Class Average = " << classMean << '\n';
      outFile << "Class Standard Deviation = " << standardDeviation << '\n';
      outFile << "Percentage of As = %" << numOfAs << '\n';
      outFile << "Percentage of Bs = %" << numOfBs << '\n';
      outFile << "Percentage of Cs = %" << numOfCs << '\n';
      outFile << "Percentage of Ds = %" << numOfDs << '\n';
      outFile << "Percentage of Fs = %" << numOfFs << '\n';
      outFile << "Student  " << '\t' << "Score" << '\t' << "%" << '\t' << "Letter" << '\n';
      
      //loop through our arrays and write to file
      for(i=0; i < 22; i++){
      outFile << names[i] << '\t' << score[i] << '\t' << percent[i] << '\t' << letterGrade[i] << '\n';      
      }
     
 //close that file
    outFile.close();
  
   
   //complete program
      return 0;
}

//get the percentage of something by inputting the number you want to get the percentage of (num), and the total to divide by (divider)
double getPercentage(double num, int divider) {
   num = (num / divider * 100);
         num = ceil(num * 100) / 100;
         return num;

}