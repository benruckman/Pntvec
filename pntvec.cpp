/*
 * Pntvec class, implemented as described in file pntvec.h
 * This class represents a point in 3D space
 *
 * Ben Ruckman
 * February 4, 2021
 */


#include <iostream>
#include "pntvec.h"
#include <cmath>

//Default constructor, 0 for all values 
pntvec::pntvec()
{
  x = 0;
  y = 0;
  z = 0;
}

//Constructor for points, puts the points into the corresponding points in vectors
pntvec::pntvec(double newX, double newY, double newZ)
{
  x = newX;
  y = newY;
  z = newZ;
}

//Copy constructor
pntvec::pntvec(const pntvec & other)
{
  x = other.x;
  y = other.y;
  z = other.z;
}

//Overloaded + operator. This adds 2 points together
const pntvec pntvec::operator+ (const pntvec & rhs) const
{
  pntvec result (*this);

  result.x = result.x + rhs.x;
  result.y = result.y + rhs.y;
  result.z = result.z + rhs.z;

  return result;
}

//Overloaded subtraction operator. This subtracts rhs from this
const pntvec pntvec::operator- (const pntvec & rhs) const
{
  pntvec result (*this);
  
  result.x = result.x - rhs.x;
  result.y = result.y - rhs.y;
  result.z = result.z - rhs.z;

  return result;
}

//Overloaded negate operator. It negates the pntvec: p = -p
const pntvec pntvec::operator- () const
{
  pntvec result (*this);

  result.x = -result.x;
  result.y = -result.y;
  result.z = -result.z;

  return result;
}

//Overloaded multiplication operator. Multiplies the pntvec by a scalar
const pntvec pntvec::operator* (double scale) const
{
  pntvec result(*this);

  result.x = result.x * scale;
  result.y = result.y * scale;
  result.z = result.z * scale;

  return result;
}

//Overloaded equals operator. Sets this' points equal to the points of rhs
pntvec & pntvec::operator= (const pntvec & rhs)
{
  x = rhs.x;
  y = rhs.y;
  z = rhs.z;

  return *this;
}

//Returns this.x
double pntvec::get_x() const
{
  return x;
}

//Returns this.y
double pntvec::get_y() const
{
  return y;
}

//Returns this.z
double pntvec::get_z() const
{
  return z;
}

//Computes the distance between this, and the passed in pntvec p
double pntvec::distance_to(pntvec p) const
{
  //Declare variables
  double deltaX, deltaY, deltaZ;

  //Find the changes in x, y and z between the two pntvecs
  deltaX = std::abs(p.x - x);
  deltaY = std::abs(p.y - y);
  deltaZ = std::abs(p.z - z);

  //Return the square root of the deltas squared, which is the distance between the 2 points
  return sqrt((deltaX * deltaX) + (deltaY * deltaY) + (deltaZ * deltaZ));
}

//Returns a stream with (x, y, z) from the input pntvec
std::ostream & operator<< (std::ostream & stream, const pntvec & p)
{
  stream << "(" << p.x << ", " << p.y << ", " << p.z << ")"; 
  return stream;
}

//Should be able to do cin >> p; And it assign nums to p
std::istream & operator>> (std::istream & stream, pntvec & p)
{
  double x, y, z;
  stream >> x >> y >> z;
  
  p = pntvec(x, y, z);

  return stream;
}
