# PhysicsSimulation
A library for producing physics simulations

# Classes:  
## Particle - 
Base class for all particles
### Constructors - 
Particle(double mass, double charge)
Particle()
### Public Member Functions - 
void setProperties(double mass, double charge, bool antiparticle = false)  
void printParticle()  
void setPosition(double x, double y, double z)  
std::vector<double> getPosition()  
bool checkPosition()  

## Lepton -
Lepton class derived from Particle
### Constructors - 
Lepton(int gen, bool neutrino = false, bool antiparticle = false)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;creates an instance of Lepton with generation 1 = electron, 2 = muon, 3 = tau.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;neutrino = true creates a lepton with the properties of a neutrino or else the lepton that corresponds 
                 to the generation.
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;antiparticle = true creates an instance of the corresponding antilepton
## Baryon - 
Baryon class derived from Particle
### Constructors - 

# Namespaces:
## Coulomb - 
Functions for simulating the coulomb interaction
### Public Member Functions - 
std::vector<double> Force(Particle p1, Particle p2)  
std::vector<double> Acceleration(Particle p1, Particle p2)  

## Utility -
Utility functions with general purpose
### Public Member Functions - 
double DistanceMag(Particle p1, Particle p2)  
std::vector<double> DistanceVec(Particle p1, Particle p2)  
double Magnitude(std::vector<double> vect)  
