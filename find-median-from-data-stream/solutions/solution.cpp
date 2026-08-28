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
        if (n == 0) return 0;
        else if (n%2 == 1) return numArr[n/2];
        else {
            float f = n;
            return (numArr[(f-1)/2.0] + numArr[f/2.0])/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */