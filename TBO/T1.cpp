#include <iostream>
#include <string.h>

/**
 * Dejan Sandria S
 * 0617104029
 */

using namespace std;

string string_input = "";
string nt[3] = {"a", "0", "1"};

void check(string input, int length_input)
{
    int length = 0;
    bool matched = false;
    for (int i = 1; i <= length_input; i++) {
        string result = "";
        for(int j = 0; j < 3; j++) {
            if (i == 1) {
                result += nt[j];
                if (input == result)
                {
                    matched = true;
                    break;
                }
            } else {
                for (int k = 0; k < i; k++) {
                    result += nt[j];
                    if (input == result)
                    {
                        matched = true;
                        break;
                    }
                }
            }
            
        }

        if (i == length_input) break;
        // cout << result << endl;
    }

    if (matched) cout << "String termasuk dalam tata bahasa reguler" << endl;
    else cout << "String tidak termasuk dalam tata bahasa reguler" << endl;
}

int main()
{
    cout << "Input string : "; cin >> string_input;
    check(string_input, string_input.length());
    system("PAUSE");
    return 0;
}