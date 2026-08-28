class MedianFinder {
public:
    vector<int> numArr;

    MedianFinder() {

    }
    
    void addNum(int num) {
        for (int i = 0; i < numArr.size(); i++){
            if (num < numArr[i]) {
                numArr.insert(numArr.begin() + i, num);
                return;
            }
        }
        numArr.push_back(num);
    }
    
    double findMedian() {
        int n = numArr.size();

        if (n % 2 == 1) {
            return numArr[n / 2];
        }
        else {
            return (numArr[n / 2 - 1] + numArr[n / 2]) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */