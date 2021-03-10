
/* Name: Andrew Stade
Date: 10/7/2019
Section: 2 */

#include <iostream>
#include <iomanip>
#include "mixed.h"

using namespace std; 

//Friend Functions
Mixed operator+(const Mixed& a, const Mixed& b)
{
    Mixed result;
    result.ToFraction();
    result.val = a.val + b.val;
    result.num = (a.num*b.den) + (b.num*a.den);
    result.den = a.den * b.den;
    result.Simplify();
    return result;
}

Mixed operator-(const Mixed& c, const Mixed& d)
{
    Mixed result;
    result.ToFraction();
    result.val = c.val - d.val;
    result.num = c.num - d.num;
    result.den = c.den * d.den;
    result.Simplify();
    return result;
}

Mixed operator*(const Mixed& e, const Mixed& f)
{
    Mixed result;
    result.val = e.val * f.val;
    result.num = e.num * f.num;
    result.den = e.den * f.den;
    return result;
}

Mixed operator/(const Mixed& g, const Mixed& h)
{
    Mixed result;
  /*  result.val = g.val / h.val;
    result.num = g.num / h.num;
    result.den = g.den / h.den; */
    result.Simplify();
    return result;
}
   
bool operator<(const Mixed& i, const Mixed& j)
{
    int resultx;
    int resulty;
    
    if (i.val < j.val)
    {        
        return true;
    }
    else if (i.val == j.val)
    {
        resultx = i.num / i.den;
        resulty = j.num / j.den;
        if (resultx < resulty)
        {
            return true;
        }
    }
    else
        return false;
}

bool operator>(const Mixed& k, const Mixed& l)
{
    int resultx;
    int resulty;
    
    if (k.val > l.val)
    {        
        return true;
    }
    else if (k.val == l.val)
    {
        resultx = k.num / k.den;
        resulty = l.num / l.den;
        if (resultx > resulty)
        {
            return true;
        }
    }
    else
        return false;

}

bool operator<=(const Mixed& m, const Mixed& n)
{
    int resultx;
    int resulty;
    
    if (m.val <= n.val)
    {        
        return true;
    }
    else if (m.val == n.val)
    {
        resultx = m.num / m.den;
        resulty = n.num / n.den;
        if (resultx <= resulty)
        {
            return true;
        }
    }
    else
        return false;
}

bool operator>=(const Mixed& o, const Mixed& p)
{
    int resultx;
    int resulty;
    
    if (o.val >= p.val)
    {        
        return true;
    }
    else if (o.val == p.val)
    {
        resultx = o.num / o.den;
        resulty = p.num / p.den;
        if (resultx >= resulty)
        {
            return true;
        }
    }
    else
        return false;   
}

bool operator==(const Mixed& q, const Mixed& r)
{
    
    if (q.val == r.val)
    {    
        if (q.num == r.num)
        {
            if (q.den == q.den)
            {
                return true;
            }
        }
    }
    else
        return false;
}

bool operator!=(const Mixed& s, const Mixed& t)
{
    if (s.val == t.val)
    {    
        if (s.num == t.num)
        {
            if (s.den == t.den)
            {
                return false;
            }
        }
    }
    else
        return true;  
}

ostream& operator<<(ostream& u, const Mixed& v)
{
    if (v.val == 0 && v.num == 0 && v.den == 0)
    {
        u << 0;
    }
    else if (v.val == 0 &&  v.den > 0)
    {
        u << v.num << "/" << v.den; 
    }
    else if (v.val > 0 && v.num >= 0 &&  v.den > 0)
    {
        u << v.val << " " << v.num << "/" << v.den;
    }
    else if (v.val < 0 && v.num >= 0 && v.den > 0)
    {
        u << v.val << " " << v.num << "/" << v.den;
    }
    else if (v.num == 0 && v.den == 0)
    {
        u << v.val;
    }
    else 
    {
        u << 0;
    }
}

istream& operator>>(istream& w, Mixed& x)
{
    
    char divSign = '/';
    
    w >> x.val >> x.num >> divSign >> x.den;
     
    if (x.val >= 0)
    {        
        x.val = x.val;
        x.num = x.num;
        x.den = x.den;
    }
    else if (x.val < 0 && x.num > 0 || x.den > 0)    
    {
        x.val = x.val;
        x.num = x.num;
        x.den = x.den;
    } 
    else 
    {
        x.val = 0;
        x.num = 0;
        x.den = 0;
    } 

}

Mixed::Mixed(int q, int r, int s)
// Constructor (takes in integer, numerator, denominator)
{
    if (q >= 0)
    {        
        val = q;
        num = r;
        den = s;
    }
    else if (q < 0 && r > 0 || s > 0)    
    {
        val = q;
        num = r;
        den = s;
    }
    else
    {
        val = 0;
        num = 0;
        den = 0;
    }
}

Mixed::Mixed(int p)
// Acts as a default constructor
{
    val = p;
    num = 0;
    den = 1;
}

double Mixed::Evaluate()
{
    double data;
    double extra;
    
    if (den != 0)
    {
        data = num * 1.0 / den * 1.0;
        if (val < 0)
        {
            val = val * -1;
            extra = val + data;
            extra = extra * -1;
            val = val * -1;
            return (extra);
        }
        else
            extra = val + data;
            return (extra); 
    }
}

void Mixed::ToFraction()
{
    int val1;
    

    if (val < 0)
    {
        num = num - den * val;
        num = num * -1;
        val = 0;
    }
    else if (val > 0 && num > 0)
    {
        num = den * val + num;
        val = 0;
    }
    else if (val == 0)
    {
        val = num / den;
        num = num % den;
        val = 0;
    }
}

void Mixed::Simplify()
{
    int num2;
    int den2;
    int answer;
    
    if (num > 0)
    {
        for (int i = den * num; i > 1; i--) 
        {  
            if ((den % i == 0) && (num % i == 0)) 
            {  
                den /= i;  
                num /= i;  
                answer = num / den;
                val = val + answer;
                num = num % den;
            }
        }
    }
    else if (num < 0)
    {
        num = num * -1;
        den = den * -1;
        for (int i = den * num; i > 1; i--)
        {
                den /= i;  
                num /= i;  
                answer = num / den;
                val = val + answer;
                num = num % den;
        }
        num = num * -1;
        den = den * -1;
    }
    
}

Mixed& Mixed::operator++() 
{
   val = val + 1;
   return *this;
}

Mixed Mixed::operator++(int) 
{
   Mixed temp = *this;	
   val = val + 1;		
   return temp;	
}

Mixed& Mixed::operator--() 
{
   val = val - 1;		
   return *this;
}

Mixed Mixed::operator--(int)
{
   Mixed temp = *this;	
   val = val - 1;		
   return temp;	
}

