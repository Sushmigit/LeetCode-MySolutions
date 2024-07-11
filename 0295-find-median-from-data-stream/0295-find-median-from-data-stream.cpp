class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    MedianFinder() {
        
    }
    // minheap.size <= maxheap.size <= minheap.size+1  
    void addNum(int num) {
        int lsize = maxheap.size();
        int rsize = minheap.size();
        if(lsize == 0) //max heap size is 0
            maxheap.push(num);
        //Odd No of Elements
        else if(lsize == rsize) //maxheap size == minheapsize
        {
           if(num<minheap.top()) // eg maxheap 2  minheap 5 num =3; insert into maxheap 2,3
               maxheap.push(num);
            else // eg maxheap 2 minheap 6 num =7 maxheap 2,6 minheap 7 
            {
                int temp = minheap.top();
                minheap.pop();
                maxheap.push(temp);
                minheap.push(num);
            }
     }
        //Even No of Elements and maxheap size > minheapsize by 1
        else
        { 
            if(minheap.size()==0) 
            {
                if(num>maxheap.top()) //eg maxheap 2  minheap  num =3 => minheap 3
                minheap.push(num);
            
                else //eg maxheap 3  minheap  num =2 => maxheap 2 minheap 3
                {
                    int temp = maxheap.top();
                    maxheap.pop();
                    maxheap.push(num);
                    minheap.push(temp);
                }
            }
            //max has 2 ele and min has 1 ele
            else if(num>=maxheap.top())
                minheap.push(num);//eg maxheap 2,3 minheap 5 num=6=> maxheap 2,3 minheap 5,6
            else
            {
                if(num<maxheap.top())//eg maxheap 2,3 minheap 5 num=1=> maxheap 1,2 minheap3,5 
                {
                    int temp = maxheap.top();
                    maxheap.pop();
                    minheap.push(temp);
                    maxheap.push(num);
                }
                else
                    minheap.push(num);
            }
        }
    }
    
    double findMedian() {
        int lsize = maxheap.size();
        int rsize = minheap.size();
        if(lsize > rsize)
            return double(maxheap.top());
        else
            return double(maxheap.top()+minheap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */