#include "Lomuto.h"
#include <iostream>
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


int LomutoPartition(vector <int> A, int p, int r){
    int x = A[r];
    i = p-1;
    for(int j = p; j < r; j++){
        if(A[j] <= x){
            i++;
            if(i < j){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp; 
            }
            else{
                continue;
            }
        }
    }
    int temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;
    return i+1;
}