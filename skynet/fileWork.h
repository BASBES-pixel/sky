#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "bubble.h"
#include "TrueVec.h"

std::vector<CBubble> readFile(const std::string& filename) {
	std::vector<CBubble> Foam;
	std::ifstream file(filename);
	std::string line;

	if (!file.is_open()) {
		throw std::runtime_error("Не удалось открыть файл: " + filename);
	}

	std::string name;
	float radius = 0, mass = 0;
	CVec coordinate, velocity;

	while (std::getline(file, line)) 
	{
		if (line.find('{') != std::string::npos) 
		{
	
			name = "";
			radius = 0;
			mass = 0;
			coordinate = CVec();
			velocity = CVec();
			continue;
		}

		if (line.find('}') != std::string::npos)
		{
	
			if (!name.empty()) 
			{
				Foam.emplace_back(name, coordinate, velocity, mass, radius);
			}
		continue;
		}


		std::istringstream iss(line);
		std::string key, sep;
		iss >> key >> sep;

		if (key == "Name") 
		{
			iss >> name;
			if (!name.empty() && name.back() == ';') 
			{
				name.pop_back();
			}
		} 
		else if (key == "Radius") 
		{
			iss >> radius;
		} 
	        else if (key == "Mass") {
			iss >> mass;
		} 
		else if (key == "Coordinate") 
		{
			char sep;
			float x, y, z;
			iss >> sep >> x >> sep >> y >> sep >> z;
			coordinate = CVec(x, y, z);
		} 
		else if (key == "Velocity") 
		{
			char sep;
			float x, y, z;
			iss >> sep >> x >> sep >> y >> sep >> z;
			velocity = CVec(x, y, z);
		}
	}

	return Foam;
}


void writeCSV( const std::vector<CBubble>& bubbles, const std::string& filename, double step, Sizes Size) 
{
	std::ofstream file(filename, std::ios::app); 
	if (!file.is_open()) 
	{
		throw std::runtime_error( "Failed to open file: " + filename );
	}

	if (step == 0) 
	{
		file << "Sizes: Mass = "<< Size.total_mass<<", Length = "<< Size.charac_length
			<<", Time = "<< Size.charac_time <<", Center of Mass = "<< Size.center_of_mass <<".\n"
		     <<"Step,Name,Mass,Radius,X,Y,Z,VelX,VelY,VelZ\n";
	}

	for (const auto& bubble : bubbles) 
	{
		file << step << ","<< bubble << "\n";
	}

	file.close();
}

