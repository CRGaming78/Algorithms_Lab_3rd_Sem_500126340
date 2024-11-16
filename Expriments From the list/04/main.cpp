#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int id;
    int start;
    int finish;
};

bool activityComparator(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(vector<Activity> &activities) {
    sort(activities.begin(), activities.end(), activityComparator);
    cout << "Selected Activities: ";
    int lastSelected = 0;
    cout << "Activity" << activities[lastSelected].id << " ";
    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= activities[lastSelected].finish) {
            cout << "Activity" << activities[i].id << " ";
            lastSelected = i;
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;
    vector<Activity> activities(n);
    cout << "Enter the activity id, start time, and finish time:\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].id >> activities[i].start >> activities[i].finish;
    }
    activitySelection(activities);
    return 0;
}