#include <iostream>
#include "Atom.hh"
#include "ExpLog.hh"
#include "ExpNot.hh"
#include "ExpAnd.hh"
#include "ExpOr.hh"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int Atom::counter=0;

string DimacsToString (){

    string DimacsFile;
    cout << endl << "Enter the dimacs file name : ";
    cin >> DimacsFile;

    string exp_log;
    string line;

    ifstream file1(DimacsFile.c_str());

    int nbclauses ,nbvar ;
    string type;

    if(!file1)  //error
  		return "Cannot open the File : " + DimacsFile;


    while( getline(file1, line) ) {
      stringstream ss_line;
      ss_line << line;

            if (line.size()>=1 and ss_line.get() == 'p'){
                ss_line >> type >> nbvar >>nbclauses;

                std::cout << "Nbvar, nbclauses test :" << '\n';
                std::cout << nbvar << '\n';;
                std::cout << nbclauses << '\n';


                for(int i=0; i<nbclauses; i++){
                    exp_log +='(';
                    getline(file1, line);

                    stringstream clause;

                    clause <<line;

                    int var;
                    clause >> var;
                    while(var !=0){
                        if(var <0) exp_log +="NOT(a_" + to_string(-1*(var+1))+')';
                        else exp_log +="a_" + to_string(var-1);
                        clause >> var;
                        if(var != 0 ) exp_log += " OR ";
                    }
                    exp_log+= ')';
                    if(i < nbclauses - 1) exp_log += " AND ";
                }

              }
            else continue;
      std::cout << "/* message */" << '\n';
    }
    file1.close();
    return exp_log;
}

void testAtom(){
  Atom a(ThreeVal_t::T);
  Atom b;
  Atom c(b);

  b = ThreeVal_t::T;
  cout << a.toString() << endl;
  cout << b.toString() << endl;
  cout << c.toString() << endl;
  c = false;
  a = b = ThreeVal_t::F;
  cout << a.toString() << endl;
  cout << b.toString() << endl;
  cout << c.toString() << endl;
  cout << a.evaluate() << endl;
}

void testExpNot()
 {
   Atom a(ThreeVal_t::T);
   ExpNot n1(a);
   ExpNot n2(n1);

   cout << n1.toString() << endl;
   cout << n2.toString() << endl;
   cout << n2.evaluate() << endl;
 }

 void testExpOrExpAnd()
 {
   Atom a(ThreeVal_t::T);
   Atom b;
   Atom c(ThreeVal_t::F);
   ExpNot n1(a);
   ExpAnd and1(n1,b);
   ExpAnd and2(c,b);
   ExpOr or1(and1,and2);
   cout << and1.toString() << std::endl;
   cout << or1.toString() << "=" << or1.evaluate() << endl;
 }

 void testOperations()
 {
   Atom a(ThreeVal_t::U),b(ThreeVal_t::U),c(ThreeVal_t::U);
   ExpNot nota(a);
   ExpAnd and1(a , b);
   ExpAnd and2(nota , c);
   ExpAnd and3(b , c);
   ExpOr or1(and1,and2);
   ExpOr or2(or1,and3);

   cout << or2.toString() << endl;

   while(or2 == ThreeVal_t::U)
     {
 	if(a == ThreeVal_t::U)
 	  {
 	    a = ThreeVal_t::T;
 	    continue;
 	  }
 	if(b == ThreeVal_t::U)
 	  {
 	    b = ThreeVal_t::T;
 	    continue;
 	  }
 	if(c == ThreeVal_t::U)
 	  {
 	    c = ThreeVal_t::F;
 	    continue;
 	  }
  }
   cout << or2.toString() << endl;
 }

int main()
{
  std::cout << '\n'<< "/* TestAtom */" << '\n';
  testAtom();
  std::cout << '\n'<< "/* TestExpNot */" << '\n';
  testExpNot();
  std::cout << '\n'<< "/* TestExpOrExpAnd */" << '\n';
  testExpOrExpAnd();
  std::cout << '\n'<< "/* TestOperations */" << '\n';
  testOperations();
  cout << endl << "/* DimacsToString */"  << endl;
cout <<endl<< DimacsToString() << endl;

}
