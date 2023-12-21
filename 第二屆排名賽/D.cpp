#include <bits/stdc++.h>

using namespace std;

int main(void) {
	double H, M;
	
	char c;
	
	while (cin >> H >> c >> M) {
		if (H == 0)
			break;
			
		if (M == 0) {
			if (H == 12) {
				printf("0.000\n");
			}else {
				int n = 12;
				
				n -= H;
				
				n = 12 - n;
				
				double ansH = 5*n*6;
				
				double tempans = 360 - ansH;
				
				if (tempans < ansH)
					ansH = tempans;
				
				if (ansH < 0)
					ansH *= -1;
				
				printf("%.3lf\n",ansH);
			}
		}else {
			if (H == 12){
				H = 0;
			}
			if (H * 30 > M * 6) {
				double add = 0.5 * M;
				
				double ans = (H * 30 - M * 6) + add;
				
				double temp = 360 - ans;
				
				if (temp < ans)
					ans = temp;
				
				if (ans < 0)
					ans *= -1;
				
				printf("%.3lf\n",ans);
			}else if (H * 30 < M * 6) {
				double add = 0.5 * M;
				
				double ans = (M * 6 - H * 30) - add;
				
				double temp = 360 - ans;
				
				if (temp < ans)
					ans = temp;
				
				if (ans < 0)
					ans *= -1;
				
				printf("%.3lf\n",ans);
			}else if (H * 30 == M * 6) {
				double add = 0.5 * M;
				
				printf("%.3lf\n",add);	
			}
		}
	}
	return 0;	
}
