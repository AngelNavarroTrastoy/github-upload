//LINADV model algorithm for Numerical_Meteorology. v2
/*The algorithm is explained step by step acording to the cookbook shown in the documentation of the course. */

// <fstream> allows to create files and save the data on them.
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;


int main() {

  /*Step 1: Set model parameters: idim, deltax(m), deltat(s), ubar(m/s)*/ 
  int idim = 99, deltax= 10000, deltat = 300, ubar = 10;

  /*Step 2: Initialize model variables: LINADV only has 'h'. Set a gaussian using the formula given in the documentation.*/

  int h0 = 10, sigma = 100000;
  vector<float> h;
  //ofstream Myfile("LINADVinit.txt");
    for (int i = 1; i <= idim ; i++){
      int j = h0*exp(-pow((i-49)*deltax,2)/(2*pow(sigma,2)));
      h.push_back(j);
    }

  /*Step 3: Compute tendencies of state variables*/
  //Centered difference set directly to the heighttendency (htend in the documentation)

  //Create the new vectors
    vector<float> htend = h, hinit = h, hnew;

  for(int i = 1; i < 99 ; i++){
    htend[i] = -ubar*((h[i+1]-h[i-1])/(2*deltax));
    int hn = h[i-1] + deltat*htend[i-1];
    hnew.push_back(hn);
  }

  /*Step 4: Extrapolate in time: State varibales are extrapolated to the next time level using the leap-frop time stepping*/

  //Set the timesteps number    
  int timesteps = 320;
  vector<float> hhh;

  //Open the file to save the data of the last timestep  
  //ofstream Myfile("LINADVfin.txt");

  //Create the loop
  for(int j = 1; j <= timesteps ; j++){
    
    //Update hold = h; h = hnew;
    vector<float> hold = h;
    h = hnew;
    
    for(int i = 1; i < 99 ; i++){
      htend[i] = -ubar*((h[i+1]-h[i-1])/(2*deltax));
      hnew[i-1] = hold[i-1] + 2*deltat*htend[i-1];
        }
  }
  
  ofstream Myfile("LINADV_data.txt");
  for(int i = 0; i< 99 ; i++){
    string a = to_string(hinit[i]);
    string b = to_string(hnew[i]);
    string c = to_string(i-49);
    Myfile << c + " " + a + " " + b + "\n";
  }
  Myfile.close();
    
}

//Modular LINADV

/*int main(){

  cout << "Please introduce model parameters: \n";
  cout << "idim: \n";
  cin >> int idim;

  LINADV(idim, deltax, deltat, ubar, steps)

  
  }*/
