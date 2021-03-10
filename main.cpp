//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include <string>
#include <iostream>
#include <iomanip>
#include "catch.hpp"
using Catch::Matchers::Equals;
using namespace std;
//------------------------------

// Fix the following class
class Complex {
  private:
  int x, y;

  public:
  Complex(int a = 0, int b = 0) : x{a}, y{b};

  int re() const{return x;};
  int im() const{return y;};

  friend istream& operator>>(istream&, Complex&);
  friend ostream& operator<<(ostream&, const Complex&);
};

std::istream& operator>>(istream& input, Complex& g)
{
  input >> g.x;
  input >> g.y >> "i";
  return input;
};
std::ostream& operator<<(ostream& output, const Complex& g);
{
  string s = g;
  output << g.x;
  if(g.y < 0)
  output << "-" << g.y << "i" << endl;
  else
  output << "+" << g.y << "i" << endl;

  return output;
};




//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Complex c;
        REQUIRE( c.re() == 0 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c2" ) {
        Complex c{1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c3" ) {
        Complex c{1,1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "o1" ) {
        Complex c; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("0+0i") );
    }
    SECTION( "o2" ) {
        Complex c{1, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("1+2i") );
    }
    SECTION( "o3" ) {
        Complex c{2, -2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("2-2i") );
    }
    SECTION( "o4" ) {
        Complex c{-2, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("-2+2i") );
    }
    SECTION( "p1" ) {
        Complex c;
        c << "1+1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "p2" ) {
        Complex c;
        c << "1-1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == -1 );
    }
    SECTION( "p3" ) {
        Complex c;
        c << "-1+0i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "p4" ) {
        Complex c;
        c << "-1-2i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == -2 );
    }
}
//------------------------------
