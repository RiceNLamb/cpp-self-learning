#include <iostream>
#include <string>

using namespace std;
string testing {"\u0444"};
string &testing_ref = testing;
string poop = "";

string top_row[3] = {"-","-","-"};

auto skadonk(){
  struct ploop {
    string s{"poop"};
    string p{"slgja"};
  };
  ploop ploopy_struct;
  return ploopy_struct;


}

int main() {
  cout << testing_ref << "123123123123123123123123123123123123123131231231231231312312312312231231213123123123123123123123123123123123123";
  cin >> poop;
  auto plop{skadonk()};
  cout << plop.s;
  cout << poop ;
  for (int i = 0; i <=(sizeof(top_row)/sizeof(string)) ; ++i) {
    cout << i << "\n";
    cout << top_row[i];
    
  }
  cout << "♣ " << endl;
  cout << testing;
  return 0;
}