#include <stdio.h>

struct Job {
    int id;
    int deadline;
    int profit;
};

void sortJobsByProfit(struct Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

int findMaxDeadline(struct Job jobs[], int n) {
    int max = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > max) {
            max = jobs[i].deadline;
        }
    }
    return max;
}

void jobScheduling(struct Job jobs[], int n) {
    sortJobsByProfit(jobs, n);
    int maxDeadline = findMaxDeadline(jobs, n);
    int slot[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++) {
        slot[i] = -1;
    }
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    printf("Scheduled jobs: ");
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != -1) {
            printf("%d ", jobs[slot[i]].id);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    struct Job jobs[n];
    for (int i = 0; i < n; i++) {
        printf("Enter job id, deadline and profit for job %d: ", i + 1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }
    jobScheduling(jobs, n);
    return 0;
}