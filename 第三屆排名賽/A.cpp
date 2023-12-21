#include <bits/stdc++.h>

using namespace std;

int main(void) {
        //freopen("in.txt", "r", stdin);
        int n, t = 1;
        int prime[1500];
        prime[0] = 2;
        for (int i = 3; true; i++) {
                bool judge = true;
                for (int j = 2; j <= sqrt(i); j++)
                        if (i%j == 0) {
                                judge = false;
                                break;
                        }
                if (judge)
                        prime[t++] = i;
                if (t == 1500)
                    break;
        }

        while (cin >> n) {
                if (n == 0)
                    break;
//                cout <<"sdfsdf" << endl;
                int ans = 0;
                int sum = 0;
                int i = 0;
                int k = 0;

                label:
                while (true){
                        sum += prime[i];
                        if (sum == n) {
                                ans++;
                               break;
                        }
                        if (sum > n)
                                break;
                        i++;
                        if (i == 1500)
                            break;
                }
                if (k <= 1498) {
                        i = k+1;
                        k++;
                        sum = 0;
                        goto label;
                }
                printf("%d\n", ans);
        }
        return 0;
}

