#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int i = 1; i <= yellow; i++) {
        int last = yellow % i;
        if (last == 0) {
            int share = yellow / i;

            int n = ( share + 2 ) * ( i + 2 );
            if (n == (brown + yellow)) {
                int width = share + 2;
                int height = i + 2;
                cout << width << " : " << height <<endl;
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }

    return answer;
}

int main()
{
    cout << "============" << endl;
    solution(10, 2);
    cout << "============" << endl;
    solution(8, 1);
    cout << "============" << endl;
    solution(24, 24);

    return 0;
}