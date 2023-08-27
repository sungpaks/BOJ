#include <iostream>
#include <cmath>

using namespace std;

long double getDist(long double x1, long double y1, long double z1, long double x2, long double y2, long double z2){
	return abs(sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1)));
}

int main () {
	long double ax, ay, az, bx, by, bz, cx, cy, cz;
	cin >> ax >> ay >> az >> bx >> by >> bz >> cx >> cy >> cz;
	//long double x=(ax+bx)/2, y=(ay+by)/2, z=(az+bz)/2;
	long double ad = getDist(ax,ay,az,cx,cy,cz), bd = getDist(bx,by,bz,cx,cy,cz);
	long double minD = min(ad, bd);
	while (1) {
		long double mx = (ax+bx)/2, my = (ay+by)/2, mz = (az+bz)/2;
		long double md = getDist(mx,my,mz,cx,cy,cz);
		if (abs(minD-md) < 1e-6) break;
		minD = md;
		if (ad < bd) {
			bx = mx; by = my; bz = mz;
			bd = md;
		}
		else {
			ax = mx; ay = my; az = mz;
			ad = md;
		}
	}
	printf("%.10Lf", minD);
}
// 직선의방정식 ax+by+cz+k=0 에서 x1,y1,z1까지의 거리 d
// d = (ax1 + by1 + cz1 + k)/sqrt(a^2+b^2+c^2)