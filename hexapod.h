xapo#ifndef HEXAPOD_H
#define HEXAPOD_H
#include "vector3.h"

//measurements based on computer model of robot
double BICEP_LENGTH = 5.000;
double FOREARM_LENGTH =16.750;
double SWITCH_ANGLE = 19.690;
//top center to wrist hole: X7.635 Y+/-0.553 Z0.87
double T2W_X = 7.635;
double T2W_Y = 0.553;
double T2W_Z = -0.870;
//base center to shoulder hole: X8.093 Y+/-2.15 Z7.831
double B2S_X = 8.093;
double B2S_Y = 2.150;
double B2S_Z = 6.618;

//some experimentally determined limits on in/out distance (distance along motor shaft direction)
double MAX_IN = 4.46;
double MAX_OUT = 4.25;
double POS_STEP = 0.1;
double RPY_STEP = 1;

class Hexapod{

public: 
	//constructor
	Hexapod();
	//destructor
	~Hexapod();

	//updater
	void update_end_effector( double x,double y,
		double z,double u, double v, double w);

	//build shoulders
	void build_shoulders();

	//update wrists
	void update_wrists();

	void update_ik(double x, double y, double z,
		double u, double v, double w);

	void update_shoulders();

	Hexapod * get_rpy();

	Hexapod * get_pos();

	bool check_ik(double x,double y,
		double z,double u, double v, double w);

	void best_effort_ik(double& x, double& y, dobule& z, double& u, double& v, double& w);



private:

	//variables
	Vector3 wrists[6];
	Vector3 shoulders[6];
	Vector3 elbows[6];
	Vector3 shoulder_to_elbow [6];
    Vector3 ee_pos;
    Vector3 ee_rpy;
    Vector3 ee_up;
    Vector3 ee_fw;
    Vector3 ee_left;
    double angles [6];

    Vector3 el;
    Vector3 wr;
    double aa;
    double cc;
    double bb;
    double rel_z;
};

#endif