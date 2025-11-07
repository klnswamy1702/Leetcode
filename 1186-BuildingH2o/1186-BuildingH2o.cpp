// Last updated: 07/11/2025, 13:42:55
class H2O {
public:
    // H2O() {
        
    // }

    // void hydrogen(function<void()> releaseHydrogen) {
        
    //     // releaseHydrogen() outputs "H". Do not change or remove this line.
    //     releaseHydrogen();
    // }

    // void oxygen(function<void()> releaseOxygen) {
        
    //     // releaseOxygen() outputs "O". Do not change or remove this line.
    //     releaseOxygen();
    // }

    int h=0,o=0;
    condition_variable cv;
    mutex m;

    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lck(m);
        while(h>=2){
            cv.wait(lck);
        }
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        h++;
        if(h==2 and o==1){
            h=0;
            o=0;
        }
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lck(m);
        while(o==1){
            cv.wait(lck);
        }

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        o++;
        if(h==2 and o==1){
            h=0;
            o=0;
        }
        cv.notify_all();
    }
};