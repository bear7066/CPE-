#include <iostream>
using namespace std;

int n, members[15];
bool used[15];
int output, limit;

void dfs(int i, int current) {
    if(output < current) {
        output = current;
    }
    if(output == limit) return; //已達最大值，直接輸出結果

    for(; i < n; i++) {                                 //i為第一個選擇的玩家index
        if(used[i]) continue;                           //使用過就忽略
        for(int j = i + 1; j < n; j++) {                //第二個
            if(used[j]) continue;                       //使用過就忽略
            int sum = members[i] + members[j];
            for(int k = j + 1; k < n; k++) {            //第三個
                if(used[k] || sum + members[k] < 20) continue;  //使用過就忽略
                used[i] = used[j] = used[k] = true;     //標記為使用
                dfs(i + 1, current + 1);                //往下尋找
                used[i] = used[j] = used[k] = false;    //取消標記
            }
        }
    }
}

int main() {
    int serial = 1;
    while(cin >> n) {
        if(n == 0)break;

        //初始化變數與輸入資料
        for(int i = 0; i < n; i++) {
            scanf(" %d", &members[i]);
            used[i] = false;
        }
        output = 0;
        limit = n / 3;  //最大組數會是n/3，超過便會停止運算以節省時間

        //計算並輸出
        dfs(0, 0);
        printf("Case %d: %d\n", serial++, output);
    }
}
