#include <iostream> 
#include <iomanip>
#include <cmath>

const double pi = acos(-1);

using namespace std;

int main(){
  double A;
  cin >> A;
  double r = sqrt(A / pi);
  cout << fixed << setprecision(12) << (r * 2) << endl;
  return 0;
}