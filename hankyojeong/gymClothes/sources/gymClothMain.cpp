#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef struct _StudentState {
    int index;
    bool lost;
    bool reserve;
} StudentState;

// Complete the isBalanced function below.
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    StudentState* allStudent = new StudentState[n];
    for (int i = 0; i < n; i++) {
        StudentState student;
        student.index = i;
        student.lost = false;
        student.reserve = false;

        allStudent[i].index = i + 1;
    }

    for (auto iter = lost.begin(); iter != lost.end(); iter++) {
        int lostIndex = *iter;
        allStudent[lostIndex - 1].lost = true;
        // cout << *iter << endl;
    }

    for (auto iter = reserve.begin(); iter != reserve.end(); iter++) {
        int reserveIndex = *iter;
        allStudent[reserveIndex - 1].reserve = true;
        // cout << *iter << endl;
    }

    for (int i = 0; i < n; i++) {
        StudentState student = allStudent[i];
        if (student.lost) {
            if (student.reserve) {
                cout << i << "to" << i << endl;
                student.reserve = false;
                student.lost = false;

                continue;
            }
            
            int beforeIndex = i - 1;
            if (beforeIndex >= 0) {
                if (allStudent[beforeIndex].reserve) {
                    cout << beforeIndex << "to" << i << endl;

                    allStudent[beforeIndex].reserve = false;
                    allStudent[i].lost = false;

                    continue;
                }
            }

            int afterIndex = i + 1;
            if (afterIndex < n) {
                if (allStudent[afterIndex].reserve) {
                    cout << afterIndex << "to" << i << endl;

                    allStudent[afterIndex].reserve = false;
                    allStudent[i].lost = false;

                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        StudentState student = allStudent[i];
        if (!student.lost) {
            cout << i << ", ";
            cout << endl;
            answer++;
        }
    }

    return answer;
}

int main()
{
    int n = 3;
    // 기본값(0)으로 초기화 된 5개의 원소를 가지느vector v를 생성
    vector<int> lostStudent;
    vector<int> reserveStudent;

    lostStudent.push_back(3);
    // lostStudent.push_back(4);

    // reserveStudent.push_back(1);
    reserveStudent.push_back(1);
    // reserveStudent.push_back(5);

    int maxStudent = solution(n, lostStudent, reserveStudent);

    cout << "Max Student: " << maxStudent << endl;

    return 0;
}