#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
#define ALL(x) x.begin(),x.end()
using namespace std;

typedef long long int Numeric; //Change this datatype for floating point or integers

class Point {
    private:
        void CheckRank(Point p) {
            if(p.rank != rank) {
                cerr << 'Warning: operation of points with ranks ' << rank << ' and ' << p.rank << endl;
                Resize(max(rank, p.rank), 0);
            }
        }

    public:
        vector<Numeric> coordinates;
        int rank;
    
    Point(Numeric x, Numeric y) {
        rank = 2;
        coordinates.push_back(x);
        coordinates.push_back(y);
    }

    Point(Numeric x, Numeric y, Numeric z) {
        rank = 3;
        coordinates.push_back(x);
        coordinates.push_back(y);
        coordinates.push_back(z);
    }

    Point(vector<Numeric> coords) {
        coordinates = coords;
        rank = coordinates.size();
    }

    Point(const Point& p) {
        coordinates = p.coordinates;
        rank = p.rank;
    }

    void Resize(int newRank, int newValue) {
        while(rank > newRank) {
            coordinates.pop_back();
            rank--;
        }
        while(rank < newRank) {
            coordinates.push_back(newValue);
            rank++;
        }
    }

    Point Copy() {
        Point p(0, 0);
        p.coordinates = coordinates;
        p.rank = rank;
        return p;
    }

    Point Zero(int zeroRank) {
        Point p(0, 0);
        p.Resize(zeroRank, 0);
        return p;
    }

    Point Identity(int idRank) {
        Point p(1, 1);
        p.Resize(idRank, 1);
        return p;
    }

    Numeric GetX() {
        return coordinates[0];
    }

    Numeric GetY() {
        return coordinates[1];
    }

    Numeric GetZ() {
        return coordinates[2];
    }

    void SetX(Numeric x) {
        coordinates[0] = x;
    }

    void SetY(Numeric y) {
        coordinates[1] = y;
    }

    void SetZ(Numeric z) {
        coordinates[2] = z;
    }

    Numeric SqrMagnitude() {
        Numeric value = 0;
        for(int i = 0; i < rank; i++) {
            value += coordinates[i] * coordinates[i];
        }
        return value;
    }

    double Magnitude() {
        return sqrt(SqrMagnitude());
    }

    void Add(Point p) {
        CheckRank(p);
        for(int i = 0; i < rank; i++) {
            coordinates[i] += p.coordinates[i];
        }
    }

    void Subtract(Point p) {
        CheckRank(p);
        for(int i = 0; i < rank; i++) {
            coordinates[i] -= p.coordinates[i];
        }
    }

    void Multiply(Point p) {
        CheckRank(p);
        for(int i = 0; i < rank; i++) {
            coordinates[i] *= p.coordinates[i];
        }
    }

    void Divide(Point p) {
        CheckRank(p);
        for(int i = 0; i < rank; i++) {
            coordinates[i] /= p.coordinates[i];
        }
    }

    void Scale(double value) {
        for(int i = 0; i < rank; i++) {
            coordinates[i] *= value;
        }
    }

    void Normalize() {
        Scale(1 / Magnitude());
    }

    void Rotate2D(Point origin, double angle) {
        if(rank != 2) {
            cerr << 'Incorrect rank for 2D rotation.' << endl;
            return;
        }
        SetX(GetX() - origin.GetX());
        SetY(GetY() - origin.GetY());
        double newX = GetX() * cos(angle) - GetY() * sin(angle);
        double newY = GetX() * sin(angle) + GetY() * cos(angle);
        SetX(newX + origin.GetX());
        SetY(newY + origin.GetY());
    }

    Numeric DotProduct(Point p) {
        CheckRank(p);
        Numeric value = 0;
        for(int i = 0; i < rank; i++) {
            value += coordinates[i] * p.coordinates[i];
        }
        return value;
    }

    Point CrossProduct(Point p) {
        if(rank > 3) {
            cerr << 'Incorrect rank for cross product.' << endl;
            return Zero(rank);
        }
        Point a = Copy();
        Point b = p.Copy();
        Point result = Zero(3);
        a.Resize(3, 0);
        b.Resize(3, 0);
        result.SetX(a.GetY() * b.GetZ() - a.GetZ() * b.GetY());
        result.SetY(a.GetZ() * b.GetX() - a.GetX() * b.GetZ());
        result.SetZ(a.GetX() * b.GetY() - a.GetY() * b.GetX());
        return result;
    }

    bool operator == (Point p) const {
        for(int i = 0; i < rank; i++) {
            if(fabs(coordinates[i] - p.coordinates[i]) > EPS) {
                return false;
            }
        }
        return true;
    }

    bool operator < (Point p) const {
        for(int i = 0; i < rank; i++) {
            if(fabs(coordinates[i] - p.coordinates[i]) > EPS) {
                return coordinates[i] < p.coordinates[i];
            }
        }
        return false;
    }
};

Point Vector(Point a, Point b) {
    Point c = a.Copy();
    Point d = b.Copy();
    d.Subtract(c);
    return d;
}

bool CCW(Point a, Point b, Point c) {
    Point ba = Vector(b, a);
    Point bc = Vector(b, c);
    return ba.CrossProduct(bc).GetZ() > -EPS;
}

double Angle(Point a, Point b, Point c) {
    Point ba = Vector(b, a);
    Point bc = Vector(b, c);
    return acos(ba.DotProduct(bc) / (ba.Magnitude() * bc.Magnitude()));
}

class Line {
    public:
        Point start;
        Point end;

    Line(Point s, Point e) : start(s), end(e) {}
    Line(Numeric sx, Numeric sy, Numeric ex, Numeric ey) : start(sx, sy), end(ex, ey) {}
    Line(Numeric sx, Numeric sy, Numeric sz, Numeric ex, Numeric ey, Numeric ez) : start(sx, sy, sz), end(ex, ey, ez) {}

    double GetLength() {
        Point v = Vector(start, end);
        return v.Magnitude();
    }

    Point GetNearestPoint(Point p) {
        Point se = Vector(start, end);
        Point sp = Vector(start, p);
        Point s = start.Copy();
        double n = se.DotProduct(sp) / (se.Magnitude() * se.Magnitude());
        se.Scale(n);
        s.Add(se);
        return s;
    }

    bool IsCollinear(Point p) {
        Point se = Vector(start, end);
        Point sp = Vector(start, p);
        return se.CrossProduct(sp) == se.Zero(3);
    }

    bool IsInSegment(Point p) {
        if(IsCollinear(p)) {
            Point se = Vector(start, end);
            Point sp = Vector(start, p);
            double n = se.DotProduct(sp) / (se.Magnitude() * se.Magnitude());
            if(n >= 0 && n <= 1) {
                return true;
            }
        }
        return false;
    }

    bool IsParallel(Line l) {
        Point se = Vector(start, end);
        Point nw = Vector(l.start, l.end);
        return se.CrossProduct(nw) == se.Zero(3);
    }

    bool IsPerpendicular(Line l) {
        Point se = Vector(start, end);
        Point nw = Vector(l.start, l.end);
        return fabs(se.DotProduct(nw)) < EPS;
    }

    bool HasIntersection(Line l) {
        Point v1 = Vector(start, end);
        Point v2 = Vector(l.start, l.end);
        Point s1 = start;
        Point s2 = l.start;
        if(IsParallel(l)) {
            return false;
        }
        double a, b;
        int rankIndex = 0;
        Numeric v1a, v1b, v2a, v2b, s1a, s1b, s2a, s2b;
        bool found = false;
        for(int i = 0; i < s1.rank; i++) {
            if(found) {
                break;
            }
            for(int j = i + 1; j < s1.rank; j++) {
                v1a = v1.coordinates[i];
                v1b = v1.coordinates[j];
                v2a = v2.coordinates[i];
                v2b = v2.coordinates[j];
                s1a = s1.coordinates[i];
                s1b = s1.coordinates[j];
                s2a = s2.coordinates[i];
                s2b = s2.coordinates[j];
                if(fabs(v2b * v1a - v2a * v1b) > EPS) {
                    break;
                }
            }
        }
        a = (v2a * (s1b - s2b) - v2b * (s1a - s2a)) / (double)(v2b * v1a - v2a * v1b);
        if(fabs(v2a) < EPS) {
            b = (s1b - s2b + a * v1b) / (double)v2b;
        } else {
            b = (s1a - s2a + a * v1a) / (double)v2a;
        }
        for(int i = 0; i < s1.rank; i++) {
            if(fabs(s1.coordinates[i] + a * v1.coordinates[i] - s2.coordinates[i] - b * v2.coordinates[i]) > EPS) {
                return false;
            } 
        }
        return true;
    }

    bool HasIntersectionInSegments(Line l) {
        if(HasIntersection(l)) {
            Point p = GetIntersection(l);
            return IsInSegment(p) && l.IsInSegment(p);
        }
        return false;
    }

    Point GetIntersection(Line l) {
        Point v1 = Vector(start, end);
        Point v2 = Vector(l.start, l.end);
        Point s1 = start.Copy();
        Point s2 = l.start.Copy();
        Numeric v1a, v1b, v2a, v2b, s1a, s1b, s2a, s2b;
        bool found = false;
        for(int i = 0; i < s1.rank; i++) {
            if(found) {
                break;
            }
            for(int j = i + 1; j < s1.rank; j++) {
                v1a = v1.coordinates[i];
                v1b = v1.coordinates[j];
                v2a = v2.coordinates[i];
                v2b = v2.coordinates[j];
                s1a = s1.coordinates[i];
                s1b = s1.coordinates[j];
                s2a = s2.coordinates[i];
                s2b = s2.coordinates[j];
                if(fabs(v2b * v1a - v2a * v1b) > EPS) {
                    break;
                }
            }
        }
        double a = (v2a * (s1b - s2b) - v2b * (s1a - s2a)) / (double)(v2b * v1a - v2a * v1b);
        v1.Scale(a);
        s1.Add(v1);
        return s1;
    }
};

class NSphere {
    public:
        Point center;
        Numeric radius;

    NSphere(Point c, Numeric r) : center(c) {
        radius = r;
    }

    NSphere(Numeric x, Numeric y, Numeric r) : center(x, y) {
        radius = r;
    }

    NSphere(Numeric x, Numeric y, Numeric z, Numeric r) : center(x, y, z) {
        radius = r;
    }

    bool ContainsPoint(Point p) {
        Point rp = Vector(center, p);
        return rp.SqrMagnitude() < radius * radius;
    }

    bool PointOnBorder(Point p) {
        Point rp = Vector(center, p);
        return abs(rp.SqrMagnitude() - radius * radius) <= EPS;
    }

    bool Intersects(NSphere s) {
        Point rr = Vector(center, s.center);
        return rr.Magnitude() < radius + s.radius;
    }
};

class Poly2D {
    public:
        vector<Point> vertices;

    Poly2D(vector<Point> vs) {
        vertices = vs;
    }

    Numeric GetArea() {
        Numeric area = 0;
        for(int i = 0; i < vertices.size(); i++) {
            area += vertices[i].GetX() * vertices[(i + 1) % vertices.size()].GetY() - vertices[(i + 1) % vertices.size()].GetX() * vertices[i].GetY();
        }
        return fabs(area) / 2;
    }

    double GetPerimeter() {
        double perimeter = 0;
        for(int i = 0; i < vertices.size(); i++) {
            Point v1 = vertices[i];
            Point v2 = vertices[(i + 1) % vertices.size()];
            Point edge = Vector(v1, v2);
            perimeter += edge.Magnitude();
        }
        return perimeter;
    }

    bool IsConvex() {
        Point v1 = vertices[0];
        Point v2 = vertices[1];
        Point v3 = vertices[2];
        bool direction = CCW(v1, v2, v3);
        for(int i = 1; i < vertices.size(); i++) {
            v1 = vertices[i];
            v2 = vertices[(i + 1) % vertices.size()];
            v3 = vertices[(i + 2) % vertices.size()];
            if(CCW(v1, v2, v3) != direction) {
                return false;
            }
        }
        return true;
    }

    bool ContainsPoint(Point p) {
        double angleSum = 0;
        for(int i = 0; i < vertices.size(); i++) {
            Point v1 = vertices[i];
            Point v2 = vertices[(i + 1) % vertices.size()];
            if(CCW(v1, p, v2)) {
                angleSum += Angle(v1, p, v2);
            } else {
                angleSum -= Angle(v1, p, v2);
            }
        }
        return fabs(fabs(angleSum) - 2 * PI) < EPS;
    }

    Line GetEdge(int n) {
        Point v1 = vertices[n % vertices.size()];
        Point v2 = vertices[(n + 1) % vertices.size()];
        Line edge(v1, v2);
        return edge;
    }
};



struct point{
    double x,y;
    bool operator < (point other) const { 
        if(x>other.x)
            return x < other.x; 
        else
            return y < other.y; 
    }
};



// Given three colinear points p, q, r, the function checks if 
// point q lies on line segment 'pr' 
bool onSegment(point p, point q, point r) { 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 
  
// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(point p, point q, point r) { 
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
    // for details of below formula. 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
  
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(point p1, point q1, point p2, point q2) { 
    // Find the four orientations needed for general and 
    // special cases 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    // General case 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false; // Doesn't fall in any of the above cases 
} 


point lineLineIntersection(point A, point B, point C, point D) { 
    // Line AB represented as a1x + b1y = c1 
    double a1 = B.y - A.y; 
    double b1 = A.x - B.x; 
    double c1 = a1*(A.x) + b1*(A.y); 
  
    // Line CD represented as a2x + b2y = c2 
    double a2 = D.y - C.y; 
    double b2 = C.x - D.x; 
    double c2 = a2*(C.x)+ b2*(C.y); 
  
    double determinant = a1*b2 - a2*b1; 
  
    if (determinant == 0){ 
        // The lines are parallel. This is simplified 
        // by returning a pair of FLT_MAX 
        point aux1;
        aux1.x = FLT_MAX;
        aux1.y = FLT_MAX;
        return aux1; 
    } 
    else
    { 

        point aux2;
        aux2.x = (b2*c1 - b1*c2)/determinant; 
        aux2.y = (a1*c2 - a2*c1)/determinant; 
        return aux2; 
    } 
} 

double distance(point a, point b){
    return sqrt((a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y));
}

int main(){
sync;

int n; cin>>n; 
int k; cin>>k; 
vector<point> poligono; 
while(n--){
    double a,b; cin>>a>>b;
    point aux; 
    aux.x = a; 
    aux.y = b;
    poligono.pb(aux);
}
poligono.push_back(poligono[0]);


//vector<line> lineas;

vector < pair < pair < double , double > , pair < double , double> > > lineas;

while(k--){
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    point primero, segundo; 
    primero.x = a; 
    primero.y = b; 
    segundo.x = c; 
    segundo.y = d;
/*
    line linea; 
    linea.uno = primero; 
    linea.dos = segundo; 

*/


    

    lineas.pb(mp(mp(a,b),mp(c,d)));
}

double totalLen = 0;

for(int k = 0; k<lineas.size(); k++){

     pair < pair < double , double > , pair < double , double> > primerLinea = lineas[k];

    double lenOfInter = 0;
    vector<point> intersecciones;

    for(int i=0; i<poligono.size(); i++){
        point a;
        point b; 
        a.x = primerLinea.first.first;
        a.y = primerLinea.first.second; 
        b.x = primerLinea.second.first; 
        b.y = primerLinea.second.second;
        if(doIntersect(a,b,poligono[i],poligono[i+1])){
            pair<double,double> toBePoint; 
            intersecciones.pb(lineLineIntersection(a, b, poligono[i], poligono[i+1]));
        }
    }

    double countLengthOfIntersection = 0; 
    for(int i = 0; i<intersecciones.size()-1; i+=2){
        countLengthOfIntersection+=distance(intersecciones[i],intersecciones[i+1]);
    }

    totalLen += countLengthOfIntersection;
}

cout<<totalLen<<endl;

return 0;
}
