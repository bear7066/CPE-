#include <iostream>
#include <cstring>
using namespace std;

int graph[10][10];          //連接圖
int inNum[10], outNum[10];  //連接組合的in跟out計數
bool need[10];              //額外需要印出的數字
string ans;

void DFS(int prev) {
    cout << prev;   //印出前一個數字

    //尋找下一個
    for(int i = 0; i < 10; i++) {
        if(graph[prev][i]) {    //若該數字有組合就選擇其作為下一個數字
            outNum[prev]--;
            inNum[i]--;
            graph[prev][i]--;
            DFS(i);
            return;
        }
    }
}

int main() {
    int m, n, i, j;
    while(cin >> m >> n) {
        //初始化變數
        memset(graph, 0, sizeof(graph));
        memset(need, 0, sizeof(need));
        memset(inNum, 0, sizeof(inNum));
        memset(outNum, 0, sizeof(outNum));
        ans = "";

        //建立graph
        for(; m <= n; m++) {
            if(m >= 10) {
                graph[m / 10][m % 10]++;
                outNum[m / 10]++;
                inNum[m % 10]++;
                need[m / 10] = need[m % 10] = false;    //一定會印到數字，因此不須額外列印
            } else {
                need[m] = true;                         //1~10不在graph中，需要額外列印
            }
        }

        while(true) {
            int start = -1;
            //以連接輸出數字大於輸入數字的優先選擇，以此做為開頭
            for(i = 0; i < 10; i++) {
                if(outNum[i] > inNum[i]) {
                    start = i;
                    break;
                }
            }
            //若都相同，則從最小的開始找一組可以開始的作為開頭
            if(start == -1) {
                for(i = 0; i < 10; i++) {
                    if(inNum[i] || outNum[i]) {
                        start = i;
                        break;
                    }
                }
            }
            
            if(start == -1) break;
            DFS(start);     //搜尋字串
        }
        //將剩餘數字印出
        for(int i = 0; i < 10; i++) {
            if(need[i]) cout << i;
        }
        cout << endl;
    }
}
