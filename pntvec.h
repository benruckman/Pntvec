/* 
 * This is a class delcaration for the class file pntvec.cpp
 *
 * A pntvec represents a point in 3D space. 
 *
 * Ben Ruckman
 * February 4, 2021
 */
#ifndef PNTVEC_H
#define PNTVEC_H

#include <iostream>

class pntvec
{
  //These are accessable through get methods. Shouldn't be able to change directly. 
 private: 
  double x;
  double y;
  double z;

 public:
  // Constructors
  pntvec ();
  pntvec (double x, double y, double z); 
  pntvec (const pntvec & other);

  //Get methods for x, y, and z
  double get_x() const;
  double get_y() const;
  double get_z() const;

  //Calculates the distance from this pntvec to pntvec b
  double distance_to(const pntvec b) const;

  //Overloaded operators for pntvec math
  pntvec & operator= (const pntvec &); 
  const pntvec operator+(const pntvec & rhs) const;
  const pntvec operator-(const pntvec & rhs) const;
  const pntvec operator*(double scale) const;

  //This is the negate operator (used like p = -p)
  const pntvec operator-() const;


  friend std::ostream & operator<< (std::ostream & stream, const pntvec & p);
  friend std::istream & operator>> (std::istream & stream, pntvec & p);
  
};

#endif
