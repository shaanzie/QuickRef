# RAFT

- A generic way to distribute a state machine among a set of servers
  - Ensures that every server agrees upon the same series of state transitions
- Basic idea
  - Nodes colectively select a leader, and the rest are followers
  - Leader is responsible for state transition log replication

- Leader finds the proposal value, and followers can accept or propose a new value
- Electing the leader
  - Voting request: Leader requests a vote from all followers for re-election
    - Vote contains
      - Term: Last calculated number
      - Index: Commiteed transaction available to candidate
  - Follower node's decision making
    - Compare leader's value with node value
    - If term < Node's term, decline, else go to next step
    - If index < Node index, decline, else, vote for candidate
  - Majority voting
    - Votes are consolidated and majority leader node is selected
- Multiple Leader candidates
  - Current leader failure
    - Elect a new leader with a higher term value
    - Old leader receives heartbeat from new leader and drops to follower state
  - Simultaneous request vote
    - Majority voting declined for lesser followers
    - Winner sends heartbeat message to all nodes

- Commiting Entry Log
  - AppendEntries sends the proposal number to update all followers entry log
  - Majority voting decides whether to accept or reject the log