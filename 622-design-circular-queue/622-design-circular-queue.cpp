class MyCircularQueue {
private: 
    int maxi;
    int front; int rear;
    vector<int> cir_queue;
    
public:
    MyCircularQueue(int k) {
        this->maxi = k;
        cir_queue.resize(maxi);
        
        front =-1;
        rear =-1;
    }
    
    bool enQueue(int value) {
        
        if(front==0 && rear==maxi-1) return false;  //overflow
        if(front!=0 && rear==front-1) return false; //overflow
        
        if(front==-1 && rear==-1){//  queue is empy: insert first element
            front=0;
            rear =0;
        }
        else if(rear==maxi-1 && front!=0) {
            rear=0;
        }
        else{
            rear=rear+1;
        }
        
        cir_queue[rear]=value;
        return true;
    }
    
    bool deQueue() {
        if(front==-1 && rear==-1){ return false;} // deletion not possible:underflow
        
        int val = cir_queue[front];
        if(front==rear) {
            front=-1;
            rear=-1;
        }
        else if(front==maxi-1) front=0;
        else front =front+1;
        
        return true;

    }
    
    int Front() {
        if(front==-1 && rear==-1) return -1;
        return cir_queue[front];
    }
    
    int Rear() {
        if(front==-1 && rear==-1) return -1;
        return cir_queue[rear];
    }
    
    bool isEmpty() {
        if(front==-1 && rear==-1) return true;
        
        return false;
    }
    
    bool isFull() {
         if(front==0 && rear==maxi-1) return true;  //overflow
        if(front!=0 && rear==front-1) return true; //overflow
        
        
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */