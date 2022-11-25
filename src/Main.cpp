#include <iostream>
#include "Hoare.h"
#include "Lomuto.h"
#include "Median.h"
#include <string>
#include <sstream>
#include <string.h>
#include <fstream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <math.h>
#include <iomanip>
using namespace std;
using namespace std::chrono;

vector <int> lomuto_arr;
vector <int> hoare_arr;
vector <int> median_arr;


int LomutoPartition(int p, int r){
    int x = lomuto_arr[r];
    int i = p-1;
    int temp;
    for(int j = p; j < r; j++){
        if(lomuto_arr[j] <= x){
            i++;
            temp = lomuto_arr[i];
            lomuto_arr[i]=lomuto_arr[j];        //Lomuto Partition Algorithm, straight out of the lecture slides
            lomuto_arr[j]=temp;
        }
    }
    temp = lomuto_arr[i+1];
    lomuto_arr[i+1] = lomuto_arr[r];
    lomuto_arr[r] = temp;
    return i+1;
}
int HoarePartition(int p, int r){
    int x = hoare_arr[p];
    int i = p -1;
    int j = r +1;
    while (true) {
        // Find leftmost element greater than
        // or equal to pivot
        do {
            i++;
        } while (hoare_arr[i] < x);
 
        // Find rightmost element smaller than
        // or equal to pivot
        do {
            j--;
        } while (hoare_arr[j] > x);
 
        // If two pointers met.
        if (i >= j)
            return j;
 
        swap(hoare_arr[i], hoare_arr[j]);
    }
}
int MedianPartition(int p , int r){
    int pInit = p;
    int rInit = r;
    int x = median_arr[p + ((r-p)/2)];
    while(pInit <= rInit){
        while(median_arr[pInit] < x) pInit++;
        while(median_arr[rInit]> x) rInit--;
        if(pInit <= rInit){
            swap(median_arr[pInit], median_arr[rInit]);
            pInit++;
            rInit--;
        }
        if(p < rInit)MedianPartition(p,rInit);
        if(pInit < r)MedianPartition(pInit,r);
    }

    return r;
}
void HoareQuicksort(int p, int r){
    if(p < r){
        int q = HoarePartition(p,r);
        HoareQuicksort(p,q);
        HoareQuicksort(q+1,r);
    }
}
void LomutoQuicksort(int p, int r){
    if(p < r){
        int q = LomutoPartition(p,r);
        LomutoQuicksort(p,q-1);
        LomutoQuicksort(q+1,r);
    }
}

void MedianQuicksort(int p, int r){
    if(p < r){
        int q = MedianPartition(p,r);
        MedianQuicksort(p,q-1);
        MedianQuicksort(q+1,r);
    }
}


int main(int argc, char *argv[]) {
    string inputfile_name = ""; //input file
    string outputfile_name = "";   //output file

    inputfile_name = argv[1];
    outputfile_name = argv[2];

    string output_check = outputfile_name.substr(outputfile_name.length() - 4, outputfile_name.length()); // ensuring file ends in .txt
    string input_check = inputfile_name.substr(inputfile_name.length() - 4, inputfile_name.length());

    const char *o_check = output_check.c_str(); // strcmp can only be compared with const char pointers
    const char *i_check = input_check.c_str(); // c_str() changes string to const char *

    if (strcmp(i_check, ".txt") != 0)
    {
        printf("Invalid Command: Stopped on input file.\n");
        exit(0);                                    // checkers to ensure we have valid .txt files
    }
    else if ((strcmp(o_check, ".txt") != 0))
    {
        printf("Invalid Command: Stopped on output file.\n");
        exit(0);
    }
    ifstream infile(inputfile_name);
    ofstream outfile(outputfile_name);

    string command;
    while (infile >> command){
        lomuto_arr.push_back(stoi(command));
        hoare_arr.push_back(stoi(command));     //created 3 seperate arrays for each Partition scenario
        median_arr.push_back(stoi(command));
    }

    //////////////////////////////////////////////////LAMUTO
    outfile << "Original Lomuto array:" <<endl;
    outfile << "[";
    for(int i = 0; i < lomuto_arr.size(); i++){     //Prints original *untouched* array
        if(i != lomuto_arr.size()-1){
            outfile << lomuto_arr[i] << ",";
        }
        else{
            outfile << lomuto_arr[i];
        }
    }
    outfile << "]" << endl;
    LomutoQuicksort(0, lomuto_arr.size()-1);        //Quicksort call with Lomuto's Partition
    outfile << "Sorted Lomuto array: " << endl;
    outfile << "[";
    for(int j = 0; j < lomuto_arr.size(); j++){
       if(j == lomuto_arr.size()-1){
            outfile << lomuto_arr[j];               //Prints sorted array
        }
        else{
            outfile << lomuto_arr[j] << ",";
        }
    }
    outfile << "]" << endl;
    outfile << endl;
    //////////////////////////////////////////////////////////////Now Hoares
    outfile << "Original Hoare array:" <<endl;
    outfile << "[";
    for(int i = 0; i < hoare_arr.size(); i++){
        if(i != hoare_arr.size()-1){
            outfile << hoare_arr[i] << ",";         //Prints original *untouched* array
        }
        else{
            outfile << hoare_arr[i];
        }
    }
    outfile << "]" << endl;
    HoareQuicksort(0, hoare_arr.size()-1);           //Quicksort call with Hoare's Partition
    outfile << "Sorted Hoare array: " << endl;
    outfile << "[";
    for(int j = 0; j < hoare_arr.size(); j++){
       if(j == hoare_arr.size()-1){
            outfile << hoare_arr[j];                    //Prints sorted array
        }
        else{
            outfile << hoare_arr[j] << ",";
        }
    }
    outfile << "]" << endl;
    outfile << endl;
    /////////////////////////////////////////////TODO:Median Partition
    outfile << "Original Median array:" <<endl;
    outfile << "[";
    for(int i = 0; i < median_arr.size(); i++){
        if(i != median_arr.size()-1){
            outfile << median_arr[i] << ",";         //Prints original *untouched* array
        }
        else{
            outfile << median_arr[i];
        }
    }
    outfile << "]" << endl;
    int n = sizeof(median_arr)/sizeof(median_arr[0]);
    MedianQuicksort(0, median_arr.size()-1);           //Quicksort call with Median Partition
    outfile << "Sorted Median array: " << endl;
    outfile << "[";
    for(int j = 0; j < median_arr.size(); j++){
       if(j == median_arr.size()-1){
            outfile << median_arr[j];                    //Prints sorted array
        }
        else{
            outfile << median_arr[j] << ",";
        }
    }
    outfile << "]" << endl;
    

    return 0;
}