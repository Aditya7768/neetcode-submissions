class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        mergeSort(nums, 0, n, temp);
        return nums;
    }

private:
    void mergeSort(vector<int>& arr, int left, int right, vector<int>& temp) {
        if (right - left <= 1) return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, temp);
        mergeSort(arr, mid, right, temp);
        merge(arr, left, mid, right, temp);
    }

    void merge(vector<int>& arr, int left, int mid, int right, vector<int>& temp) {
        int i = left, j = mid, k = left;
        while (i < mid && j < right) {
            temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
        }
        while (i < mid) temp[k++] = arr[i++];
        while (j < right) temp[k++] = arr[j++];
        for (int idx = left; idx < right; ++idx) arr[idx] = temp[idx];
    }
};