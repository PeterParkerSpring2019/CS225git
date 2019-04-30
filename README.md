# DataStructures
CS225 course Spring 2019. DON'T EVER use copy and paste. If you look at this code, you need to write it from scratch. Use this only as a resource for hints. DO YOUR OWN ASSIGNMENTS, but don't waste your time. This semester was taught by Craig Zilles but uses the same structure that Wade was using for the past 2 years.

--------------------------------------------------------------------------
Huge Topic Overview (should understand these topics ahead of time if you are trying to get ahead in the class)
- CS225 references, pointers, memory on the stack and heap, and C++ class constructors, destructors, etc. (1 month)

(Data Structures start after 1 month of C++ and is where the real value of this class is held)
- Linked Lists (this was my worst topic. Luckily, you only have to deal with complex linked list code for just the MP during this whole course)
- Stack/Queues (don't ever focus on directly, but will appear A LOT over the semester.)

These next 3 are sorta like side-topics that appear often over the semester, but you don't see their importance at first.
- DFS/BFS -- 1st less obvious topic -- topic isn't covered much in lecture, but these use Stack/Queue and you will see these kinds of traversals repeatedly over the semester and next few years as a computer scientist, especially with any kind of Graph traversals (CS374)
- Iterators -- 2nd less obvious topic -- Hard to implement from scratch -- should focus on understanding how to use them with EVERY data structure -- it would make your life a lot easier
(- "Vectors" -- after leraning about array, lists, stacks, and queues, std::vector can accomplish most of what these accomplish right away without you having to write any code from scratch -- Vectors are very useful in C++, I mainly used them in POTD's)

- BST
- AVL (didn't get tested on that much, but the rotations are still relevant material in my opinion)
- BTree
- (KDTree -- cool structure, but you only ever see it in the MP, never on theory or coding exams)
- Hashing (Seperate Chaining, Linear Hashing, and Double Hashing -- understand Resizes/Rehashing and everything else will fall into place!)
- (Along with hashing, try to start to understand std::maps, specifically mapping and dictionary finding using a KEY and a VALUE)
- Priority Queue (-- we mainly call these as Heaps and Min/Max Heaps. We focus on a Min Heap implementation and Heapify. Understand Heapify!)
- Disjoint Sets (pretty easy -- effective when applied with BFS/DFS. Easy because they are used commonly in graphs)
- Graphs (BIG CS TOPIC, but only semi-big in CS225. This is really just introducing the whole concept, but still, it can be complicated material because it can require using a lot of multiple data structures together -- Deals with Graph Theory logic you learned in CS173 and will continue to a lot of future applications such as A.I (some CS400+ class) and CS374 Algorithms (oh boy, this is a tough class).
(Graphs include 3 implementations, but really you just want to focus on the Adjacency List (lab and mp code for AdjList DOES NOT reflect exam code unlike older exames. Adjlist implementation expected on FINAL. Graphs also deal a lot with find paths, shortest paths Algorithms, and weighted/directed graph scenarios. Pay attention at the end and enjoy the content)
