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


vector <int> HoareQuicksort(vector <int> A, int p, int r){
    if(p < r){
        int q = HoarePartition(A,p,r);
        HoareQuicksort(A,p,q-1);
        HoareQuicksort(A,q+1,r);
    }
}
vector <int> LomutoQuicksort(vector <int> A, int p, int r){
    if(p < r){
        int q = LomutoPartition();
        LomutoQuicksort(A,p,q-1);
        LomutoQuicksort(A,q+1,r);
    }
}
vector <int> MedianQuicksort(vector <int> A, int p, int r){
    if(p < r){
        int q = MedianPartition();
        MedianQuicksort(A,p,q-1);
        MedianQuicksort(A,q+1,r);
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

    vector <int> arr;
    string command;
    while (infile >> command){
        arr.push_back(stoi(command));
    }
    /*
    cout << "Input array: Size is  " << arr.size() << endl;
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    */
    vector<int> Hoare_sorted_array = HoareQuicksort(arr, 1, arr.size()-1);
    vector<int> Lomuto_sorted_array = LomutoQuicksort(arr, 1, arr.size()-1);
    vector<int> Median_sorted_array = MedianQuicksort(arr, 1, arr.size()-1);
    outfile << "Sorted Hoare Array: " << endl;
    outfile << "[";
    for(int j = 0; j < Hoare_sorted_array.size(); j++){
        outfile<< Hoare_sorted_array[j] << ",";
    }
    outfile << "]" << endl;

    /*
    Where we'll run quicksort?
    Each cpp file will be a partition...
    maybe we create a generic quicksort() function then just insert the different partitions?
    */
    return 0;
}