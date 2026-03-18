// #include <iostream>
// #include <string>

// using namespace std;

// int main() {
//     string s;
//     // Nhập xâu từ bàn phím
//     cin >> s;

//     // Bước 1: Đếm xem có bao nhiêu số để in ra dòng đầu tiên (số n)
//     int n = 0;
//     bool dangTrongSo = false;
//     for (int i = 0; i < s.length(); i++) {
//         if (s[i] >= '0' && s[i] <= '9') {
//             if (dangTrongSo == false) {
//                 n++;
//                 dangTrongSo = true;
//             }
//         } else {
//             dangTrongSo = false;
//         }
//     }
//     cout << n << endl;

//     // Bước 2: Tách và in từng số
//     string soTam = "";
//     for (int i = 0; i < s.length(); i++) {
//         // Kiểm tra xem ký tự tại i có phải là số không
//         if (s[i] >= '0' && s[i] <= '9') {
//             soTam += s[i]; // Gom các chữ số lại
//         } else {
//             // Nếu gặp chữ cái mà trước đó có gom được số
//             if (soTam != "") {
//                 // Chuyển chuỗi thành số rồi in để mất số 0 ở đầu (ví dụ "04" thành 4)
//                 // Cách thủ công: dùng long long để đề phòng số lớn
//                 long long ketQua = stoll(soTam); 
//                 cout << ketQua << endl;
//                 soTam = ""; // Xóa đi để chờ gom số tiếp theo
//             }
//         }
//     }

//     // Kiểm tra lần cuối nếu chuỗi kết thúc bằng số
//     if (soTam != "") {
//         cout << stoi(soTam) << endl;
//     }

//     return 0;
// }




#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    // input to the vector
    stringstream ss(s);
    string word;
    vector<string> words;
    while (ss >> word) {
        words.push_back(word);
    }

    //create new string and loop through the vector and add space between the words
    string res = "";
    for (int i = 0; i < words.size(); i++) {
        res += words[i];
        if (i != words.size() - 1) res += " ";
    }

    //lower 
    bool check = true;
    for (int i = 0; i < res.size(); i++) {
        if (isalpha(res[i])) {
            if (check) {
                res[i] = toupper(res[i]);
                check = false;
            } else {
                res[i] = tolower(res[i]);
            }
        } else if (res[i] == '.') {
            check = true; 
        }
    }

    cout << res << endl;
    return 0;
}