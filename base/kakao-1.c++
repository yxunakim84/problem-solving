// #include <string>
// #include <vector>
// #include <map>

// using namespace std;

// map<char, int> term_dict;

// vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
//     vector<int> answer;

//     int today_year, today_month, today_day;
//     sscanf(today.c_str(), "%d.%d.%d", &today_year, &today_month, &today_day);

//     // 타입별 보관기간
//     for(int i = 0; i < terms.size(); i++) {
//       // 'a 6' 분리해주기
//       char type;
//       int month;
//       sscanf(terms[i].c_str(), "%c %d", &type, &month);

//       // dict에 다시 넣어주기
//       term_dict[type] = month;
//     }

//     // privacies 판별
//     for(int i = 0; i < privacies.size(); i++) {
//       int year, month, day;
//       char type;
//       sscanf(privacies[i].c_str(), "%d.%d.%d %c", &year, &month, &day, &type);

//       // 유효기간 계산한 값
//       int term_month = term_dict[type];
//       int ret_year = month + term_month < 12 ? year : year + 1;
//       int ret_month = (month + term_month) % 12;
//       int ret_day = day - 1;
//       if(ret_day == 0) {
//         ret_day = 28;
//         ret_month -= 1;
//       }

//       // 비교
//       if(ret_year > today_year) continue;
//       if(ret_year == today_year && ret_month > today_month) continue;
//       if(ret_month == today_month && ret_day >= today_day) continue;
       
//       answer.push_back(i+1);
//     }



//     return answer;
// }


#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> term_dict;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    int today_year, today_month, today_day;
    sscanf(today.c_str(), "%d.%d.%d", &today_year, &today_month, &today_day);

    int today_days = today_year * 12 * 28 + today_month * 28 + today_day;

    
    // 타입별 보관기간
    for(int i = 0; i < terms.size(); i++) {
      // 'a 6' 분리해주기
      char type;
      int month;
      sscanf(terms[i].c_str(), "%c %d", &type, &month);

      // dict에 다시 넣어주기
      term_dict[type] = month;
    }

    // privacies 판별
    for(int i = 0; i < privacies.size(); i++) {
      int year, month, day;
      char type;
      sscanf(privacies[i].c_str(), "%d.%d.%d %c", &year, &month, &day, &type);

         // 유효기간 계산한 값
        int term_month = term_dict[type];

        // 시작일/만료일을 '총 일수'로 계산
        int start_days  = year * 12 * 28 + month * 28 + day;
        int expire_days = start_days + term_month * 28 - 1; // 전날까지 유효

         // 오늘 기준 만료 여부
        if (expire_days < today_days) {
            answer.push_back(i + 1); // 1-based index
        }
    }
    return answer;
}