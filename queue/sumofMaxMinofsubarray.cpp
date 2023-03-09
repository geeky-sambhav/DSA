int sumOfMinMax(int *arr, int k, int n) {
    // initialize sum as 0
    int sum = 0;
    
    // create 2 deques d1 and d2
    deque<int> d1;
    deque<int> d2;
    
    // first subarray
    for (int i = 0; i < k; i++) {
        // only push the elements that may contribute to maximum
        while (!d1.empty() && arr[d1.back()] <= arr[i]) {
            d1.pop_back();
        }
        
        // only push the elements that may contribute to minimum
        while (!d2.empty() && arr[d2.back()] >= arr[i]) {
            d2.pop_back();
        }
        
        // add the current element's index
        d1.push_back(i);
        d2.push_back(i);
    }
    
    // sum of min and max for first subarray
    sum += (arr[d2.front()] + arr[d1.front()]);
    
    // traverse the remaining subarray
    for (int i = k; i < n; i++) {
        // remove the previous element (sliding window technique)
        while (!d1.empty() && d1.front() <= (i -k)) {
            d1.pop_front();
        }
        while (!d2.empty() && d2.front() <= (i - k)) {
            d2.pop_front();
        }
        
        // only push the elements that may contribute to maximum
        while (!d1.empty() && arr[d1.back()] <= arr[i]) {
            d1.pop_back();
        }
        
        // only push the elements that may contribute to minimum
        while (!d2.empty() && arr[d2.back()] >= arr[i]) {
            d2.pop_back();
        }
        
        // add the current element's index
        d1.push_back(i);
        d2.push_back(i);
        
        // sum of min and max for current subarray
        sum += (arr[d1.front()] + arr[d2.front()]);
    }
    
    // return total sum
    return sum;
}