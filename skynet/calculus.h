#ifndef CALCULUS_H
#define CALCULUS_H
#include <cmath>
#include <vector>
#include <iostream>
#include "bubble.h"
constexpr float G = 6.67430e-11f;



Sizes desize( std::vector<CBubble>& );
std::vector<CVec> Accel( const std::vector<CBubble>& );
CVec GrFi( const CBubble&,  const CBubble& );
void Knot( std::vector<CBubble>&, const float );


Sizes desize( std::vector<CBubble>& Foam )
{
	CVec center_of_mass(0,0,0);
	double mass, time, length;
	for(const auto& Bubble : Foam)
	{
		mass += Bubble.get_Mass();
		center_of_mass += Bubble.get_Cord().dot( Bubble.get_Mass() );
		for(const auto& Rubble : Foam)
		{
			if(Bubble != Rubble)
			{
				length += ( Bubble.get_Cord() - Rubble.get_Cord() ).len();
			}

		}
	}
	
	center_of_mass = center_of_mass.dot( 1.0/mass );
	length /= Foam.size() * ( Foam.size() - 1 );
	time = sqrt( pow( length,3 )/( G * mass ) );

	for(auto& Bubble : Foam)
	{
		Bubble.change_Cord( ( Bubble.get_Cord() - center_of_mass ).dot( 1.0 / length ) );
		Bubble.change_Vel( Bubble.get_Vel().dot( time/length ) );
		Bubble.change_Mass( Bubble.get_Mass() / mass );
		Bubble.change_Rad( Bubble.get_Rad() / length );
	}	
	return {mass, length, time, center_of_mass};
}


void Knot( std::vector<CBubble>& Foam, const float dt ) 
{
	size_t N = Foam.size();
	std::vector<CVec> k1(N), k2(N), k3(N), k4(N), kv1(N), kv2(N), kv3(N), kv4(N),  acc(N);
	std::vector<CBubble> Temp = Foam;
//1
	acc = Accel(Foam);
	for (size_t i = 0; i < N; ++i) 
	{
		kv1.at(i) = acc.at(i).dot(dt);  
		k1.at(i) = Foam.at(i).get_Vel().dot(dt);  
	}
//2
	for (size_t i = 0; i < N; ++i) 
	{
		Temp.at(i).add_Cord(k1.at(i).dot(0.5));
		Temp.at(i).add_Vel(kv1.at(i).dot(0.5)); 
	}
	acc = Accel(Temp);
	for (size_t i = 0; i < N; ++i) 
	{
		kv2.at(i) = acc.at(i).dot(dt); 
		k2.at(i) = Temp.at(i).get_Vel().dot(dt); 
	}
//3
	Temp = Foam;
	for (size_t i = 0; i < N; ++i) {
		Temp.at(i).add_Cord(k2.at(i).dot(0.5)); 
		Temp.at(i).add_Vel(kv2.at(i).dot(0.5)); 
	}
	acc = Accel(Temp);
	for (size_t i = 0; i < N; ++i) 
	{
		kv3.at(i) = acc.at(i).dot(dt);
		k3.at(i) = Temp.at(i).get_Vel().dot(dt); 
	}
//4
	Temp = Foam;
	for (size_t i = 0; i < N; ++i) 
	{
		Temp.at(i).add_Cord(k3.at(i));  
		Temp.at(i).add_Vel(kv3.at(i)); 
	}
	
	for (size_t i = 0; i < N; ++i) 
	{
		kv4.at(i) = acc.at(i).dot(dt); 
		k4.at(i) = Temp.at(i).get_Vel().dot(dt); 
	}

	for (size_t i = 0; i < N; ++i) 
	{
        CVec delta_coord = (k1.at(i) + k2.at(i).dot(2) + k3.at(i).dot(2) + k4.at(i)).dot(1.0 / 6);
        CVec delta_vel = (kv1.at(i) + kv2.at(i).dot(2) + kv3.at(i).dot(2) + kv4.at(i)).dot(1.0 / 6);
        Foam.at(i).add_Cord(delta_coord);
        Foam.at(i).add_Vel(delta_vel);
	}
}


CVec GrFi( const CBubble& Obj1, const CBubble& Obj2 )//Расчет силы между двумя телами, обезразмеренными
{
	CVec C = Obj2.get_Cord() - Obj1.get_Cord();
	float r = C.len();
	if(r == 0)
	{
		throw std::invalid_argument("Тела слишком близко");
	}
	float k = Obj1.get_Mass() * Obj2.get_Mass() / pow(r,3);
	return C.dot(k); 
}

std::vector<CVec> Accel ( const std::vector<CBubble>& Foam )//Расчет равнодействующей силы, обезразмеренными
{	std::vector<CVec> Accel(Foam.size(),CVec(0, 0, 0));
	CVec Fi;
	for(size_t i = 0 ; i < Foam.size() - 1; ++i)
	{	
		for(size_t j = i + 1 ; j < Foam.size(); ++j)
		{	
			if(Foam.at(i) != Foam.at(j))

			{
				Fi =  GrFi(Foam.at(i), Foam.at(j));
				Accel.at(i) += Fi.dot( 1 / (Foam.at(i).get_Mass()) );
				Accel.at(j) -= Fi.dot( 1 / (Foam.at(j).get_Mass()) );
			}
		}
	}
	return Accel;
}
#endif
