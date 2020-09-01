// PC3.0.cpp : This file does contain the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string.h>
#include "PC3.0.h"

using namespace std;


#define VERSION_1  1
#define VERSION_2  2

#define VERSION  2

/** \mainpage Pocket Caddy Version 3
* \section v1 Introduction

        Pocket Caddy is a simple console application to keep simple, as well as some advanced statistics such as:

        Strokes (score)

        Course yardage

        Putts

        GIR (greens in regulation) with percentage

        Fairways hit with percentage

        Course par

        VERSIONS

        The application has 2 versions, the versions differetiate mostly within the club setup portion and how collisions happen choosing a yardage.
        Version 1 creates a range for each clubs yardage, using upper and lower distances entered for each particular club.
        Version 2 uses an average distance for each club, which creates a range linking each clubs average distance to the next.

        PLAYING A ROUND

        You will start by choosing 9 or 18 holes and setting up club distances.
        After that simply follow prompts given throughout each hole to get a detailed statistical summary of your round.

        SAVING A ROUND

        When you complete a round, an outfile feature allows you to save your round within a text file on your computer
        (phone hopefully in the future) if you choose.

* \section v2 Club Setup

***** \subsection step1 Club Setup Version 1

        Uses macro to choose pre determined version.

        Version 1 creates a range for each clubs yardage,
        using upper and lower distances entered for each particular club.

***** \subsection step2 Club Setup Version 2

        Uses macro to choose pre determined version.

        Version 2 uses an average distance for each club,
        which creates a range linking each clubs average distance to the next.

***** \subsection step3 Club Setup Error Checking

        Functions check_distance, check_distance2 ane check_distanceV2 to check club distance inputs.

        check_distanceV2 makes sure club distance is lower than the previous clubs distance.

        check_distance and check_distance2 makes sure the previous clubs lower distance
        is higher than the current clubs upper distance.

        All functions check to make sure the club distance is atleast over 30
        and lower than 400.

        Version 2 only uses one funciton for checking compared to 2
        for version 1.



* \section v3 Stats

***** \subsection step4 get_holes

        Aquires the amount of holes to be played.

        Uses error checking to make sure
        amount of holes input is 9 or 18.

***** \subsection step5 get_par

        Aquires the number of par for the hole.

        Uses error checking to make sure
        par input is 3, 4, or 5.


***** \subsection step6 get_yardage

        Aquires the yardage of the hole being played.

        Uses error checking to make sure
        yardage is above 75 and under 700 yards.


***** \subsection step7 get_fairway_hit


        Adds 1 for a fairway hit on that particular hole.

        If hole is a par 3 this function is skipped
        since par 3 fairways do not exist.


***** \subsection step8 get_GIR:

        Counter for Greens hit in regulation.

        Adds 1 for a green hit in regulation.

        This function should be invoked for
        each hole since each hole has a green,
        unlike fairways.


***** \subsection step9 get_putts

        Uses error checking to make sure
        amount of putts is under 11.

        Putts could be 0 on the rare chance of a hole in 1.


***** \subsection step10 get_strokes

        Gets total strokes for the hole.

        Error checking for total strokes
        must be between 1 and 10.

        Total strokes should be atleast 1 more
        than putt amount.

        Unless putt amount is 10 for that particular hole
        then total strokes will be 10.

***** \subsection step11 Summary

        Summary function outputs various stats after each holes.

        Outputs stats such as; Overall score, total strokes, total yards, fairway hit percentage,
        GIR (green in regulation) percentage, and total putts.

* \section v4 Outfile Summary

        Outfile summary allows the user to save the round to a text file.

        The outfile feature allows the user to save all stats gathered
        throughout the round.

        Also allows the user to save the date of the round and the course played at.

*/
//END MAINPAGE



double STATS::get_holes() {

    /*
    Gets the amount of holes to be played

    Uses error checking to make sure
    amount of holes input is 9 or 18
    */


    cout << "Enter number of holes (9 or 18): " << '\n';
    cin >> holes;


    //error checking for number of holes must be 9 or 18
    while (!cin || holes != 9.0 && holes != 18.0) {

        cout << "\n";
        cout << "***ERROR****\n";
        cout << "\n";

        cout << "Must enter 9 or 18, try again:" << '\n';
        cin.clear();
        cin.ignore();
        cin >> holes;


    }


    return holes;

}

double STATS::get_par(double i) {

    /*
    Gets the number of par for the hole

    Uses error checking to make sure
    par input is 3, 4, or 5
    */


    cout << "Enter par for hole " << i << ": " << '\n';
    cin >> par;


    //error checking for par must be 3,4 or 5
    while (!cin || par != 3.0 && par != 4.0 && par != 5.0) {

        cout << "\n";
        cout << "***ERROR****\n";
        cout << "\n";

        cout << "Must enter 3, 4 or 5, try again:" << '\n';
        cin.clear();
        cin.ignore();
        cin >> par;

    }

    return par;


}


double STATS::get_yardage(double i){
    /*
    Gets the yardage of the hole being played

    Uses error checking to make sure
    yardage is above 75 and under 700 yards
    */


    cout << "Enter yardage for hole " << i << ": " << '\n';

    cin >> yardage;


    //error checking yardage must be between 75 and 700 yards
    while (!cin || yardage <= 75.0 || yardage >= 700.0) {

        cout << "\n";
        cout << "***ERROR****\n";
        cout << "\n";

        cout << "Must be between 75 and 700 yards try again:" << '\n';
        cin.clear();
        cin.ignore();
        cin >> yardage;

    }



    return yardage;

}



double  STATS::get_fairway_hit(double i) {

    /*
    Counter for fairways hit

    Adds 1 for a fairway hit on that particular hole

    If hole is a par 3 this function is skipped
    since par 3 fairways do not exist
    */

    cout << "Did you hit the Fairway on hole: " << i << " (1 yes , 0 no) " << '\n';
    cin >> hit;


    //error checking for correct input must be 0 or 1
    while (!cin || hit != 0.0 && hit != 1.0) {

        cout << "\n";
        cout << "***ERROR****\n";
        cout << "\n";

        cout << "Must enter (1) yes or (0) no, try again:" << '\n';
        cin.clear();
        cin.ignore();
        cin >> hit;

    }

    return hit;

}



double STATS::get_GIR(double i) {

    /*
    Counter for GIR

    Adds 1 for a green hit in regulation

    This function should be invoked for
    each hole since each hole has a green,
    unlike fairways
    */

    cout << "Did you hit the green in regulation on hole: " << i << " (1 yes, 0 no)" << '\n';
    cin >> gir;


    //error checking for GIR must be 1 or 0
    while (!cin || gir != 0.0 && gir != 1.0) {

        cout << "\n";
        cout << "***ERROR****\n";
        cout << "\n";

        cout << "Must enter (1) yes or (0) no, try again:" << '\n';
        cin.clear();
        cin.ignore();
        cin >> gir;

    }


    return gir;

}

double STATS::get_putts(double i) {

    /*
    Gets amount of putts for the hole

    Uses error checking to make sure
    amount of putts is under 11

    Putts could be 0 on the rare chance of a hole in 1
    */

    cout << "Enter number of putts for hole " << i << ":\n";
    cin >> putts;


    //error checking for putts must be under 10
    while (!cin || putts > 10) {

        cout << "\n";
        cout << "***ERROR****\n";
        cout << "\n";

        cout << "Number of putts must be between 0 and 10, try again:" << '\n';
        cin.clear();
        cin.ignore();
        cin >> putts;
    }
    return putts;

}

double STATS::get_strokes(double i) {

    /*
    Gets total strokes for the hole

    Error checking for total strokes
    must be between 1 and 10

    Total strokes should be atleast 1 more
    than putt amount.
    Unless putt amount is 10 for that particular hole
    then total strokes should be 10
    (needs to be added)
    */

    cout << "Enter total strokes for hole " << i << ":\n";
    cin >> strokes;


    //error checking for strokes must be atleast 1 and under 10
    while (!cin || strokes < 1.0 || strokes > 10.0) {


        //if strokes are over 10
        //else must be over 1

        if (strokes > 10) {

            cout << "\n";
            cout << "***ERROR****\n";
            cout << "\n";

            cout << "Max strokes is 10, try again:" << '\n';
            cin.clear();
            cin.ignore();
            cin >> strokes;
        }

        else {

            cout << "\n";
            cout << "***ERROR****\n";
            cout << "\n";

            cout << "Must be between 1 and 10  try again:" << '\n';
            cin.clear();
            cin.ignore();
            cin >> strokes;
        }

    }


    return strokes;


}




double Clubs::get_club_distance() {


    /*
    Club setup for both versions

    Uses macro to choose pre determined version

    Version 1 creates a range for each clubs yardage,
    using upper and lower distances entered for each particular club.

    Version 2 uses an average distance for each club,
    which creates a range linking each clubs average distance to the next.
    */


    double distance = 0;

    cout << "Starting club setup..... \n";



    //macro to check for version

    #if VERSION == VERSION_1

    int i = 0;

    for (int k = 0; k < 9; k++) {



        cout << "Enter upper distance for, ";

        cout << clubs[k] << " : ";
        cin >> distance;

        good_distance1 = check_distance(distance, club_distances, i);


        club_distances[i] = good_distance1;

        i++;


        //gets lower club distance
        cout << "Enter lower distance for, ";
        cout << clubs[k] << " : ";
        cin >> distance;

        //error checking for lower distance
        good_distance2 = check_distance2(distance, good_distance1, i);


        club_distances[i] = good_distance2;

        i++;


    }


    //assigns clubs upper and lower distances
    HD = club_distances[0];
    LD = club_distances[1];
    H4 = club_distances[2];
    L4 = club_distances[3];
    H5 = club_distances[4];
    L5 = club_distances[5];
    H6 = club_distances[6];
    L6 = club_distances[7];
    H7 = club_distances[8];
    L7 = club_distances[9];
    H8 = club_distances[10];
    L8 = club_distances[11];
    H9 = club_distances[12];
    L9 = club_distances[13];
    HP = club_distances[14];
    LP = club_distances[15];
    HG = club_distances[16];
    LG = club_distances[17];



/*

    //hard testing for club distances

    HD = 310;
    LD = 280;
    H4 = 280;
    L4 = 250;
    H5 = 250;
    L5 = 220;
    H6 = 220;
    L6 = 200;
    H7 = 200;
    L7 = 180;
    H8 = 180;
    L8 = 150;
    H9 = 150;
    L9 = 130;
    HP = 130;
    LP = 110;
    HG = 110;
    LG = 80;

*/



    #else


    int i = 0;

    for (int k = 0; k < 9; k++) {



        //gets upper club distance
        cout << "Enter average distance for, ";

        cout << clubs[k] << " : ";
        cin >> distance;

        good_distance = check_distanceV2(distance, good_distance, i);


        club_distancesV2[i] = good_distance;

        i++;


    }

    //assign distances
    D = club_distancesV2[0];
    I4 = club_distancesV2[1];
    I5 = club_distancesV2[2];
    I6 = club_distancesV2[3];
    I7 = club_distancesV2[4];
    I8 = club_distancesV2[5];
    I9 = club_distancesV2[6];
    PW = club_distancesV2[7];
    GW = club_distancesV2[8];



/*

    //Hard testing for club distances
    D = 250;
    I4 = 200;
    I5 = 180;
    I6 = 170;
    I7 = 160;
    I8 = 150;
    I9 = 130;
    PW = 110;
    GW = 90;
*/


    #endif

    cout << "End club setup... \n";

    return 0;

}



double Clubs::check_distanceV2(double distance, double good_distance , int i) {


    /*
    Check club distance for Version 2

    Makes sure club distance is lower than the previous clubs distance

    Also checks to make sure the club distance is atleast over 30
    and lower than 400

    Version 2 only uses one funciton for checking compared to 2
    for version 1
    */



    //needs to be second club to compare
    if (i >= 1) {

            while (good_distance <= distance) {

            cout << "\n";
            cout << "***ERROR****\n";
            cout << "\n";

            cout << "Club distance needs to be lower than the previous clubs distance (" << club_distancesV2[i-1] << ") try again:" << '\n';
            cin.clear();
            cin.ignore();
            cin >> distance;
        }

    }



    // error checking to make sure distance is in upper and lower range
    while (!cin || distance < 30.0 || distance > 400.0) {

        if (distance > 400) {

            cout << "\n";
            cout << "***ERROR****\n";
            cout << "\n";

            cout << "Max club distance is 400 yards, try again:" << '\n';
            cin.clear();
            cin.ignore();
            cin >> distance;
        }
        else {

            cout << "\n";
            cout << "***ERROR****\n";
            cout << "\n";

            cout << "Club distance must be above 30 yards, try again:" << '\n';
            cin.clear();
            cin.ignore();
            cin >> distance;
        }
        i++;

    }
    return distance;

}




double Clubs::check_distance(double distance, double club_distances[], int i) {

    /*
    Check club distance for Version 1

    Makes sure the previous clubs lower distance is higher than the
    current clubs upper distance

    Also checks to make sure the club distance is atleast over 30
    and lower than 400

    */


    // needs to be atleast second club
    if (i > 1) {
        while (club_distances[i - 1] < distance) {

            cout << "\n";
            cout << "***ERROR****\n";
            cout << "\n";

            cout << "Upper club distance needs to be lower than the previous clubs lower distance (" << club_distances[i - 1] << ") try again:" << '\n';
            cin.clear();
            cin.ignore();
            cin >> distance;
        }

    }


    // error checking to make sure distance is in upper and lower range
    while (!cin || distance < 30.0 || distance > 400.0) {

        if (distance > 400) {

            cout << "\n";
            cout << "***ERROR****\n";
            cout << "\n";

            cout << "Max club distance is 400 yards, try again:" << '\n';
            cin.clear();
            cin.ignore();
            cin >> distance;
        }
        else {

            cout << "\n";
            cout << "***ERROR****\n";
            cout << "\n";

            cout << "Club distance must be above 30 yards, try again:" << '\n';
            cin.clear();
            cin.ignore();
            cin >> distance;
        }
        i++;

    }
    return distance;

}


double Clubs::check_distance2(double distance, double good_distance1, int i) {

    /*
    Check club distance for Version 1

    Makes sure the previous clubs lower distance is higher than the
    current clubs upper distance

    Also checks to make sure the club distance is atleast over 30
    and lower than 400

    */


    //Error checking
    while (!cin || distance > 20.0 || distance < 400.0) {

        //checks to make sure the lower distance is lower than the upper distance
        if (distance >= good_distance1) {

            cout << "\n";
            cout << "***ERROR****\n";
            cout << "\n";

            cout << "The clubs lower distance must be lower than its upper distance (" << club_distances[i - 1] << ") try again:" << '\n';
            cin.clear();
            cin.ignore();
            cin >> distance;

        }
        else {
            break;
        }

    }


    //checks to make sure the club distance is above 20 yards and below 400 yards
    while (!cin || distance < 20.0 || distance > 400.0) {

        if (distance > 400) {

            cout << "\n";
            cout << "***ERROR****\n";
            cout << "\n";

            cout << "Max club distance is 400 yards, try again:" << '\n';
            cin.clear();
            cin.ignore();
            cin >> distance;
        }
        else if (distance < 20) {

            cout << "\n";
            cout << "***ERROR****\n";
            cout << "\n";

            cout << "Club distance must be above 20 yards, try again:" << '\n';
            cin.clear();
            cin.ignore();
            cin >> distance;
        }



    }
    return distance;

}



double Clubs::get_club() {

    /*

    Gets club choice using version 1

    using a target distance entered this function
    chooses a club based on the version 1 club setup method

    also error checks to make sure target entered is
    between upper driver distance and low gap wedge distance

    */

    //target
    double t;

    //gets initial target distance
    cout << "Enter target distance you want to hit to : " << '\n';
    cin >> t;

    cout << "target = " << t << '\n';

    //checks if target entered is higher than the upper driver limit
    while (t > HD || t < LG) {

        cout << "\n";
        cout << "***ERROR****\n";
        cout << "\n";

        cout << "Target must be between driver distance: (" << HD << ") and gap wedge distance: (" << LG << "). Try again:" << '\n';
        cin.clear();
        cin.ignore();
        cin >> t;
    }

    if (t > HD) {
        cout << "Target is greater than upper driver limit" << '\n';
    }
    else if (t <= HD && t >= LD) {
        cout << "Driver is recommended " << '\n';
    }
    else if (t <= H4 && t >= L4) {
        cout << "4 Iron is recommended " << '\n';
    }
    else if (t <= H5 && t >= L5) {
        cout << "5 Iron is recommended " << '\n';
    }
    else if (t <= H6 && t >= L6) {
        cout << "6 Iron is recommended " << '\n';
    }
    else if (t <= H7 && t >= L7) {
        cout << "7 Iron is recommended " << '\n';
    }
    else if (t <= H8 && t >= L8) {
        cout << "8 Iron is recommended " << '\n';
    }
    else if (t <= H9 && t >= L9) {
        cout << "9 Iron is recommended " << '\n';
    }
    else if (t <= HP && t >= LP) {
        cout << "Pitching Wedge is recommended " << '\n';
    }
    else if (t <= HG && t >= LG) {
        cout << "Gap/Approach Wedge is recommended " << '\n';
    }
    else {

    }

    return 0;

}



double Clubs::get_clubV2() {

    /*

    Gets club choice using version 2

    using a target distance entered this function
    chooses a club based on the version 2 club setup method

    also error checks to make sure target entered is
    between driver distance and gap wedge distance

    */

    double t;
    //gets initial target distance
    cout << "Enter target distance you want to hit to : " << '\n';
    cin >> t;


    cout << "target = " << t << '\n';

    //checks if target entered is higher than the upper driver limit
    while (t > D || t < GW) {

        cout << "\n";
        cout << "***ERROR****\n";
        cout << "\n";

        cout << "Target must be between driver distance: (" << D << ") and gap wedge distance: (" << GW << "). Try again:" << '\n';
        cin.clear();
        cin.ignore();
        cin >> t;
    }

    if (t > D) {
        cout << "Target is greater than upper driver limit, Driver is recommended." << '\n';
    }
    else if (t <= D && t >= (D + I4)/2) {
        cout << "Driver is recommended " << '\n';
    }
    else if (t <= (D + I4)/2 && t >= (I4 + I5)/2) {
        cout << "4 Iron is recommended " << '\n';
    }
    else if (t <= (I4 + I5)/2 && t >= (I5 + I6)/2) {
        cout << "5 Iron is recommended " << '\n';
    }
    else if (t <= (I5 + I6)/2 && t >= (I6 + I7)/2) {
        cout << "6 Iron is recommended " << '\n';
    }
    else if (t <= (I6 + I7)/2 && t >= (I7 + I8)/2) {
        cout << "7 Iron is recommended " << '\n';
    }
    else if (t <= (I7 + I8)/2 && t >= (I8 + I9)/2) {
        cout << "8 Iron is recommended " << '\n';
    }
    else if (t <= (I8 + I9)/2 && t >= (I9 + PW)/2) {
        cout << "9 Iron is recommended " << '\n';
    }
    else if (t <= (I9 + PW)/2 && t >= (PW + GW)/2) {
        cout << "Pitching Wedge is recommended " << '\n';
    }
    else if (t <= (PW + GW)/2 && t >= GW) {
        cout << "Gap/Approach Wedge is recommended " << '\n';
    }
    else {

    }

    return 0;

}







double Summary::summary(double tot_yardage, double tot_par, double tot_strokes, double i, double fairway_percent, double fairway_total, double tot_fairways_hit, double GIR_percent, double tot_GIR, double tot_putts) {

    /*
    Summary function outputs various stats after each holes.

    Outputs stats such as; Overall score, total strokes, total yards, fairway hit percentage,
    GIR (green in regulation) percentage, and total putts.
    */
    cout << "*****************************************************" << '\n';

    double stroke_to_par = (tot_strokes - tot_par);

    cout << "AFTER " << i << " HOLES: " << '\n';
    if (stroke_to_par > 0) {
        cout << "Overall score: " << plus << stroke_to_par << " with " << tot_strokes << " total strokes\n";

    }
    else if (stroke_to_par == 0) {

        cout << "Overall score: Even, with " << tot_strokes << " total strokes\n";
    }
    else {

        cout << "Overall score: " << stroke_to_par << " with " << tot_strokes << " total strokes\n";
    }

    cout << "Total yardage: " << tot_yardage << " yds" << '\n';
    cout << "Fairway hit percentage: " << tot_fairways_hit << '/' << fairway_total << " " << fairway_percent << '%' << '\n';
    cout << "GIR percentage: " << tot_GIR << '/' << i << " " << GIR_percent << '%' << '\n';
    cout << "Total putts: " << tot_putts << '\n';



    cout << "*****************************************************" << '\n';

    return 0;


}




int main(int argc, char* argv[]){


    STATS stats1;
	Clubs clubs1;
	Summary summary1;



	double x;

	//GETS 9 OR 18 HOLES
	x = stats1.get_holes();



	//SETS UP CLUB DISTANCES
	clubs1.get_club_distance();

	double tot_par = 0;
	double tot_yardage = 0;
	double tot_strokes = 0;

	//FAIRWAY VARIABLES
	double tot_fairways_hit = 0;
	double fairway_total = 0;
	double fairway_percent = 0;

	//GIR VARIABLES
	double tot_GIR = 0;
	double GIR_percent = 0;

	double tot_putts = 0;

	//loop for number of holes
	for (double i = 1; i <= 1; i++) {

		//YARDAGE
		double y;

		//PAR
		double p;

		//TARGET
		double t;

		//STROKES
		double s;

		//FAIRWAY HIT
		double f;

		//GETS GIR
		double g;

		//PUTTS
		double putts;


		cout << ".\n";
		cout << "..\n";
		cout << "...\n";
		cout << "Starting hole # " << i << '\n';
		cout << "...\n";
		cout << "..\n";
		cout << ".\n";


		// ============== GETS YARDAGE =========================



		y = stats1.get_yardage(i);
		//add total yardage
		tot_yardage += y;



		// ============== GETS PAR =========================



		p = stats1.get_par(i);
		//add total par
		tot_par += p;



		// ============== GETS FARIWAY HIT =========================

		//only invoke fairway function if hole is a par 4 or 5
		if (p == 4 || p == 5) {


            #if VERSION == VERSION_1
			clubs1.get_club();
            #else
            clubs1.get_clubV2();
            #endif
			fairway_total++;
			f = stats1.get_fairway_hit(i);

			//add total fairway hit
			tot_fairways_hit += f;
			//calculate percentage
			fairway_percent = (tot_fairways_hit / fairway_total) * 100;


		}
		else {


		}

		// ============== GETS TARGET CLUB 2 =========================


		//gets target club
        #if VERSION == VERSION_1
        clubs1.get_club();
        #else
        clubs1.get_clubV2();
        #endif


		// ============== GETS GREEN IN REGULATION =========================



		g = stats1.get_GIR(i);
		//add GIR
		tot_GIR += g;
		GIR_percent = (tot_GIR / i) * 100;



		// ============== GETS PUTTS =========================



		putts = stats1.get_putts(i);
		//add putts
		tot_putts += putts;



		// ============== GETS TOTAL STROKES =========================



		s = stats1.get_strokes(i);
		//add strokes
		tot_strokes += s;
		cout << '\n';


		// ============== SUMMARY =========================


				//summarize
		summary1.summary(tot_yardage, tot_par, tot_strokes, i, fairway_percent, fairway_total, tot_fairways_hit, GIR_percent, tot_GIR, tot_putts);


	}

		// ============== EXPORT =========================
	string exp = "";

	//Directory test
	//string dir = "C:\\Users\\%USERNAME%\\Desktop\\";

	string file_name = "";
	string info_date;
	string info_course;


    /*

    Outfile summary allows the user to save the round to a text file.

    The outfile feature allows the user to save all stats gathered
    throughout the round.

    Also allows the user to save the date of the round and the course played at.

    */

	cout << "Would you like to save your round to a text file? (Y or N): \n";
	cin >> exp;
	if (exp == "Y" || exp == "y") {

		ofstream myfile;
		cout << "Enter name of file: \n";

        cin >> file_name;


        cout << "Enter date: \n";
        getline(cin, info_date);
        cin >> info_date;

        cout << "Enter course name: \n";
        cin.ignore();
        getline(cin, info_course);

		myfile.open(file_name);


		myfile << "Date:\n " << info_date << '\n';
		myfile << "Course:\n " << info_course << '\n';

		myfile << "*****************************************************" << '\n';
		string plus = "+";

		double stroke_to_par = (tot_strokes - tot_par);

		myfile << "AFTER " << x << " HOLES: " << '\n';
		if (stroke_to_par > 0) {
			myfile << "Overall score: " << plus << stroke_to_par << " with " << tot_strokes << " total strokes\n";

		}
		else if (stroke_to_par == 0) {

			myfile << "Overall score: Even, with " << tot_strokes << " total strokes\n";
		}
		else {

			myfile << "Overall score: " << stroke_to_par << " with " << tot_strokes << " total strokes\n";
		}

		myfile << "Total yardage: " << tot_yardage << " yds" << '\n';
		myfile << "Fairway hit percentage: " << tot_fairways_hit << '/' << fairway_total << " " << fairway_percent << '%' << '\n';
		myfile << "GIR percentage: " << tot_GIR << '/' << x << " " << GIR_percent << '%' << '\n';
		myfile << "Total putts: " << tot_putts << '\n';



		myfile << "*****************************************************" << '\n';


		myfile.close();


	}


	return 0;

}
