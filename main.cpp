#include <bits/stdc++.h>
using namespace std;

struct ToDo {
    string goalName, difficulty;
    int priority, Estimated_time;
};

bool MySort(ToDo a, ToDo b) {
    if (a.priority != b.priority)
        return a.priority < b.priority; // Priority first
    else {
        // If priorities are the same, use difficulty
        if (a.difficulty == "easy" || (a.difficulty == "mid" && b.difficulty == "hard"))
            return true; // Easy tasks come before
        else if (b.difficulty == "easy" || (b.difficulty == "mid" && a.difficulty == "hard"))
            return false; // Easy tasks come first
        else
            return a.Estimated_time < b.Estimated_time; // Fall back to estimated time
        }
}
void printTable(const vector<ToDo>& things) {
    // Set table headers
    cout << setw(20) << left << "Goal Name" << setw(10) << left << "Priority"
         << setw(15) << left << "Difficulty" << setw(20) << right << "Estimated Time (min)" << endl;

    // Print table separator line
    cout << setfill('-') << setw(70) << "" << setfill(' ') << endl;

    // Iterate through each task and print its details
    for (const ToDo& task : things) {
        cout << setw(20) << left << task.goalName << setw(10) << left << task.priority
             << setw(15) << left << task.difficulty << setw(20) << right << task.Estimated_time << endl;
    }
}
int main() {
    cout << "Eisenhower Matrix\n\n";
    cout << "Guides \n1. please insert your goal's informations\nthen press zero to EXIT or any number to continue\n2. please make sure to insert the right Data Type\nto avoid crashing\n";
    int key = 1;
    vector<ToDo> things; // Use vector and push_back
    cout << "Here We Go \n\n";
    do {
        ToDo newGoal;
        cout << "Insert goal's name : ";
        cin >> newGoal.goalName;

        cout << "What it's priority in your day ? (1-3): ";
        cin >> newGoal.priority; // No need to repeat input

        // Input validation for priority
        while (newGoal.priority < 1 || newGoal.priority > 3) {
        cout << "Invalid priority. Please enter a value in range(1-3): ";
        cin >> newGoal.priority;
        }

        cout << "How much is difficult? (1-3): "; // 1 is easy and so on
        cin >> newGoal.difficulty;

        cout << "What is the estimated time for this task (in minutes)? : ";
        cin >> newGoal.Estimated_time;

        things.push_back(newGoal); // Add new goal to the vector

        cout << "A new goal has been added, you're all set\n";
        cout << "Press 0 to EXIT, or any number to add a new goal\n";
        cin >> key;
        } while (key != 0);
    sort(things.begin(), things.end(),MySort);
    cout << "\nYour Today's ToDo seems to be like that: \n\n";
    printTable(things);
	return 0;
}
