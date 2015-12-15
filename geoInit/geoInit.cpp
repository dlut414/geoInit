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

const static double dp = 0.01;
const static double tl = 1.;
const static double th = 1.;
const static int bd = 3;

int _tmain(int argc, _TCHAR* argv[])
{
	typedef Vec3<double> vec;
	
	unsigned bd1 = 0, bd2 = 0;
	vector<vec> p;
	vector<vec> u;
	vector<int> t;
	int x = int(tl / dp);
	int z = int(th / dp);
	/*dambreak flow*/
	/*
	for (int k = -bd; k <= z+bd; k++) {
		for (int i = -bd; i <= x+bd; i++) {
			vec r = vec(i*dp, 0., k*dp);
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
			else if(i < 0.2/dp && k < 0.4/dp){
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
			vec r = vec(i*dp, 0., k*dp);
			vec v = vec(double(i)+double(k), 0., 0.);
			t.push_back(0);
			p.push_back(r);
			u.push_back(v);
		}
	}
	*/
	/*cavity flow*/
	//for (int k = -bd; k <= z+bd; k++) {
	//	for (int i = -bd; i <= z+bd; i++) {
	//		vec r = vec(i*dp, 0., k*dp);
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
	/*passive scalar*/
	for (int k = 0; k <= z; k++) {
		for (int i = 0; i <= z; i++) {
			vec r = vec(i*dp-0.5, 0., k*dp-0.5);
			vec v = vec(0., 0., 0.);
			t.push_back(0);
			p.push_back(r);
			u.push_back(v);
		}
	}
	/*collision*/
	/*
	for (int k = 0; k < z; k++) {
		for (int i = 0; i < z; i++) {
			vec r = vec(i*dp, 0., k*dp);
			vec v = vec(0., 0., 0.);
			if (i < bd || i >= z - bd || k < bd || k >= z - bd) {
				bd2++;
				t.push_back(2);
				p.push_back(r);
				u.push_back(v);
			}
			else if (i == bd || i == z - bd - 1 || k == bd || k == z - bd - 1) {
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
	//t.push_back(0); p.push_back(vec(0.25, 0., 0.25+dp)); u.push_back(vec(0., 0., 0.));
	*/
	/*boundary value problem*/
	/*
	for (int k = 0; k < z; k++) {
		for (int i = 0; i < x; i++) {
			vec r = vec(i*dp, 0., k*dp);
			vec v = vec(0., 0., 0.);
			if (0&&i < bd) {
				bd2++;
				t.push_back(2);
			}
			else if (0&&i==bd) {
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
	file << dp << endl;
	file << p.size() << " " << bd1 << " " << bd2 << endl;
	for (unsigned i = 0; i < p.size(); i++) {
		file << t[i] << " " << p[i].x << " " << p[i].y << " " << p[i].z << " " << u[i].x << " " << u[i].y << " " << u[i].z << endl;
	}
	cout << " p num: " << p.size() << endl;

	return 0;
}

