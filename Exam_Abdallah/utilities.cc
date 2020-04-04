#include "utilities.h"
#include <iostream>

int numberofLine(const std::string& s)
{
  unsigned int nb_ligne = 1;
  unsigned int i = 0;
  while(s[i]!='\0')
    {
      if (s[i] == '\n')
	{
	  nb_ligne++;
	}
      i++; 
    }
  return nb_ligne;
}

std::string removeLines(std::string s)
{
  unsigned int i = 0;
  while(s[i]!='\0')
    {
      if (s[i] == '\n')
	{
	  s[i]=' ';
	}
      i++; 
    }
  return s;
}
int maxLength(const std::string& s)
{
  unsigned int max = 0;
  unsigned int i = 0;
  unsigned int deb = 0;
  while(s[i]!='\0')
    {
      if (s[i] == '\n')
	{
	  if(i-deb > max)
	    max = i-deb;
	  deb = i+1;
	}
      i++; 
    }
  if(max == 0)
    max = s.length();
  return max;
}
  
void recordVariables(TableOfVariables& t,char name,int val)
{
  t[name] = val;
}
int getValue(TableOfVariables& t,char name)
{
  return t[name];
}


void printVariables(TableOfVariables& t)
{
  for (auto s : t)
    {
      std::cout << s.first << " = " << s.second << std::endl;
    }
}

// return std::string::npos if no new line else return the pos of \n
size_t getLine(std::string s, std::string& line)
{
  size_t pos;
  if((pos = s.find('\n')) != std::string::npos)
    {
      line = s.substr(0,pos);
    }
  return pos;
}
