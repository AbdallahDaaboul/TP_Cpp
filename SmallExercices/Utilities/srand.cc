#include <cstdlib>
#include <ctime>
 
int alea32()
{
        return rand()%32;
}
 
int main()
{
        srand(time(0));