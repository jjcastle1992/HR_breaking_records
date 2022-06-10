#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'breakingRecords' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY scores as parameter.
 */

vector<int> breakingRecords(vector<int> scores) {
    int numberOfGames = 0;
    int firstGameScore = 0;
    int maxScore = 0;
    int minScore = 0;
    int numHighScores = 0;
    int numLowScores = 0;
    vector <int> scoreRecords;

    //Get the first game score to set the baseline.
    firstGameScore = scores[0];

    //Set max and min to the first game score.
    maxScore = firstGameScore;
    minScore = firstGameScore;

    //Iterate through all the scores and compare to max and min scores. If a new record high or low, then increment
    //number of high/low scores.

    for (int i = 1; i < scores.size(); i++ ) {
        int currentScore = scores[i];
        if (currentScore > maxScore) {
            maxScore = currentScore;
            numHighScores++;
        }
        else if (currentScore < minScore) {
            minScore = currentScore;
            numLowScores++;
        }
        else {
            if (currentScore < 0 ) {
                std::cout << "ERROR: SCORE CANNOT BE NEGATIVE!" << std::endl;
            }
        }
    }
    scores.push_back(numHighScores);
    scores.push_back(numLowScores);

    return scoreRecords;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split(rtrim(scores_temp_temp));

    vector<int> scores(n);

    for (int i = 0; i < n; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    vector<int> result = breakingRecords(scores);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
