#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Process {
    string name;
    int burstTime;
    int remainingTime;
    int weight;
    int completionTime = 0;
    double virtualRuntime = 0.0;
};

int main() {
    vector<Process> processes = {
        {"P1", 5, 5, 1024},
        {"P2", 8, 8, 2048},
        {"P3", 4, 4, 512}
    };

    cout << "\nCFS Scheduler Simulation\n";
    cout << "------------------------\n";

    int time = 0;

    while (true) {
        int selected = -1;

        for (int i = 0; i < processes.size(); i++) {
            if (processes[i].remainingTime <= 0)
                continue;

            if (selected == -1 ||
                processes[i].virtualRuntime <
                processes[selected].virtualRuntime) {
                selected = i;
            }
        }

        if (selected == -1)
            break;

        Process &p = processes[selected];

        cout << "Time " << time << ": "
             << p.name << " executes\n";

        p.remainingTime--;
        p.virtualRuntime += 1024.0 / p.weight;
        time++;

        if (p.remainingTime == 0)
            p.completionTime = time;
    }

    cout << "\nScheduling Statistics\n";
    cout << "---------------------------------------------\n";
    cout << left << setw(10) << "Process"
         << setw(10) << "Burst"
         << setw(12) << "Complete"
         << setw(12) << "Turnaround"
         << setw(10) << "Waiting" << "\n";

    for (const Process &p : processes) {
        int turnaround = p.completionTime;
        int waiting = turnaround - p.burstTime;

        cout << left << setw(10) << p.name
             << setw(10) << p.burstTime
             << setw(12) << p.completionTime
             << setw(12) << turnaround
             << setw(10) << waiting << "\n";
    }

    cout << "\nAll processes completed!\n";
    return 0;
}
