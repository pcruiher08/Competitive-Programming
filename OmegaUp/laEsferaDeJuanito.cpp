#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
//! Precision error constant
#define EPS 0.000000001

//! The mathematical constant Pi
#define PI 3.1415926535897932384626433832795028841971

using namespace std;

/**
 * Used to tell the type of object in an Intersection.
 */
enum IntersectionType {NONE, POINT, LINE, PLANE};

/**
 * Used to classify the number of solutions that a system of equations yields.
 */
enum SLENumSolutions {ZERO, ONE, INFINITE};

/**
 * Converts radians into degrees.
 * @param rad Angle in radians.
 * @return Angle in degrees.
 */
long double RadToDeg(long double rad) {
	return 180 / PI * rad;
}

/**
 * Converts degrees into radians.
 * @param deg Angle in degrees.
 * @return Angle in radians.
 */
long double DegToRad(long double deg) {
	return PI / 180 * deg;
}

/**
 * Object that holds information about an intersection.
 */
struct Intersection {
	//! The type of intersection. This may be of type NONE, POINT, LINE or PLANE.
	IntersectionType type;

	//! The intersection object, held as a void pointer to allow casting to its original form.
	void* object;
};

/**
 * Points are objects that can contain any number of components.
 * They can also be considered vectors.
 */
class Point {
	public:
		//! Vector of components or coordinates.
		vector<long double> coordinates;

	/**
	 * Constructs a point in two dimensions given the X and Y coordinates.
	 * @param x X coordinate of the point.
	 * @param y Y coordinate of the point.
	 */
	Point(long double x, long double y) {
		coordinates.push_back(x);
		coordinates.push_back(y);
	}

	/**
	 * Constructs a point in three dimensions given the X, Y and Z coordinates.
	 * @param x X coordinate of the point.
	 * @param y Y coordinate of the point.
	 * @param z Z coordinate of the point.
	 */
	Point(long double x, long double y, long double z) {
		coordinates.push_back(x);
		coordinates.push_back(y);
		coordinates.push_back(z);
	}

	/**
	 * Constructs a point from an arbitrary set of coordinates.
	 * @param coords An N dimensional array or vector of coordinates.
	 */
	Point(vector<long double> coords) {
		coordinates = coords;
	}

	/**
	 * Creates a copy of another point.
	 * @param p The point to copy.
	 */
	Point(const Point& p) {
		coordinates = p.coordinates;
	}

	/**
	 * Returns the rank or the number of dimensions the point contains.
	 */
	int GetRank() {
		return coordinates.size();
	}

	/**
	 * Returns the first component of the point.
	 */
	long double GetX() {
		return coordinates[0];
	}

	/**
	 * Returns the second component of the point.
	 */
	long double GetY() {
		return coordinates[1];
	}

	/**
	 * Returns the third component of the point.
	 */
	long double GetZ() {
		return coordinates[2];
	}

	/**
	 * Returns the value of the component at a certain index.
	 * @param index Index of the component.
	 */
	long double Get(int index) {
		return coordinates[index];
	}

	/**
	 * Sets the first component of the point.
	 * @param x The value to set the first component to.
	 */
	void SetX(long double x) {
		coordinates[0] = x;
	}

	/**
	 * Sets the second component of the point.
	 * @param y The value to set the second component to.
	 */
	void SetY(long double y) {
		coordinates[1] = y;
	}

	/**
	 * Sets the third component of the point.
	 * @param z The value to set the third component to.
	 */
	void SetZ(long double z) {
		coordinates[2] = z;
	}

	/**
	 * Sets the value of the component at a certain index.
	 * @param index Index of the component.
	 * @param value Value of the component.
	 */
	void Set(int index, long double value) {
		coordinates[index] = value;
	}

	/**
	 * Returns the square of the magnitude of the vector.
	 */
	long double SqrMagnitude() {
		long double value = 0;
		for(int i = 0; i < GetRank(); i++) {
			value += coordinates[i] * coordinates[i];
		}
		return value;
	}

	/**
	 * Returns the magnitude of the vector.
	 */
	long double Magnitude() {
		return sqrt(SqrMagnitude());
	}

	/**
	 * Adds the components of another point onto those of the current point.
	 * @param p The point to add onto the current point.
	 */
	void Add(Point p) {
		for(int i = 0; i < GetRank(); i++) {
			coordinates[i] += p.coordinates[i];
		}
	}

	/**
	 * Subtracts the components of another point from those of the current point.
	 * @param p The point to subtract from the current point.
	 */
	void Subtract(Point p) {
		for(int i = 0; i < GetRank(); i++) {
			coordinates[i] -= p.coordinates[i];
		}
	}

	/**
	 * Scales the vector by a given factor.
	 * @param factor The value to scale the point by.
	 */
	void Scale(long double factor) {
		for(int i = 0; i < GetRank(); i++) {
			coordinates[i] *= factor;
		}
	}

	/**
	 * Normalizes or sets the magnitude of the current vector to be equal to one.
	 */
	void Normalize() {
		if(abs(Magnitude()) < EPS) {
			return;
		}
		Scale(1 / Magnitude());
	}

	/**
	 * If the current point is two dimensional, the function rotates the point by a certain angle.
	 * @param angle The angle in radians to rotate the point by. If the angle is positive, the rotation will be counterclockwise.
	 * @param center The center of rotation. By default this is the origin.
	 */
	void Rotate2D(long double angle, Point center = Point(0, 0)) {
		Subtract(center);
		long double newX = GetX() * cos(angle) - GetY() * sin(angle);
		long double newY = GetX() * sin(angle) + GetY() * cos(angle);
		SetX(newX);
		SetY(newY);
		Add(center);
	}

	/**
	 * If the current point is three dimensional, the function rotates the point by a certain angle around a normal vector.
	 * @param angle The angle in radians to rotate the point by. If the angle is positive, the rotation will be counterclockwise.
	 * @param normal A vector that represents the axis of rotation.
	 * @param center The center of rotation. By default this is the origin.
	 */
	void Rotate3D(long double angle, Point normal, Point center = Point(0, 0, 0)) {
		Point unitNormal(normal);
		unitNormal.Normalize();
		Subtract(center);
		Point rotation = *this * cos(angle) + unitNormal.CrossProduct(*this) * sin(angle) + unitNormal * (unitNormal.DotProduct(*this)) * (1 - cos(angle));
		SetX(rotation.GetX());
		SetY(rotation.GetY());
		SetZ(rotation.GetZ());
		Add(center);
	}

	/**
	 * Returns the dot product of the current point and another point.
	 * @param p The other point in the dot product.
	 */
	long double DotProduct(Point p) {
		long double value = 0;
		for(int i = 0; i < GetRank(); i++) {
			value += coordinates[i] * p.coordinates[i];
		}
		return value;
	}

	/**
	 * Returns the cross product of the current point and another point. This function does not work for vectors of more than three dimensions.
	 * @param p The other point in the cross product.
	 */
	Point CrossProduct(Point p) {
		Point a(*this);
		Point b(p);
		Point result = Point(0, 0, 0);
		while(a.GetRank() < 3) {
			a.coordinates.push_back(0);
		}
		while(b.GetRank() < 3) {
			b.coordinates.push_back(0);
		}
		result.SetX(a.GetY() * b.GetZ() - a.GetZ() * b.GetY());
		result.SetY(a.GetZ() * b.GetX() - a.GetX() * b.GetZ());
		result.SetZ(a.GetX() * b.GetY() - a.GetY() * b.GetX());
		return result;
	}

	/**
	 * Returns the addition of the current point and another point.
	 * @param p The point added to the current point.
	 */
	Point operator + (Point p) const {
		Point addition(coordinates);
		addition.Add(p);
		return addition;
	}

	/**
	 * Returns the subtraction of the current point and another point.
	 * @param p The point subtracted from the current point.
	 */
	Point operator - (Point p) const {
		Point subtraction(coordinates);
		subtraction.Subtract(p);
		return subtraction;
	}

	/**
	 * Multiplies the magnitude of the vector by a given amount.
	 * @param amount The amount to multiply the vector by.
	 */
	Point operator * (long double amount) const {
		Point multiplication(coordinates);
		multiplication.Scale(amount);
		return multiplication;
	}

	/**
	 * Divides the magnitude of the vector by a given amount.
	 * @param amount The amount to divide the vector by.
	 */
	Point operator / (long double amount) const {
		Point division(coordinates);
		division.Scale(1 / amount);
		return division;
	}

	/**
	 * Checks if two points are equal to each other, taking into account possible precision errors.
	 * @param p The point compared to the current point.
	 * @return True if both points are practially equal, or false if otherwise.
	 */
	bool operator == (Point p) const {
		if(coordinates.size() != p.GetRank()) {
			return false;
		}
		for(int i = 0; i < coordinates.size(); i++) {
			if(abs(coordinates[i] - p.coordinates[i]) > EPS) {
				return false;
			}
		}
		return true;
	}

	/**
	 * Checks if a point is less than another point, taking into account possible precision errors.
	 * @param p The point compared to the current point.
	 * @return True if all the components of the first point are less than those of the other point, or false if otherwise.
	 */
	bool operator < (Point p) const {
		for(int i = 0; i < coordinates.size(); i++) {
			if(abs(coordinates[i] - p.coordinates[i]) > EPS) {
				return coordinates[i] < p.coordinates[i];
			}
		}
		return false;
	}
};

/**
 * Object that holds information about the solution of a system of equations.
 */
struct SLESolution {
	//! The number of solutions. This may be of type ZERO, ONE or INFINITE.
	SLENumSolutions numSolutions;

	//! A vector containing the solution if there is a solution.
	vector<long double> solutionVector;
};

/**
 * Returns a point corresponding to the origin or a zero vector with a given rank.
 * @param rank The rank or the number of dimensions of the point.
 */
Point Zero(int rank) {
	vector<long double> coords;
	for(int i = 0; i < rank; i++) {
		coords.push_back(0);
	}
	return Point(coords);
}

/**
 * Checks if two vectors BA and BC are closer in the counterclockwise direction. These two vectors have a common starting point B.
 * @param a The point A which corresponds to the ending point of the first vector.
 * @param b The starting point B of both vectors.
 * @param c The point C which corresponds to the ending point of the second vector.
 * @return True if BA and BC are closer in the counterclockwise direction, or false if otherwise.
 */
bool CCW(Point a, Point b, Point c) {
	Point ba = a - b;
	Point bc = c - b;
	return ba.CrossProduct(bc).GetZ() > -EPS;
}

/**
 * Returns the angle between two vectors BA and BC. These two vectors have a common starting point B.
 * @param a The point A which corresponds to the ending point of the first vector.
 * @param b The starting point B of both vectors.
 * @param c The point C which corresponds to the ending point of the second vector.
 * @return Angle in radians.
 */
long double Angle(Point a, Point b, Point c) {
	Point ba = a - b;
	Point bc = c - b;
	return acos(ba.DotProduct(bc) / (ba.Magnitude() * bc.Magnitude()));
}

/**
 * Matrices hold a table of values that can be used to apply linear transformations to points.
 */
class Matrix {
	public:
		//! A two dimensional vector that holds all of the coefficients.
		vector<vector<long double> > matrix;

	/**
	 * Constructs a zero matrix of a given size.
	 * @param rows The number of rows in the zero matrix.
	 * @param cols The number of columns in the zero matrix.
	 */
	Matrix(int rows, int cols) {
		for(int y = 0; y < rows; y++) {
			vector<long double> submatrix;
			for(int x = 0; x < cols; x++) {
				submatrix.push_back(0);
			}
			matrix.push_back(submatrix);
		}
	}

	/**
	 * Constructs a matrix from a two dimensional C++ vectors.
	 * @param m A two dimensional C++ vector.
	 */
	Matrix(vector<vector<long double> > m) {
		matrix = m;
	}

	/**
	 * Constructs a copy of another matrix.
	 * @param m The matrix to copy.
	 */
	Matrix(const Matrix& m) {
		matrix = m.matrix;
	}

	/**
	 * Returns the value of the matrix at a given row and column.
	 * @param row The row to access.
	 * @param col The column to access.
	 */
	long double Get(int row, int col) {
		return matrix[row][col];
	}

	/**
	 * Changes the value of the matrix at a given row and column to a given amount.
	 * @param row The row to access.
	 * @param col The column to access.
	 * @param value The new value at that position.
	 */
	void Set(int row, int col, long double value) {
		matrix[row][col] = value;
	}

	/**
	 * Swaps the positions of two rows within the matrix.
	 * @param a The index of the first row to swap.
	 * @param b The index of the second row to swap.
	 */
	void SwapRow(int a, int b) {
		for(int x = 0; x < GetColumns(); x++) {
			long double tmp = matrix[a][x];
			matrix[a][x] = matrix[b][x];
			matrix[b][x] = tmp;
		}
	}

	/**
	 * Swaps the positions of two columns within the matrix.
	 * @param a The index of the first column to swap.
	 * @param b The index of the second column to swap.
	 */
	void SwapColumn(int a, int b) {
		for(int y = 0; y < GetRows(); y++) {
			long double tmp = matrix[y][a];
			matrix[y][a] = matrix[y][b];
			matrix[y][b] = tmp;
		}
	}

	/**
	 * Deletes a row from the matrix.
	 * @param row The index of the row to delete.
	 */
	void DeleteRow(int row) {
		matrix.erase(matrix.begin() + row);
	}

	/**
	 * Deletes a column from the matrix.
	 * @param col The index of the column to delete.
	 */
	void DeleteColumn(int col) {
		for(int y = 0; y < GetRows(); y++) {
			matrix[y].erase(matrix[y].begin() + col);
		}
	}

	/**
	 * Inserts a row of zeroes into the matrix.
	 * @param row The index at which the row is inserted.
	 */
	void InsertRow(int row) {
		vector<long double> newRow;
		for(int x = 0; x < GetColumns(); x++) {
			newRow.push_back(0);
		}
		matrix.insert(matrix.begin() + row, newRow);
	}

	/**
	 * Inserts a column of zeroes into the matrix.
	 * @param col The index at which the column is inserted.
	 */
	void InsertColumn(int col) {
		for(int y = 0; y < GetRows(); y++) {
			matrix[y].insert(matrix[y].begin() + col, 0);
		}
	}

	/**
	 * Returns the number of rows held by a matrix.
	 */
	int GetRows() {
		return matrix.size();
	}

	/**
	 * Returns the number of columns held by a matrix.
	 */
	int GetColumns() {
		if(matrix.size() > 0) {
			return matrix[0].size();
		}
		return 0;
	}

	/**
	 * Returns the transpose of the matrix
	 */
	Matrix GetTranspose() {
		Matrix transpose(GetColumns(), GetRows());
		for(int y = 0; y < GetRows(); y++) {
			for(int x = 0; x < GetColumns(); x++) {
				transpose.Set(x, y, Get(y, x));
			}
		}
		return transpose;
	}

	/**
	 * Returns a submatrix of a given size that is offset a certain amount.
	 * @param rows The number of rows in the submatrix.
	 * @param cols The number of columns in the submatrix.
	 * @param startRow The row at which the submatrix starts or is offset.
	 * @param startCol The column at which the submatrix starts or is offset.
	 * @return The resulting submatrix.
	 */
	Matrix GetSubmatrix(int rows, int cols, int startRow = 0, int startCol = 0) {
		Matrix submatrix(rows, cols);
		for(int y = 0; y < rows; y++) {
			for(int x = 0; x < cols; x++) {
				submatrix.matrix[y][x] = matrix[y + startRow][x + startCol];
			}
		}
		return submatrix;
	}

	/**
	 * Multiplies or Applies a linear transformation onto an input vector, assuming that the current matrix is the transformation matrix. This can be expressed by the equation AX = Y, where A is the current matrix, X is the input vector and Y is the output vector.
	 * @param Xvec The vector X that is multiplied by the transformation matrix A.
	 * @return The vector Y that is the output of the transformation.
	 */
	Point Multiply(Point Xvec) {
		if(GetColumns() != Xvec.GetRank()) {
			cerr << "Invalid matrix/vector size for transformation" << endl;
			return Xvec;
		} else {
			vector<long double> components;
			for(int y = 0; y < GetRows(); y++) {
				long double comp = 0;
				for(int x = 0; x < GetColumns(); x++) {
					comp += Xvec.coordinates[x] * matrix[y][x];
				}
				components.push_back(comp);
			}
			return Point(components);
		}
	}

	/**
	 * Returns the determinant of the current matrix assuming it is square.
	 */
	long double GetDeterminant() {
		long double determinant = 0;
		if(GetRows() != GetColumns()) {
			cerr << "Cannot obtain the determinant of a non-square matrix" << endl;
			return 0;
		}
		if(GetRows() > 1) {
			for(int x = 0; x < GetColumns(); x++) {
				Matrix submatrix = GetSubmatrix(GetRows() - 1, GetColumns(), 1);
				submatrix.DeleteColumn(x);
				if(x % 2 == 0) {
					determinant += matrix[0][x] * submatrix.GetDeterminant();
				} else {
					determinant -= matrix[0][x] * submatrix.GetDeterminant();
				}
			}
		} else {
			return matrix[0][0];
		}
		return determinant;
	}

	/**
	 * Solves a system of equations of the form AX = Y for the vector X, assuming that the current matrix A is the transformation matrix.
	 * @param Yvec The vector Y in the equation.
	 * @return An SLESolution object that is of type NONE if the system has no solutions, ONE if there is one solution or INFINITE if there are infinitely many solutions. If there is one solution, the SLESolution object also stores this vector.
	 */
	SLESolution SolveEquations(Point Yvec) {
		SLESolution none;
		none.numSolutions = ZERO;
		SLESolution infinite;
		infinite.numSolutions = INFINITE; 
		if(Yvec.GetRank() != GetRows()) {
			return none;
		}
		Matrix reducedSystem(*this);
		reducedSystem.InsertColumn(reducedSystem.GetColumns());
		for(int y = 0; y < Yvec.GetRank(); y++) {
			reducedSystem.Set(y, reducedSystem.GetColumns() - 1, Yvec.coordinates[y]);
		}
		//Removes rows of only zero
		for(int y = reducedSystem.GetRows() - 1; y >= 0; y--) {
			if(Point(reducedSystem.matrix[y]) == Zero(reducedSystem.GetColumns())) {
				reducedSystem.DeleteRow(y);
			}
		}
		//Removes redundant rows
		for(int a = reducedSystem.GetRows() - 1; a >= 0; a--) {
			for(int b = a - 1; b >= 0; b--) {
				Point pa(reducedSystem.matrix[a]);
				Point pb(reducedSystem.matrix[b]);
				pa.Normalize();
				pb.Normalize();
				if((pa == pb) || (pa == (pb * -1))) {
					reducedSystem.DeleteRow(a);
					break;
				}
			}
		}
		//Returns none if a contradictary row is found
		for(int a = reducedSystem.GetRows() - 1; a >= 0; a--) {
			for(int b = a - 1; b >= 0; b--) {
				Point pa(reducedSystem.matrix[a]);
				Point pb(reducedSystem.matrix[b]);
				pa.coordinates.pop_back();
				pb.coordinates.pop_back();
				pa.Normalize();
				pb.Normalize();
				if((pa == pb) || (pa == (pb * -1))) {
					return none;
				}
			}
		}
		if(reducedSystem.GetRows() < reducedSystem.GetColumns() - 1) {
			return infinite;
		}
		vector<long double> newYVec;
		vector<Point> XVecs;
		for(int y = 0; y < reducedSystem.GetRows(); y++) {
			newYVec.push_back(reducedSystem.Get(y, reducedSystem.GetColumns() - 1));
		}
		reducedSystem.DeleteColumn(reducedSystem.GetColumns() - 1);
		for(int k = 0; k < reducedSystem.GetRows() - 1; k++) {
			Matrix subsystem = reducedSystem.GetSubmatrix(reducedSystem.GetColumns(), reducedSystem.GetColumns(), k);
			vector<long double> subsystemYVecCoords;
			for(int i = 0; i < reducedSystem.GetColumns(); i++) {
				subsystemYVecCoords.push_back(newYVec[k + i]);
			}
			Point subsystemYVec(subsystemYVecCoords);
			Matrix LMatrix(subsystem.GetRows(), subsystem.GetColumns());
			for(int i = 0; i < subsystem.GetRows(); i++) {
				LMatrix.matrix[i][i] = 1;
			}
			Matrix UMatrix(subsystem);
			int swappingRow = 0;
			for(int x = 0; x < subsystem.GetColumns(); x++) {
				for(int y = swappingRow; y < subsystem.GetRows(); y++) {
					if(abs(UMatrix.matrix[y][x]) > EPS) {
						if(y != swappingRow) {
							UMatrix.SwapRow(y, swappingRow);
							long double tmp = subsystemYVec.coordinates[y];
							subsystemYVec.coordinates[y] = subsystemYVec.coordinates[swappingRow];
							subsystemYVec.coordinates[swappingRow] = tmp;
						}
						swappingRow++;
						break;
					}
				}
			}
			int currCol = 0;
			for(int y = 0; y < subsystem.GetRows(); y++) {
				int currRow = y;
				if(currCol >= subsystem.GetColumns()) {
					break;
				}
				while(UMatrix.matrix[currRow][currCol] == 0) {
					currRow++;
					if(currRow >= subsystem.GetRows()) {
						currRow = y;
						currCol++;
						if (currCol >= subsystem.GetColumns()) {
							break;
						}
					}
				}
				if(currCol < subsystem.GetColumns()) {
					if(currRow != y) {
						UMatrix.SwapRow(currRow, y);
					}
					for(int z = y + 1; z < subsystem.GetRows(); z++) {
						if(UMatrix.matrix[z][currCol] != 0) {
							long double mult = UMatrix.matrix[z][currCol] / UMatrix.matrix[y][currCol];
							LMatrix.matrix[z][currCol] = mult;
							for(int x = currCol; x < subsystem.GetColumns(); x++) {
								UMatrix.matrix[z][x] -= mult * UMatrix.matrix[y][x];
							}
						}
					}
					currCol++;
				}
			}
			vector<long double> Zvec;
			vector<long double> output;
			for(int y = 0; y < subsystem.GetRows(); y++) {
				long double current = subsystemYVec.coordinates[y];
				for(int x = 0; x < subsystem.GetColumns(); x++) {
					if(x < Zvec.size()) {
						current -= LMatrix.matrix[y][x] * Zvec[x];
					}
				}
				Zvec.push_back(current);
			}
			for(int y = subsystem.GetRows() - 1; y >= 0; y--) {
				long double current = Zvec[y];
				for(int x = subsystem.GetColumns() - 1; x >= 0; x--) {
					if(x > y) {
						current -= output[subsystem.GetColumns() - x - 1] * UMatrix.matrix[y][x];
					}
					if(x == y) {
						current /= UMatrix.matrix[y][x];
					}
				}
				output.push_back(current);
			}
			vector<long double> reverseOutput;
			while(output.size() > 0) {
				reverseOutput.push_back(output.back());
				output.pop_back();
			}
			Point XVec(reverseOutput);
			XVecs.push_back(XVec);
		}
		bool valid = true;
		for(int y = 1; y < XVecs.size(); y++) {
			if(!(XVecs[y] == XVecs[y - 1])) {
				valid = false;
			}
		}
		if(valid) {
			SLESolution one;
			one.numSolutions = ONE;
			one.solutionVector = XVecs[0].coordinates;
			return one;
		}
		return none;
	}
};

/**
 * Lines are represented by a starting point and an ending point, and can also be used as line segments.
 */
class Line {
	public:
		//! The starting point of the line or line segment.
		Point start;

		//! The ending point of the line or line segment.
		Point end;
	
	/**
	 * Constructs a line from two point classes.
	 * @param s Starting point.
	 * @param e Ending point.
	 */
	Line(Point s, Point e) : start(s), end(e) {}

	/**
	 * Constructs a line from the components of two dimensional points.
	 * @param sx X component of the starting point.
	 * @param sy Y component of the starting point.
	 * @param ex X component of the ending point.
	 * @param ey Y component of the ending point.
	 */
	Line(long double sx, long double sy, long double ex, long double ey) : start(sx, sy), end(ex, ey) {}

	/**
	 * Constructs a line from the components of three dimensional points.
	 * @param sx X component of the starting point.
	 * @param sy Y component of the starting point.
	 * @param sz Z component of the starting point.
	 * @param ex X component of the ending point.
	 * @param ey Y component of the ending point.
	 * @param ez Z component of the ending point.
	 */
	Line(long double sx, long double sy, long double sz, long double ex, long double ey, long double ez) : start(sx, sy, sz), end(ex, ey, ez) {}

	/**
	 * Returns the length of the current line segment
	 */
	long double GetLength() {
		Point vec = end - start;
		return vec.Magnitude();
	}

	/**
	 * Returns the point on the line closest to another point in space given by the input.
	 * @param p The input point.
	 */
	Point GetNearestPoint(Point p) {
		Point vec = end - start;
		Point lvec = p - start;
		long double n = vec.DotProduct(lvec) / (vec.Magnitude() * vec.Magnitude());
		return GetInterpolation(n);
	}

	/**
	 * Returns the point in the line segment closest to another point in space given by the input.
	 * @param p The input point.
	 */
	Point GetNearestPointInSegment(Point p) {
		Point vec = end - start;
		Point lvec = p - start;
		long double n = vec.DotProduct(lvec) / (vec.Magnitude() * vec.Magnitude());
		if(n < 0) {
			n = 0;
		}
		if(n > 1) {
			n = 1;
		}
		return GetInterpolation(n);
	}

	/**
	 * Converts the line into a vector or the difference between the start and end points.
	 */
	Point GetVector() {
		return end - start;
	}

	/**
	 * Returns true if a point is collinear to the line.
	 * @param p The point that is checked.
	 */
	bool IsCollinear(Point p) {
		return GetNearestPoint(p) == p;
	}

	/**
	 * Returns true if a point is contained within a line segment.
	 * @param p The point that is checked.
	 */
	bool IsInSegment(Point p) {
		if(IsCollinear(p)) {
			Point vec = end - start;
			Point lvec = p - start;
			long double n = vec.DotProduct(lvec) / (vec.Magnitude() * vec.Magnitude());
			if(n >= 0 && n <= 1) {
				return true;
			}
		}
		return false;
	}

	/**
	 * Returns true if the line is parallel to another line.
	 * @param l The line that is checked.
	 */
	bool IsParallel(Line l) {
		Point vec = end - start;
		Point lvec = l.end - l.start;
		vec.Normalize();
		lvec.Normalize();
		return (vec == lvec) || (vec == (lvec * -1));
	}

	/**
	 * Returns true if the line is perpendicular to another line.
	 * @param l The line that is checked.
	 */
	bool IsPerpendicular(Line l) {
		Point vec = end - start;
		Point lvec = l.end - l.start;
		return abs(vec.DotProduct(lvec)) < EPS;
	}

	/**
	 * Returns true if the input line and the current line are the same.
	 * @param l The line that is checked.
	 */
	bool Equals(Line l) {
		return IsCollinear(l.start) && IsCollinear(l.end);
	}

	/**
	 * Returns true if the input line segment and the current line segment have the exact same place regardless of direction.
	 * @param l The line that is checked.
	 */
	bool EqualsSegment(Line l) {
		return (start == l.start && end == l.end) || (start == l.end && end == l.start);
	}

	/**
	 * Checks for intersections with another line and returns an intersection object.
	 * @param l The line that the current line may intersect with.
	 * @return An intersection object of type line if both lines are the same, of type point if they intersect at a point or of type none if no intersection could be found.
	 */
	Intersection GetIntersection(Line l) {
		Intersection none;
		none.type = NONE;
		if(IsParallel(l)) {
			if(IsCollinear(l.start)) {
				Line* linePtr = new Line(start, end);
				Intersection line;
				line.type = LINE;
				line.object = (void*)linePtr;
				return line;
			} else {
				return none;
			}
		}
		Matrix coefficients(start.GetRank(), 2);
		for(int y = 0; y < start.GetRank(); y++) {
			coefficients.Set(y, 0, (end - start).coordinates[y]);
			coefficients.Set(y, 1, -(l.end - l.start).coordinates[y]);
		}
		SLESolution solution = coefficients.SolveEquations(l.start - start);
		if(solution.numSolutions == ONE) {
			long double s = solution.solutionVector[0];
			Point* pointPtr = new Point(GetInterpolation(s));
			Intersection point;
			point.type = POINT;
			point.object = (void*)pointPtr;
			return point;
		}
		return none;
	}

	/**
	 * Checks for intersections with another line segment and returns an intersection object.
	 * @param l The line segment that the current line may intersect with.
	 * @return An intersection object of type line segment if both input segments are collinear, of type point if both input segments meet at a point or of type none if no intersection could be found. If the intersection is of type line segment, it only contains the overlapping region of both input segments.
	 */
	Intersection GetSegmentIntersection(Line l) {
		Intersection none;
		none.type = NONE;
		Intersection intersect = GetIntersection(l);
		if(intersect.type == POINT) {
			Point p = *(Point*)intersect.object;
			if(IsInSegment(p) && l.IsInSegment(p)) {
				return intersect;
			}
		} else if (intersect.type == LINE) {
			vector<Point> pointsInSegment;
			vector<Point> uniquePoints;
			if(IsInSegment(l.start)) {
				pointsInSegment.push_back(l.start);
			}
			if(IsInSegment(l.end)) {
				pointsInSegment.push_back(l.end);
			}
			if(l.IsInSegment(start)) {
				pointsInSegment.push_back(start);
			}
			if(l.IsInSegment(end)) {
				pointsInSegment.push_back(end);
			}
			for(int i = 0; i < pointsInSegment.size(); i++) {
				bool unique = true;
				for(int j = 0; j < uniquePoints.size(); j++) {
					if(pointsInSegment[i] == uniquePoints[j]) {
						unique = false;
						break;
					}
				}
				if(unique) {
					uniquePoints.push_back(pointsInSegment[i]);
				}
			}
			if (uniquePoints.size() == 1) {
				Point* pointPtr = new Point(uniquePoints[0]);
				Intersection pointIntersect;
				pointIntersect.type = POINT;
				pointIntersect.object = (void*)pointPtr;
				return pointIntersect;
			} else if (uniquePoints.size() == 2) {
				Line* linePtr = new Line(uniquePoints[0], uniquePoints[1]);
				Intersection lineIntersect;
				lineIntersect.type = LINE;
				lineIntersect.object = (void*)linePtr;
				return lineIntersect;
			}
		}
		return none;
	}

	/**
	 * Returns a point at an intermediate position of the line segment.
	 * @param fraction A decimal value that corresponds to the location of the interpolation, where zero yields the starting point and one yields the ending point. This value does not necessarily have to be between zero and one.
	 */
	Point GetInterpolation(long double fraction) {
		Point vec = end - start;
		vec.Scale(fraction);
		vec.Add(start);
		return vec;
	}
};

/**
 * Planes are infinitely large flat surfaces that are represented by a center position and a normal vector.
 */
class Plane {
	public:
		//! Center point or intersecting point of the plane.
		Point center;

		//! Normal vector to the plane.
		Point normal;

	/**
	 * Constructs a plane from three points that represent two vectors CA and CB that lie on the plane.
	 * @param c Starting point C of both vectors and intersection point of the plane.
	 * @param a Ending point A of the vector CA.
	 * @param b Ending point B of the vector CB.
	 */
	Plane(Point c, Point a, Point b) : center(c), normal((a - c).CrossProduct(b - c)) {}

	/**
	 * Constructs a plane from an intersecting point and a normal vector to the plane.
	 * @param c Center point C that intersects the plane.
	 * @param n Normal vector to the plane.
	 */
	Plane(Point c, Point n) : center(c), normal(n) {}

	/**
	 * Returns true if the input point lies on the plane.
	 * @param p The point that is checked.
	 */
	bool ContainsPoint(Point p) {
		return abs(normal.DotProduct(p - center)) <= EPS;
	}

	/**
	 * Returns true if the input line lies on the plane.
	 * @param l The line that is checked.
	 */
	bool ContainsLine(Line l) {
		return ContainsPoint(l.start) && ContainsPoint(l.end);
	}

	/**
	 * Returns true if the input line is parallel to the plane.
	 * @param l The line that is checked.
	 */
	bool IsParallel(Line l) {
		return abs(normal.DotProduct(l.end - l.start)) <= EPS;
	}

	/**
	 * Returns true if the input plane is parallel to the current plane.
	 * @param p The plane that is checked.
	 */
	bool IsParallel(Plane p) {
		Point unitNormal(normal);
		Point otherNormal(p.normal);
		unitNormal.Normalize();
		otherNormal.Normalize();
		return (unitNormal == otherNormal) || (unitNormal == (otherNormal * -1));
	}

	/**
	 * Returns true if the input line is perpendicular to the plane.
	 * @param l The line that is checked.
	 */
	bool IsPerpendicular(Line l) {
		Point unitNormal(normal);
		Point lineNormal = l.end - l.start;
		unitNormal.Normalize();
		lineNormal.Normalize();
		return (unitNormal == lineNormal) || (unitNormal == (lineNormal * -1));
	}

	/**
	 * Retuns true if the input plane is perpendicular to the current plane.
	 * @param p The plane that is checked.
	 */
	bool IsPerpendicular(Plane p) {
		return abs(normal.DotProduct(p.normal)) <= EPS;
	}

	/**
	 * Checks for intersections between the plane and an input line and returns an intersection object.
	 * @param l The line that the plane may intersect with.
	 * @return An intersection object of type line if the input line lies on the plane, of type point if the line goes through the plane at a point or of type none if no intersection was found.
	 */
	Intersection GetIntersection(Line l) {
		Intersection none;
		none.type = NONE;
		if(IsParallel(l)) {
			if(ContainsLine(l)) {
				Line* linePtr = new Line(l.start, l.end);
				Intersection lineIntersect;
				lineIntersect.type = LINE;
				lineIntersect.object = (void*)linePtr;
				return lineIntersect;
			} else {
				return none;
			}
		} else {
			long double distance = (center - l.start).DotProduct(normal) / (l.end - l.start).DotProduct(normal);
			Point* pointPtr = new Point(l.GetInterpolation(distance));
			Intersection pointIntersect;
			pointIntersect.type = POINT;
			pointIntersect.object = (void*)pointPtr;
			return pointIntersect;
		}
	}

	/**
	 * Checks for intersections between the current plane and another input plane and returns an intersection object.
	 * @param p The plane that the current plane may intersect with.
	 * @return An intersection object of type plane if both planes are the same, of type line if they intersect at a line or of type none if no intersection was found.
	 */
	Intersection GetIntersection(Plane p) {
		Intersection none;
		none.type = NONE;
		if(IsParallel(p)) {
			if(ContainsPoint(p.center)) {
				Plane* planePtr = new Plane(center, normal);
				Intersection planeIntersect;
				planeIntersect.type = PLANE;
				planeIntersect.object = (void*)planePtr;
				return planeIntersect;
			} else {
				return none;
			}
		} else {
			Point lineVec = normal.CrossProduct(p.normal);
			//Solve system of equations with infinite solutions for one solution
			Matrix coefficients(2, normal.GetRank());
			//Store indices of remaining columns
			vector<long double> columnIndices;
			Point YVec(normal.DotProduct(center), p.normal.DotProduct(p.center));
			for(int x = 0; x < coefficients.GetColumns(); x++) {
				coefficients.Set(0, x, normal.Get(x));
				coefficients.Set(1, x, p.normal.Get(x));
				columnIndices.push_back(x);
			}
			//Remove columns of zeroes
			for(int x = coefficients.GetColumns() - 1; x >= 0; x--) {
				if(coefficients.Get(0, x) == 0 && coefficients.Get(1, x) == 0) {
					coefficients.DeleteColumn(x);
					columnIndices.erase(columnIndices.begin() + x);
				}
			}
			//Remove excess columns with the same coefficients
			for(int x = coefficients.GetColumns() - 1; x >= 0; x--) {
				if(coefficients.Get(0, x) == coefficients.Get(1, x) && coefficients.GetColumns() > 2) {
					coefficients.DeleteColumn(x);
					columnIndices.erase(columnIndices.begin() + x);
				}
			}
			//Remove excess columns
			while(coefficients.GetColumns() > 2) {
				coefficients.DeleteColumn(coefficients.GetColumns() - 1);
				columnIndices.pop_back();
			}
			SLESolution XVec = coefficients.SolveEquations(YVec);
			if(XVec.numSolutions == ONE) {
				Point lineStart = Zero(normal.GetRank());
				for(int x = 0; x < XVec.solutionVector.size(); x++) {
					lineStart.Set(columnIndices[x], XVec.solutionVector[x]);
				}
				Line* linePtr = new Line(lineStart, lineStart + lineVec);
				Intersection lineIntersect;
				lineIntersect.type = LINE;
				lineIntersect.object = (void*)linePtr;
				return lineIntersect;
			}
			return none;
		}
	}

	/**
	 * Returns the point on the plane closest to another point in space given by the input.
	 * @param p The input point.
	 */
	Point GetNearestPoint(Point p) {
		Intersection intersect = GetIntersection(Line(p, p + normal));
		if(intersect.type == POINT) {
			return *(Point*)intersect.object;
		} else {
			cerr << "Error finding nearest point to plane" << endl;
			return p;
		}
	}
};

/**
 * NSpheres are regions or spaces bounded by all points that are a certain radius away from a center point. This means that the NSphere is capable of representing circles, spheres and higher dimensional objects such as hyperspheres. The rank of the NSphere is determined by the rank of the center point.
 */
class NSphere {
	public:
		//! Center point of the NSphere.
		Point center;

		//! Radius of the NSphere, which represents the distance between the center point and all boundary points.
		long double radius;

	/**
	 * Constructs an NSphere from a center point object and a given radius.
	 * @param c The center point, whose rank determines the rank of the NSphere.
	 * @param r The radius of the NSphere.
	 */
	NSphere(Point c, long double r) : center(c) {
		radius = r;
	}

	/**
	 * Constructs a two dimensional NSphere or a circle given the coordinates of the center and the radius.
	 * @param x The X coordinate of the center of the circle.
	 * @param y The Y coordinate of the center of the circle.
	 * @param r The radius of the circle.
	 */
	NSphere(long double x, long double y, long double r) : center(x, y) {
		radius = r;
	}

	/**
	 * Constructs a three dimensional NSphere or a sphere given the coordinates of the center and the radius.
	 * @param x The X coordinate of the center of the sphere.
	 * @param y The Y coordinate of the center of the sphere.
	 * @param z The Z coordinate of the center of the sphere.
	 * @param r The radius of the sphere.
	 */
	NSphere(long double x, long double y, long double z, long double r) : center(x, y, z) {
		radius = r;
	}

	/**
	 * Returns true if the input point is within or on the surface of the NSphere.
	 * @param p The point that is checked.
	 */
	bool ContainsPoint(Point p) {
		Point rp = p - center;
		return rp.SqrMagnitude() - radius * radius <= EPS;
	}

	/**
	 * Returns true if the input point is on the surface of the NSphere.
	 * @param p The point that is checked.
	 */
	bool PointOnBorder(Point p) {
		Point rp = p - center;
		return abs(rp.SqrMagnitude() - radius * radius) <= EPS;
	}

	/**
	 * Returns true if the volume of the input NSphere intersects with the current NSphere.
	 * @param s The NSphere that is checked.
	 */
	bool Intersects(NSphere s) {
		Point rr = s.center - center;
		return rr.Magnitude() - radius - s.radius <= EPS;
	}

	/**
	 * Returns true if the volume of the input NSphere is fully contained by the current NSphere.
	 * @param s The NSphere that is checked.
	 */
	bool FullyContains(NSphere s) {
		Point rr = s.center - center;
		return rr.Magnitude() + s.radius - radius <= EPS;
	}

	/**
	 * Returns the surface area of the NSphere.
	 */
	long double GetSurfaceArea() {
		long double rank = center.GetRank();
		return 2 * pow(PI, rank / 2.0) * pow(radius, rank - 1) / tgamma(rank / 2.0);
	}

	/**
	 * Returns the volume of the NSphere.
	 */
	long double GetVolume() {
		long double rank = center.GetRank();
		return pow(PI, rank / 2.0) * pow(radius, rank) / tgamma(rank / 2.0 + 1);
	}

	/**
	 * Returns the point on the surface of the NSphere closest to another point in space given by the input.
	 * @param p The input point.
	 */
	Point GetNearestPointOnSurface(Point p) {
		Point vec = p - center;
		vec.Normalize();
		vec.Scale(radius);
		vec.Add(center);
		return vec;
	}
};

/**
 * Polygons are used to represent two dimensional shapes bounded by a set of points. The vertices should be ordered in a counter clockwise direction, otherwise the class may not work properly.
 */
class Polygon {
	public:
		//! The vertices of the polygon
		vector<Point> vertices;

	/**
	 * Constructs a polygon from a vector or array of Point objects
	 * @param points A C++ vector of point objects.
	 */
	Polygon(vector<Point> points) {
		vertices = points;
	}

	/**
	 * Returns the area bounded by the polygon.
	 */
	long double GetArea() {
		long double area = 0;
		for(int i = 0; i < vertices.size(); i++) {
			area += vertices[i].GetX() * vertices[(i + 1) % vertices.size()].GetY() - vertices[(i + 1) % vertices.size()].GetX() * vertices[i].GetY();
		}
		return abs(area) / 2;
	}

	/**
	 * Returns the perimeter of the bounds of the polygon.
	 */
	long double GetPerimeter() {
		long double perimeter = 0;
		for(int i = 0; i < vertices.size(); i++) {
			perimeter += GetEdge(i).GetLength();
		}
		return perimeter;
	}

	/**
	 * Returns true if the polygon is a convex shape.
	 */
	bool IsConvex() {
		RemoveDuplicates();
		bool directionSet = false;
		bool direction = false;
		for(int i = 0; i < vertices.size(); i++) {
			Point v1 = vertices[i];
			Point v2 = vertices[(i + 1) % vertices.size()];
			Point v3 = vertices[(i + 2) % vertices.size()];
			if(abs(Angle(v1, v2, v3) - PI) < EPS) {
				continue;
			}
			if(!directionSet) {
				directionSet = true;
				direction = CCW(v1, v2, v3);
			} else {
				if(CCW(v1, v2, v3) != direction) {
					return false;
				}
			}
		}
		return true;
	}

	/**
	 * Returns true if the input point is contained within the polygon or on the border of the polygon.
	 * @param p The point that is checked.
	 */
	bool ContainsPoint(Point p) {
		if(PointOnBorder(p)) {
			return true;
		}
		long double angleSum = 0;
		for(int i = 0; i < vertices.size(); i++) {
			Point v1 = vertices[i];
			Point v2 = vertices[(i + 1) % vertices.size()];
			if(CCW(v1, p, v2)) {
				angleSum += Angle(v1, p, v2);
			} else {
				angleSum -= Angle(v1, p, v2);
			}
		}
		return abs(abs(angleSum) - 2 * PI) < EPS;
	}

	/**
	 * Returns true if the input point is on the border of the polygon.
	 * @param p The point that is checked.
	 */
	bool PointOnBorder(Point p) {
		for(int i = 0; i < vertices.size(); i++) {
			if(GetEdge(i).IsInSegment(p)) {
				return true;
			}
		}
		return false;
	}

	/**
	 * Removes duplicate points from the polygon, those of which may cause certain functions to fail.
	 */
	void RemoveDuplicates() {
		for(int i = vertices.size() - 1; i >= 0; i--) {
			if(vertices[i] == vertices[(i + 1) % vertices.size()]) {
				vertices.erase(vertices.begin() + i);
			}
		}
	}

	/**
	 * Returns a line segment which represents one of the edges of the polygon.
	 * @param index The index of the edge the function should return.
	 */
	Line GetEdge(int index) {
		Point v1(vertices[index % vertices.size()]);
		Point v2(vertices[(index + 1) % vertices.size()]);
		Line edge(v1, v2);
		return edge;
	}
};

/**
 * Triangles are subclasses of polygons that only contain three points.
 */
class Triangle : public Polygon {
	public:

	/**
	 * Constructs a triangle from three points.
	 * @param a The first point of the triangle.
	 * @param b The second point of the triangle.
	 * @param c The third point of the triangle.
	 */
	Triangle(Point a, Point b, Point c) : Polygon({a, b, c}) {}

	/**
	 * Returns true if the triangle has a right or 90° angle.
	 */
	bool HasRightAngle() {
		Line l1 = GetEdge(0);
		Line l2 = GetEdge(1);
		Line l3 = GetEdge(2);
		return l1.IsPerpendicular(l2) || l1.IsPerpendicular(l3) || l2.IsPerpendicular(l3);
	}

	/**
	 * Returns a value which indicates the number of sides that have equal length.
	 */
	int GetEqualSides() {
		Line l1 = GetEdge(0);
		Line l2 = GetEdge(1);
		Line l3 = GetEdge(2);
		int equalSides = 0;
		if(abs(l1.GetLength() - l2.GetLength()) < EPS) {
			equalSides++;
		};
		if(abs(l1.GetLength() - l3.GetLength()) < EPS) {
			equalSides++;
		};
		if(abs(l2.GetLength() - l3.GetLength()) < EPS) {
			equalSides++;
		};
		return equalSides;
	}

	/**
	 * Returns the smallest circle that fully contains the triangle.
	 */
	NSphere GetCircumcircle() {
		Point midpointA = GetEdge(0).GetInterpolation(0.5);
		Point midpointB = GetEdge(1).GetInterpolation(0.5);
		Point perpA = GetEdge(0).GetVector();
		Point perpB = GetEdge(1).GetVector();
		perpA.Rotate2D(DegToRad(90));
		perpB.Rotate2D(DegToRad(90));
		Line bisectorA(midpointA, midpointA + perpA);
		Line bisectorB(midpointB, midpointB + perpB);
		Intersection intersection = bisectorA.GetIntersection(bisectorB);
		Point center = *(Point*)intersection.object;
		return NSphere(center, (center - vertices[0]).Magnitude());
	}

	/**
	 * Returns the largest circle that is fully contained by the triangle.
	 */
	NSphere GetIncircle() {
		long double a = GetEdge(1).GetLength();
		long double b = GetEdge(2).GetLength();
		long double c = GetEdge(0).GetLength();
		Point midpoint(a * vertices[0].GetX() + b * vertices[1].GetX() + c * vertices[2].GetX(), a * vertices[0].GetY() + b * vertices[1].GetY() + c * vertices[2].GetY());
		midpoint.Scale(1 / (a + b + c));
		long double radius = 2 * GetArea() / GetPerimeter();
		NSphere incircle(midpoint, radius);
		return incircle;
	}
};

/**
 * Quaternions are used to accurately represent rotations in three dimensions.
 */
class Quaternion {
	public:
		//! Real or first component of the quaternion.
		long double real;

		//! X or second component of the quaternion.
		long double x;

		//! Y or third component of the quaternion.
		long double y;

		//! Z or fourth component of the quaternion.
		long double z;

	/**
	 * Constructs a quaternion given its four components.
	 * @param qr The real component of the quaternion.
	 * @param qx The X component of the quaternion.
	 * @param qy The Y component of the quaternion.
	 * @param qz The Z component of the quaternion.
	 */
	Quaternion(long double qr, long double qx, long double qy, long double qz) {
		real = qr;
		x = qx;
		y = qy;
		z = qz;
	}

	/**
	 * Constructs a quaternion from the real component and a three dimensional vector.
	 * @param r The real component of the quaternion.
	 * @param v A three dimensional vector containing the X, Y and Z components.
	 */
	Quaternion(long double r, Point v) {
		real = r;
		x = v.GetX();
		y = v.GetY();
		z = v.GetZ();
	}

	/**
	 * Constructs a copy of another quaternion
	 * @param q The quaternion to copy.
	 */
	Quaternion(const Quaternion &q) {
		real = q.real;
		x = q.x;
		y = q.y;
		z = q.z;
	}

	/**
	 * Returns the real component of the quaternion.
	 */
	long double GetReal() {
		return real;
	}

	/**
	 * Returns a vector or point containing the X, Y and Z components of the quaternion.
	 */
	Point GetImaginary() {
		Point p(x, y, z);
		return p;
	}

	/**
	 * Returns the X component of the quaternion.
	 */
	long double GetX() {
		return x;
	}

	/**
	 * Returns the Y component of the quaternion.
	 */
	long double GetY() {
		return y;
	}

	/**
	 * Returns the Z component of the quaternion.
	 */
	long double GetZ() {
		return z;
	}

	/**
	 * Returns the square of the magnitude of the quaternion.
	 */
	long double SqrMagnitude() {
		return real * real + x * x + y * y + z * z;
	}

	/**
	 * Returns the magnitude of the quaternion.
	 */
	long double Magnitude() {
		return sqrt(SqrMagnitude());
	}

	/**
	 * Normalizes or scales the magnitude of the quaternion to one.
	 */
	void Normalize() {
		double mag = Magnitude();
		if(abs(mag) < EPS) {
			return;
		}
		real /= mag;
		x /= mag;
		y /= mag;
		z /= mag;
	}

	/**
	 * Returns the conjugate of the quaternion, where the imaginary vector is inverted.
	 */
	Quaternion Conjugate() {
		Quaternion conjugate(real, -x, -y, -z);
		return conjugate;
	}

	/**
	 * Inverts the current quaternion.
	 */
	Quaternion Inverse() {
		long double sqr = SqrMagnitude();
		Quaternion inverse(real / sqr, -x / sqr, -y / sqr, -z / sqr);
		return inverse;
	}

	/**
	 * Returns the addition of two quaternions.
	 * @param q The quaternion to add to the current quaternion.
	 */
	Quaternion operator + (Quaternion q) const {
		Quaternion addition(real + q.real, x + q.x, y + q.y, z + q.z);
		return addition;
	}

	/**
	 * Returns the subtraction of two quaternions.
	 * @param q The quaternion to subtract from the current quaternion.
	 */
	Quaternion operator - (Quaternion q) const {
		Quaternion subtraction(real - q.real, x - q.x, y - q.y, z - q.z);
		return subtraction;
	}

	/**
	 * Returns the product of two quaternions.
	 * @param q The quaternion to multiply by the current quaternion.
	 */
	Quaternion operator * (Quaternion q) const {
		Quaternion multiplication(real * q.real - x * q.x - y * q.y - z * q.z, real * q.x + x * q.real + y * q.z - z * q.y, real * q.y - x * q.z + y * q.real + z * q.x, real * q.z + x * q.y - y * q.x + z * q.real);
		return multiplication;
	}

	/**
	 * Returns the division of two quaternions.
	 * @param q The quaternion to divide by the current quaternion.
	 */
	Quaternion operator / (Quaternion q) const {
		Quaternion current(real, x, y, z);
		return current * q.Inverse();
	}

	/**
	 * Checks if two quaternions are equal, taking into account possible precision errors.
	 * @param q The quaternion that is compared to the current quaternion.
	 */
	bool operator == (Quaternion q) const {
		return !(abs(real - q.real) > EPS || abs(x - q.x) > EPS || abs(y - q.y) > EPS || abs(z - q.z) > EPS);
	}
};

int main(){
    long double Ax,Ay,Az;
    long double Bx,By,Bz;
    cin>>Ax>>Ay>>Az>>Bx>>By>>Bz;
    Point A(Ax,Ay,Az);
    Point B(Bx,By,Bz);
    Line diameterLine(A,B);

    Point Center = diameterLine.GetInterpolation(0.5);
    long double radius = (A-Center).Magnitude();
    NSphere sphere(Center, radius);

    Point origin(0,0,0);
    Point P(0,0,0);
    if( !(sphere.ContainsPoint(origin) || sphere.PointOnBorder(origin)) ){
        Point res = sphere.GetNearestPointOnSurface(origin);
        P.SetX(res.GetX());
        P.SetY(res.GetY());
        P.SetZ(res.GetZ());
    }
    cout<<fixed<<setprecision(3)<<P.GetX()<<" "<<P.GetY()<<" "<<P.GetZ()<<endl;
}