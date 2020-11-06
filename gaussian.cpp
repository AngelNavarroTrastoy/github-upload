#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;



int main(){
  int h0 = 10, sigma = 100000;
  ofstream Myfile("Gaussian.txt");
  vector<int> h;
  vector<int> dh = {1,2,3,4};
  for(int i=1;i<100;i++){
    int j = h0*exp(-pow((i-49)*10000,2)/(2*pow(sigma,2)));
    h.push_back (j);
    dh[1] = 151;
    string data1 = to_string(i);
    string data2 = to_string(j);
    Myfile << data1 + " " + data2 + "\n";
    }
  vector<int> ddh;
  ddh = h;
  Myfile.close();
  cout << ddh[48] << endl;
}
