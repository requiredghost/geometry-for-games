#include <iostream>
#include <string>
#include "geometry.h"
#include "test.h"
#include "windows.h"

TVector3 VectorAT;
TVector3 VectorBT;
TVector3 VectorCT;
TVector3 VectorDT;

TVector2 VectorA2DT;
TVector2 VectorB2DT;
TVector2 VectorC2DT;
TVector2 VectorD2DT;

TPlane PlaneAT;
TPlane PlaneBT;
TPlane PlaneCT;
TPlane PlaneDT;

T3DLine LineAT;
T3DLine LineBT;
T3DLine LineCT;
T3DLine LineDT;

TTriangle2 TTriangle2AT;

TCircle CircleAT;
TCircle CircleBT;
TCircle CircleCT;
TCircle CircleDT;

TSphere SphereAT;
TSphere SphereBT;
TSphere SphereCT;
TSphere SphereDT;

TTriangle2 LineA2DT;
TTriangle2 LineB2DT;

float testfloat = 0.0f;

using namespace std;

int getint(int inint) {
	return inint;
}

float getfloat(float infloat) {
	return infloat;
}


bool testmefunctions() {

	system("cls");
	system("COLOR 0E");



	VectorAT.m_fX = 1;
	VectorAT.m_fY = 1;
	VectorAT.m_fZ = 2;
	VectorBT.m_fX = 2;
	VectorBT.m_fY = 5;
	VectorBT.m_fZ = 3;
	VectorCT.m_fX = 7;
	VectorCT.m_fY = 9;
	VectorCT.m_fZ = 8;

	PlaneAT.m_v3normal = VectorAT;
	PlaneAT.m_v3point = VectorCT;



	const float tfloat = 4.0f;

	VectorA2DT.m_fX = 3;
	VectorA2DT.m_fY = 5;
	VectorB2DT.m_fX = 3;
	VectorB2DT.m_fY = 99;

	CircleAT.m_fRadius = 2;
	CircleAT.m_v2center = VectorA2DT;
	CircleBT.m_fRadius = 4;
	CircleBT.m_v2center = VectorB2DT;

	cout << "Testing..." << endl;

	bool result = Equals(VectorAT, VectorBT);
	if (result == false) {
		cout << "Equals Works!" << endl;
		Beep(1000, 50);
	}
	else {
		cout << "Problem with Equals" << endl;
		cout << "Result: (" << VectorAT.m_fX << ", " << VectorAT.m_fY << ", " << VectorAT.m_fZ << ")" << endl;
		system("COLOR 0C");
		Beep(300, 1000);
		system("pause");
	}

	cout << endl;

	VectorAT = Add(VectorAT, VectorBT, VectorCT);

	if ((VectorAT.m_fX == 3) && (VectorAT.m_fY == 6) && (VectorAT.m_fZ == 5)) {
		cout << "Add Works!" << endl;
		Beep(1000, 50);
	}
	else {
		cout << "Problem with Add" << endl;
		cout << "Result: (" << VectorAT.m_fX << ", " << VectorAT.m_fY << ", " << VectorAT.m_fZ << ")" << endl;
		system("COLOR 0C");
		Beep(300, 1000);
		system("pause");
	}

	cout << endl;

	VectorAT = Subtract(VectorAT, VectorBT, VectorCT);
	if ((VectorAT.m_fX == 1) && (VectorAT.m_fY == 1) && (VectorAT.m_fZ == 2)) {
		cout << "Subtract Works!" << endl;
		Beep(1000, 50);
	}
	else {
		cout << "Problem with Subtract" << endl;
		cout << "Result: (" << VectorAT.m_fX << ", " << VectorAT.m_fY << ", " << VectorAT.m_fZ << ")" << endl;
		system("COLOR 0C");
		Beep(300, 1000);
		system("pause");
	}

	cout << endl;

	VectorAT = ScaleVector(VectorAT, tfloat, VectorCT);
	if ((VectorAT.m_fX == 4) && (VectorAT.m_fY == 4) && (VectorAT.m_fZ == 8)) {
		cout << "ScaleVector Works!" << endl;
		Beep(1000, 50);
	}
	else {
		cout << "Problem with ScaleVector" << endl;
		cout << "Result: (" << VectorAT.m_fX << ", " << VectorAT.m_fY << ", " << VectorAT.m_fZ << ")" << endl;
		system("COLOR 0C");
		Beep(300, 1000);
		system("pause");
	}

	cout << endl;

	testfloat = Magnitude(VectorCT);
	if ((testfloat > 9.79795) && (testfloat < 9.79797)) {
		cout << "Magnitude Works!" << endl;
		Beep(1000, 50);
	}
	else {
		cout << "Problem with Magnitude" << endl;
		cout << "Result: " << testfloat << endl;
		system("COLOR 0C");
		Beep(300, 1000);
		system("pause");
	}

	cout << endl;

	testfloat = DotProduct(VectorAT, VectorBT);
	if (testfloat == 21) {
		cout << "DotProduct Works!" << endl;
		Beep(1000, 50);
	}
	else {
		cout << "Problem with DotProduct" << endl;
		cout << "Result: " << testfloat << endl;
		system("COLOR 0C");
		Beep(300, 1000);
		system("pause");
	}

	cout << endl;

	VectorAT = CrossProduct(VectorAT, VectorBT, VectorCT);
	if ((VectorAT.m_fX == -28) && (VectorAT.m_fY == 4) && (VectorAT.m_fZ == 12)) {
		cout << "CrossProduct Works!" << endl;
		Beep(1000, 50);
	}
	else {
		cout << "Problem with CrossProduct" << endl;
		cout << "Result: (" << VectorAT.m_fX << ", " << VectorAT.m_fY << ", " << VectorAT.m_fZ << ")" << endl;
		system("COLOR 0C");
		Beep(300, 1000);
		system("pause");
	}

	cout << endl;

	VectorAT = Normalise(VectorAT, VectorBT);
	if (((VectorAT.m_fX > -0.911323) && (VectorAT.m_fX < -0.911321)) && ((VectorAT.m_fY > 0.130188) && (VectorAT.m_fY < 0.130190)) && ((VectorAT.m_fZ > 0.390566) && (VectorAT.m_fZ < 0.390568))) {
		cout << "Normalise Works!" << endl;
		Beep(1000, 50);
	}
	else {
		cout << "Problem with Normalise" << endl;
		cout << "Result: (" << VectorAT.m_fX << ", " << VectorAT.m_fY << ", " << VectorAT.m_fZ << ")" << endl;
		system("COLOR 0C");
		Beep(300, 1000);
		system("pause");
	}

	cout << endl;

	VectorAT = Projection(VectorAT, VectorBT, VectorCT);
	if (((VectorAT.m_fX > -0.911323) && (VectorAT.m_fX < -0.911321)) && ((VectorAT.m_fY > 0.130188) && (VectorAT.m_fY < 0.130190)) && ((VectorAT.m_fZ > 0.390566) && (VectorAT.m_fZ < 0.390568))) {
		cout << "Projection Works!" << endl;
		Beep(1000, 50);
	}
	else {
		cout << "Problem with Projection" << endl;
		cout << "Result: (" << VectorAT.m_fX << ", " << VectorAT.m_fY << ", " << VectorAT.m_fZ << ")" << endl;
		system("COLOR 0C");
		Beep(300, 1000);
		system("pause");
	}

	cout << endl;

	testfloat = ComputeAngleBetween(VectorA2DT, VectorB2DT);
	if ((testfloat < 29.229) && (testfloat > 29.227)) {
		cout << "Compute Angle Between Works!" << endl;
		Beep(1000, 50);
	}
	else {
		cout << "Problem with Compute Angle Between" << endl;
		cout << "Result: " << testfloat << endl;
		system("COLOR 0C");
		Beep(300, 1000);
		system("pause");
	}

	cout << endl;

	cout << "Line start: (1,1,1) Line End: (2,5,7)" << endl;
	testfloat = ComputeDistancePointToLine(LineAT, VectorAT);
	if ((testfloat < 3.22445) && (testfloat > 3.22443)) {
		cout << "Compute Distance Point To Line Between Works!" << endl;
		Beep(1000, 50);
	}
	else {
		cout << "Problem with Compute Distance Point To Line" << endl;
		cout << "Result: " << testfloat << endl;
		system("COLOR 0C");
		Beep(300, 1000);
		system("pause");
	}
	cout << endl;

	testfloat = ComputeDistancePointToPlane(PlaneAT, VectorAT);
	if ((testfloat < 13.0640) && (testfloat > 13.0638)) {
		cout << "Compute Distance Point To Plane Works!" << endl;
		Beep(1000, 50);
	}
	else {
		cout << "Problem with Compute Distance Point To Plane" << endl;
		cout << "Result: " << testfloat << endl;
		system("COLOR 0C");
		Beep(300, 1000);
		system("pause");
	}

	cout << endl;

	testfloat = ComputeDistanceCircleToCircle(CircleAT, CircleBT);
	if (testfloat == 94) {
		cout << "Compute Distance Circle To Circle Works!" << endl;
		Beep(1000, 50);
	}
	else {
		cout << "Problem with Compute Distance Circle To Circle" << endl;
		cout << "Result: " << testfloat << endl;
		system("COLOR 0C");
		Beep(300, 1000);
		system("pause");
	}

	cout << endl;

	testfloat = ComputeDistancePointToSphere(SphereAT, VectorAT);
	if ((testfloat < 1.1) && (testfloat > 0.9)) {
		cout << "Compute Distance Point To Circle Works!" << endl;
		Beep(1000, 50);
	}
	else {
		cout << "Problem with Compute Distance Point To Circle" << endl;
		cout << "Result: " << testfloat << endl;
		system("COLOR 0C");
		Beep(300, 1000);
		system("pause");
	}

	cout << endl;

	CircleAT.m_v2center.m_fX = 3;
	CircleAT.m_v2center.m_fY = 5;
	TTriangle2AT.m_v2p1.m_fY = 4;
	TTriangle2AT.m_v2p1.m_fX = 8;
	TTriangle2AT.m_v2p2.m_fY = 3;
	TTriangle2AT.m_v2p2.m_fX = 12;
	TTriangle2AT.m_v2p3.m_fY = 6;
	TTriangle2AT.m_v2p3.m_fX = 14;

	result = ComputeDistanceCircleToTriangle(CircleAT, TTriangle2AT);

	if (result == 1) {
		cout << "Compute Distance Circle To Triangle works!";
	}
	else {
		cout << "Problem with Compute Distance Circle To Triangle" << endl;
		cout << "Result: " << result << endl;
		system("COLOR 0C");
		Beep(300, 1000);
		system("pause");
	}

	cout << endl << endl << "-= Testing finished! =-" << endl;

	//system("pause");
	return true;
}












