/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 25th May 2024
*/
#ifndef SENECA_TIMEDTASK_H
#define SENECA_TIMEDTASK_H

#include <iostream>
#include <chrono>
#include <string>
#include <iomanip>

namespace seneca {

    struct Task {
        std::string name;
        std::string units;
        std::chrono::nanoseconds duration;
    };

    class TimedTask {
        static const int max_tasks = 10;
        Task tasks[max_tasks];
        int current_tasks;
        std::chrono::steady_clock::time_point start_time;
        std::chrono::steady_clock::time_point end_time;

    public:
        TimedTask();
        void startClock();
        void stopClock();
        void addTask(const char* task_name);
        friend std::ostream& operator<<(std::ostream& os, const TimedTask& tt);
    };

}

#endif // SENECA_TIMEDTASK_H
