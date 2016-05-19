/*
*/
// geoInit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "./common/typedef/Vec3.h"
using namespace std;

const static double DP = 1.0/120.0;
const static double BW = 1.0;
const static double BH = 8.0;
const static int BD = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	typedef Vec3<double> vec;
	
	unsigned bd1 = 0, bd2 = 0;
	vector<vec> p;
	vector<vec> u;
	vector<int> t;
	int x = int(BW / DP);
	int z = int(BH / DP);
	/*dambreak flow*/
	/*
	for (int k = -BD; k <= z+BD; k++) {
		for (int i = -BD; i <= x+BD; i++) {
			vec r = vec(i*DP, 0., k*DP);
			vec v = vec(0., 0., 0.);
			//if (r.z >= 0.5) continue;
			if (i < 0 || i > x || k < 0 || k > z) {
				bd2++;
				t.push_back(2);
				p.push_back(r);
				u.push_back(v);
			}
			else if (i == 0 || i == x || k == 0 || k == z) {
				bd1++;
				t.push_back(1);
				p.push_back(r);
				u.push_back(v);
			}
			else if(i < 0.2/DP && k < 0.4/DP){
				t.push_back(0);
				p.push_back(r);
				u.push_back(v);
			}
		}
	}
	*/
	/*grad test*/
	/*
	for (int k = 0; k < z; k++) {
		for (int i = 0; i < z-k; i++) {
			vec r = vec(i*DP, 0., k*DP);
			vec v = vec(double(i)+double(k), 0., 0.);
			t.push_back(0);
			p.push_back(r);
			u.push_back(v);
		}
	}
	*/
	/*cavity flow*/
	//for (int k = -BD; k <= z+BD; k++) {
	//	for (int i = -BD; i <= z+BD; i++) {
	//		vec r = vec(i*DP, 0., k*DP);
	//		vec v = vec(0., 0., 0.);
	//		//if ((i <= 0 && k <= 0) || (i >= z && k >= z) || (i <= 0 && k >= z) || (i >= z && k <= 0)) continue;
	//		//if ((i >= z && k >= z)) continue;
	//		if (i < 0 || i > z || k < 0 || k > z) {
	//			if (k >= z) v = vec(1., 0., 0.);
	//			bd2++;
	//			t.push_back(2);
	//			p.push_back(r);
	//			u.push_back(v);
	//		}
	//		else if (i == 0 || i == z || k == 0 || k == z) {
	//			if (k == z) v = vec(1., 0., 0.);
	//			bd1++;
	//			t.push_back(1);
	//			p.push_back(r);
	//			u.push_back(v);
	//		}
	//		else{
	//			t.push_back(0);
	//			p.push_back(r);
	//			u.push_back(v);
	//		}
	//	}
	//}
	/*thermal cavity flow*/
	for (int k = -BD; k <= z + BD; k++) {
		for (int i = -BD; i <= z + BD; i++) {
			vec r = vec(i*DP, 0., k*DP);
			vec v = vec(0., 0., 0.);
			//if ((i <= 0 && k <= 0) || (i >= z && k >= z) || (i <= 0 && k >= z) || (i >= z && k <= 0)) continue;
			//if ((i >= z && k >= z)) continue;
			if (i < 0 || i > z || k < 0 || k > z) {
				if (k >= z) v = vec(0., 0., 0.);
				bd2++;
				t.push_back(2);
				p.push_back(r);
				u.push_back(v);
			}
			else if (i == 0 || i == z || k == 0 || k == z) {
				if (k == z) v = vec(0., 0., 0.);
				bd1++;
				t.push_back(1);
				p.push_back(r);
				u.push_back(v);
			}
			else {
				t.push_back(0);
				p.push_back(r);
				u.push_back(v);
			}
		}
	}
	/*passive scalar*/
	//for (int k = 0; k <= z; k++) {
	//	for (int i = 0; i <= z; i++) {
	//		vec r = vec(i*DP-0.5, 0., k*DP-0.5);
	//		vec v = vec(0., 0., 0.);
	//		t.push_back(0);
	//		p.push_back(r);
	//		u.push_back(v);
	//	}
	//}
	/*collision*/
	/*
	for (int k = 0; k < z; k++) {
		for (int i = 0; i < z; i++) {
			vec r = vec(i*DP, 0., k*DP);
			vec v = vec(0., 0., 0.);
			if (i < BD || i >= z - BD || k < BD || k >= z - BD) {
				bd2++;
				t.push_back(2);
				p.push_back(r);
				u.push_back(v);
			}
			else if (i == BD || i == z - BD - 1 || k == BD || k == z - BD - 1) {
				bd1++;
				t.push_back(1);
				p.push_back(r);
				u.push_back(v);
			}
		}
	}
	t.push_back(0); p.push_back(vec(0.2525, 0., 0.2575)); u.push_back(vec(0., 0., 5.));
	t.push_back(0); p.push_back(vec(0.2525, 0., 0.2525)); u.push_back(vec(0., 0., -5.));
	//t.push_back(0); p.push_back(vec(0.25, 0., 0.25)); u.push_back(vec(0., 0., -5.));
	//t.push_back(0); p.push_back(vec(0.25, 0., 0.25+DP)); u.push_back(vec(0., 0., 0.));
	*/
	/*boundary value problem*/
	/*
	for (int k = 0; k < z; k++) {
		for (int i = 0; i < x; i++) {
			vec r = vec(i*DP, 0., k*DP);
			vec v = vec(0., 0., 0.);
			if (0&&i < BD) {
				bd2++;
				t.push_back(2);
			}
			else if (0&&i==BD) {
				bd1++;
				t.push_back(1);
			}
			else {
				t.push_back(0);
			}
			p.push_back(r);
			u.push_back(v);
		}
	}
	*/

	ofstream file("Geo.in");
	file << "0." << endl;
	file << DP << endl;
	file << p.size() << " " << bd1 << " " << bd2 << endl;
	for (unsigned i = 0; i < p.size(); i++) {
		file << t[i] << " " << p[i].x << " " << p[i].z << " " << u[i].x << " " << u[i].z << endl;
	}
	cout << " p num: " << p.size() << endl;

	return 0;
}

