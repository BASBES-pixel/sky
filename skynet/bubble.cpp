#include <iostream>
#include "bubble.h"

CBubble::CBubble(const std::string _Name, const CVec& _C, const CVec& _V, const float _M, const float _R): Name(_Name), Cord(_C), Vel(_V)
{ 
	if (_R <=  0)
	{
		throw std::invalid_argument("Радиус отрицателен");
	}
	if(_M <= 0)
	{
		throw std::invalid_argument("Масса отрицательна");
	}		
	Mass = _M; Rad = _R;
}

std::string CBubble:: get_Name()const{ return Name; }

CVec CBubble::get_Cord()const{ return Cord; }
		
CVec CBubble::get_Vel()const{ return Vel; }
		
float CBubble::get_Mass()const{ return Mass; }
		
float CBubble::get_Rad()const{ return Rad; }
	
void CBubble::change_Name(const std::string N)
{
	Name = N;
}


void CBubble::change_Cord(const CVec& _CV)
{
	Cord = _CV;
}
		
void CBubble::change_Vel(const CVec& _CV)
{
	Vel = _CV;
}

void CBubble::add_Cord(const CVec& _CV)
{
	Cord += _CV;
}

void CBubble::add_Vel(const CVec& _CV)
{
	Vel += _CV;
}


void CBubble::change_Mass(const float M)
{
	if(M > 0)
	{
		Mass = M;
	}
	else
	{
		throw std::invalid_argument("Масса отрицательна");
	}
}

void CBubble::change_Rad(const float R)
{
	if(R > 0)
	{
		Rad = R;
	}
	else
	{
		throw std::invalid_argument("Радиус отрицательен");
	}
}


