/*
Name: Darshan Kalpeshbhai Prajapati
Seneca Id: 112908215
Seneca email: dkprajapati2@myseneca.ca
dat: 25th May 2024
*/
#include "TimedTask.h"

namespace seneca {

    TimedTask::TimedTask() : current_tasks(0) {}

    void TimedTask::startClock() {
        start_time = std::chrono::steady_clock::now();
    }

    void TimedTask::stopClock() {
        end_time = std::chrono::steady_clock::now();
    }

    void TimedTask::addTask(const char* task_name) {
        if (current_tasks < max_tasks) {
            tasks[current_tasks].name = task_name;
            tasks[current_tasks].units = "nanoseconds";
            tasks[current_tasks].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
            current_tasks++;
        }
    }

    std::ostream& operator<<(std::ostream& os, const TimedTask& tt) {
        os << "--------------------------\n";
        os << "Execution Times:\n";
        os << "--------------------------\n";
        for (int i = 0; i < tt.current_tasks; ++i) {
            os << std::setw(21) << std::left << tt.tasks[i].name
                << std::setw(13) << std::right << tt.tasks[i].duration.count()
                << ' ' << tt.tasks[i].units << '\n';
        }
        os << "--------------------------\n";
        return os;
    }

}
