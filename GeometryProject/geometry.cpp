#include <iostream>
#include <string>
#include <cmath>
#include "geometry.h"
#include "test.h"


#define PI 3.14159265f
#define EPS 1e-9

using namespace std;


TVector3 VectorAG;
TVector3 VectorBG;
TVector3 VectorCG;
TVector3 VectorDG;
TVector3 VectorEG;
TVector3 VectorFG;
TVector3 VectorGG;
TVector3 VectorHG;
TVector3 VectorIG;

TVector2 Vector2DGA;
TVector2 Vector2DGB;
TVector2 Vector2DGC;
TVector2 Vector2DGD;

T3DLine LineGA;
T3DLine LineGB;
T3DLine LineGC;
T3DLine LineGD;

TTriangle2 TriangleA2D;

bool Equals(TVector3& _krA, TVector3& _krB) {

	VectorAG = _krA;
	VectorBG = _krB;

	float iT = 0;

	bool equals = false;

	if ((_krA.m_fX == _krB.m_fX) && (_krA.m_fY == _krB.m_fY) && (_krA.m_fZ == _krB.m_fZ)) {
		equals = true;
	}

	return equals;
}

TVector3& Add(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant) {

	VectorAG = _krA;
	VectorBG = _krB;

	float iT = 0;

	_rResultant.m_fX = (VectorAG.m_fX + VectorBG.m_fX);
	_rResultant.m_fY = (VectorAG.m_fY + VectorBG.m_fY);
	_rResultant.m_fZ = (VectorAG.m_fZ + VectorBG.m_fZ);

	return _rResultant;
}

TVector3& Subtract(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant) {

	VectorAG = _krA;
	VectorBG = _krB;

	_rResultant.m_fX = (VectorAG.m_fX - VectorBG.m_fX);
	_rResultant.m_fY = (VectorAG.m_fY - VectorBG.m_fY);
	_rResultant.m_fZ = (VectorAG.m_fZ - VectorBG.m_fZ);

	return _rResultant;
}

TVector3& ScaleVector(const TVector3& _krA, const float _kfScalar, TVector3& _rResultant) {

	VectorAG = _krA;
	float iT = 0;
	float scalar = _kfScalar;

	VectorAG.m_fX = (VectorAG.m_fX * scalar);
	VectorAG.m_fY = (VectorAG.m_fY * scalar);
	VectorAG.m_fZ = (VectorAG.m_fZ * scalar);

	cout << endl << endl;
	iT = iT * scalar;

	_rResultant = VectorAG;

	return  _rResultant;

}

float Magnitude(const TVector3& _krA) {
	VectorAG = _krA;


	float result;

	result = sqrt((VectorAG.m_fX * VectorAG.m_fX) + (VectorAG.m_fY * VectorAG.m_fY) + (VectorAG.m_fZ * VectorAG.m_fZ));

	return result;
}

float DotProduct(const TVector3& _krA, const TVector3& _krB) {

	VectorAG = _krA;
	VectorBG = _krB;

	float result = 0;

	result = ((VectorAG.m_fX + VectorBG.m_fX) + (VectorAG.m_fY + VectorBG.m_fY) + (VectorBG.m_fZ + VectorBG.m_fZ));

	return result;
}

TVector3& CrossProduct(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant) {

	VectorAG = _krA;
	VectorBG = _krB;
	VectorCG = _rResultant;

	VectorCG.m_fX = ((VectorAG.m_fY * VectorBG.m_fZ) - (VectorAG.m_fZ * VectorBG.m_fY));
	VectorCG.m_fY = ((VectorAG.m_fZ * VectorBG.m_fX) - (VectorAG.m_fX * VectorBG.m_fZ));
	VectorCG.m_fZ = ((VectorAG.m_fX * VectorBG.m_fY) - (VectorAG.m_fY * VectorBG.m_fX));

	_rResultant = VectorCG;

	return _rResultant;
}

TVector3& Normalise(const TVector3& _krA, TVector3& _rResultant) {

	VectorAG = _krA;
	float iT = 0;
	float AL = 0;
	float BL = 0;



	//|V| = sqrt(x*x + y*y + z*z)

	AL = sqrt((VectorAG.m_fX * VectorAG.m_fX) + (VectorAG.m_fY * VectorAG.m_fY) + (VectorAG.m_fZ * VectorAG.m_fZ));

	//V/|V| = (x/|V|, y/|V|, z/|V|)

	VectorCG.m_fX = (VectorAG.m_fX / AL);
	VectorCG.m_fY = (VectorAG.m_fY / AL);
	VectorCG.m_fZ = (VectorAG.m_fZ / AL);

	_rResultant = VectorCG;

	return _rResultant;
}

TVector3& Projection(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant) {

	float iT = 0;
	float dot_p = 0;
	float mag = 0;
	float ans = 0;

	VectorAG = _krA;
	VectorBG = _krB;

	dot_p = ((VectorAG.m_fX * VectorBG.m_fX) + (VectorAG.m_fY * VectorBG.m_fY) + (VectorAG.m_fZ * VectorBG.m_fZ));

	mag = (sqrt((VectorBG.m_fX * VectorBG.m_fX) + (VectorBG.m_fY * VectorBG.m_fY) + (VectorBG.m_fZ * VectorBG.m_fZ)));

	ans = (dot_p / mag);

	cout << "Scalar Projection: " << ans << endl;

	_rResultant.m_fX = VectorAG.m_fX * ans;
	_rResultant.m_fY = VectorAG.m_fY * ans;
	_rResultant.m_fZ = VectorAG.m_fZ * ans;


	return _rResultant;
}

float ComputeAngleBetween(const TVector2& _krA, const TVector2& _krB) {

	float iT = 0;
	float dot_p = 0;
	float mag = 0;
	float ans = 0;
	float length_A;
	float length_B;
	float dot_product;

	Vector2DGA = _krA;
	Vector2DGB = _krB;

	length_A = sqrt((Vector2DGA.m_fX * Vector2DGA.m_fX) + (Vector2DGA.m_fY * Vector2DGA.m_fY));
	length_B = sqrt((Vector2DGB.m_fX * Vector2DGB.m_fX) + (Vector2DGB.m_fY * Vector2DGB.m_fY));

	dot_product = ((Vector2DGA.m_fX * Vector2DGB.m_fX) + (Vector2DGA.m_fY * Vector2DGB.m_fY));

	ans = (dot_product / (length_A * length_B));

	ans = acos(ans);

	iT = ans;

	ans = (ans * 180 / PI);
	//cout << "Or: " << iT << " Radians" << endl;

	return ans;
}

float ComputeAngleBetween(const TVector3& _krA, const TVector3& _krB) {

	float iT = 0;
	float dot_p = 0;
	float mag = 0;
	float ans = 0;
	float length_A;
	float length_B;
	float dot_product;

	VectorAG = _krA;
	VectorBG = _krB;

	length_A = sqrt((VectorAG.m_fX * VectorAG.m_fX) + (VectorAG.m_fY * VectorAG.m_fY) + (VectorAG.m_fZ * VectorAG.m_fZ));
	length_B = sqrt((VectorBG.m_fX * VectorBG.m_fX) + (VectorBG.m_fY * VectorBG.m_fY) + (VectorBG.m_fZ * VectorBG.m_fZ));

	dot_product = ((VectorAG.m_fX * VectorBG.m_fX) + (VectorAG.m_fY * VectorBG.m_fY) + (VectorAG.m_fZ * VectorBG.m_fZ));

	ans = (dot_product / (length_A * length_B));

	ans = acos(ans);

	iT = ans;

	ans = (ans * 180 / PI);

	return ans;
}

float ComputeDistancePointToLine(const T3DLine& _krLine, const TVector3& _krPoint) {

	float linebeginx;
	float linebeginy;
	float linebeginz;

	float lineendx;
	float lineendy;
	float lineendz;

	/*float linex;
	float liney;
	float linez;*/

	float distance;

	VectorAG = _krPoint;

	float iT;

	cout << "-= Line =-" << endl;

	cout << "Line Start X: ";
	cin >> linebeginx;

	cout << "Line Start Y: ";
	cin >> linebeginy;

	cout << "Line Start Z: ";
	cin >> linebeginz;

	cout << "Line End X: ";
	cin >> lineendx;

	cout << "Line End Y: ";
	cin >> lineendy;

	cout << "Line End Z: ";
	cin >> lineendz;

	/* First part of equation */

	VectorCG.m_fX = (VectorAG.m_fX - linebeginx);
	VectorCG.m_fY = (VectorAG.m_fY - linebeginy);
	VectorCG.m_fZ = (VectorAG.m_fZ - linebeginz);
	VectorDG.m_fX = (VectorAG.m_fX - lineendx);
	VectorDG.m_fY = (VectorAG.m_fY - lineendy);
	VectorDG.m_fZ = (VectorAG.m_fZ - lineendz);

	VectorFG.m_fX = (VectorCG.m_fX * VectorDG.m_fX);
	VectorFG.m_fY = (VectorCG.m_fY * VectorDG.m_fY);
	VectorFG.m_fZ = (VectorCG.m_fZ * VectorDG.m_fZ);

	/* Normalise FG INTO VectorGG*/

	iT = sqrt((VectorFG.m_fX * VectorFG.m_fX) + (VectorFG.m_fY * VectorFG.m_fY) + (VectorFG.m_fZ * VectorFG.m_fZ));
	VectorGG.m_fX = (VectorFG.m_fX / iT);
	VectorGG.m_fY = (VectorFG.m_fY / iT);
	VectorGG.m_fZ = (VectorFG.m_fZ / iT);

	/* Second part of equation */

	VectorEG.m_fX = (lineendx - linebeginx);
	VectorEG.m_fY = (lineendy - linebeginy);
	VectorEG.m_fZ = (lineendz - linebeginz);

	/* Normalise EG INTO VectorHG*/

	iT = sqrt((VectorEG.m_fX * VectorEG.m_fX) + (VectorEG.m_fY * VectorEG.m_fY) + (VectorEG.m_fZ * VectorEG.m_fZ));
	VectorHG.m_fX = (VectorEG.m_fX / iT);
	VectorHG.m_fY = (VectorEG.m_fY / iT);
	VectorHG.m_fZ = (VectorEG.m_fZ / iT);

	/*distance = normalised FG / normalised EG*/

	float x;
	float y;
	float z;

	x = (VectorGG.m_fX + VectorHG.m_fX);
	y = (VectorGG.m_fY + VectorHG.m_fY);
	z = (VectorGG.m_fZ + VectorHG.m_fZ);

	distance = (x + y + z);

	return distance;
}

/*
name of function : ComputeDistancePointToPlane
@author: Andres Villacreces
@parameter: Find the Distance From a point to a Plane
@return: float
*/
float ComputeDistancePointToPlane(const TPlane& _krPlane, const TVector3& _krPoint)
{
	float M = sqrt(pow(_krPlane.m_v3normal.m_fX, 2) + pow(_krPlane.m_v3normal.m_fY, 2) + pow(_krPlane.m_v3normal.m_fZ, 2));

	TVector3 VecPo = Subtract(_krPoint, _krPlane.m_v3point, VecPo);

	float d = abs((VecPo.m_fX * _krPlane.m_v3normal.m_fX) + (VecPo.m_fY * _krPlane.m_v3normal.m_fY) + (VecPo.m_fZ * _krPlane.m_v3normal.m_fZ)) / M;

	return d;
}

/*
name of function : ComputeDistancePointToSphere
@author: Andres Villacreces
@parameter: Find the Distance Between a point and the Center of a Sphere
@return: float
*/
float ComputeDistancePointToSphere(const TSphere& _krSphere, const TVector3& _krPoint)
{
	TVector3 _rResultant;
	TVector3 VecPo;
	TVector3 DisSpPo = Subtract(_krPoint, _krSphere.m_v3center, _rResultant);

	VecPo = _krPoint;

	float d = sqrt(pow(_krSphere.m_v3center.m_fX - VecPo.m_fX, 2) + pow(_krSphere.m_v3center.m_fY - VecPo.m_fY, 2) + pow(_krSphere.m_v3center.m_fZ - VecPo.m_fZ, 2)) - _krSphere.m_fRadius;

	return d;

}
/*
float ComputeDistancePointToSphere(const TSphere& _krSphere, const TVector3& _krPoint){

system("cls");

	float x, y, z, h, k, j, r, d;

	std::cout << "COMPUTING DISTANCE BETWEEN POINT AND CENTER OF THE SPHERE:" << endl << endl;

	std::cout << "1) Enter the Coordinates of the Point:" << endl << endl;

	std::cout << "      Enter the Coordinate x-- ";
	std::cin >> x;
	std::cout << "      Enter the Coordinate y-- ";
	std::cin >> y;
	std::cout << "      Enter the Coordinate Z-- ";
	std::cin >> z;
	cout << endl;

	std::cout << "  The 3D Coordinate is:" << endl;
	std::cout << "    * " << "(" << x << " , " << y << " , " << z << ")" << "\n";
	cout << endl << endl;

	std::cout << "2) Defining the EQUATION for the SPHERE" << endl << endl;
	std::cout << "   * Enter the Value 'h'-- ";
	std::cin >> h;
	std::cout << "   * Enter the Value 'k'-- ";
	std::cin >> k;
	std::cout << "   * Enter the Value 'j'-- ";
	std::cin >> j;
	std::cout << "   * Enter the Value 'r'-- ";
	std::cin >> r;
	cout << endl;

	std::cout << "  The Equation for the SPHERE is: " << endl;
	std::cout << "    * " << "[" << "(" << "x" << " - " << h << ")" << "^" << 2 << "]" << " + " << "[" << "(" << "y" << " - " << k << ")" << "^" << 2 << "]"
		<< " + " << "[" << "(" << "z" << " - " << j << ")" << "^" << 2 << "]" << " = " << "(" << r << ")" << "^" << 2 << "\n";
	cout << endl << endl;

	std::cout << "3) Finding the Distance Between POINT and Center of the SPHERE:" << endl << endl;
	d = sqrt((pow((x - h), 2)) + (pow((y - k), 2)) + (pow((z - j), 2))) - r;

	return d;
}*/

/*
name of function : ComputeDistanceCircleToCircle
@author: Andres Villacreces
@parameter: Find the Distance Between the Center of two Circles
@return: float
*/
float ComputeDistanceCircleToCircle(const TCircle& _krCircle1, const TCircle& _krCircle2)
{
	TVector2 _rResultant;

	_rResultant.m_fX = _krCircle1.m_v2center.m_fX - _krCircle2.m_v2center.m_fX;
	_rResultant.m_fY = _krCircle1.m_v2center.m_fY - _krCircle2.m_v2center.m_fY;

	float d = sqrt(pow(_rResultant.m_fX, 2) + pow(_rResultant.m_fY, 2));


	return d;

}

/*float ComputeDistanceCircleToCircle(const TCircle& _krCircle1, const TCircle& _krCircle2) {

system("cls");

	float h1, h2, k2, k1, r1, r2, d;

	std::cout << "COMPUTING DISTANCE BETWEEN THE CENTERS OF TWO CICLES:" << endl << endl;

	std::cout << "1) Defining the EQUATION for the First CIRCLE:" << endl << endl;

	std::cout << "      * Center of the Circle: Coordinate 'h'-- ";
	std::cin >> h1;
	std::cout << "      * Center of the Circle: Coordinate 'k'-- ";
	std::cin >> k1;
	std::cout << "      Enter the Radius-- ";
	std::cin >> r1;
	cout << endl;
	std::cout << "  The EQUATION for the First Circle is:" << endl;
	std::cout << "    * " << "(" << "x" << " - " << h1 << ")" << "^" << 2 << " + " << "(" << "y" << " - " << k1 << ")" << "^" << 2 << " = " << r1 << "^" << 2 << "\n";
	cout << endl << endl;

	std::cout << "2) Defining the EQUATION for the Second CIRCLE:" << endl << endl;

	std::cout << "      * Center of the Circle: Coordinate 'h'-- ";
	std::cin >> h2;
	std::cout << "      * Center of the Circle: Coordinate 'k'-- ";
	std::cin >> k2;
	std::cout << "      Enter the Radius-- ";
	std::cin >> r2;
	cout << endl;
	std::cout << "  The EQUATION for the Second Circle is:" << endl;
	std::cout << "    * " << "(" << "x" << " - " << h2 << ")" << "^" << 2 << " + " << "(" << "y" << " - " << k2 << ")" << "^" << 2 << " = " << r2 << "^" << 2 << "\n";
	cout << endl << endl;

	std::cout << "3) Finding the Distance Between the Centers of TWO CIRCLES:" << endl << endl;
	d = sqrt((pow((h2 - h1), 2)) + (pow((k2 - k1), 2)));

	return d;
}*/

float ComputeDistanceCircleToTriangle(const TCircle& _krCircle, const TTriangle2& _krTriangle)
{
	TVector2 Trianglecenter;
	TVector2 EndResult;

	Trianglecenter.m_fX = (_krTriangle.m_v2p1.m_fX + _krTriangle.m_v2p2.m_fX + _krTriangle.m_v2p3.m_fX) / 3;
	Trianglecenter.m_fY = (_krTriangle.m_v2p1.m_fY + _krTriangle.m_v2p2.m_fY + _krTriangle.m_v2p3.m_fY) / 3;

	EndResult.m_fX = _krCircle.m_v2center.m_fX - Trianglecenter.m_fX;
	EndResult.m_fY = _krCircle.m_v2center.m_fY - Trianglecenter.m_fY;

	float d = sqrt(pow(EndResult.m_fX, 2) + pow(EndResult.m_fY, 2));


	return d;
}


/*
float ComputeDistanceCircleToTriangle(const TCircle& _krCircle, const TTriangle2& _krTriangle) {

	system("cls");

float x1, y1, x2, y2, x3, y3, cx, cy, d, dx, dy;

std::cout << "COMPUTING DISTANCE BETWEEN THE CENTER OF A CIRCLE AND A TRIANGLE:" << endl << endl;
/*
std::cout << "1) Defining the EQUATION for the CIRCLE:" << endl << endl;

std::cout << "      * Center of the Circle: Coordinate 'h'-- ";
std::cin >> h;
std::cout << "      * Center of the Circle: Coordinate 'k'-- ";
std::cin >> k;
std::cout << "      * Enter the Radius-- ";
std::cin >> r;
cout << endl;
std::cout << "  The EQUATION for the Circle is:" << endl;
std::cout << "    * " << "(" << "x" << " - " << h << ")" << "^" << 2 << " + " << "(" << "y" << " - " << k << ")" << "^" << 2 << " = " << r << "^" << 2 << "\n";
cout << endl << endl;
*/
/*
cout << "Center Of Circle X: ";
cin >> cx;
cout << "Center Of Circle Y: ";
cin >> cy;

std::cout << "2) Defining the CENTROID of the TRIANGLE:" << endl << endl;

std::cout << "      * First Point X-Coordinate-- ";
std::cin >> x1;
std::cout << "      * First Point Y-Coordinate-- ";
std::cin >> y1;
std::cout << "      * Second Point X-Coordinate-- ";
std::cin >> x2;
std::cout << "      * Second Point Y-Coordinate-- ";
std::cin >> y2;
std::cout << "      * Third Point X-Coordinate-- ";
std::cin >> x3;
std::cout << "      * Third Point Y-Coordinate-- ";
std::cin >> y3;
cout << endl;
std::cout << "  The CENTROID of the TRIANGLE is Defined by:" << endl;
std::cout << "    * " << "M" << " = " << "[" << "(" << x1 << " + " << x2 << " + " << x3 << ")" << "/" << 3 << " , "
<< "(" << y1 << " + " << y2 << " + " << y3 << ")" << "/" << 3 << "]" << "\n";

dx = ((x1 + x2 + x3) / 3);
dy = ((y1 + y2 + y3) / 3);


std::cout << "    * " << "M" << " = " << "[" << "(" << dx << " , " << dy << "]" << "\n";
cout << endl << endl;

std::cout << "3) Finding the Distance Between the Center of the CIRCLE and the TRIANGLE:" << endl << endl;

d = sqrt((dx - cx)*(dx - cx) + ((dy - cy)*(dy - cy)));

return d;
}
*/
/*
name of function : ComputeLineSphereIntersection
@author: Andres Villacreces
@parameter: Find the Points of Intersection Between a Line and a Sphere
@return: EIntersections
*/
EIntersections ComputeLineSphereIntersection(const T3DLine& _krLine, const TSphere& _krSphere, TVector3& _rv3IntersectionPoint1, TVector3& _rv3IntersectionPoint2) {

	float dx, dy, dz;
	float Imagi_t, RealP_t;
	float X1, X2, Y1, Y2, Z1, Z2, x1, x0, y1, y0, z1, z0, h, k, j, r;
	float a_coftt, b_coftt, c_coftt, Dscrt, Value_t_1, Value_t_2;


	std::cout << "COMPUTING LINE AND SPHERE INTERSECTION:" << endl << endl;

	std::cout << "1) Defining the 3D LINE:" << endl << endl;

	std::cout << "     Enter the Values for the X-Point" << endl;
	std::cout << "      * x1-- ";
	std::cin >> x1;
	std::cout << "      * x0-- ";
	std::cin >> x0;
	std::cout << "     Enter the Values for the Y-Point" << endl;
	std::cout << "      * y1-- ";
	std::cin >> y1;
	std::cout << "      * y0-- ";
	std::cin >> y0;
	std::cout << "     Enter the Values for the Z-Point" << endl;
	std::cout << "      * z1-- ";
	std::cin >> z1;
	std::cout << "      * z0-- ";
	std::cin >> z0;

	dx = x1 - x0;
	dy = y1 - y0;
	dz = z1 - z0;

	cout << endl;
	std::cout << "    The 3D LINE is Defined by:" << endl;
	std::cout << "     * " << "x" << " = " << dx << "t" << ((x0 < 0) ? ' ' : '+') << x0 << "\n";
	std::cout << "     * " << "y" << " = " << dy << "t" << ((y0 < 0) ? ' ' : '+') << y0 << "\n";
	std::cout << "     * " << "z" << " = " << dz << "t" << ((z0 < 0) ? ' ' : '+') << z0 << "\n";
	cout << endl << endl;

	std::cout << "2) Finding the EQUATION for the SPHERE" << endl << endl;
	std::cout << "     * Enter the Value 'h'-- ";
	std::cin >> h;
	std::cout << "     * Enter the Value 'k'-- ";
	std::cin >> k;
	std::cout << "     * Enter the Value 'j'-- ";
	std::cin >> j;
	std::cout << "     * Enter the value 'Radius'-- ";
	std::cin >> r;
	cout << endl;

	std::cout << "  The Equation for the ELLIPSE is: " << endl;
	std::cout << "   * " << "[" << "(" << "xs" << " - " << h << ")" << "^" << 2 << "]" << " + " << "[" << "(" << "ys" << " - " << k << ")" << "^" << 2 << "]"
		<< " + " << "[" << "(" << "zs" << " - " << j << ")" << "^" << 2 << "]" << " = " << "(" << r << ")" << "^" << 2 << "\n";
	cout << endl << endl;

	std::cout << "3) Finding Points of Intersection of SPHERE and LINE" << endl << endl;

	std::cout << "    Using Quadratic Equation to Find the Points" << endl;

	a_coftt = (pow((x1 - x0), 2)) + (pow((y1 - y0), 2)) + (pow((z1 - z0), 2));
	b_coftt = 2 * (((x1 - x0) * (x0 - h) + (y1 - y0) * (y0 - k) + (z1 - z0) * (z0 - j)));
	c_coftt = (pow((h), 2)) + (pow((k), 2)) + (pow((j), 2)) + (pow((x0), 2)) + (pow((y0), 2)) + (pow((z0), 2)) - 2 * (h * x0 + k * y0 + j * z0) - (pow((r), 2));

	std::cout << "     Coefficients: " << endl;
	std::cout << "       * a_coefficient = " << a_coftt << endl;
	std::cout << "       * b_coefficient = " << b_coftt << endl;
	std::cout << "       * c_coefficient = " << c_coftt << endl;
	Dscrt = b_coftt * b_coftt - 4 * a_coftt * c_coftt;
	std::cout << "         Discriminant  = " << Dscrt << endl;
	cout << endl;

	if (Dscrt > 0)
	{
		Value_t_1 = (-b_coftt + sqrt(Dscrt)) / (2 * a_coftt);
		std::cout << "      * Value_t_1 = " << Value_t_1 << endl;

		X1 = Value_t_1 * (x1 - x0) + x0;
		Y1 = Value_t_1 * (y1 - y0) + y0;
		Z1 = Value_t_1 * (z1 - z0) + z0;

		Value_t_2 = (-b_coftt - sqrt(Dscrt)) / (2 * a_coftt);
		std::cout << "      * Value_t_2 = " << Value_t_2 << endl;

		X2 = Value_t_2 * (x1 - x0) + x0;
		Y2 = Value_t_2 * (y1 - y0) + y0;
		Z2 = Value_t_2 * (z1 - z0) + z0;

		cout << endl;
		std::cout << "  First Point of Intersection" << endl;
		std::cout << "    P1: " << "(" << X1 << " , " << Y1 << " , " << Z1 << ")" << endl;
		cout << endl;
		std::cout << "  Second Point of Intersection" << endl;
		std::cout << "    P2: " << "(" << X2 << " , " << Y2 << " , " << Z2 << ")" << endl;
		cout << endl;
		return  INTERSECTION_TWO;
	}

	else if (Dscrt == 0)
	{
		Value_t_1 = (-b_coftt + sqrt(Dscrt)) / (2 * a_coftt);
		std::cout << "      * Value_t_1 = " << Value_t_1 << endl;

		X1 = Value_t_1 * (x1 - x0) + x0;
		Y1 = Value_t_1 * (y1 - y0) + y0;
		Z1 = Value_t_1 * (z1 - z0) + z0;

		Value_t_2 = (-b_coftt - sqrt(Dscrt)) / (2 * a_coftt);
		std::cout << "      * Value_t_2 = " << Value_t_1 << endl;

		X2 = Value_t_2 * (x1 - x0) + x0;
		Y2 = Value_t_2 * (y1 - y0) + y0;
		Z2 = Value_t_2 * (z1 - z0) + z0;

		std::cout << " The Point of Intersection" << endl;
		std::cout << "  P1: " << "(" << X1 << " , " << Y1 << " , " << Z1 << ")" << endl;
		std::cout << " Second Point of Intersection" << endl;
		std::cout << "  P2: " << "(" << X2 << " , " << Y2 << " , " << Z2 << ")" << endl;
		return  INTERSECTION_ONE;
	}

	else
	{
		std::cout << " There are no Intersection Points" << endl;
		RealP_t = -b_coftt / (2 * a_coftt);
		Imagi_t = sqrt(-Dscrt) / (2 * a_coftt);

		std::cout << "      * Value_t_1 = " << RealP_t << " + " << Imagi_t << " i" << endl;
		std::cout << "      * Value_t_2 = " << RealP_t << " - " << Imagi_t << " i" << endl;
		return  INTERSECTION_NONE;
	}
}

/*
name of function : IsLinePlaneIntersection
@author: Andres Villacreces
@parameter: Find the Point of Intersection Between a Line and a Plane
@return: bool
*/
bool IsLinePlaneIntersection(const T3DLine& _krLine, const TPlane& _krPlane, TVector3& _rv3IntersectionPoint) {

	system("cls");

	float X, Y, Z, Value_t, dx, dy, dz, x1, x0, y1, y0, z1, z0, m, n, c;

	std::cout << "COMPUTING LINE AND PLANE INTERSECTION:" << endl << endl;

	std::cout << "1) Defining the 3D LINE:" << endl << endl;

	std::cout << " Enter the Values for the X-Point" << endl;
	std::cout << "   * x1-- ";
	std::cin >> x1;
	std::cout << "   * x0-- ";
	std::cin >> x0;
	std::cout << " Enter the Values for the Y-Point" << endl;
	std::cout << "   * y1-- ";
	std::cin >> y1;
	std::cout << "   * y0-- ";
	std::cin >> y0;
	std::cout << " Enter the Values for the Z-Point" << endl;
	std::cout << "   * z1-- ";
	std::cin >> z1;
	std::cout << "   * z0-- ";
	std::cin >> z0;

	dx = x1 - x0;
	dy = y1 - y0;
	dz = z1 - z0;

	cout << endl;
	std::cout << "  The 3D LINE is Defined by:" << endl;
	std::cout << "  * " << "x" << " = " << dx << "t" << ((x0 < 0) ? ' ' : '+') << x0 << "\n";
	std::cout << "  * " << "y" << " = " << dy << "t" << ((y0 < 0) ? ' ' : '+') << y0 << "\n";
	std::cout << "  * " << "z" << " = " << dz << "t" << ((z0 < 0) ? ' ' : '+') << z0 << "\n";
	cout << endl << endl;

	std::cout << "2) Finding the EQUATION for the PLANE" << endl << endl;
	std::cout << "  * Enter the Slope of the Line on the y-z Plane: ";
	std::cin >> m;
	std::cout << "  * Enter the Slope of the Line on the x-y Plane: ";
	std::cin >> n;
	std::cout << "  * Enter the 'y' Value of the Plane at the Point (0,0,0): ";
	std::cin >> c;
	cout << endl;

	std::cout << "  The Equation for the PLANE is: " << endl;
	std::cout << "  * " << "y" << " = " << m << "x" << " + " << n << "z" << " + " << c << "\n";
	cout << endl << endl;		std::cout << "3) Finding Point of Intersection of PLANE with LINE" << endl << endl;

	std::cout << "    Using Quadratic Equation to Find the Points" << endl;

	Value_t = (c + m * x0 + n * z0 - y0) / (m * x0 - m * x1 + n * z0 - n * z1 - y0 + y1);
	std::cout << "     * t_Value = " << Value_t << endl;

	X = Value_t * (x1 - x0) + x0;
	Y = Value_t * (y1 - y0) + y0;
	Z = Value_t * (z1 - z0) + z0;



	std::cout << "  The Point of Intersection Between a LINE AND a PLANE" << endl;
	std::cout << "    P: " << "(" << X << " , " << Y << " , " << Z << ")" << endl;

	return true;
}

bool IsIntersection(const T3DLine& _krLine1, const T3DLine& _krLine2) {

	system("cls");

	double d1, d2, d3, d4, d5, m;

	cout << "Line 1 first point X:";
	cin >> VectorAG.m_fX;
	cout << "Line 1 first point Y:";
	cin >> VectorAG.m_fY;
	cout << "Line 1 first point Z:";
	cin >> VectorAG.m_fZ;

	cout << "Line 1 second point X:";
	cin >> VectorBG.m_fX;
	cout << "Line 1 second point Y:";
	cin >> VectorBG.m_fY;
	cout << "Line 1 second point Z:";
	cin >> VectorBG.m_fZ;

	cout << endl << endl;

	cout << "Line 2 first point X:";
	cin >> VectorCG.m_fX;
	cout << "Line 2 first point Y:";
	cin >> VectorCG.m_fY;
	cout << "Line 2 first point Z:";
	cin >> VectorCG.m_fZ;

	cout << "Line 2 first point X:";
	cin >> VectorDG.m_fX;
	cout << "Line 2 first point Y:";
	cin >> VectorDG.m_fY;
	cout << "Line 2 first point Z:";
	cin >> VectorDG.m_fZ;

	cout << endl << endl;

	VectorEG.m_fX = (VectorAG.m_fX - VectorCG.m_fX);
	VectorEG.m_fY = (VectorAG.m_fY - VectorCG.m_fY);
	VectorEG.m_fZ = (VectorAG.m_fZ - VectorCG.m_fZ);

	VectorFG.m_fX = (VectorDG.m_fX - VectorCG.m_fX);
	VectorFG.m_fY = (VectorDG.m_fY - VectorCG.m_fY);
	VectorFG.m_fZ = (VectorDG.m_fZ - VectorCG.m_fZ);

	if (abs(VectorFG.m_fX) < EPS && abs(VectorFG.m_fY) < EPS && abs(VectorFG.m_fZ) < EPS) {
		return false; //NO COLL
	}

	VectorGG.m_fX = (VectorBG.m_fX - VectorAG.m_fX);
	VectorGG.m_fY = (VectorBG.m_fY - VectorAG.m_fY);
	VectorGG.m_fZ = (VectorBG.m_fZ - VectorAG.m_fZ);

	if (abs(VectorGG.m_fX) < EPS && abs(VectorGG.m_fY) < EPS && abs(VectorGG.m_fZ) < EPS) {
		return false; //NO COLL
	}

	d1 = VectorEG.m_fX * VectorFG.m_fX + VectorEG.m_fY * VectorFG.m_fY + VectorEG.m_fZ * VectorFG.m_fZ;
	d2 = VectorFG.m_fX * VectorGG.m_fX + VectorFG.m_fY * VectorGG.m_fY + VectorFG.m_fZ * VectorGG.m_fZ;
	d3 = VectorEG.m_fX * VectorGG.m_fX + VectorEG.m_fY * VectorGG.m_fY + VectorEG.m_fZ * VectorGG.m_fZ;
	d4 = VectorFG.m_fX * VectorEG.m_fX + VectorFG.m_fY * VectorEG.m_fY + VectorFG.m_fZ * VectorEG.m_fZ;
	d5 = VectorGG.m_fX * VectorGG.m_fX + VectorGG.m_fY * VectorGG.m_fY + VectorGG.m_fZ * VectorGG.m_fZ;

	m = d5 * d4 - d2 * d2;
	if (abs(m) < EPS) {
		return false; //NO COLL
	}

	return true; //COLL
}

TTriangle2& RotateTriangleAroundPoint(const TTriangle2& _krTriangle, const float _kfRotAngleInRadians, const TVector2& _krRotAroundPoint, TTriangle2& _rRotatedTriangle) {

	system("cls");

	float t1x, t1y, t2x, t2y, t3x, t3y, cx, cy, angle;

	cout << "-= Triangle =-" << endl;
	cout << "First Point X: ";
	cin >> t1x;
	cout << "First Point Y: ";
	cin >> t1y;
	cout << "Second Point X: ";
	cin >> t2x;
	cout << "Second Point Y: ";
	cin >> t2y;
	cout << "Third Point X: ";
	cin >> t3x;
	cout << "Third Point Y: ";
	cin >> t3y;

	cout << endl << endl;

	cout << "-= Circle =-" << endl;
	cout << "Center of circle X: ";
	cin >> cx;
	cout << "Center of circle Y: ";
	cin >> cy;

	cout << endl << endl;

	cout << " -= Angle =- " << endl;

	cout << "Rotation in Radians: ";
	cin >> angle;

	/* COMPUTE */



	return TriangleA2D;
}




/*
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
float  x1, x2, x3, y1, y2, y3, z1, z2, z3;
float Vx, Vy, Vz, Wx, Wy, Wz, Nx, Ny, Nz;



std::cout << "COMPUTING DISTANCE FROM ANY POINT TO A LINE:" << endl << endl;

std::cout << "1) Defining the Points of the Triangle:" << endl << endl;

std::cout << "     Coordinates First Point:" << endl << endl;

std::cout << "      * Enter the Coordinate x-- ";
std::cin >> x1;
std::cout << "      * Enter the Coordinate y-- ";
std::cin >> y1;
std::cout << "      * Enter the Coordinate Z-- ";
std::cin >> z1;
std::cout << endl;

std::cout << "  The 3D Coordinate is:" << endl;
std::cout << "    * " << "P1" << " = " << "(" << x1 << " , " << y1 << " , " << z1 << ")" << "\n";
std::cout << endl << endl;

std::cout << "     Coordinates Second Point:" << endl << endl;

std::cout << "      * Enter the Coordinate x-- ";
std::cin >> x2;
std::cout << "      * Enter the Coordinate y-- ";
std::cin >> y2;
std::cout << "      * Enter the Coordinate Z-- ";
std::cin >> z2;
std::cout << endl;

std::cout << "  The 3D Coordinate is:" << endl;
std::cout << "    * " << "P2" << " = " << "(" << x2 << " , " << y2 << " , " << z2 << ")" << "\n";
std::cout << endl << endl;

std::cout << "     Coordinates Third Point:" << endl << endl;

std::cout << "      * Enter the Coordinate x-- ";
std::cin >> x3;
std::cout << "      * Enter the Coordinate y-- ";
std::cin >> y3;
std::cout << "      * Enter the Coordinate Z-- ";
std::cin >> z3;
std::cout << endl;

std::cout << "  The 3D Coordinate is:" << endl;
std::cout << "    * " << "P3" << " = " << "(" << x3 << " , " << y3 << " , " << z3 << ")" << "\n";
std::cout << endl << endl;

std::cout << "    * " << "The cross product of two sides of the triangle" << "\n";
std::cout << "    * " << "v = P2 - P1" << "\n";
std::cout << "    * " << "w = P3 - P1" << "\n";
std::cout << "    * " << "N = v * w" << "\n";
std::cout << "    * " << "  N = (P2 - P1) * (P3 - P1)" << "\n";


std::cout << "Vx = x2 - x1" << "\n";
std::cout << "Vy = y2 - y1" << "\n";
std::cout << "Vz = z2 - z1" << "\n";
std::cout << "Wx = x3 - x1" << "\n";
std::cout << "Wy = y3 - y1" << "\n";
std::cout << "Wz = z3 - z1" << "\n";
std::cout << endl;

std::cout << "Nx=(Vy*Wz)-(Vz*Wy)" << "\n";
std::cout << "Ny=(Vz*Wx)-(Vx*Wz)" << "\n";
std::cout << "Nz=(Vx*Wy)-(Vy*Wx)" << "\n";
std::cout << endl;

std::cout << "      Nx" << " = "	<< "[" << y2 << " - " << "(" << y1 << ")" << "]" << "*" << "[" << z3 << " - " << "(" << z1 << ")" << "]" << " - "
<< "[" << y3 << " - " << "(" << y1 << ")" << "]" << "*" << "[" << z2 << " - " << "(" << z1 << ")" << "]" << "\n";

std::cout << "      Ny" << " = "	<< "[" << z2 << " - " << "(" << z1 << ")" << "]" << "*" << "[" << x3 << " - " << "(" << x1 << ")" << "]" << " - "
<< "[" << x2 << " - " << "(" << x1 << ")" << "]" << "*" << "[" << z3 << " - " << "(" << z1 << ")" << "]" << "\n";

std::cout << "      Nz" << " = "	<< "[" << x2 << " - " << "(" << x1 << ")" << "]" << "*" << "[" << y3 << " - " << "(" << y1 << ")" << "]" << " - "
<< "[" << x3 << " - " << "(" << x1 << ")" << "]" << "*" << "[" << y3 << " - " << "(" << y1 << ")" << "]" << "\n";
std::cout << endl;

Vx = x2-x1;
Vy = y2-y1;
Vz = z2-z1;
Wx = x3-x1;
Wy = y3-y1;
Wz = z3-z1;

std::cout << "      Nx" << " = "	<< "[" << Vy << " * " << Wz << "]" << " - " << "[" << Vz << " * " << Wy << "]" << "\n";
std::cout << "      Ny" << " = "	<< "[" << Vz << " * " << Wx << "]" << " - " << "[" << Vx << " * " << Wz << "]" << "\n";
std::cout << "      Nz" << " = "	<< "[" << Vx << " * " << Wy << "]" << " - " << "[" << Vy << " * " << Wx << "]" << "\n";
std::cout << endl;

Nx = (Vy*Wz)-(Vz*Wy);
Ny = (Vz*Wx)-(Vx*Wz);
Nz = (Vx*Wy)-(Vy*Wx);

std::cout << "      Nx" << " = "	<< Nx << "\n";
std::cout << "      Ny" << " = "	<< Ny << "\n";
std::cout << "      Nz" << " = "	<< Nz << "\n";










system("pause");
return(0);
}



*/