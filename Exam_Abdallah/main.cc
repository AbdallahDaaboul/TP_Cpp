#include <iostream>
#include "shape.hh"
#include "terminal.hh"
#include "processing.hh"
#include "inputOutput.hh"
#include "decision.hh"

void test1()
{
  Start * s1 = new Start;
  End * s2 = new End;
  Decision * s6 = new Decision("d1","a<b");
  Decision * s7 = new Decision(*s6);
  s7->setText("b>=a");
  std::cout << "\""<< s6->label() << "\" (id:" << s6->id() << ") Nombre de connexions ";
  std::cout << s6->nb_connect_max() << std::endl;
  std::cout << "\""<< s7->label() << "\" (id:" << s7->id() << ") Nombre de connexions ";
  std::cout << s7->nb_connect_max() << std::endl;

  std::cout << s1->toString() << std::endl;
  std::cout << s2->toString() << std::endl;
  std::cout << s6->toString() << std::endl;
  std::cout << s7->toString() << std::endl;

  delete s1;
  delete s2;
  delete s6;
  delete s7;
}
void test2()
{
  Start * s1 = new Start;
  End * s2 = new End;
  Processing * s3 = new Processing("Declaration 1");
  s3->setText("declare a \ndeclare b \ndeclare c \n");
  InputOutput * s4 = new InputOutput("Read 1"," read a \n read b \n ",true);
  InputOutput * s5 = new InputOutput("Print 1",false);
  s5->setText(" print a \n print b \n print c \n");
  Decision * s6 = new Decision("d1","a<b");
  Decision * s7 = new Decision(*s6);
  s7->setText("b>=a");
  std::cout << "\"" << s3->label() << "\" (id:" << s3->id() << ") Nombre de connexions ";
  std::cout << s3->nb_connect_max() << std::endl;
  std::cout << "\""<< s6->label() << "\" (id:" << s6->id() << ") Nombre de connexions ";
  std::cout << s6->nb_connect_max() << std::endl;
  std::cout << "\""<< s7->label() << "\" (id:" << s7->id() << ") Nombre de connexions ";
  std::cout << s7->nb_connect_max() << std::endl;


  std::cout << s1->toString() << std::endl;
  std::cout << s2->toString() << std::endl;
  std::cout << s3->toString() << std::endl;
  std::cout << s4->toString() << std::endl;
  std::cout << s5->toString() << std::endl;
  std::cout << s6->toString() << std::endl;
  std::cout << s7->toString() << std::endl;

  delete s1;
  delete s2;
  delete s3;
  delete s4;
  delete s5;
  delete s6;
}

int main()
{
  test1();
  test2();

  return 0;
}
