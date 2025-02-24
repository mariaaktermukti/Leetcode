#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple>
using namespace std;

struct Task {
    int userId;
    int taskId;
    int priority;
};

class TaskManager {
private:
    unordered_map<int, Task> taskMap; 
    priority_queue<tuple<int, int, int>> taskQueue; 

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& t : tasks) {
            add(t[0], t[1], t[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        Task task = {userId, taskId, priority};
        taskMap[taskId] = task; 
        taskQueue.emplace(priority, taskId, userId); 
    }

    void edit(int taskId, int newPriority) {
        if (taskMap.find(taskId) != taskMap.end()) {
            Task& task = taskMap[taskId];
            task.priority = newPriority;
            taskQueue.emplace(newPriority, taskId, task.userId); 
        }
    }

    void rmv(int taskId) {
        if (taskMap.find(taskId) != taskMap.end()) {
            taskMap.erase(taskId); 
        }
    }

    int execTop() {
        while (!taskQueue.empty()) {
            auto [priority, taskId, userId] = taskQueue.top();
            taskQueue.pop();

            if (taskMap.find(taskId) != taskMap.end() && taskMap[taskId].priority == priority) {
                taskMap.erase(taskId); 
                return userId; 
            }
        }
        return -1; 
    }
};

int main() {
    vector<vector<int>> tasks = {
        {1, 101, 10}, 
        {2, 102, 20}, 
        {3, 103, 15}
    };

    TaskManager taskManager(tasks);

    taskManager.add(4, 104, 5);
    taskManager.edit(102, 8);
    cout << taskManager.execTop() << endl; 
    taskManager.rmv(101);
    taskManager.add(5, 105, 15);
    cout << taskManager.execTop() << endl; 

    return 0;
}
