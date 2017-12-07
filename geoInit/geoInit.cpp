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

int _tmain(int argc, _TCHAR* argv[])
{
	typedef Vec3<double> vec;
	
	unsigned bd1 = 0, bd2 = 0;
	vector<vec> p;
	vector<vec> u;
	vector<int> t;
	/*dambreak flow*/
	//for (int k = -BD; k <= iH+BD; k++) {
	//	for (int i = -BD; i <= iW+BD; i++) {
	//		vec r = vec(i*DP, 0., k*DP);
	//		vec v = vec(0., 0., 0.);
	//		//if (r.iH >= 0.5) continue;
	//		if (i < 0 || i > iW || k < 0 || k > iH) {
	//			bd2++;
	//			t.push_back(2);
	//			p.push_back(r);
	//			u.push_back(v);
	//		}
	//		else if (i == 0 || i == iW || k == 0 || k == iH) {
	//			bd1++;
	//			t.push_back(1);
	//			p.push_back(r);
	//			u.push_back(v);
	//		}
	//		else if(i < 0.2/DP && k < 0.4/DP){
	//			t.push_back(0);
	//			p.push_back(r);
	//			u.push_back(v);
	//		}
	//	}
	//}
	/*grad test*/
	//for (int k = 0; k < iH; k++) {
	//	for (int i = 0; i < iH-k; i++) {
	//		vec r = vec(i*DP, 0., k*DP);
	//		vec v = vec(double(i)+double(k), 0., 0.);
	//		t.push_back(0);
	//		p.push_back(r);
	//		u.push_back(v);
	//	}
	//}
	/*cavity flow*/
	//for (int k = -BD; k <= iH+BD; k++) {
	//	for (int i = -BD; i <= iH+BD; i++) {
	//		vec r = vec(i*DP, 0., k*DP);
	//		vec v = vec(0., 0., 0.);
	//		//if ((i <= 0 && k <= 0) || (i >= iH && k >= iH) || (i <= 0 && k >= iH) || (i >= iH && k <= 0)) continue;
	//		//if ((i >= iH && k >= iH)) continue;
	//		if (i < 0 || i > iH || k < 0 || k > iH) {
	//			if (k >= iH) v = vec(1., 0., 0.);
	//			bd2++;
	//			t.push_back(2);
	//			p.push_back(r);
	//			u.push_back(v);
	//		}
	//		else if (i == 0 || i == iH || k == 0 || k == iH) {
	//			if (k == iH) v = vec(1., 0., 0.);
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
	const static double dp = 1.0/80.0;
	const static double bw = 1.0;
	const static double bh = 1.0;
	const static int bd = 4;
	int iW = int(bw / dp);
	int iH = int(bh / dp);
	for (int k = -bd; k <= iH + bd; k++) {
		for (int i = -bd; i <= iW + bd; i++) {
			vec r = vec(i*dp, 0., k*dp);
			vec v = vec(0., 0., 0.);
			//if ((i <= 0 && k <= 0) || (i >= iH && k >= iH) || (i <= 0 && k >= iH) || (i >= iH && k <= 0)) continue;
			//if ((i >= iH && k >= iH)) continue;
			if (i < 0 || i > iW || k < 0 || k > iH) {
				if (k >= iH) v = vec(0., 0., 0.);
				bd2++;
				t.push_back(2);
				p.push_back(r);
				u.push_back(v);
			}
			else if (i == 0 || i == iW || k == 0 || k == iH) {
				if (k == iH) v = vec(0., 0., 0.);
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
	//for (int k = 0; k <= iH; k++) {
	//	for (int i = 0; i <= iH; i++) {
	//		vec r = vec(i*DP-0.5, 0., k*DP-0.5);
	//		vec v = vec(0., 0., 0.);
	//		t.push_back(0);
	//		p.push_back(r);
	//		u.push_back(v);
	//	}
	//}
	/*collision*/
	/*
	for (int k = 0; k < iH; k++) {
		for (int i = 0; i < iH; i++) {
			vec r = vec(i*DP, 0., k*DP);
			vec v = vec(0., 0., 0.);
			if (i < BD || i >= iH - BD || k < BD || k >= iH - BD) {
				bd2++;
				t.push_back(2);
				p.push_back(r);
				u.push_back(v);
			}
			else if (i == BD || i == iH - BD - 1 || k == BD || k == iH - BD - 1) {
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
	for (int k = 0; k < iH; k++) {
		for (int i = 0; i < iW; i++) {
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
	/*SPHERIC benchmark test6*/
	/*
	int cylinderLeft = int(1.0 / DP);
	int cylinderRight = int(2.0 / DP);
	int cylinderBottom = int(2.0 / DP);
	int cylinderTop = int(3.0 / DP);
	for (int k = -BD; k <= iH + BD; k++) {
		for (int i = -BD; i <= iW + BD; i++) {
			vec r = vec(i*DP, 0., k*DP);
			vec v = vec(0., 0., 0.);
			if (i == 0 || i == iW || k == 0 || k == iH) {
				bd1++;
				t.push_back(1);
				p.push_back(r);
				u.push_back(v);
			}
			else if ((i == cylinderLeft || i == cylinderRight) && (k >= cylinderBottom && k <= cylinderTop)) {
				bd1++;
				t.push_back(1);
				p.push_back(r);
				u.push_back(v);
			}
			else if ((k == cylinderBottom || k == cylinderTop) && (i >= cylinderLeft && i <= cylinderRight)) {
				bd1++;
				t.push_back(1);
				p.push_back(r);
				u.push_back(v);
			}
			else if (i > cylinderLeft && i < cylinderRight && k > cylinderBottom && k < cylinderTop) {
				continue;
			}
			else {
				t.push_back(0);
				p.push_back(r);
				u.push_back(v);
			}
		}
	}
	*/
	/*Blasius boundary layer*/
	/*
	for (int k = -BD; k <= iH + BD; k++) {
		for (int i = -BD; i <= iW + BD; i++) {
			vec r = vec(i*DP, 0., k*DP);
			vec v = vec(0., 0., 0.);
			if (k == 0 || k == iH) {
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
	*/
	/*Taylor-Green vortex*/
	/*
	for (int k = -BD; k <= iH + BD; k++) {
		for (int i = -BD; i <= iW + BD; i++) {
			vec r = vec(i*DP, 0., k*DP);
			vec v = vec(0., 0., 0.);
			t.push_back(0);
			p.push_back(r);
			u.push_back(v);
		}
	}
	*/
	/*backward-facing step*/
	//const double dp = 1.0 / 100.0;
	//const double bw = 3.0;
	//const double bh = 1.0;
	//const double bwoff = 1.0;
	//const double bhoff = 0.5;
	//const int bd = 1;
	//const int ih = int(bh / dp);
	//const int iw = int(bw / dp);
	//for (int k = 0; k <= ih; k++) {
	//	for (int i = 0; i <= iw; i++) {
	//		vec r = vec(i*dp, 0., k*dp);
	//		vec v = vec(0., 0., 0.);
	//		if (r.x < bwoff && r.z < bhoff) continue;
	//		if (k == 0 || k == ih || (abs(r.x - bwoff) <dp && r.z < bhoff) || (abs(r.z - bhoff) <dp && r.x < bwoff)) {
	//			bd1++;
	//			t.push_back(1);
	//			p.push_back(r);
	//			u.push_back(v);
	//		}
	//		else {
	//			t.push_back(0);
	//			p.push_back(r);
	//			u.push_back(v);
	//		}
	//	}
	//}

	ofstream file("Geo.in");
	file << "0." << endl;
	file << dp << endl;
	file << p.size() << " " << bd1 << " " << bd2 << endl;
	for (unsigned i = 0; i < p.size(); i++) {
		file << t[i] << " " << p[i].x << " " << p[i].z << " " << u[i].x << " " << u[i].z << endl;
	}
	cout << " p num: " << p.size() << endl;

	return 0;
}

