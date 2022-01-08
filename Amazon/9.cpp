int isValid(vector<vector<int>> mat) {
    int n = mat.size();
    int sq = sqrt(n);

    int cache1[9][9] = {0};
    int cache2[9][9] = {0};
    int cache3[9][9] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0) {
                int num = mat[i][j] - 1;
                int k = i / sq * sq + j / sq;

                if (cache1[num][i] || cache2[num][j] || cache3[k][num]) {
                    return false;
                }

                cache1[num][i] = 1;
                cache2[num][j] = 1;
                cache3[k][num] = 1;

            }

        }
    }

    return true;
}