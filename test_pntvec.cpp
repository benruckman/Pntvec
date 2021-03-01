/*
 * Tester class for pntvec.cpp
 *
 * Ben Ruckman
 * February 4, 2021
 */

#include <iostream>
#include <sstream>
#include <string>
#include "pntvec.h"

//Declaring helper methods before main, so they are able to be called in main
bool test_default_constructor();
bool test_constructor();
bool test_copy_constructor();
bool test_multiply_operator();
bool test_subtract_operator();
bool test_add_operator();
bool test_equals_operator();
bool test_negate_operator();
bool test_distance_between_pntvecs();
bool test_iStream();
bool test_oStream();


int main()
{
  //This if chain is basically unit tests, of if a constructor or other method works, it returns false, and goes to the next method.
  //If the method doesn't work, then it returns true which causes main to print an error, and return -1
  if(test_default_constructor())
    {
      std::cout << "Error in default constructor" << std::endl;
      return -1;
    }
  if(test_constructor())
    {
      std::cout << "Error in constructor" << std::endl;
      return -1;
    }
  if(test_copy_constructor())
    {
      std::cout << "Error in copy constructor" << std::endl;
      return -1;
    }
  if(test_multiply_operator())
    {
      std::cout << "Error in multiply operator" << std::endl;
      return -1;
    }
  if(test_subtract_operator())
    {
      std::cout << "Error in subtract operator" << std::endl;
      return -1;
    }
  if(test_add_operator())
    {
      std::cout << "Error in add operator" << std::endl;
      return -1;
    }
  if(test_equals_operator())
    {
      std::cout << "Error in equals operator" << std::endl;
      return -1;
    }
  if(test_negate_operator())
    {
      std::cout << "Error in negate operator" << std::endl;
      return -1;
    }
  if(test_distance_between_pntvecs())
    {
      std::cout << "Error in distance to method" << std::endl;
      return -1;
    }
if(test_iStream())
    {
      std::cout << "Error in iStream method" << std::endl;
      return -1;
    }
if(test_oStream())
    {
      std::cout << "Error in oStream method" << std::endl;
      return -1;
    }
  
  
  //If it makes it through all tests print "No error" and return 0
  std::cout << "No error" << std::endl;
  return 0;
};

//Basic test for tesing the default constructor
bool test_default_constructor()
{
  pntvec def = pntvec(); //x = 0, y = 0, z = 0
  
  if(def.get_x() != 0 || def.get_y() != 0 || def.get_z() != 0)
    {
      return true;
    }   
  return false;
}

//Basic test for testing the constructor with points
bool test_constructor()
{
  pntvec def = pntvec(-2.0, 6.0, 7.1); //x = -2.0, y = 6.0, z = 7.1
  
  if(def.get_x() != -2.0 || def.get_y() != 6.0 || def.get_z() != 7.1)
    {
      return true;
    }   
  return false;
}

//Basic test for the copy constructor
bool test_copy_constructor()
{
  pntvec def = pntvec(2.0, 6.0, -7.1);
  pntvec copy = pntvec(def); //x = 2.0, y = 6.0, z = -7.1
  
  if(copy.get_x() != 2.0 || copy.get_y() != 6.0 || copy.get_z() != -7.1)
    {
      return true;
    }   
  return false;
}

//Basic test for the overloaded multiply operator
bool test_multiply_operator()
{
  pntvec def = pntvec(1.0, -7.0, 150);
  def = def * 0; //x = 0, y = 0, z = 0
  
  if(def.get_x() != 0 || def.get_y() != 0 || def.get_z() != 0)
    {
      return true;
    }   
  
  pntvec p = pntvec(1.0, 2.0, -3.0);
  p = p * 3.0; //x = 3.0, y = 6.0, z = -9.0
  
  if(p.get_x() != 3.0 || p.get_y() != 6.0 || p.get_z() != -9.0)
    {
      return true;
    } 
  
  p = p * 1.0; //x = 3.0, y = 6.0, z = -9.0
  if(p.get_x() != 3.0 || p.get_y() != 6.0 || p.get_z() !=- 9.0)
    {
      return true;
    }   
  
  p = p * -.5; //x = -1.5, y = -3.0, z = 4.5
  if(p.get_x() != -1.5 || p.get_y() != -3.0 || p.get_z() != 4.5)
    {
      return true;
    }   
  
  return false;
}

//Basic test for the overloaded subtraction operator
bool test_subtract_operator()
{
  pntvec def = pntvec(); //Makes sure that minus 0 doesn't do anything weird
  pntvec one = pntvec(1.0, 1.0, 1.0);
  pntvec ten = pntvec(1000.0, 1000.0, 1000.0);
  
  for(int i = 999; i >-1000; i--) //Loops through 999 to -999 and checks to make sure that ten is actually being subtracted by one each time for x, y, and z
    {
      ten = ten - one - def;
      if(ten.get_x() != i || ten.get_y() != i || ten.get_z() != i)
	return true;
    }

  one = one - pntvec(7.0, 6.0, -10.0);
  
  if(one.get_x() != -6.0 || one.get_y() != -5.0 || one.get_z() != 11.0)
    return true;

  return false;
}

//Basic test for the overloard addition operator
bool test_add_operator()
{
  pntvec def = pntvec();
  pntvec one = pntvec(1.0, 1.0, 1.0);
  pntvec ten = pntvec(-10.0, -10.0, -10.0);
  
  for(int i = -9; i < 300; i++) //Loops through 11 to 29, making sure that ten's value is added by 1 each time
    {
      ten = ten + one + def;
      if(ten.get_x() != i || ten.get_y() != i || ten.get_z() != i)
	return true;
    }
  
  return false;
}

//Basic test for overloaded equals operator
bool test_equals_operator()
{
  pntvec def = pntvec();
  pntvec pnt = pntvec(2.0, 3.0, 1.0);
  
  def = pnt; //Def should now have pnt's values
  
  if(def.get_x() != 2.0 || def.get_y() != 3.0 || pnt.get_z() != 1.0)
    {
      return true;
    }   
  
  pntvec newPnt = pntvec();
  pnt = pntvec(199.99, 17.38, -15.4);

  newPnt = pnt; //newPnt should now have pnt's values
  
  pnt = newPnt;

  newPnt = pnt; //Some just in case tests
  
  if(newPnt.get_x() != 199.99 || newPnt.get_y() != 17.38 || newPnt.get_z() != -15.4)
    {
      return true;
    }
  
  return false;
}

//Basic test for overloaded negate operator
bool test_negate_operator()
{
  pntvec def = pntvec();
  def = -def; //-0 = 0
  
  if(def.get_x() != 0 || def.get_y() != 0 || def.get_z() != 0)
    {
      return true;
    }   
  
  pntvec p = pntvec(7.0, -4.0, 7.5);
  def = -p; //x = -7.0, y = 4.0, z = -7.5
  
  if(def.get_x() != -7.0 || def.get_y() != 4.0 || def.get_z() != -7.5)
    {
      return true;
    }   
  
  return false;
}

//Basic test for distance between 2 pntvecs
bool test_distance_between_pntvecs()
{
  pntvec def = pntvec();
  pntvec def2 = pntvec();
  
  //Distance between 2 default points should be 0
  if(def.distance_to(def2) != 0)
    {
      return true;
    }
  
  pntvec pnt = pntvec(1.0, 2.0, 3.0);
  
  //Distance here is  3.74166
  if(def.distance_to(pnt) == 3.74166)
    {
     return true;
    }
  
  pnt = pntvec(-17.0, 102.0, -55.0);
  pntvec newPnt = pntvec(110.0, -13.0, 104.0);
  

  //Distance here is 233.741
  if(pnt.distance_to(newPnt) == 233.741)
    {
      return true;
    }


  return false;
}

//Simple test for in stream on the pntvec class
bool test_iStream()
{
  pntvec p = pntvec();

  std::stringstream stream;
  stream << "1.0 3.0 7.0";

  stream >> p;
  if(p.get_x() != 1.0 || p.get_y() != 3.0 || p.get_z() != 7.0)
    {
      return true;
    }
  std::stringstream stream2;
  stream2 << "17.0 -11.0 8.7        hi there      17   "; //It should just look at the first 3 numbers

  stream2 >> p;
  if(p.get_x() != 17.0 || p.get_y() != -11.0 || p.get_z() != 8.7)
    {
      return true;
    }

  return false;
}

//Simple test for out stream on the pntvec class
bool test_oStream()
{
  pntvec p = pntvec();

  std::stringstream stream;
  std::stringstream streamPoint;

  stream << "(0, 0, 0)";  
  streamPoint << p;

  if(stream.str() != streamPoint.str())
    {
      return true;
    }

  p = pntvec(-7.3, -17.0, 11.0);

  std::stringstream stream2;
  std::stringstream streamPoint2;

  stream2 << "(-7.3, -17, 11)";
  streamPoint2 << p;

 if(stream2.str() != streamPoint2.str())
    {
      return true;
    }

  return false;
}
