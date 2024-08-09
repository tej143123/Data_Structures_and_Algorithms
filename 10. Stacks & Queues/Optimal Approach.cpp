// Stack class.
class Stack {
    public:
    int *arr;
    int arrSize;
    int topi;
public:
    Stack(int capacity) {
        arrSize = capacity;
        arr = new int[arrSize];
        topi = -1;
    }

    void push(int num) {
        if((arrSize - topi) > 1){
            topi++;
            arr[topi] = num;
        }
    }

    int pop() {
        if(topi >= 0){
            int x = arr[topi];
            topi--;
            return x;
        }
        return -1;
    }
    
    int top() {
        if(topi >= 0){
            return arr[topi];
        }
        return -1;
    }
    
    int isEmpty() {
        if(topi >= 0){
            return 0;
        }
        return 1;
    }
    
    int isFull() {
        if((arrSize - topi) > 1) return 0;
        return 1;
    }
    
};
