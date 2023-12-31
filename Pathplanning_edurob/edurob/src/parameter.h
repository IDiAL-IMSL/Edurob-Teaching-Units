#ifndef PARAMETER_H
#define PARAMETER_H

#define MECANUM
// #define DIFF
// #define OMNI4
// #define OMNI3

// Parameters

// #############-USER-CODE-START-#####################

#ifdef OMNI4
//############################## 4 Omni Wheels ##############################
static const double wheelRadius = 0.015;     // Wheelradius in meters (Mecanum 4-Omni)
static const double l1 = 0.0825;             // Distance between axels aka "length"
static const double l2 = 0.0825;             // Distance between wheels aka "width"
//###########################################################################
#endif

#ifdef MECANUM
//############################## 4 Mecanum Wheels ##############################
static const double wheelRadius = 0.015;     // Wheelradius in meters (Mecanum 4-Omni)
static const double l1 = 0.1;                // Distance between axels aka "length"
static const double l2 = 0.0865;             // Distance between wheels aka "width"
//###########################################################################
#endif

#ifdef OMNI3
//############################## 3 Omni Wheels ##############################
static const double wheelRadius = 0.012825;  // Wheelradius in meters (3-Omni)
static const double l1 = 0.1025;             // Distance between axels aka "length"
static const double l2 = 0.1025;             // Distance between wheels aka "width"
//###########################################################################
#endif

static const float maxTSpeed = 0.5;          // Maximum translational speed in m/s
static const float maxRSpeed = 1.5;          // Maximum rotational speed in rad/s
static const float maxTAccel = 0.5;          // Maximum translational acceleration in m/s²
static const float maxRAccel = 1.5;          // Maximum rotational acceleration in rad/s²

// #############-USER-CODE-END-#####################


#ifdef OMNI3
//############################## 3 Omni Wheels ##############################
static const int EncoderDir[4] = {1, -1, -1, -1};  // Counting direction of encoderchannels (+1 or -1)
static const int MotorDir[4] = {-1, 1, 1, 1};      // Direction of motors (+1 or -1)
static const int NumMotors = 3;                    // Number of Motors 3-Omni
//###########################################################################
#else
//############################## 4 Mecanum/ 4 Omni Wheels ##############################
static const int EncoderDir[4] = {-1, -1, -1, -1}; // Counting direction of encoderchannels (+1 or -1)
static const int MotorDir[4] = {1, 1, 1, 1};       // Direction of motors (+1 or -1)
static const int NumMotors = 4;                    // Number of Motors (Max=4) 4 Wheels
//###########################################################################
#endif

static const int sampleTime = 5;                                         // Sample time in ms
static const int gearing = 150.0;                                        // Number of motorrotations per wheelrotation
static const int encoderSteps = 12;                                      // Number of encoder increments per motorrotation
static const double incrementsToRad = 2 * PI / (encoderSteps * gearing); // Conversion from encoder increments to rad
static const double circumference = (2 * PI * wheelRadius);              // Circumference in meters
static const double msToRads = (2 * PI) / circumference;                 // Conversion from m/s to rad/s
static const int nMax = 210;                                             // Maximum revolutions / min
static double Rad2PWM = 100.0 * 60.0 * gearing / (2.0 * PI * nMax);      // Conversion from rad/s to pwm duty cicle

// Motornumbering
// |2|--|1|
//    ||
// |3|--|4|

// Pin definitions Motoren
static const int PWM_A[4] = {25, 5, 21, 14};  // GPIO PWM channel A
static const int PWM_B[4] = {26, 18, 22, 27}; // GPIO PWM channel B
static const int Enc_A[4] = {32, 10, 19, 36}; // GPIO Encoder channel A
static const int Enc_B[4] = {33, 9, 23, 39};  // GPIO Encoder channel B


static const int EnablePIN = 12;              // Enable Signalpin for motordrivers

struct pidParam
{                   // PID Parameters
  double input;     // Input data
  double output;    // Output data
  double setpoint;  // Setpoint
  double p;         // Proportional
  double i;         // Integral
  double d;         // Differential
  int sampleTimeMs; // Sampletime in ms
  double outMin;    // Lower limit of output
  double outMax;    // Upper limit of output
};



#endif // PARAMETER_H