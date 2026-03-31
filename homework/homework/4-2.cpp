#include <iostream>
#include <iomanip> // setw를 쓰기 위한 헤더

using namespace std;

int main() {
    // 1. Header (한글 대신 영어로 쓰면 인코딩 오류가 안 납니다)
    cout << setw(10) << "Number" << setw(15) << "Square" << endl;
    cout << "---------------------------" << endl;

    // 2. Loop 1 to 100
    for (int i = 1; i <= 100; i++) {
        cout << setw(10) << i << setw(15) << i * i << endl;
    }

    return 0;
}
