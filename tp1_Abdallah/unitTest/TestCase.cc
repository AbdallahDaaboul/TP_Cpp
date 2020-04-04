#include "catch.hpp"
#include "../passgrid.hh"

bool checkCases(const PassGrid& p)
{
  for (std::size_t i = 0 ; i < p.getH(); i++ )
    for (std::size_t j = 0 ; j < p.getW(); j++)
      if(p(i,j) < 33 || p(i,j) > 94)
        return false;
  return true;
}
bool diff(const PassGrid& p1, const PassGrid&p2)
{
  for (std::size_t i = 0 ; i < p1.getH(); i++ )
    for (std::size_t j = 0 ; j < p1.getW(); j++)
      if(p1(i,j)  !=  p2(i,j))
        return true;
  return false;
}
TEST_CASE("1: Size of the grid","[grid]"){
  PassGrid p0(0,0);
  REQUIRE(p0.getW() == 0);
  REQUIRE(p0.getH() == 0);
  PassGrid p1(10,8);
  REQUIRE(p1.getW() == 10);
  REQUIRE(p1.getH() == 8);
}

TEST_CASE("2: Grid contents","[grid]"){
  PassGrid p0(10,10);
  SECTION("All characters are printable character"){
    REQUIRE(checkCases(p0));
  }
  
  SECTION("Two successively generated grid are different")
    {
      PassGrid p1(10,10);
      REQUIRE(diff(p0,p1));
    }
  SECTION("reset make differences")
    {
      PassGrid p1(p0);
      p0.reset();
      REQUIRE(diff(p0,p1));
    }
}
