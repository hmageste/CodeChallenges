#include "pch.h"
#include "framework.h"
#include "CandyCrashSolvers.h"

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void set_begin_end_removal(const vector<pair<char, int>>& vec, vector<pair<char, int>>::iterator& prev_it, vector<pair<char, int>>::iterator& next_it) {
    // check if neighbors can be removed
    if (prev_it != vec.begin()) {
        auto prev_it_2 = prev(prev_it);
        auto next_it_2 = next(next_it);
        if (next_it_2 != vec.end()) {
            if (prev_it_2->first == next_it_2->first && prev_it_2->second + next_it_2->second > 2) {
                --prev_it, ++next_it;
                set_begin_end_removal(vec, prev_it, next_it);
            }
        }
    }
}

LIBCANDYCRASH1D_API string recursive_iterator_approach(const string& input) {
    vector<pair<char, int>> prec_letters;
    for (const auto& c : input) {
        if (!prec_letters.empty() && c == prec_letters.back().first) {
            prec_letters.back().second++;
        }
        else {
            prec_letters.push_back({ c, 1 });
        }
    }

    auto it = prec_letters.begin();
    while (it != prec_letters.end()) {
        if (it->second > 2) {
            // find range to remove
            auto start_it = it, stop_it = it;
            set_begin_end_removal(prec_letters, start_it, stop_it);

            it = prec_letters.erase(start_it, stop_it + 1);
        }
        else {
            ++it;
        }
    }

    string res = "";
    
    constexpr int option = 2; // choose one of the two to return the response
    if (option == 1) {
        for (const auto& p : prec_letters) {
            res += string(p.second, p.first);
        }
    }
    else {
        res = accumulate(prec_letters.begin(), prec_letters.end(), string(""),
            [](const string& accum, const auto& p) { return move(accum) + string(p.second, p.first); });
    }

    return res;
}

LIBCANDYCRASH1D_API string stack_approach(const string& input) {
    using stack_elem = pair<char, int>;
    stack<stack_elem> st;
    for (const auto& c : input) {
        if (!st.empty() && c != st.top().first && st.top().second >= 3) {
            st.pop();
        }

        if (!st.empty() && c == st.top().first) {
            st.top().second++;
        }
        else {
            st.push({ c, 1 });
        }
    }

    if (!st.empty() && st.top().second >= 3) st.pop();
    
    string res = "";
    while (!st.empty()) {
        const auto [c, freq] = st.top(); st.pop();
        res = string(freq, c) + res;
    }

    return res;
}
