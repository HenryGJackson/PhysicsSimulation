# PhysicsSimulation
A console application for physics simulations

# Using the User Interface:
A makefile is included to help you build the project. (Enter ./LetsGo to run)  
Typing "help" brings up the menu of options you can choose from.  
Options entered successively will all be chosen unless they overwrite each other by making choices on the same parameter.  
Multiple chosen simulations will be executed.  
Typing "quit" exits the program.  

# Systems:
## Box -
Class used to build all simulations.
### Constructors -
`Box(std::vector<Particle*> part, double len, int numsteps,
  double timestep, int bType = 0, std::string id = "Box")`  
### Public Member Functions -
`void CheckBounds(int j);`  
Check boundaries for particle `j`.  
`void EarthGravity();`  
Apply an external force equivalent to gravity on earth.  
`std::vector<double> EvalForce(std::vector<double> pos, double mass);`  
Evaluate the force on a particle at `pos` with mass `mass` due to the external force.  
`Particle* GetParticle(int i);`  
Return a pointer to particle `i`.  
`void Go();`  
Run the simulation.  
`void MoveParticlesGrav();`  
Move particle only taking into account gravity.  
`void MoveParticlesEM();`  
Move particles only taking into account the electromagnetic force.  
`void MoveParticlesAll();`  
Move particles accounting for all forces.
`void Print();`  
Print information about the box.
`void setBField(std::vector<double> B);`  
Set the magnetic field vector.  
`void setExtForce(VectFunction* f);`  
Set the external acceleration as a vector function.  
`void setForceAll(bool reset);`  
Set the force on each particle accounting for all forces.  
`void setForcesEM(bool reset);`  
Set the force on each particle accounting for electronmagnetic forces.  
`void setForcesGrav(bool reset);`  
Set the force on each particle accounting for gravitational forces.  

# Particles:  
## Particle -
Base class for all particles, derives from object.
### Constructors -
`Particle(double mass, double charge, std::string id = "Particle")`
`Particle(std::string id = "Particle")`
### Public Member Functions -
`void addToForce(std::vector<double> f);`
Add vector to the force member of the particle.    
`void takeFromForce(std::vector<double> f);`  
Take vector away from the force member of the particle.    
`bool checkBoundsA(double L);`  
Check if the particle has cross one of the boundaries and apply absorbing boundary conditions.  
`void checkBoundsB(double L);`  
Check if the particle has cross one of the boundaries and apply bouncing boundary conditions.  
`bool checkPosition();`  
Check that the particle is within the boundaries.  
`void ConvertUnits(bool toSI = true);`  
Convert between SI and natural units.  
`double getCharge();`  
Return the charge of the particle.  
`Force* getForce();`  
Return the force on the particle.  
`double getMass();`  
Return the mass of the particle.
`std::vector<double> getPosition();`  
Return the vector position of the particle.  
`double getPosition(int i);`  
Return a given component of the position vector.  
`std::vector<double> getVelocity();`  
Return the velocity vector.  
`double getVelocity(int i);`  
Return a given component of the velocity.  
`void Move(double timestep);`  
Move the particle based on the force applied.  
`void printParticle();`  
Print information about the particle.  
`void ReverseVel(int i);`  
Reverse the velocity by multiplying by -1.  
`void setProperties(double mass, double charge, bool antiparticle = false);`  
Set the mass, charge and antiparticle status.
`void setPosition(double x, double y, double z);`  
Set the position of the particle.  
`void setForce(Force* f);`  
Set the force on the particle.  
`void setForce(double x, double y, double z);`    

## Lepton -
Lepton class derived from Particle
### Constructors -
Lepton(int gen, bool neutrino = false, bool antiparticle = false)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;creates an instance of Lepton with generation 1 = electron, 2 = muon, 3 = tau.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;neutrino = true creates a lepton with the properties of a neutrino or else the lepton that corresponds
                 to the generation.
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;antiparticle = true creates an instance of the corresponding antilepton
## Hadron -
Hadron class derived from Particle
### Constructors -

# Forces:
## Coulomb -
Namespace containing functions for simulating the coulomb interaction
### Public Member Functions -
std::vector<double> Force(Particle p1, Particle p2)  
std::vector<double> Acceleration(Particle p1, Particle p2)  

## Maxwell - (doesn't yet exist)

# Tools:
## Utility -
Utility functions with general purpose
### Public Member Functions -
double DistanceMag(Particle p1, Particle p2)  
std::vector<double> DistanceVec(Particle p1, Particle p2)  
double Magnitude(std::vector<double> vect)  

## MathFunction -
Base class for mathematical functions to be used in the simulations

## Polynomial -
Derived class from MathFunction. Functions of the form f(x) = A*x^n + B*x^m ...
