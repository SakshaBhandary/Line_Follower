# Line_Follower
An autonomous line-following robot using an Arduino (ATmega328P) microcontroller paired with an array of infrared reflectance sensors. Integrated a PID control algorithm to continuously adjust motor speeds via an L298N motor driver, ensuring smooth, accurate tracking of black path.

## PID Control for Line Following
PID stands for Proportional, Integral, and Derivative – a control algorithm used to correct errors between the desired path and actual movement. Without PID, the robot may jerk, overshoot, or zigzag. PID ensures smooth and accurate turns while following a line.

• Proportional (P): Reacts to the current error (how far the robot is from the center of the line).
• Integral (I): Accumulates past errors (helps in fine-tuning if the robot keeps drifting).
• Derivative (D): Predicts future error (helps reduce overshoot and smooths out the motion).

> The project demonstrates key skills in C++/ C programming, sensor calibration, real-time control systems, and PID tuning for dynamic trajectory correction.
