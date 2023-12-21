#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;
bool IsQue, IsSta, IsPQ;
int data[maxn][2], n;

void Que() {
        int arr[maxn];
        int S = 0, E = 0;
        memset(arr, -1, sizeof(arr));
        for (int i = 0; i < n; i++) {
                if (data[i][0] == 1) {
                        arr[E++] = data[i][1];
                } else if (data[i][0] == 2) {
                        int H = S;
                        while (arr[H]==0)
                                H++;
                        if (H >= n) {
                                IsQue = false;
                                return;
                        }
                        if (data[i][1] != arr[H]) {
                                IsQue = false;
                                return;
                        }
                        arr[H] = 0;
                }
        }
}

void Sta() {
        int arr[maxn];
        int S = 0, E = 0;
        memset(arr, -1, sizeof(arr));
        for (int i = 0; i < n; i++) {
                if (data[i][0] == 1) {
                        arr[E++] = data[i][1];
                } else if (data[i][0] == 2) {
                        int T = E-1;
                        while (arr[T]==0)
                                T--;
                        if (T < 0) {
                                IsSta = false;
                                return;
                        }
                        if (data[i][1] != arr[T]) {
                                IsSta = false;
                                return;
                        }
                        arr[T] = 0;
                }
        }
}

void PQ() {
        int arr[maxn];
        int S = 0, E = 0;
        memset(arr, -1, sizeof(arr));
        for (int i = 0; i < n; i++) {
                if (data[i][0] == 1) {
                        arr[E++] = data[i][1];
                } else if (data[i][0] == 2) {
                        int M = 0, Pr = 0;
                        for (int j = 0; j < E; j++) {
                                if (arr[j] > M) {
                                        Pr = j;
                                        M = arr[j];
                                }
                        }
                        if (M == 0) {
                                IsPQ = false;
                                return;
                        }
                        if (M != data[i][1]) {
                                IsPQ = false;
                                return;
                        }
                        arr[Pr] = 0;
                }
        }
}

int main(void) {
        while (~scanf("%d", &n)) {
                memset(data, -1, sizeof(data));
                for (int i = 0; i < n; i++)
                        scanf("%d %d", &data[i][0], &data[i][1]);
                IsQue = true;
                IsSta = true;
                IsPQ  = true;
                PQ();
                Que();
                Sta();
                int cnt = 0;
                if (IsQue)
                    cnt++;
                if (IsPQ)
                    cnt++;
                if (IsSta)
                    cnt++;
                if (cnt >= 2)
                        printf("not sure\n");
                else if (cnt == 0)
                        printf("impossible\n");
                else if (cnt == 1)
                        if (IsQue)
                            printf("queue\n");
                        else if (IsSta)
                            printf("stack\n");
                        else if (IsPQ)
                            printf("priority queue\n");

        }
        return 0;
}
