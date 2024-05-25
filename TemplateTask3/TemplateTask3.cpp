#include <iostream>
#include <vector>
#include <algorithm>

class functor {
    int sum;
    int count;
public:
    functor () : sum{0}, count{0} { }
    void operator()(int x) {
        if (x % 3 == 0) {
            sum += x; 
            ++count;
        }
    }

    void get_sum() {
        std::cout << "[OUT]: get_sum() = " << sum << std::endl;
    }

    void get_count() {
        std::cout << "[OUT]: get_count() = " << count << std::endl;
    }
    ~functor() { }
};
int main()
{
    functor f;
    std::vector<int> vec = { 4, 1, 3, 6, 25, 54 };
    f = std::for_each(vec.begin(), vec.end(), f);

    std::cout << "[IN]:";
    for (int x : vec) {
        std::cout << " " << x;
    }
    std::cout << std::endl;

    f.get_sum();
    f.get_count();

    return 0;
}

