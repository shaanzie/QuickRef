# Paxos

- First consensus algorithm
- Objective: Choosing a single value under crash or network fault
- System process
  - Making a proposal
  - Accepting a value
  - Handling Failures

- Proposer
  - Propose a value to be chosen by the consensus
- Acceptor
  - Form the consensus and accept values
- Learner
  - Learn which value was chosen by each acceptor

- Making a proposal
  - Proposer proposes a value (form a timeline, biggest number considered up-to-date)
  - Acceptor's decision making: If proposal number is lesser than acceptor's proposal number, it is rejected
  - Acceptor sends a response based on acceptance to the proposer
- Accepting a value
  - Proposer checks if majority of acceptors have rejected
    - If yes, update with latest proposal number
  - Else if majority of acceptors have accepted the number
    - If yes, accept
  - Else, reject
  - Proposer sends accept message to all acceptor with the proposal number
  - Notify the learner with the accept value
- Handling failures
  - Acceptor failure
    - Majority voting removes single point of failure
    - If more than N/2 fail, then no consensus is reached
  - Proposer failure
    - During the prepare phase, no proposal value is given
    - During the accept phase, acceptor just propose a new value, and send this number
  - Dueling proposers
    - Leader election chooses only one proposer, mitigating this