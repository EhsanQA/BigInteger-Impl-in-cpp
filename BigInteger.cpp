#include <bits/stdc++.h>

using namespace std;

class BigInteger {
    public:
        vector<int> digits;
        string theNum;
    BigInteger(string s) {
        for (int i = s.size() - 1; i > -1; i--) {
            digits.push_back(int(s.at(i)) - '0');
        }
        theNum = s;
    }
    BigInteger() {

    }
    public:
        string sum(string s1, string s2) {
            vector<int> couts;
            couts.push_back(0);
            BigInteger ans;
            BigInteger b1(s1);
            BigInteger b2(s2);
            int i = 0;
            while (true) {
                if (i <= b1.digits.size() - 1 && i <= b2.digits.size() - 1) {
                    int tmp = couts.at(0);
                    ans.digits.push_back((b1.digits.at(i) + b2.digits.at(i) + tmp) % 10);
                    couts.clear();
                    couts.push_back((b1.digits.at(i) + b2.digits.at(i) + tmp - (b1.digits.at(i) + b2.digits.at(i) + tmp) % 10) / 10);
                    // cout << couts.at(0) << "COUTED" << endl;
                    if (i == b1.digits.size() - 1 && i == b2.digits.size() - 1) {
                        ans.digits.push_back(couts.at(0));
                    }
                    i++;
                } else if (i == b1.digits.size()) {
                    for (int j = i; j < b2.digits.size(); j++) {
                        int tmp = couts.at(0);
                        ans.digits.push_back((b2.digits.at(i) + tmp) % 10);
                        couts.clear();
                        couts.push_back((b2.digits.at(i) + tmp - (b2.digits.at(i) + tmp) % 10) / 10);
                    }
                    if (i != b2.digits.size()) {
                        ans.digits.push_back(couts.at(0));
                    }
                    break;
                } else if (i == b2.digits.size()) {
                    for (int j = i; j < b1.digits.size(); j++) {
                        int tmp = couts.at(0);
                        ans.digits.push_back((b1.digits.at(i) + tmp) % 10);
                        couts.clear();
                        couts.push_back((b1.digits.at(i) + tmp - (b1.digits.at(i) + tmp) % 10) / 10);
                    }
                    if (i != b1.digits.size()) {
                        ans.digits.push_back(couts.at(0));
                    }
                    break;
                }
            }
            string s;
            if (ans.digits.at(ans.digits.size() - 1) != 0) {
                s += to_string(ans.digits.at(ans.digits.size() - 1));
            }
            for (int j = ans.digits.size() - 2; j > -1; j--) {
                s += to_string(ans.digits.at(j));
            }
            return s;
        }

};

int main() {
    vector<int> v;
    BigInteger b("567");
    
    cout << b.sum("954", "9089");
    return 0;
}
