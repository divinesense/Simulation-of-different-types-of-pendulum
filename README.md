# Simulation-of-different-types-of-pendulum
Simulates different types of pendulum using OpenGL

1. Uses OpenGL (C++) to simulate different types of pendulum.
2. The different pendulums simulated are :
      a) Damped pendulum
      b) Circular pendulum
      c) Seconds pendulum
      d) Spherical pendulum

SIMPLE PENDULUM :

A pendulum is a weight suspended from a pivot so that it can swing freely. When a pendulum is displaced sideways from its resting, equilibrium position, it is subject to a restoring force due to gravity that will accelerate it back toward the equilibrium position. When released, the restoring force combined with the pendulum's mass causes it to oscillate about the equilibrium position, swinging back and forth. The time for one complete cycle, a left swing and a right swing, is called the period. The period depends on the length of the pendulum and also to a slight degree on the amplitude, the width of the pendulum's swing

DAMPING PENDULUM : 
 
Damping pendulum is similar to simple pendulum but, its amplitude keeps reducing every second as per damping coefficient.

            A problem that is difficult to solve analytically (but quite easy on the computer) is what happens when a damping term is added to the pendulum equations of motion.         
            
            Equation of damped pendulum is shown below:
            
                      (d^2 θ)/〖dt〗^2 +αdθ/mdt+(g sin⁡θ)/l=0

3. It uses Runge Kutta Method of 4th order to carry out numerical integration.

Runge–Kutta family is generally referred to as "RK4", "classical Runge–Kutta method" or simply as "the Runge–Kutta method".
Let an initial value problem be specified as follows.
 
Here, y is an unknown function (scalar or vector) of time t which we would like to approximate; The function f and the data  ,   are given.
Now pick a step-size h>0 and define
 
for n = 0, 1, 2, 3, . . . , using
  
Here   is the RK4 approximation of  , and the next value ( ) is determined by the present value ( ).

CIRCULAR PENDULUM : 

A circular pendulum is a weight (or bob) fixed on the end of a string (or rod) suspended from a pivot. Its construction is similar to an ordinary pendulum; however, instead of rocking back and forth, the bob of a conical pendulum moves at a constant speed in a circle with the string (or rod) tracing out a cone.

SECONDS PENDULUM : 
 
A seconds pendulum is a pendulum whose period is precisely two seconds; one second for a swing in one direction and one second for the return swing, a frequency of 1/2 Hz. A pendulum is a weight suspended from a pivot so that it can swing freely.
 
