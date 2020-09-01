// V6.0.h : This file does NOT contain the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
//#include <bits/stdc++.h>


//using namespace std;

class STATS {

private:

	double holes = 0, yardage = 0, par = 0, putts = 0, strokes = 0, hit = 0, gir = 0;

public:

	double get_holes();
	double get_par(double i);
	double get_yardage(double i);
	double get_fairway_hit(double i);
	double get_GIR(double i);
	double get_putts(double i);
	double get_strokes(double i);

};



class Summary {

private:

	std::string plus = "+";


public:

	double summary(double tot_yardage, double tot_par, double tot_strokes, double i, double fairway_percent, double fairway_total, double tot_fairways_hit, double GIR_percent, double tot_GIR, double tot_putts);

};


// ============== INITIAL CLUB SETUP =========================

class Clubs {

private:


	std::string clubs[10] = { "Driver","4 Iron","5 Iron","6 Iron","7 Iron", "8 Iron","9 Iron", "Pitching Wedge", "Gap Wedge" };
	double LD = 0, HD = 0, L4 = 0, H4 = 0, L5 = 0, H5 = 0, L6 = 0, H6 = 0, L7 = 0, H7 = 0, L8 = 0, H8 = 0, L9 = 0, H9 = 0, LP = 0, HP = 0, LG = 0, HG = 0,
	D = 0, I4 = 0, I5 = 0, I6 = 0, I7 = 0, I8 = 0, I9 = 0, PW = 0, GW = 0;
	double club_distances[18] = { HD,LD,H4,L4,H5,L5,H6,L6,H7,L7,H8,L8,H9,L9,HP,LP,HG,LG };

	//for version 2
	double club_distancesV2[9] = {D, I4, I5, I6, I7, I8, I9, PW, GW};
	double good_distance = 0;

	//for version 1
	double good_distance1 = 0;
	double good_distance2 = 0;
	int i = 0;


public:

	//get the distance to target
	double get_club_distance();


	//error checking for club distances
	double check_distance(double distance, double club_distances[], int i);
	//error checking for lower distance
	double check_distance2(double distance, double good_distance1, int i);


	//version 2 error checking
	double check_distanceV2(double distance, double good_distance, int i);
	double get_clubV2();


	//choose club based on distance
	double get_club();
};
