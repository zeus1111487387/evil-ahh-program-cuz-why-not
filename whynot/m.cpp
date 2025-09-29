#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <Windows.h>

int main()
{
    int g_multiplier = 1; // g_ for global ofc ofc
    int* buffer = nullptr; // g_ would look ridiculous on the others, not going to bother adding it
    size_t bytes = 0;
    while (!FindWindowA(nullptr, "Task Manager"))
    {
        bytes = static_cast<size_t>(1024 * 1024) * g_multiplier;
        std::free(buffer);

        buffer = static_cast<int*>(std::malloc(bytes));

        for (size_t i = 0; i < bytes / sizeof(int); ++i) { // idk
            buffer[i] = static_cast<int>(i);
        }

        volatile int v = buffer[0]; // volatile for preventing compiler optimizations because they're trash
        (void)v;

        g_multiplier += 1; // yuh, we increase the god damn multiplier

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::free(buffer);
    return 0;
}
