#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;

void evaluateTruthValues(bool p, bool q) {
    bool conjunction = p && q;
    bool disjunction = p || q;
    bool exclusive_or = p != q;
    bool implication = !p || q;
    bool equivalence = p == q;

    cout << "p = " << p << ", q = " << q << endl;
    cout << "p AND q: " << conjunction << endl;
    cout << "p OR q: " << disjunction << endl;
    cout << "p XOR q: " << exclusive_or << endl;
    cout << "p -> q: " << implication << endl;
    cout << "p <-> q: " << equivalence << endl;
    cout << endl;
}

bool getConjunction(bool p, bool q) {
    return p && q;
}
bool getDisjunction(bool p, bool q) {
    return p || q;
}
bool getExclusive_or(bool p, bool q) {
    return p != q;
}
bool getImplication(bool p, bool q) {
    return !p || q;
}
bool getEquivalence(bool p, bool q) {
    return p == q;
}


bool convertToBool(string value) {
    if (value == "True" || value == "true" || value == "1") {
        return true;
    }
    else if (value == "False" || value == "false" || value == "0") {
        return false;
    }
    else {
        cout << "Невірне значення! Використовуйте True або False." << endl;
        exit(1);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string p_str, q_str;
    bool p, q;

    cout << "Введіть значення p (True або False): ";
    cin >> p_str;
    cout << "Введіть значення q (True або False): ";
    cin >> q_str;

    p = convertToBool(p_str);
    q = convertToBool(q_str);

    evaluateTruthValues(p, q);

    return 0;
}
