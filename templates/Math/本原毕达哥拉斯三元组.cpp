vector<vector<int>> A = {{1, -2, 2},
                         {2, -1, 2},
                         {2, -2, 3}};
vector<vector<int>> B = {{1, 2, 2},
                         {2, 1, 2},
                         {2, 2, 3}};
vector<vector<int>> C = {{-1, 2, 2},
                         {-2, 1, 2},
                         {-2, 2, 3}};
vector<int> O = {3, 4, 5};

int sum(vector<int> &a) {
    return a[0] + a[1] + a[2];
}

vector<int> mul(vector<int> &a, vector<vector<int>> &b) {
    vector<int> tmp(3);
    for (int i = 0; i < 3; i ++ ) {
        for (int j = 0; j < 3; j ++ ) {
            tmp[i] += a[j] * b[i][j];
        }
    }
    return tmp;
}

int maxn = 5e6;
queue<vector<int>> triangles;

void init() {
    triangles.push(O);
    while (!triangles.empty()) {
        vector<int> ori = triangles.front(); triangles.pop();
        vector<int> nxtA = mul(ori, A), nxtB = mul(ori, B), nxtC = mul(ori, C);
        if (sum(nxtA) <= maxn) triangles.push(nxtA);
        if (sum(nxtB) <= maxn) triangles.push(nxtB);
        if (sum(nxtC) <= maxn) triangles.push(nxtC);
    }
}