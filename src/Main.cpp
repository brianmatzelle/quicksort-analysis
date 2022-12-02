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

vector<vector<int> > lomuto_master;
vector<vector<int> > hoare_master;     //master array of every input array
vector<vector<int> > median_master;

int LomutoPartition(vector<int> &lomuto_arr, int p, int r){
    int x = lomuto_arr[r];
    int i = p-1;
    int temp;
    for(int j = p; j < r; j++){
        if(lomuto_arr[j] <= x){
            i++;
            // temp = lomuto_arr[i];
            // lomuto_arr[i]=lomuto_arr[j];        //Lomuto Partition Algorithm, straight out of the lecture slides
            // lomuto_arr[j]=temp;
            swap(lomuto_arr[i], lomuto_arr[j]);
        }
    }
    // temp = lomuto_arr[i+1];
    // lomuto_arr[i+1] = lomuto_arr[r];
    // lomuto_arr[r] = temp;
    swap(lomuto_arr[i+1], lomuto_arr[r]);

    return i+1;
}

int MedianOfThree(vector<int> &median_arr,int p, int r){
    int pivot;
    int pInit = p;
    int rInit = r;
    int x = p+((r-p)/2);
    if (pInit>x && pInit<rInit || pInit>rInit && pInit<x ) x=pInit;
    else if (rInit>pInit && rInit<x || rInit>x && rInit<pInit ) x=rInit;
    pivot = x;

    return pivot;

}
int HoarePartition(vector<int> &hoare_arr,int p, int r){
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

int MedianPartition(vector<int> &median_arr,int p, int r){
    int x = median_arr[MedianOfThree(median_arr, p,r)];
    int i = p -1;
    int j = r +1;
    while (true) {
        // Find leftmost element greater than
        // or equal to pivot
        do {
            i++;
        } while (median_arr[i] < x);
 
        // Find rightmost element smaller than
        // or equal to pivot
        do {
            j--;
        } while (median_arr[j] > x);
 
        // If two pointers met.
        if (i >= j)
            return j;
 
        swap(median_arr[i], median_arr[j]);
    }

}
void HoareQuicksort(vector<int> &hoare_arr,int p, int r){
    if(p < r){
        int q = HoarePartition(hoare_arr,p,r);
        HoareQuicksort(hoare_arr,p,q);
        HoareQuicksort(hoare_arr,q+1,r);
    }
}
void MedianQuicksort(vector<int> &median_arr,int p, int r){
    if(p < r){
        int q = MedianPartition(median_arr,p,r);
        MedianQuicksort(median_arr,p,q);
        MedianQuicksort(median_arr,q+1,r);
    }
}
void LomutoQuicksort(vector<int> &lomuto_arr, int p, int r){
    if(p < r){
        //cout << "makes it to partition..." << endl;
        //cout << "p:"<<p <<endl;
        //cout << "r:"<<r <<endl;
        //cout << lomuto_arr.size() << endl;
       // cout <<"first element: " <<lomuto_arr[0]<<endl;
        int q = LomutoPartition(lomuto_arr,p,r);
        //cout << "post partition..." << endl;
        LomutoQuicksort(lomuto_arr,p,q-1);
        LomutoQuicksort(lomuto_arr,q+1,r);
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

    string n; //will hold n, the length of a given array
    vector<vector<int> > lomuto_master;

    //STEP ONE: fill the master arrays
    vector<int> temp_array;
    while(infile>>n){
        int s = stoi(n);
        //cout << "n:" << s << endl;
        for(int i = 0; i < s; i++){
            int element;
            infile>> element;
            //cout <<"element: " <<element<< endl;
            temp_array.push_back(element);
        }
        lomuto_master.push_back(temp_array);
        hoare_master.push_back(temp_array);
        median_master.push_back(temp_array);
        temp_array.clear();
    }

//////////////////////BY THIS POINT, WE NOW HAVE THREE MASTER ARRAYS THAT WE CAN LOOP THROUGH

/////////////////////LOMUTO FIRST
    outfile << "lomuto:" <<endl;
    for(int i = 0; i < lomuto_master.size(); i++){
        outfile << lomuto_master[i].size() << " ";
        auto lomuto_start = std::chrono::high_resolution_clock::now();
        LomutoQuicksort(lomuto_master[i] ,0,lomuto_master[i].size()-1);                                              
        auto lomuto_finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> total_time = std::chrono::duration<double>(lomuto_finish - lomuto_start);
        outfile <<fixed<<setprecision(10) <<total_time.count() << endl;                                     
    }
    outfile << endl;
////////////////////////////////////Now Hoares
    outfile << "hoare:" <<endl;
    for(int i = 0; i < hoare_master.size(); i++){
        outfile << hoare_master[i].size() << " ";
        auto hoare_start = std::chrono::high_resolution_clock::now();
        HoareQuicksort(hoare_master[i] ,0,hoare_master[i].size()-1);
        auto hoare_finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> total_time = std::chrono::duration<double>(hoare_finish - hoare_start);
        outfile <<fixed<<setprecision(10) <<total_time.count() << endl;                                     
    }
    outfile<<endl;
    /////////////////////////////////////////////Median Partition
    outfile << "median:" <<endl;
    for(int i = 0; i < median_master.size(); i++){
        outfile << median_master[i].size() << " ";
        auto median_start = std::chrono::high_resolution_clock::now();   
        MedianQuicksort(median_master[i] ,0,median_master[i].size()-1);
        auto median_finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> total_time = std::chrono::duration<double>(median_finish - median_start);
        outfile <<fixed<<setprecision(10) <<total_time.count()<<endl;                                    
    }

    return 0;
}