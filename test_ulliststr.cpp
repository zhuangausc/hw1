#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_front(to_string(1));
  dat.push_back(to_string(7));
  dat.push_front(to_string(8));
  dat.push_back(to_string(9));
  dat.pop_back();
  dat.pop_front();
  cout << dat.get(0) << " " << dat.get(1) << endl;
  // prints: 8 7 9
  cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
  cout << "Front is: " << dat.front() << endl;
  cout << "Back is: " << dat.back() << endl;
}
