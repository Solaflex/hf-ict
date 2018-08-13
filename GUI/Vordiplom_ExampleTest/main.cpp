#include <iostream>
#include <cctype>
using namespace std;

int main()
{

    string myString = "3j4h5u6n4h65j";

    int Multiplicator = 0;
    for(char c:myString){

        if(isdigit(c)) {
            if(Multiplicator > 0) {
                Multiplicator = Multiplicator * 10 + c;
            } else {
                Multiplicator = (int)c - 48;
            }
        } else {
            for(int i = 0; i < Multiplicator; i++) {
                cout << c;
            }
            cout << endl;
            Multiplicator = 0;
        }
    }

    return 0;
}
