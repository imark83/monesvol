#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

unsigned char nnn[2] = {0xc3,0x91};
unsigned char NNN[2] = {0xc3,0xb1};


// CONVERT STRING TO NUMBERS 1-27, WITH Ñ, 
vector<unsigned> toInt(string &op) {
  size_t len=op.size();
  for(auto c : op) {
    if((unsigned char) c == nnn[0]) len--;
  }
  vector<unsigned> rop(len);


  int i=0;
  for (auto c : op) {
    if((unsigned char) c == nnn[0]) continue;
    if((unsigned char) c == nnn[1]) rop[i++] = 15;
    if((unsigned char) c == NNN[1]) rop[i++] = 15;
    if('A'<=c && c<='N')rop[i++] = c-'A'+1;
    if('a'<=c && c<='n')rop[i++] = c-'a'+1;
    if('Z'>=c && c>='O')rop[i++] = c-'A'+2;
    if('z'>=c && c>='o')rop[i++] = c-'a'+2;
    if(c==' ') rop[i++] = 0;
  }

  return rop;
}

ostream & operator<<(ostream &out, vector<unsigned> &op) {
  for(auto i :op) 
    out << i << " ";
  return out;
}

int main(int argc, char const *argv[]) {
  vector<unsigned> msg_int;
  string msg(argv[1]);
  msg_int = toInt(msg);

  cout << msg_int << endl;

  return 0;
}