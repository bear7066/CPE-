#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> input, predict;   //輸入資料與預測結果
    int ans[5], buffer;                     //答案與暫存值

    //循環T次
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        input.clear();
        for(int i = 0; i < 10; i++) {
            cin >> buffer;
            input.insert(buffer);            
        }

        cout << "Case " << t << ":";

        bool find = false;

        multiset<int>::iterator it = input.begin();

        //取最小前兩個
        int first = *(it++);
        int second = *(it++);

        for(; it != input.end(); it++) {
            // input[0] = ans[0] + ans[1]
            // input[1] = ans[0] + ans[2]
            // 因此要找到input[i] = ans[1] + ans[2]，使得 input[0] + input[1] + input[i] = 2 * (ans[0] + ans[1] + ans[2])
            // 若 (input[0] + input[1] + input[i]) % 2 不為0，表示這不是我們要的組合
            // 因為multiset不能用index訪問 因此使用iterator
            if((first + second + *it) % 2)
                continue;

            //若符合條件，則可以算出預測的前三個ans
            int buffer = (first + second + *it) / 2;    //buffer = (ans[0] + ans[1] + ans[2])
            //相減得到前三個
            ans[0] = buffer - *it;   
            ans[1] = buffer - second;
            ans[2] = buffer - first;

            //第三大 + 最大 = input[8]，因此可以計算出ans[4]
            ans[4] = *(--input.rbegin()) - ans[2];

            //同理推論ans[3]
            ans[3] = *input.rbegin() - ans[4];

            //最後測試所有組合是否符合測資
            predict.clear();
            for(int i = 0; i < 4; i++) {
                for(int j = i + 1; j < 5; j++) {
                    predict.insert(ans[i] + ans[j]);
                }
            }
            //若比對與input相同則輸出結果
            if(input == predict) {
                for(int i = 0; i < 5; i++) {
                    cout << " " << ans[i];
                }
                cout << endl;
                find = true;
                break;
            }
        }

        if(!find) {
            cout << "Impossible\n";
        }
    }
}
