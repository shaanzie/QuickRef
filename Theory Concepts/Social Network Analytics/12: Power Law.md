# Power Law

- Network degree distributions are fundamental tools used in the study of complex networks
  - Reveal insights
  - Lay foundation on the modelling of network dynamics
  - Help guide the design of graph algorithms
  - Power law distribution accurately captures node degrees in complex networks

- Degree Distribution
  - Probability distribution of the degrees over the whole network
  - p<sub>x</sub> is the fraction of vertices in a network that have a degree x
    - Probability that a randomly selected node of the network has a degree x

- Power Law
  - Functional relationship between two quanitities, where a relative change in one quantity results in a proportional change in another quantity, independent of the initial size of those quantities
  - One quantity varies as a power of another
  - The law describes how a lot of the time, not much actually happens but more often than not, some patterns cover a wide range of magnitudes

- Power law distribution
  - The probability for a node to have x-edges connected is proportional to x<sup>-a</sup>
    - P(x) = Cx<sup>-a</sup>
    - Where a is the power law exponent
    - where C is a normalisation constant
  - Most scale-free networks have exponents between 2 and 3
  - They lack a characteristic degree or scale
  - High degree nodes are called hubs
  - The distribution belongs to the class of fat-tailed distributions
  - It deviates from the Poisson distribution in two ways
    - Higher peaks
    - Fatter tails
  - Compared to the Poisson distribution, the power law shows
    - Greater probability of nodes with a number of links close to the average of all links
    - A smaller probability of nodes with many links (4+)
  - Taking log of the equation, yields a straight line with slope as m = -a and b = log C as the intercept
  - It decreases less sharply compaired to the log plot of an exponential distribution
  - Few real world distributions show power law over the entire range
    - In particular, not for smaller values of the variable being measured
  - The distribution must deviate from the power-law form below some minimum value x<sub>min</sub>
  - To find the power law exponent, we need to make a judgement about the value of x<sub>min</sub>.
  - After that, a is calculated as a = 1 + n[Sum(ln (x<sub>i</sub> / x<sub>min</sub>))]<sup>-1</sup>
    - N is the number of samples that go into the sample, excluding the ones below x<sub>min</sub>
    - An estimate of the expected statistical error is given by a - 1 / sqrt(n)

- Scale Free networks
  - A variety of complex networks share an important property
    - Some nodes have a tremendous number of connections to other nodes, whereas most nodes just have a handful
    - Hubs can have n number of links, appearing to have no scale
  - Scale free networks are robust against accidental failures but vulnerable to coordinated attacks
  - Understanding such characteristics could lead to new applications in many areas
  - A network that has a power-law degree distribution is a scale-free network
  - It is a connected graph with the number of links x originating from a given node exhibits a power law distribution
  - It can be constructed by
    - Growth
    - Preferential attachment
  - These two mechanisms explain the existence of hubs
  - Features
    - Hubs are large in scale free networks, due to preferential attachment
    - Degree distribution follows power law
    - Hubs show a small world property
  - Properties
    - Display robustness to accidental failures
    - More vulnerable to non-random attacks
    - Have short average path lengths, as L ~ log N / log log k

- Fat Tailed distribution
  - Largely skewed, or displays kurtosis relative to either a normal or an exponential distribution
  - Tails decay like power law