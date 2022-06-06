#include <iostream>
using namespace std;

int main() {
    int serial = 1;
    int N, R;
    int C1, C2, P;
    int S, D, T;

    while(cin >> N >> R) {
        if(N == 0 || R == 0) break;

        int graph[101][101] = {0};

        //輸入graph的參數
        for (int i = 0; i < R; ++i)
        {
            cin >> C1 >> C2 >> P;
            graph[C1][C2] = graph[C2][C1] = P;  //無向圖
        }


        //計算所有A點到B點最大乘載量
        for (int k = 1; k <= N; ++k)    //計算N次
        {
            //更新從i到j的最大乘載量
            for (int i = 1; i <= N; ++i)
            {
                for (int j = 1; j <= N; ++j)
                {
                    //若找到一條比直接到達乘載量更大的路徑，更新它
                    graph[i][j] = max(graph[i][j], min(graph[i][k], graph[k][j]));
                }
            }
        }

        cin >> S >> D >> T;

        int max_trans = graph[S][D] - 1;    //從graph獲取最大乘載量，並扣掉導遊
        int output = T / max_trans;         //計算來回次數
        if(T % max_trans > 0) output += 1;  //無條件進位

        cout << "Scenario #" << serial++ << endl;
        cout << "Minimum Number of Trips = " << output << "\n\n";
    }

    return 0;
}
