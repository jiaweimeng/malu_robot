#include <malu_robot/robot.h>
#include <unistd.h>
#include <math.h>


int main(void)
{
    Robot robot;
    robot.Handle();
    sleep(1);
    robot.Init(1500,1500,0);
    robot.SetVelocity(888);
    robot.SetAcceleration(666);
    clock_t time = clock();
    int num = 0;
    while(1)
    {
        robot.Handle();
        if(fabs((float)(clock() - time))/CLOCKS_PER_SEC > 1.0)
        {
            std::cout << robot.DebugString()<<std::endl;
            robot.GetDetial();
            time = clock();
            num ++;
        }
        if(num == 20)
        {
            robot.SetPosition(500,1500,0);
            robot.SetPosition(1500,1500,0);
            num ++;
            std::deque<float*>path;
            float p1[3] = {2500,1500,0};
            float p2[3] = {1500,1500,0};
            path.push_back(p1);
            path.push_back(p2);
            robot.SetPosition(path);
        }
    }

}
