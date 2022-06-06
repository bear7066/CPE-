#include <iostream>
#include <vector>
using namespace std;

typedef struct Point {
    int x, y, z;
    int operator-(const Point &point) const {   //計算兩個Point的距離
        return abs(x - point.x) + abs(y - point.y) + abs(z - point.z);
    }
} Point;

vector<Point> points;
vector<bool> visited;
vector<int> selected;

void dfs(int idx) {
    visited[idx] = true;    //標記為找過
    selected.push_back(idx);
    for(int i = 0; i < points.size(); i++) {
        if(visited[i]) continue;
        if(points[idx] - points[i] == 2) {
            dfs(i);
        }
    }
}

bool check() {
    bool x, y, z;   //紀錄是否觸碰到三個邊
    x = y = z = false;

    for(int id : selected) {
        //紀錄有碰到哪一邊
        if(points[id].x == 0) x = true;
        if(points[id].y == 0) y = true;
        if(points[id].z == 0) z = true;
    }

    return x && y && z;
}

int main() {
    int n, m, x, y, z;
    while(cin >> n >> m) {
        if(!(n || m)) break;
        
        //輸入資料
        points.clear();
        visited = vector<bool>(m, false);
        for(int i = 0; i < m; i++) {
            cin >> x >> y >> z;
            points.push_back({x, y, z});
        }

        bool win = false;
        for(int i = 0; i < m; i++) {
            if(visited[i]) continue;   //若找過就跳過
            selected.clear();   //清空選取紀錄
            dfs(i);             //搜尋
            if(check()) {       //檢查是否勝利
                win = true;
                break;
            }
        }
        
        if(win) {
            cout << "Benny\n";
        } else {
            cout << "Willy\n";
        }
    }
}
