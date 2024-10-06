#include <iostream>
using namespace std;

void truthTable() {
    bool p, q, r;

    cout << "p\tq\tr\tq ~ r\tp -> (q ~ r)" << endl;
    cout << "-----------------------------------" << endl;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                p = i;  
                q = j;
                r = k;  

                bool not_r = !r;            
                bool q_and_not_r = q && not_r; 
                bool result = !p || q_and_not_r; 

                cout << p << "\t" << q << "\t" << r << "\t" << q_and_not_r << "\t" << result << endl;
            }
        }
    }
}

int main() {
    truthTable();
    return 0;
}
