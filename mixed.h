
/* Name: Andrew Stade
Date: 10/7/2019
Section: 2 */

#include <iostream>
using namespace std;

class Mixed
{
   // Math operators
   friend Mixed operator+(const Mixed& a, const Mixed& b);
   friend Mixed operator-(const Mixed& c, const Mixed& d);
   friend Mixed operator*(const Mixed& e, const Mixed& f);
   friend Mixed operator/(const Mixed& g, const Mixed& h);
   
   // Comparing operators
   friend bool operator<(const Mixed& i, const Mixed& j);
   friend bool operator>(const Mixed& k, const Mixed& l);
   friend bool operator<=(const Mixed& m, const Mixed& n);
   friend bool operator>=(const Mixed& o, const Mixed& p);
   friend bool operator==(const Mixed& q, const Mixed& r);
   friend bool operator!=(const Mixed& s, const Mixed& t);
   
   friend ostream& operator<<(ostream& u, const Mixed& v);
   friend istream& operator>>(istream& w, Mixed& x);
    
public:
    Mixed(int q, int r, int s);
    Mixed(int p = 0);
    
    //accessor
    double Evaluate();
    
    //mutators
    void ToFraction();
    void Simplify();
    
    // Increment and decrement operators
    Mixed& operator++(); 
    Mixed operator++(int);
    Mixed& operator--();
    Mixed operator--(int);

private:
    int val;
    int num;
    int den;
};

