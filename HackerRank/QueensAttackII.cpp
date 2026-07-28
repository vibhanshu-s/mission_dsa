#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;
    const int UP_RIGHT = 4, UP_LEFT = 5, DOWN_RIGHT = 6, DOWN_LEFT = 7;

    vector<int> limit(8);
    limit[UP] = n - r_q;
    limit[DOWN] = r_q - 1;
    limit[LEFT] = c_q - 1;
    limit[RIGHT] = n - c_q;
    limit[UP_RIGHT] = min(n - r_q, n - c_q);
    limit[UP_LEFT] = min(n - r_q, c_q - 1);
    limit[DOWN_RIGHT] = min(r_q - 1, n - c_q);
    limit[DOWN_LEFT] = min(r_q - 1, c_q - 1);

    for (int i = 0; i < (int) obstacles.size(); i++) {
        int dr = obstacles[i][0] - r_q;
        int dc = obstacles[i][1] - c_q;

        if (dc == 0 && dr != 0) {
            if (dr > 0) {
                limit[UP] = min(limit[UP], dr - 1);
            } else {
                limit[DOWN] = min(limit[DOWN], -dr - 1);
            }
        } else if (dr == 0 && dc != 0) {
            if (dc > 0) {
                limit[RIGHT] = min(limit[RIGHT], dc - 1);
            } else {
                limit[LEFT] = min(limit[LEFT], -dc - 1);
            }
        } else if (abs(dr) == abs(dc)) {
            int dist = abs(dr) - 1;
            if (dr > 0 && dc > 0) {
                limit[UP_RIGHT] = min(limit[UP_RIGHT], dist);
            } else if (dr > 0 && dc < 0) {
                limit[UP_LEFT] = min(limit[UP_LEFT], dist);
            } else if (dr < 0 && dc > 0) {
                limit[DOWN_RIGHT] = min(limit[DOWN_RIGHT], dist);
            } else {
                limit[DOWN_LEFT] = min(limit[DOWN_LEFT], dist);
            }
        }
    }

    int total = 0;
    for (int i = 0; i < 8; i++) {
        total += limit[i];
    }

    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
