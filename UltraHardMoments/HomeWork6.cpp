#include <iostream>
#include <vector>
#include <optional>
#include <tuple>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <thread>
#include <mutex>
#include <chrono>
#include <random>
#include <execution>
#include <future>
#include <iomanip>
#include <windows.h>

using namespace std;
//#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
//#define PBWIDTH 60
//task 1
once_flag callflag, callflag2;

void FirstPrint()
{
    cout << "Safety ";
}
void SecondPrint()
{
    cout << " or Dangerous ";
}

void pcout(size_t x)
{
    call_once(callflag, FirstPrint);
    cout << x;
    call_once(callflag2, SecondPrint);
    cout << x;
}

//task 2
auto handle = GetStdHandle(STD_OUTPUT_HANDLE);


void set_cursor(int x, int y)
{
    SetConsoleCursorPosition(handle, { static_cast<SHORT>(x), static_cast<SHORT>(y) });
}

void render_progress_bar(int x, int y, int width, double progress, char fill_symbol)
{
    int fill_w = static_cast<int>(width * progress);
    int empty_w = width - fill_w;

    set_cursor(x, y);

    for (int i = 0; i < fill_w; ++i)
        std::cout << fill_symbol;

    for (int i = 0; i < empty_w; ++i)
        std::cout << " ";
}

//task 3
mutex d;
void GenerateItem(vector<int>& n) {
    random_device random;
    mt19937 randI(random());
    uniform_int_distribution <int> range(0, 100);
    lock_guard as(d);
    generate(n.begin(), n.end(), [&]() {return range(randI); });
}

void RemItem(vector<int>& n) {
    lock_guard as(d);
    cout << max_element(n.begin(), n.end()) << "\n";
}

int main()
{

    //task 1
    /*thread th1(pcout, 1);
    th1.join();
    thread th2(pcout, 2);
    th2.join();*/

    //task 2
    const int progress_x = 1;
    const int progress_y = 1;
    const int progress_width = 50;
    double progress = 0;

    auto thread = std::thread{ [progress_x, progress_y,
            progress_width, &progress]
    {
        const int size = 3;
        char symbols[size] = { '.' };
        int symbol_idx = 0;

        do
        {
            render_progress_bar(progress_x, progress_y, progress_width, progress, symbols[symbol_idx]);

            std::this_thread::sleep_for(std::chrono::milliseconds(10));

            ++symbol_idx;

            if (symbol_idx >= size)
                symbol_idx = 0;
        } while (progress < 1);

        render_progress_bar(progress_x, progress_y, progress_width, progress, symbols[symbol_idx]);
    } };

    int count = 100;
    int last_index = 0;

    while (last_index < count)
    {
        last_index += 1 + rand() % 5;

        if (last_index > count)
            last_index = count;

        progress = static_cast<double>(last_index) / count;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    thread.join();

    //task 3
    vector <int> n(100);
    size_t count = 100;
    while (count--) {
        thread own([&]() {GenerateItem(n); });

        thread rob([&]() {RemItem(n); });
        own.join();
        rob.join();
    }
    return 0;
}