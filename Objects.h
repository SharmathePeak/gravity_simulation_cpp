#pragma once
#include<iostream>
#include<raylib.h>
#include<cmath>
#include<vector>
using namespace std;

class Object {
public:

	const double G = 6.67e-5;

	float mass;

	float x, y, z;

	float radius;

	float acceleration, distance;

	float vel_x = 0, vel_y = 0, vel_z = 0;

	Color color;

	Object(float x1, float y1, float z1, float mass1, float radius1, Color color1) {
		x = x1, y = y1, z = z1;
		mass = mass1;
		radius = radius1;
		color = color1;
		cout << "Object initialization complete;" << endl;
	}

	void DrawObject() {
		DrawSphere(Vector3{ x,y,z }, radius, color);
	}

	void Acceleration(Object other_mass) {
		float dx = other_mass.x - x, dy = other_mass.y - y, dz = other_mass.z - x;
		distance = sqrt(pow(x - other_mass.x, 2) + pow(x - other_mass.y, 2) + pow(z - other_mass.z, 2));
		acceleration = G * other_mass.mass / distance*distance;
		vel_x += acceleration * dx / distance;
		vel_y += acceleration * dy / distance;
		vel_z += acceleration * dz / distance;
	}

	void movement(Object other_mass) {
		Acceleration(other_mass);
		x += vel_x;
		y += vel_y;
		z += vel_z;
	}

};