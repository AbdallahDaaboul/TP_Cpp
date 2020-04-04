#pragma once
#include <string>
#include <map>

int numberofLine(const std::string& s);
int maxLength(const std::string& s);
std::string removeLines(std::string s);
size_t getLine(std::string s, std::string& line);
typedef std::map<char,int> TableOfVariables;
void recordVariables(TableOfVariables& t,char name,int val);
int getValue(TableOfVariables& t,char name);
void printVariables(TableOfVariables& t );
