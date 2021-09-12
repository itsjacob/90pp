class CustomStack
{

  public:
    CustomStack(int maxSize)
        : maxSize_{ maxSize }
        , topIdx_{ -1 }
        , sbuf_(maxSize)
    {}

    void push(int x)
    {
        if (topIdx_ < maxSize_ - 1) {
            sbuf_[++topIdx_] = x;
        }
    }

    int pop()
    {
        if (topIdx_ < 0) {
            return -1;
        } else {
            return sbuf_[topIdx_--];
        }
    }

    void increment(int k, int val)
    {
        int end = std::min(topIdx_, k - 1);
        for (int i = 0; i <= end; i++) {
            sbuf_[i] += val;
        }
    }

  private:
    int topIdx_;
    int maxSize_;
    std::vector<int> sbuf_;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
