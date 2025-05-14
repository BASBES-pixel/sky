#ifndef BUBBLE_H
#define BUBBLE_H

#include "TrueVec.h"
#include <iostream>

struct Sizes
{
	double total_mass;
	double charac_length;
	double charac_time;
	CVec center_of_mass;
};

class CBubble
{	
	private:
		std::string Name;
		CVec Cord, Vel;
		float Mass, Rad;	
	
	public:
		CBubble(const std::string _Name, const CVec& _Cord, const CVec& _Vel, 
			const float _Mass, const float _Rad);
		std::string get_Name()const;
		CVec get_Cord()const;
		CVec get_Vel()const;
		float get_Mass()const;
		float get_Rad()const;
		void add_Cord(const CVec&);
		void add_Vel(const CVec&);
		void change_Name(const std::string);
		void change_Cord(const CVec&);
		void change_Vel(const CVec&);
		void change_Mass(const float);
		void change_Rad(const float);
		auto operator<=>(const CBubble& other) const = default;
};


inline std::ostream& operator<<(std::ostream& os, const CBubble& B)
{
	os<< B.get_Name() << "," << B.get_Mass() << "," << B.get_Rad() << "," << B.get_Cord() << "," << B.get_Vel();
	return os;
}
#endif
