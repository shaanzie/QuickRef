# Branching Process - Epidemic Model

- The simplest model of contagion the branching process works as
  - First wave
    - Person carrying new disease enters population and transmits it to each person he meets independently with a probability p
    - Infected person infects k people, called the first wave
  - Second wave
    - First wave meets another k people each, causing a second wave of k<sup>2</sup>
  - Subsequent waves

- There are only 2 possibilities for a disease in the branching process model
  - Reaches a wave where it infects noone
  - Continues to infect people in every wave
  - This is based on a quantity called the basic reproductive number of the disease

- The basic reproductive number (R<sub>0<sub>)
  - R<sub>0<sub> denotes the mathematical term that indicates how contagious an infectious disease is
  - Represents the average number of secondary infections generated from one infectious individual in a completely susceptible population
  - It is the expected number of new cases of the disease caused by a single individual
    - In a branching process model everyone meets k new people and infects each with a probability, R<sub>0</sub> = pk.
    - The outcome of the disease in the branching process model is determined by whether the basic reproductive number is smaller or larger than 1
  - If it is <1, disease dies out
  - If it is ==1, disease will be alive and stable
  - If it is >1, disease persists with a possible epidemic
  - If R0 is slightly below 1, and p increases by little, the result could push R0 above 1, causes an enormous outbreak, and vice versa

- Public health measures to reduce R0 are
  - Quarantines, reducing k
  - Encouraging behavioral measures like sanitary practices, reducing p

- R0 measures any contagious disease that may spread in a susceptible population

## SIR Epidemic Model

- Divides the fixed population into three compartments that vary with time
  - S(t) - susceptible but not yet infected
  - I(t) - infected 
  - R(t) - recovered and have immunity

- Second set of dependent variables
  - s(t) = S(t)/N
  - i(t) = I(t)/N
  - r(t) = R(t)/N

- The SIR epidemic model describes the change in the population of each of these compartments in terms of two paramters B (beta) and G (gamma)
  - B is the effective contact rate / transmission rate
  - G is the effective recovery rate and GI is the number of infected individuals that recover per unit time
  - 1/G is the infectious period, i.e, the average duration of time an individual remains infected
  - dS/dt = - BSI/N
  - dI/dt = BSI/N - GI
  - dR/dt = GI

- Preserves the basic ingredients of the branching process model at the level of individual nodes

- An individual node goes through three potential stages during the course of the epidemic
  - Susceptible
  - Infectious
  - Removed

- Model for epidemics on networks
  - In a directed graph, if edge points from v to w, it means if v gets infected, it has the potential to spread to w
  - Can be symmetric edges

- The progress of the epidemic is controlled by
  - Contact network structure
  - Probability of contagion p
  - The length of the infection t

- Initially some nodes are in the I state and others in the S state
  - Each node in state I remains infections for a fixed number of steps t
  - Each step, v has a probability p to infect each of its S neighbours
  - After t steps, v is no longer infectious and is in a removed state

- This model works for diseases that cannot reinfect a node
  - Probabilities are uniform
  - Contagiousness is on and off

- Extensions
  - Assign non-uniform probabilities
  - Infectious period can be random at length
  - Seperating state I to a sequence of several states and allowing contagion probabilities to vary for each state

- In networks that do not have a tree structure, the simple dichotomy in epidemic behavior determined by R0 does not necesarily hold
  - As R0 gets smaller and smaller as transmissions happen, the epidemic ends after a finite amount of steps

# SIS Epidemic Model

- Nodes can be reinfected multiple times
  - Nodes move between S and I states, with no R state

- Here,
  - dS/dt = - B/N (SI) + GI
  - dI/dt = B/N (SI) - GI

- If B > G, if infected people infect others faster than they recover
  - Infected population approaches ((B - G)N) / B
  - Susceptible population approaches (GN)/ B
- If B < G then the infected population approaches 0

# SI Epidemic Model

- Simplest form of all disease models
  - Born into the simulation with no immunity
  
- Once infected and with no treatment, nodes stay infected throughout life

- Can be modeled as an ODE as
  - dS/dt = - BSI/N
  - dI/dt = BSI/N