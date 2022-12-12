#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

regex regularGame("(\\d+)");
cmatch res;

const int countColor = 5;

class Tube {
public:
    Tube() = default;;

    explicit Tube(int countColor) { this->countColor = countColor; };

    Tube(int countColor, vector<int> color) {
        this->countColor = countColor;
        this->color = std::move(color);
    };

    void transfusion(Tube& out) {
        if ((color.size() < countColor && !out.color.empty())) {
            int topColor = out.color.back();
            do {
                color.push_back(out.color.back());
                out.color.pop_back();
            } while (out.color.back() == topColor && ((color.size() < countColor && !out.color.empty())));
        }
    }

    int& operator[](int index) { return color[index]; }

    ~Tube() = default;;

    friend ostream& operator<<(ostream& os, const Tube& tube);

private:
    vector<int> color;
    int countColor{};
};

ostream& operator<<(ostream& os, const Tube& Tube) {
    cout << "\n|=====\n|";
    for (auto color : Tube.color)
        os << color;
    cout << "\n|=====";
    cout << endl;
    return os;
}

void genarateGame() {
    fstream file;
    file.open("gameSetting.txt", ios_base::in);
    cout << file.is_open() << endl;

    string str = "5 11222 22211 34343 43434 55555 0 0";
    getline(file, str);
    cout << str << endl;

    if (regex_search(str.c_str(), res, regularGame)) {
        for (auto num : res)
            cout << num << endl;
    }

    file.close();
}

int main() {
    //    Test game 12.12.2022
    genarateGame();
    return 0;
}
