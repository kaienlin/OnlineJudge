#include <bits/stdc++.h>
#define IOS { ios::sync_with_stdio(false); cin.tie(nullptr); }
#define double long double

using namespace std;

int main()
{
    IOS;
    double x, y, ts, w;
    cin >> x >> y >> ts >> w;

    double R = sqrt(x * x + y * y);
    ts = (ts * 2 * M_PI) / 360;
    w = (w * 2 * M_PI) / 360;
    double ti = atan2(y, x);
    if ( ti < 0 ) ti += 2 * M_PI;
    double delta_t = min(abs(ti - ts), 2 * M_PI - abs(ti - ts));

    double lb = 0, ub = w * R;
    int T = 1000;
    while ( T-- ) {
        double v = (lb + ub) / 2;
        double r = v / w;  // the maximum radius that runner need to escape from sniper
        double dist1 = sqrt(R * R - r * r);  // runner's dist to safe position
        double time_r = dist1 / v;

        double t2 = atan(dist1/r);
        if ( t2 < 0 ) t2 += 2 * M_PI;
        double time_s = (delta_t + t2) / w;
        if ( time_r <= time_s )
            ub = v;
        else
            lb = v;
    }
    cout << setprecision(8) << fixed << lb << '\n';
    return 0;
}
