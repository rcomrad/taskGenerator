#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

std::ifstream cin;
std::ofstream cout;

void
A()
{
    std::unordered_map<char, char> m;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        m[c] = 0;
    }

    std::string s;
    std::getline(cin, s);
    m[s[0]]++;
    while (true)
    {

        std::getline(cin, s);

        if (s == "?") break;
        std::swap(m[s[0]], m[s[2]]);
    }

    for (auto& i : m)
    {
        if (i.second == 1)
        {
            cout << i.first;
        }
    }
}

void
B()
{
    std::string s;
    cin >> s;
    std::vector<int> a(10);
    for (auto i : s)
    {
        if (i >= '0' && i <= '9')
        {
            a[i - '0']++;
        }
    }

    std::set<std::pair<int, int>> m;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i]) m.insert({a[i], i});
    }

    for (auto it = m.rbegin(); it != m.rend(); it++)
    {
        cout << it->second << " ";
    }
}

void
C()
{
    std::vector<int> a(5);
    for (auto& i : a) cin >> i;
    std::sort(a.begin(), a.end());
    if (a[0] < 0) cout << "NO";
    else if (a[4] > a[0] + a[1] + a[2] + a[3]) cout << "NO";
    else cout << "YES";
}

void
D()
{
    int n, m;
    cin >> n >> m;
    std::vector<std::string> a(n);
    std::getline(cin, a[0]);
    for (auto& i : a)
    {
        std::getline(cin, i);
    }

    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a[i].size(); ++j)
        {
            if (a[i][j] == 'S')
            {
                q.push({i, j});
            }
        }
    }

    bool finish = false;
    int chese   = 0;
    int dx[]    = {1, -1, 0, 0};
    int dy[]    = {0, 0, 1, -1};
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if (cur.first < 0 || cur.first >= n) continue;
        if (cur.second < 0 || cur.second >= m) continue;

        auto& temp = a[cur.first][cur.second];
        if (temp == '*') continue;
        if (temp == 'F') finish = true;
        if (temp == 'C') chese += 1;
        temp = '*';

        for (int i = 0; i < 4; ++i)
        {
            q.push({cur.first + dx[i], cur.second + dy[i]});
        }
    }

    if (!finish) chese = 0;
    cout << chese;
}

void
E()
{
    std::vector<std::string> a(1);
    while (std::getline(cin, a.back()))
    {
        a.emplace_back();
    }
    a.pop_back();

    std::vector<int> b(a[0].size());
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a[i].size(); ++j)
        {
            if (a[i][j] == '*') b[j]++;
        }
    }

    double sum = 0;
    for (auto& i : b) sum += i;
    sum /= b.size();
    sum -= 1;
    cout << std::fixed << sum;
}

int
mainn()
{
    std::ifstream inp("../inp.in");
    std::ofstream out("../out.out");

    out << "problem\n"
           "\tРазминка;triangle;lcmp.exe;16;1;1000;100\n"
           "\tSwiper;swiper;lcmp.exe;5;1;1000;100\n"
           "\tВнеберляндская жизнь;life;ncmp.exe;9;1;1000;100\n"
           "\tЗазеркалье;labirint;ncmp.exe;6;1;1000;100\n"
           "END\n\n"

           "competition_problem\n"
           "\tРазминка;1;1\n"
           "\tSwiper;1;2\n"
           "\tВнеберляндская жизнь;1;3\n"
           "\tЗазеркалье;1;4\n"
           "\tРазминка;2;1\n"
           "\tSwiper;2;2\n"
           "\tВнеберляндская жизнь;2;3\n"
           "\tЗазеркалье;2;4\n"
           "END\n\n"

           "competition\n"
           "\tТестер;2023-04-21 15:00:00;2023-04-22 18:55:00\n"
           "\tОчный тур;2023-04-23 15:00:00;2023-04-23 18:55:00\n"
           "END\n\n";

    std::string temp;

    std::string log, pass;
    out << "user\n\tsubmitor;123;Tester;Testerovich;512;1\n";
    int cnt = 1;
    while (inp >> log >> log >> pass)
    {
        cnt++;
        out << "\t" << log << ";" << pass << ";Tester;Testerovich;512;1\n";
        temp += "\t" + std::to_string(cnt) + ";2" + "\n";
    }
    out << "\nEND\n\nuser_competition\n\t1;1\n\t1;2\n" << temp << "END\n";

    return 0;
}

int
main()
{
    std::string s;
    std::vector<std::string> tests(1);
    cin.open("../e");
    while (std::getline(cin, s))
    {
        if (s[0] == '-' && s[1] == '-')
        {
            tests.emplace_back();
        }
        else
        {
            tests.back() += s + "\n";
        }
    }
    cin.close();

    int cnt = 1;
    for (auto& i : tests)
    {
        cout.open("../test/" + std::to_string(cnt) + ".in");
        cout << i;
        cout.close();

        cin.open("../test/" + std::to_string(cnt) + ".in");
        cout.open("../test/" + std::to_string(cnt) + ".out");

        E();

        cout << "\n";
        cin.close();
        cout.close();

        ++cnt;
    }

    return 0;
}
