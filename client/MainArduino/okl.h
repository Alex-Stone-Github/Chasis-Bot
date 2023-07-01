#pragma once

struct WheelStateType {
    double left;
    double right;
};
struct ChasisSpeeds {
    double delta_theta;
    double delta_x;
};
struct Pose {
    double x;
    double y;
    double a;
};
class KinematicsLayer {
public:
    KinematicsLayer(double axel_width_cm);
    WheelStateType to_wheel_speeds(ChasisSpeeds chasis_speeds);
private:
    double axel_width_cm;
};

class OdometryLayer {
public:
    OdometryLayer(double axel_width_cm);
    Pose get_pose();
    void update(WheelStateType wheel_states, double angle);
    void reset(Pose pose);
    
private:
    WheelStateType last_wheel_states;
    double axel_width_cm;
    Pose estimated_pose;
};
