#include <vector>
#include <cassert>

/*
The problem:

Given a list of targets arranged in a line, 
determine whether a ball bounce can reach a final target.
The ball can only bounce off the targets, and if it reaches
a target with a horizontal speed of 'i', it will bounce 
off with horizontal speed 'i-1', 'i' or 'i+1.
The ball will never completely loose forward horizontal speed
(or bounce back).

The initial throw has horizontal speed of '1'.

Reachable example:
[0,1,3,4,6,9,13]

Unreachable example:
[0,1,3,7,10,14] (the jump from 3->7 is to high)
*/
bool canReach(const std::vector<int>& targets) {
    int* speed{new int{1}};

    int last{-1};

    for(int target : targets){
        if(last == -1){
            last = target;
            continue;
        }
        int delta = target - last;
        last = std::move(target);
        switch (delta - *speed){
        case -1:
            *speed -= 1;
            break;
        case 0:
            break;
        case 1:
            *speed += 1;
            break;
        default:
            return false;
        }
    }
    delete speed;
    return true;
}

int main() {
     // Example inputs:
    assert(canReach({0,1,2,3,4,7}));
}