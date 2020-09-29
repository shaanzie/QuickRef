# State Diagrams

- Activities and Sequence modeling comes under the umbrella of interaction diagrams

- Activity diagrams are shown as flow charts
- Sequence diagrams are shown as timelines with detailed descriptions about the activity
  - Scenario method is shown through english statements in sequence
  - Timeline method shows a timeline in the vertical axis and the participants in the horizontal axis
    - Requests are solid arrow marks and responses are dotted lines
    - The message should be the name of the function to be called
    - The response should be the return value of that function
    - Synchronous messages are shown as filled arrows, and asynchronous messages with a half arrow
    - If statements are denoted as (opt)[condition]
    - If else statements are denoted as (alt)[condition]
    - Looping statements are denotes as (loop)[condition]

- Transient objects are objects used to aid other objects in responding to interactons
  - The third object gets created only when it is referenced