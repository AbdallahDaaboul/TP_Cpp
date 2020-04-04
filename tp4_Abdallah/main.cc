#include "tableau2D.hh"
#include "matrix.hh"
int main(void)
{
std::cout << "**********Exercice1**********" << '\n';
  Tableau2D<float> tab(10,10);
  tab(2,2) = 42.0;
  std::cout << tab (2,2) << std::endl ;

  Tableau2D<float> tab2 = tab;
  tab2(1,1) = 1.5;

  if ( tab2 == tab )
    std::cout << "equal" << std::endl;
  else
    std::cout << "notEqual" << '\n';
  std::cout << tab2 << std::endl;

std::cout << "**********Exercice2**********" << '\n';
std::cout << "----Create matrix a1 and a2----" << '\n';
Matrix<float> a1(5, 5, 2);
Matrix<float> a2(5, 5, 1);

std::cout << a1 << std::endl;
std::cout << a2 << std::endl;

std::cout << "----(2 * a1) * (a2 * 2)----" << '\n';

std::cout << 2*a1*a2*2 << '\n';

std::cout << "----1 + a1 + a2 +1----" << '\n';
std::cout << 1+a1+a2+1 << '\n';

std::cout << "----1 - a1 - a2 -1----" << '\n';
std::cout << 1-a1-a2-1 << '\n';

std::cout << "----a3 = a1----" << '\n';
Matrix<float> a3 = a1;
std::cout << a3 << '\n';

std::cout << "----a4 =  2*(a1 + a2 - a3)----" << '\n';
Matrix<float> a4 =  2*(a1 + a2 - a3);
std::cout << a4 << '\n';

std::cout << "----a5 = a4 / 2.0----" << '\n';
Matrix<float> a5 = a4 / 2.0;
std::cout << a5 << std::endl;

std::cout << "----a5(7, 7, Matrix<float>::identity)----" << '\n';
Matrix<float> a6(7, 7, Matrix<float>::identity);
std::cout << a6 << std::endl;

std::cout << "----transpose----" << '\n';

Matrix<float> a7(4,5,1);
std::cout << a7.transpose() << '\n';
return 0;

}
