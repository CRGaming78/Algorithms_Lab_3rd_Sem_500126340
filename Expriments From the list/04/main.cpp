#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(Activity activities[], int n) {
    sort(activities, activities + n, compare);
    cout << "Selected activities (start, finish):\n";
    int lastSelected = 0;
    cout << "(" << activities[0].start << ", " << activities[0].finish << ")\n";
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= activities[lastSelected].finish) {
            cout << "(" << activities[i].start << ", " << activities[i].finish << ")\n";
            lastSelected = i;
        }
    }
}
int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;
    Activity activities[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter start and finish time for activity " << i + 1 << ": ";
        cin >> activities[i].start >> activities[i].finish;
    }
    activitySelection(activities, n);
    return 0;
}