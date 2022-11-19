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

vector <int> arr;
int LomutoPartition(int p, int r){
    //cout << "p = " << p << endl;
    //cout << "r = " << r << endl;
    /*
    cout << "Before Partitioning: " << endl;
    cout << "[";
    for(int l = 0; l < arr.size(); l++){
        if(l == arr.size()-1){
            cout << arr[l];
        }
        else{
            cout << arr[l] << ",";
        }
    }
    cout << "]" << endl;
    */
    int x = arr[r];
    int i = p-1;
    int temp;
    for(int j = p; j < r; j++){
        if(arr[j] <= x){
            i++;
            temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
    /*
    cout << "After Partitioning : " << endl;
    cout << "[";
    for(int l = 0; l < arr.size(); l++){
        if(l == arr.size()-1){
            cout << arr[l];
        }
        else{
            cout << arr[l] << ",";
        }
    }
    cout << "]" << endl;
    cout << endl;
    */
    return i+1;
    
}
/*
vector <int> HoareQuicksort(vector <int> A, int p, int r){
    if(p < r){
        int q = HoarePartition(A,p,r);
        //HoareQuicksort(A,p,q-1);
        //HoareQuicksort(A,q+1,r);
    }
}
*/
void LomutoQuicksort(int p, int r){
    if(p < r){
        int q = LomutoPartition(p,r);
        LomutoQuicksort(p,q-1);
        LomutoQuicksort(q+1,r);
    }
}
/*
vector <int> MedianQuicksort(vector <int> A, int p, int r){
    if(p < r){
        //int q = MedianPartition();
        //MedianQuicksort(A,p,q-1);
        //MedianQuicksort(A,q+1,r);
    }
}
*/

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
        arr.push_back(stoi(command));
    }
    outfile << "Original Array:" <<endl;
    outfile << "[";
    for(int i = 0; i < arr.size(); i++){
        if(i != arr.size()-1){
            outfile << arr[i] << ",";
        }
        else{
            outfile << arr[i];
        }
    }
    outfile << "]" << endl;
    //vector<int> Hoare_sorted_array = HoareQuicksort(arr, 1, arr.size()-1);
    LomutoQuicksort(0, arr.size()-1);
   // vector<int> Median_sorted_array = MedianQuicksort(arr, 1, arr.size()-1);
    outfile << "Sorted Lomuto Array: " << endl;
    outfile << "[";
    for(int j = 0; j < arr.size(); j++){
       if(j == arr.size()-1){
            outfile << arr[j];
        }
        else{
            outfile << arr[j] << ",";
        }
    }
    outfile << "]" << endl;

    return 0;
}