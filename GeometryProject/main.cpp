#include <iostream>
#include <string>
#include <windows.h>
#include "geometry.h"
#include "test.h"

TVector3 VectorA;
TVector3 VectorB;
TVector3 VectorC;
TVector3 VectorD;

TVector2 VectorA2D;
TVector2 VectorB2D;
TVector2 VectorC2D;
TVector2 VectorD2D;

TPlane PlaneA;
TPlane PlaneB;
TPlane PlaneC;
TPlane PlaneD;

T3DLine LineA;
T3DLine LineB;
T3DLine LineC;
T3DLine LineD;


TCircle CircleA;
TCircle CircleB;
TCircle CircleC;
TCircle CircleD;

TSphere SphereA;
TSphere SphereB;
TSphere SphereC;
TSphere SphereD;

TTriangle2 LineA2D;
TTriangle2 LineB2D;
TTriangle2 TTriangle2A;


float af;
float bf;
float cf;
float df;


using namespace std;
void GotoXY(int _iX, int _iY) {
	COORD point;
	point.X = _iX;
	point.Y = _iY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
void Invalid() {
	system("COLOR 40");
	system("cls");
	GotoXY(30, 7);
	cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
	GotoXY(30, 8);
	cout << char(186) << " PLEASE ENTER A VALID OPTION " << char(186) << endl;
	GotoXY(30, 9);
	cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
	Beep(1200, 500);
	Sleep(2000);
	system("COLOR 0F");
}
int main() {

	//You don't have two vectors in main, so you cannot call it. Otherwise it is just bool result = Equals(vec1, vec2);. No magic

	HWND console = GetConsoleWindow();
	RECT w;
	GetWindowRect(console, &w);
	MoveWindow(console, w.left, w.top, 800, 500, TRUE); //Resize console window

	int amountoftests = 0;
	float iT = -1;

	int choice = -1;
	while (choice != 99) {
		system("cls");
		system("COLOR 07");
		cout << "-= Main Menu =-" << endl << endl;
		cout << "1. Vector Equals Vector" << endl;
		cout << "2. Add Two Vectors" << endl;
		cout << "3. Subtract Two Vectors" << endl;
		cout << "4. Scale A Vector" << endl;
		cout << "5. Magnitude" << endl;
		cout << "6. Dot Product" << endl;
		cout << "7. CrossProduct" << endl;
		cout << "8. Normalise" << endl;
		cout << "9. Projection" << endl;
		cout << "10. Compute Angle Between Two Vector2s" << endl;
		cout << "11. Compute Angle Between Two Vector3s" << endl;
		cout << "12. Compute Distance Of Point To Line" << endl;
		cout << "13. Compute Distance Point To Plane" << endl;
		cout << "14. Compute Distance Point To Sphere" << endl;
		cout << "15. Compute Distance Circle To Circle" << endl;
		cout << "16. Distance Circle To Triangle" << endl;
		cout << "17. Line Sphere Intersection" << endl;
		cout << "18. Line Plane Intersection" << endl;
		cout << "19. Are Two Lines Intersecting" << endl;
		//cout << "20. Compute Intersection Between Two Lines" << endl;
		cout << "1234. Test All Functions" << endl;
		cout << endl;
		cout << "Tested: " << amountoftests << " times" << endl;
		cout << "99. Exit" << endl;
		cout << "Please Choose an Option: ";
		cin >> choice;

		if (choice == 1) { //Equals
			system("cls");
			cout << "-= Vector 1 =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorA.m_fX = iT;

			cout << "Y: ";
			cin >> iT;
			VectorA.m_fY = iT;

			cout << "Z: ";
			cin >> iT;
			VectorA.m_fZ = iT;

			cout << "-= Vector 2 =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorB.m_fX = iT;

			cout << "Y: ";
			cin >> iT;
			VectorB.m_fY = iT;

			cout << "Z: ";
			cin >> iT;
			VectorB.m_fZ = iT;
			bool result = Equals(VectorA, VectorB);
			if (result == true) {
				cout << "The Two Vectors Are Equal!" << endl;
			}
			else {
				cout << "The Two Vectors Are Not Equal!" << endl;
			}
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 2) { //Add
			system("cls");
			cout << "-= Vector 1 =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorA.m_fX = iT;

			cout << "Y: ";
			cin >> iT;
			VectorA.m_fY = iT;

			cout << "Z: ";
			cin >> iT;
			VectorA.m_fZ = iT;

			cout << "-= Vector 2 =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorB.m_fX = iT;

			cout << "Y: ";
			cin >> iT;
			VectorB.m_fY = iT;

			cout << "Z: ";
			cin >> iT;
			VectorB.m_fZ = iT;

			VectorA = Add(VectorA, VectorB, VectorC);
			cout << "Result: (" << VectorA.m_fX << ", " << VectorA.m_fY << ", " << VectorA.m_fZ << ")" << endl;
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 3) { //Subtract
			system("cls");
			float iT = 0;

			cout << "-= Vector 1 (Original) =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorA.m_fX = getfloat(iT);

			cout << "Y: ";
			cin >> iT;
			VectorA.m_fY = getfloat(iT);

			cout << "Z: ";
			cin >> iT;
			VectorA.m_fZ = getfloat(iT);

			cout << "-= Vector 2 (To Subtract) =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorB.m_fX = getfloat(iT);

			cout << "Y: ";
			cin >> iT;
			VectorB.m_fY = getfloat(iT);

			cout << "Z: ";
			cin >> iT;
			VectorB.m_fZ = getfloat(iT);
			VectorA = Subtract(VectorA, VectorB, VectorC);
			cout << "Result: (" << VectorA.m_fX << ", " << VectorA.m_fY << ", " << VectorA.m_fZ << ")" << endl;
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 4) { //Scale
			system("cls");
			float iT;
			float scalar;

			cout << "Scalar: ";
			cin >> scalar;

			cout << "-= Vector =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorA.m_fX = getfloat(iT);

			cout << "Y: ";
			cin >> iT;
			VectorA.m_fY = getfloat(iT);

			cout << "Z: ";
			cin >> iT;
			VectorA.m_fZ = getfloat(iT);
			VectorA = ScaleVector(VectorA, scalar, VectorB);
			cout << "Result: (" << VectorA.m_fX << ", " << VectorA.m_fY << ", " << VectorA.m_fZ << ")" << endl;
			amountoftests += 1;
			system("pause");
		}


		else if (choice == 5) { //Magnitude
			system("cls");
			float iT = 0;

			cout << "-= Vector =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorA.m_fX = getfloat(iT);

			cout << "Y: ";
			cin >> iT;
			VectorA.m_fY = getfloat(iT);

			cout << "Z: ";
			cin >> iT;
			VectorA.m_fZ = getfloat(iT);

			af = Magnitude(VectorA);
			cout << "Magnitude of Vector: " << af << endl;
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 6) { //Dot Product
			system("cls");
			float iT = 0;

			cout << "-= Vector 1 =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorA.m_fX = getfloat(iT);

			cout << "Y: ";
			cin >> iT;
			VectorA.m_fY = getfloat(iT);

			cout << "Z: ";
			cin >> iT;
			VectorA.m_fZ = getfloat(iT);

			cout << endl << endl;

			cout << "-= Vector 2 =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorB.m_fX = getfloat(iT);

			cout << "Y: ";
			cin >> iT;
			VectorB.m_fY = getfloat(iT);

			cout << "Z: ";
			cin >> iT;
			VectorB.m_fZ = getfloat(iT);
			af = DotProduct(VectorA, VectorB);
			cout << "Dot Product of Vectors: " << af << endl;
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 7) { //CrossProduct
			cout << "-= Vector 1 =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorA.m_fX = getfloat(iT);

			cout << "Y: ";
			cin >> iT;
			VectorA.m_fY = getfloat(iT);

			cout << "Z: ";
			cin >> iT;
			VectorA.m_fZ = getfloat(iT);

			cout << endl << endl;

			cout << "-= Vector 2 =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorB.m_fX = getfloat(iT);

			cout << "Y: ";
			cin >> iT;
			VectorB.m_fY = getfloat(iT);

			cout << "Z: ";
			cin >> iT;
			VectorB.m_fZ = getfloat(iT);
			VectorA = CrossProduct(VectorA, VectorB, VectorC);
			cout << "Result: (" << VectorA.m_fX << ", " << VectorA.m_fY << ", " << VectorA.m_fZ << ")" << endl;
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 8) { //Normalise
			system("cls");
			cout << "-= Vector 1 =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorA.m_fX = getfloat(iT);

			cout << "Y: ";
			cin >> iT;
			VectorA.m_fY = getfloat(iT);

			cout << "Z: ";
			cin >> iT;
			VectorA.m_fZ = getfloat(iT);

			cout << endl << endl;
			VectorA = Normalise(VectorA, VectorB);
			cout << "Normalised Vector Result: (" << VectorA.m_fX << ", " << VectorA.m_fY << ", " << VectorA.m_fZ << ")" << endl;
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 9) { //Projection
			cout << "-= Vector 1 =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorA.m_fX = getfloat(iT);

			cout << "Y: ";
			cin >> iT;
			VectorA.m_fY = getfloat(iT);

			cout << "Z: ";
			cin >> iT;
			VectorA.m_fZ = getfloat(iT);

			cout << endl << endl;

			cout << "-= Vector 2 =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorB.m_fX = getfloat(iT);

			cout << "Y: ";
			cin >> iT;
			VectorB.m_fY = getfloat(iT);

			cout << "Z: ";
			cin >> iT;
			VectorB.m_fZ = getfloat(iT);
			Projection(VectorA, VectorB, VectorC);
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 10) { //ComputeAngleBetween
			cout << "-= Vector 1 =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorA2D.m_fX = getfloat(iT);

			cout << "Y: ";
			cin >> iT;
			VectorA2D.m_fY = getfloat(iT);

			cout << endl << endl;

			cout << "-= Vector 2 =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorB2D.m_fX = getfloat(iT);

			cout << "Y: ";
			cin >> iT;
			VectorB2D.m_fY = getfloat(iT);
			af = ComputeAngleBetween(VectorA2D, VectorB2D);
			cout << "The Angle Between The Two Vectors is: " << af << " Degrees" << endl;
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 11) { //ComputeAngleBetween3v
			cout << "-= Vector 1 =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorA.m_fX = getfloat(iT);

			cout << "Y: ";
			cin >> iT;
			VectorA.m_fY = getfloat(iT);

			cout << "Z: ";
			cin >> iT;
			VectorA.m_fZ = getfloat(iT);

			cout << endl << endl;

			cout << "-= Vector 2 =-" << endl;
			cout << "X: ";
			cin >> iT;
			VectorB.m_fX = getfloat(iT);

			cout << "Y: ";
			cin >> iT;
			VectorB.m_fY = getfloat(iT);

			cout << "Z: ";
			cin >> iT;
			VectorB.m_fZ = getfloat(iT);
			af = ComputeAngleBetween(VectorA, VectorB);
			cout << "The Angle Between The Two Vectors is: " << af << " Degrees" << endl;
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 12) { //ComputeDistancePointToLine
			cout << "-= Point =-" << endl;

			cout << "Point X: ";
			cin >> VectorA.m_fX;

			cout << "Point Y: ";
			cin >> VectorA.m_fY;

			cout << "Point Z: ";
			cin >> VectorA.m_fZ;

			af = ComputeDistancePointToLine(LineA, VectorA);
			cout << "Distance of Point from line is: " << af;
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 13) { //ComputeDistancePointToPlane
			af = ComputeDistancePointToPlane(PlaneA, VectorA);
			cout << "    The Distance From a POINT to a PLANE is:  " << endl << "     * " << "[" << af << "]" << endl;
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 14) { //ComputeDistancePointToSphere
			cout << "Sphere Center X:";
			cin >> SphereA.m_v3center.m_fX;
			cout << "Sphere Center Y:";
			cin >> SphereA.m_v3center.m_fY;
			cout << "Sphere Center Z:";
			cin >> SphereA.m_v3center.m_fZ;
			cout << "Sphere Radius: ";
			cin >> SphereA.m_fRadius;
			cout << "Point X: ";
			cin >> VectorA.m_fX;
			cout << "Point Y: ";
			cin >> VectorA.m_fY;
			cout << "Point Z: ";
			cin >> VectorA.m_fZ;
			af = ComputeDistancePointToSphere(SphereA, VectorA);
			cout << "    The Distance Between POINT and Center of the SPHERE is:  " << endl << "     * " << "[" << af << "]" << endl;
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 15) { //ComputeDistanceCircleToCircle
			af = ComputeDistanceCircleToCircle(CircleA, CircleB);
			cout << "    The Distance Between the Centers of Two Circles is:  " << endl << "     * " << "[" << af << "]" << endl;
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 16) { //ComputeDistanceCircleToTriangle
			system("cls");
			cout << "Circle Center X: ";
			cin >> CircleA.m_v2center.m_fX;
			cout << "Circle Center Y: ";
			cin >> CircleA.m_v2center.m_fY;
			cout << "Triangle Point 1 Y: ";
			cin >> TTriangle2A.m_v2p1.m_fY;
			cout << "Triangle Point 1 X: ";
			cin >> TTriangle2A.m_v2p1.m_fX;
			cout << "Triangle Point 2 Y: ";
			cin >> TTriangle2A.m_v2p2.m_fY;
			cout << "Triangle Point 2 X: ";
			cin >> TTriangle2A.m_v2p2.m_fX;
			cout << "Triangle Point 3 Y: ";
			cin >> TTriangle2A.m_v2p3.m_fY;
			cout << "Triangle Point 3 X: ";
			cin >> TTriangle2A.m_v2p3.m_fX;
			af = ComputeDistanceCircleToTriangle(CircleA, LineA2D);
			cout << "    The Distance Between the Center of the CIRCLE and the TRIANGLE is:  " << endl << "     * " << "[" << af << "]" << endl;
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 17) { //ComputeLineSphereIntersection
			ComputeLineSphereIntersection(LineA, SphereA, VectorA, VectorB);
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 18) { //LinePlaneIntersection
			IsLinePlaneIntersection(LineA, PlaneA, VectorA);
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 19) { //Line and Line Intersection
			bool result = false;
			result = IsIntersection(LineA, LineB);
			if (result == true) {
				cout << "Lines Intersect" << endl;
			}
			else {
				cout << "Lines Do Not Intersect" << endl;
			}
			amountoftests += 1;
			system("pause");
		}

		else if (choice == 99) {
			break;
		}

		else if (choice == 1234) {
			bool ibooltmptest;
			ibooltmptest = testmefunctions();
			system("pause");
		}

		else {
			Invalid();
			choice = -1;
		}
	}

	return 0;
}