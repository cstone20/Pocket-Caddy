// V6.0.cpp : This file does contain the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string.h>
#include "PC2.0.h"

using namespace std;

#define VERSION_1  1
#define VERSION_2  2

#define VERSION  2


double STATS::get_holes() {

    //Holes STATS;


    cout << "Enter number of holes (9 or 18): " << '\n';
    cin >> holes;

    //error checking
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


    cout << "Enter par for hole " << i << ": " << '\n';
    cin >> par;

    //error checking
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
    cout << "Enter yardage for hole " << i << ": " << '\n';

    cin >> yardage;

    //error checking
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


    cout << "Did you hit the Fairway on hole: " << i << " (1 yes , 0 no) " << '\n';
    cin >> hit;

    // error checking
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


    cout << "Did you hit the green in regulation on hole: " << i << " (1 yes, 0 no)" << '\n';
    cin >> gir;

    //error checking
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


    cout << "Enter number of putts for hole " << i << ":\n";
    cin >> putts;

    //error checking
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

    cout << "Enter total strokes for hole " << i << ":\n";
    cin >> strokes;

    //error checking
    while (!cin || strokes < 1.0 || strokes > 10.0) {

        //if strokes is over 10
        if (strokes > 10) {

            cout << "\n";
            cout << "***ERROR****\n";
            cout << "\n";

            cout << "Max strokes is 10, try again:" << '\n';
            cin.clear();
            cin.ignore();
            cin >> strokes;
        }
        //if strokes is under 1
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





    cout << "Starting club setup..... \n";


    #if VERSION == VERSION_1
    int i = 0;

    //loops through the 9 clubs
    for (int k = 0; k < 9; k++) {


        double distance = 0;

        //gets upper club distance
        cout << "Enter upper distance for, ";

        cout << clubs[k] << " : ";
        cin >> distance;

        //error checking for upper distance
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
    //Testing
    cout << HD << '\n';
    cout << LD << '\n';
    cout << H4 << '\n';
    cout << L4 << '\n';
    cout << H5 << '\n';
    cout << L5 << '\n';
    cout << H6 << '\n';
    cout << L6 << '\n';
    cout << H7 << '\n';
    cout << L7 << '\n';
    cout << H8 << '\n';
    cout << L8 << '\n';
    cout << H9 << '\n';
    cout << L9 << '\n';
    cout << HP << '\n';
    cout << LP << '\n';
    cout << HG << '\n';
    cout << LG << '\n';
*/

/*
    //testing
    for (int j = 0; j < 17; j++) {
        cout << club_distances[j] << '\n';
    }
*/



    #else
    int i = 0;

    for (int k = 0; k < 9; k++) {
        double distance = 0;



        //gets upper club distance
        cout << "Enter average distance for, ";

        cout << clubs[k] << " : ";
        cin >> distance;




        good_distance = check_distanceV2(distance, good_distance, i);

        cout << "good distance = " << good_distance <<endl;

        club_distancesV2[i] = good_distance;
        cout << "club_distance at i = " << club_distancesV2[i] <<endl;


        i++;


        //error checking for upper distance
    }

    D = club_distancesV2[0];
    I4 = club_distancesV2[1];
    I5 = club_distancesV2[2];
    I6 = club_distancesV2[3];
    I7 = club_distancesV2[4];
    I8 = club_distancesV2[5];
    I9 = club_distancesV2[6];
    PW = club_distancesV2[7];
    GW = club_distancesV2[8];


    #endif

    cout << "End club setup... \n";

    return 0;

}

double Clubs::check_distanceV2(double distance, double good_distance, int i) {

    //need to add distance
    //check to make sure the higher club range is lower than the previous clubs low range
    //could possibly do this by setting a temp for the first index and using club_distance[i-1] for the rest of the setup


    cout << "i = " << i <<endl;
    if (i > 1) {

        cout << "previous club distance = " << club_distancesV2[i - 1] <<endl;
        while (good_distance < distance) {

            cout << "\n";
            cout << "***ERROR****\n";
            cout << "\n";

            cout << "Upper club distance needs to be lower than the previous clubs distance (" << club_distancesV2[i - 1] << ") try again:" << '\n';
            cin.clear();
            cin.ignore();
            cin >> distance;
        }

    }



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

            cout << "Club distance must be above 20 yards, try again:" << '\n';
            cin.clear();
            cin.ignore();
            cin >> distance;
        }
        i++;

    }
    return distance;

}



//error checking for club distances
double Clubs::check_distance(double distance, double club_distances[], int i) {

    //need to add distance
    //check to make sure the higher club range is lower than the previous clubs low range
    //could possibly do this by setting a temp for the first index and using club_distance[i-1] for the rest of the setup



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

            cout << "Club distance must be above 20 yards, try again:" << '\n';
            cin.clear();
            cin.ignore();
            cin >> distance;
        }
        i++;

    }
    return distance;

}



double Clubs::check_distance2(double distance, double good_distance1, int i) {

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



double Clubs::get_club(double t) {

    //MAKE SURE TARGET IS ABOVE LOW GAP WEDGE DISTANCE
    //AND BELOW HIGH DRIVER DISTANCE
    cout << "target = " << t << '\n';

    //checks if target entered is higher than the upper driver limit
    while (t > HD) {

        cout << "\n";
        cout << "***ERROR****\n";
        cout << "\n";

        cout << "Target is greater than upper driver limit (" << HD << ") Try again:" << '\n';
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
        cout << "No club range given for that target" << '\n';
    }

    return 0;

}



double Clubs::get_clubV2(double t) {

    //MAKE SURE TARGET IS ABOVE LOW GAP WEDGE DISTANCE
    //AND BELOW HIGH DRIVER DISTANCE
    cout << "target = " << t << '\n';

    //checks if target entered is higher than the upper driver limit
    while (t > D) {

        cout << "\n";
        cout << "***ERROR****\n";
        cout << "\n";

        cout << "Target is greater than upper driver limit (" << D << ") Try again:" << '\n';
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
        cout << "No club range given for that target" << '\n';
    }

    return 0;

}







double Summary::summary(double tot_yardage, double tot_par, double tot_strokes, double i, double fairway_percent, double fairway_total, double tot_fairways_hit, double GIR_percent, double tot_GIR, double tot_putts) {

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
	for (double i = 1; i <= x; i++) {

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


				//get yardage for the hole
		y = stats1.get_yardage(i);
		//add total yardage
		tot_yardage += y;



		// ============== GETS PAR =========================


				//get par for the hole
		p = stats1.get_par(i);
		//add total par
		tot_par += p;



		// ============== GETS FARIWAY HIT =========================

		//only invoke fairway function if hole is a par 4 or 5
		if (p == 4 || p == 5) {


			//gets initial target distance
			cout << "Enter target distance you want to hit to : " << '\n';
			cin >> t;

            #if VERSION == VERSION_1
			clubs1.get_club(t);
            #else
            clubs1.get_clubV2(t);
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

		cout << "Enter target distance you want to hit to : " << '\n';
		cin >> t;
		//gets target club
        #if VERSION == VERSION_1
        clubs1.get_club(t);
        #else
        clubs1.get_clubV2(t);
        #endif


		// ============== GETS GREEN IN REGULATION =========================



				//get GIR
		g = stats1.get_GIR(i);
		//add GIR
		tot_GIR += g;
		GIR_percent = (tot_GIR / i) * 100;




		// ============== GETS PUTTS =========================



				//get putts
		putts = stats1.get_putts(i);
		//add putts
		tot_putts += putts;



		// ============== GETS TOTAL STROKES =========================


				//get strokes
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

	cout << "Enter date: \n";
	cin.ignore();
	getline(cin, info_date);
	cin.ignore();

	cout << "Enter course name: \n";
	cin.ignore();
	getline(cin, info_course);
	cin.ignore();



	cout << "Would you like to save your round to a text file? (Y or N): \n";
	cin >> exp;
	if (exp == "Y" || exp == "y") {

		ofstream myfile;
		cout << "Enter name of file: \n";
		cin.ignore();
		cin >> file_name;
		cin.ignore();

		//Directory test
		//myfile.open(dir + file_name);

		myfile.open(file_name);


		myfile << "Date: " << info_date << '\n';
		myfile << "Course: " << info_course << '\n';

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

// ************** END OF MAIN ***************************




		// ============== DOCUMENTATION ==========



/*
		* represents completion
		V1.0 *
			- *Asks for number of holes to play
			- *Calculates strokes, par, yardage, fairwaysand GIR
			- *Displays strokes, par, yardage

		V2.0 *
			- *Adds error checking for input on par, yardage, fairway, GIRand number of holes to play
			- *Add fairwayand GIR% to summary
			- *Add putting strokes function
			- *Make sure all error checkingand questions are same format

		V3.0 *
			- *Modify golf class to its own.h file
			- *Add plus minus to overall par in summary display

		V3.5 *
			- *Modify.h file to separate each feature(holes, par, yardage, fairway%, GIR%, putts, strokes) into their own class

		V4.0 *
			- *Add and implement club setup class and function to get ranges of clubs
			- *Make sure all club variables are assigned with correct inputs

		V5.0 *
			- *Add target distance with club recommendation into club setup
			- *Modify club recommendation into own class  keep in same class

		V5.5 *
			- *Add error checking to club setup
			- *Add error checking to target input
			- *Add error checking for total putts
			- *Clean up and spread out inputs
			- *Add comments
			- *Add yardage for the hole needs to be over atleast 75 yards not 0
			- *Add total putts to summary

		V6.0
			- *Add outfile function

        caddyTest
            - *Move functions from the .h to the cpp

        caddyTest1
            - Create alternate version of club setup

        caddyTest2
            - Add elevation and wind functions



*/
