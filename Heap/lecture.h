#pragma once
#include "header.h"

class Lecture
{
public:
	string name;
	float area;
	int n_doors;
	int x, y;
	int n_chair;

	void create_object(string name1, float area1, int n_doors1, int x1, int y1, int n_chair1)
	{
		this->name = name1;
		this->area = area1;
		this->n_doors = n_doors1;
		this->x = x1;
		this->y = y1;
		this->n_chair = n_chair1;
	}
};
