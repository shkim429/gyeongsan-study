\* *This project has been created as part of the 42 curriculum by \<sohuikim\>.* <br><br>

# Philosophers
 <br>

# Description

### Overview
Philosophers is a simulation project based on the Dining Philosophers Problem. <br>
It models an environment in which multiple philosophers repeatedly eat, sleep, and thinking while sharing a limited number of forks. <br><br>

### Simulation Rules

#### Environment
\- One or more philosophers sit around a circular table with a bowl of spaghetti at the center. <br>
\- There are as many forks as philosophers, and each philosopher shares the forks on their left and right. <br>

#### Philosopher Routine
\- Each philosopher repeatedly performs `Eat` → `Sleep` → `Think`. <br>
\- A philosopher must acquire both the left and right forks before eating. <br>
\- After eating, the philosopher puts both forks back on the table, goes to sleep, and starts thinking. <br>
\- While eating, a philosopher cannot think or sleep. While thinking, a philosopher cannot eat or sleep. While sleeping, a philosopher cannot eat or think. <br>

#### Termination Conditions
\- A philosopher dies if they do not eat within `time_to_die` after their last meal. <br>
\- The simulation ends when every philosopher has eaten the required number of times, if `must_eat_count` is specified. <br>

#### Philosopher Behavior
\- Philosophers do not communicate with each other. <br>
\- Philosophers have no knowledge of the state of other philosophers. <br>

<br>

### Goal
The goal of this project is to understand concurrency issues, such as mutual exclusion, data races, and deadlocks, in multithreaded programming and to learn how to design programs that address them.
<br><br><br>


# Instruction

### Build
Build the project:
``` bash
make
```

### Usage
Example arguments:

```bash
./philo 5 315 100 210 # Valid input
```

```bash
./philo 1 315 100 210 # Single philosopher
```

```bash
./philo 198 408 199 199 2 # Optional meal count
```

```bash
./philo 800 10000 1 # Missing required argument
```

 | Argument | Description |
 | -------- | ----------- |
 | `number_of_philosophers` | Number of philosophers(equal to the number of forks) |
 | `time_to_die(ms)` | Maximum time a philosopher can survive without starting another meal after their last meal begins |
 | `time_to_eat(ms)` | Time spent eating |
 | `time_to_sleep(ms)` | Time spent sleeping |
 | `number_of_times_each_philosopher_must_eat(optional)` | Minimum number of meals each philosopher must complete |

<br>

# How It Works

### 1. Create and Start Threads
The program creates Philosopher and Monitor threads. <br>
They run independently and concurrently throughout the simulation. <br>
\- `Philosoper thread`: Repeatedly performs `Eat` → `Sleep` → `Think`. <br>
\- `Monitor thread` : Monitors philosopher states and checks the simulation's termination conditions. <br>
All threads wait for a common start signal and begin execution once the start flag is set. <br>

### 2. Run Philosopher Routines
Each Philosopher thread repeatedly performs the following routine: <br>

`Pick Up Forks` → `Eat` → `Put Down Fork` → `Sleep` → `Think` <br>

The routine is repeated until tue simulation ends. <br>

### 3. Monitor and Terminate the Simulation
The Monitor thread periodically checks the state of each philosopher and handles the simulation's termination conditions: <br>
\- A philosopher dies if `time_to_die` has elpased since their last meal. <br>
\- The simulation ends when every philosopher has eaten `must_eat_count` times. <br>
The Monitor thread sets the shared `end` flag when a termination condition is met. <br>
Each Philosopher thread checks the `end` flag and exits its routine. <br>
The main thread waits for all threads finish to by calling `pthread_join()`. <br>

# Synchronization Strategy

### 1. Shared Resource Protection <br>

`Fork` <br>
\- Shared resources between two adjacent philosophers <br>
\- Protected by a mutex to prevent multiple philosophers from using the same fork simultaneously <br>

`shared state` <br>
\- Shared data accessed by Philosopher and Monitor threads (`start` flag, `end` flag, last mael time, meal count) <br>
\- Protected by mutexes to prevent data races <br>

`output` <br>
\- Shared resource used by all threads <br>
\- Serialized with a mutex to prevent messages from being interleaved <br>

### 2. Deadlock Prevention <br>
\- Modified fork acquisition order to prevent circular wait: <br>
- Most philosophers: `first fork` → `second fork` <br>
- Last philosopher: `second fork` → `first fork` <br>

### 3. Resource Contention Reduction <br>

`even philosopher delay` <br>
\- Execution delayed by `time_to_eat / 2` at the start of the simulation to reduce initial fork contention <br>

`thinking delay` <br>
\- `usleep(250)` applied during the thinking phase to spread out fork acquisition attempts and reduce fork contention <br>


# References
### \- References <br>

- Linux Man Pages <br>
\- Documentation for the functions allowed in the project <br>

- GeeksforGeeks <br>
\- Thread and mutex concepts and their operating principles <br>
\- Busy waiting concept <br>
\- Process scheduling concept <br>

- Stack Overflow <br>
\- Mutex concepts and behavior <br>
\- Differences between busy waiting and sleep <br>
\- Differences between data races and race conditions <br>
\- Why `pthread_mutex_init()` is required <br>
\- Usage of `pthread_crate()` <br>


- William & Mary Computer Science (cs.wm.edu) <br>
\- Usage of `gettimeofday()` and time measurement <br>

- 42 Slack <br>
\- Usage of data race detection tools such as Helgrind <br>
\- Discussions on different interpretations of the project specification <br>
\- Strategies for reducing fork contention using thinking delays and initial execution delays <br>


### \- AI Usage <br>

\- Translating English resources into Korean and README content into English <br>
\- Verifying the understanding of concepts from reference materials <br>
\- Interpreting Helgrind logs and learning how to use ThreadSanitizer <br>
\- Learning how to identify the causes of program errors <br>
\- Comparing out-parameter and enum-based return designs for handling system function failures <br>