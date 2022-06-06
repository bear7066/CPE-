include <iostream>
using namespace std;

//比較函數 0: a = b, 1: a < b, 2: a > b
int compare(int a, int b) {
    return a == b ? 0 : (a < b ? 1 : 2);
}

int main() {
    int N, a, b, stat;
    bool ordered;
    cin >> N;

    cout << "Lumberjacks:\n";

    while(N--) {
        //初始化狀態
        ordered = true;
        stat = 0;
        cin >> a;
        for(int i = 1; i < 10; i++) {
            cin >> b;
            if(!ordered) continue;  //若判斷為unordered 將剩餘數字讀完就好
            if(!stat) {
                stat = compare(a, b);   //若 a 與 b 則看下一個比較
            } else if(compare(a, b) != 0 && compare(a, b) != stat) ordered = false;  //判斷有沒有排序
            a = b;  //移動b到a進行下一輪判斷
        }
        //輸出結果
        if(ordered) {
            cout << "Ordered\n";
        } else {
            cout << "Unordered\n";
        }
    }
}
