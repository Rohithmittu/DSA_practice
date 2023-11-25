#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {

	int candidate = -1, count = 0;

    // Find potential majority candidate
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else {
            if (arr[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }
    }

    // Verify if the candidate is the majority element
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }

    if (count > n / 2) {
        return candidate;
    } else {
        // No majority element found
        return -1;
    }
}