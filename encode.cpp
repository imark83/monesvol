#include <iostream>
#include <cstring>
#include <vector>

using namespace std;



// UNICODE FOR Ñ AND ñ
unsigned char NNN[2] = {0xc3,0x91};
unsigned char nnn[2] = {0xc3,0xb1};



// KEYBOARD LAYOUT
unsigned int keyb[3][9] = {
  {18,24,5,19,21,26,22,9,12},
  {1,20,4,6,7,8,10,11,17},
  {27,25,3,23,2,14,13,16,15}};

// CONVERT STRING TO NUMBERS 1-27, WITH Ñ, 
vector<unsigned> toInt(string &op) {
  size_t len=op.size();

  // DECREASE BYTE FOR EACH Ñ
  for(auto c : op) {
    if((unsigned char) c == nnn[0]) len--;
  }
  vector<unsigned> rop(len);


  int i=0;
  for (unsigned char c : op) {
    if(c == nnn[0]) continue;
    if(c == nnn[1] || c == NNN[1]) rop[i++] = 15;
    if('A'<=c && c<='N')rop[i++] = c-'A'+1;
    if('a'<=c && c<='n')rop[i++] = c-'a'+1;
    if('Z'>=c && c>='O')rop[i++] = c-'A'+2;
    if('z'>=c && c>='o')rop[i++] = c-'a'+2;
    if(c==' ') rop[i++] = 0;
  }
  return rop;
}


// CONVERT NUMBERS TO STRING
string toString(vector<unsigned> &op) {
  size_t len=op.size();

  // count ñ in op
  // add extra char for each ñ
  for(unsigned c : op) if (c==15) ++len;

  // prepare rop
  string rop(len,'\0');
  int i=0;
  for(unsigned x : op) {
    if(x==0) rop[i++] = ' ';
    if(1<=x && x<=14) rop[i++] = 'A'+x-1;
    if(x==15) {rop[i++]=NNN[0]; rop[i++]=NNN[1];}
    if(16<=x) rop[i++] = 'A'+x-2;
  }
  return rop;
}

ostream & operator<<(ostream &out, vector<unsigned> &op) {
  for(auto i :op) 
    out << i << " ";
  return out;
}

int getRowCol(unsigned c, unsigned &i, unsigned &j, unsigned noodle){
  for(i=0;i<3;++i) for(j=1;j<10;++j)
    if(keyb[i][j-1]==c) {
      i = (i+3-noodle)%3;
      j = (j+9-noodle)%9+1;
      return (10*i+j-1)%27+1;
    }
  return -1;
}

int main(int argc, char const *argv[]) {
  string msg(argv[1]), rop;
  vector<unsigned> msg_int;

  msg_int = toInt(msg);


  cout << msg_int << endl;
  

  unsigned i,j;
  int noodle=atoi(argv[2]);


  for(int k=0; k<msg_int.size(); ++k) {
    if(msg_int[k]==0) {noodle=(noodle%10)+1;}
    else {
      msg_int[k] = getRowCol(msg_int[k],i,j,noodle);
      cout << " " << msg_int[k]; 
    }
  }



  rop=toString(msg_int);
    
  cout << rop << endl;

  return 0;
}