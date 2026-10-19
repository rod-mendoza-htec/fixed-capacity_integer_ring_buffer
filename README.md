# Day 1 — Fixed-Capacity Integer Ring Buffer
Implementation of a ring buffer that stores integers in with a fixed capacity.

## Compilation
```bash
cmake -S . -B build
cmake --build build
```

## Tests
```bash
ctest --test-dir build --output-on-failure -V
```

## Index
- `head`: index of the oldest element in the buffer. This is the element removed when a pop occurs.
- `tail`: index where a new element (push) will be stored.

## Invariants

- `size` <= INT_RING_CAPACITY`: there won't be more elements stored than its capacity.
- `head` < INT_RING_CAPACITY`: read index always points to a valid position
- `tail` < INT_RING_CAPACITY`: write index always points to a valid position

## Questions

1. **Why are head and tail insufficient by themselves to distinguish a
full buffer from an empty buffer in this design?**
- Because when the buffer is either full or empty, `head` and `tail` are the same
2. **What does each field represent immediately before and after a
successful pop?**
* Before: `head`: points to the element to be eliminated. `tail`: points to the next slot to write. `size`: number of elements in the array.
* fter: `head`: advances to the next oldest element. `tail`: does not change. `size`: decreases by 1

3. **Why is writing to data[INT_RING_CAPACITY] invalid even though the
address is one position past the array?**
- Because array indices start at 0 and end at capacity minus 1. INT_RING_CAPACITY is not a valid index.
4. **Which invariants must be true after every public function returns?**
- 0 <= head < INT_RING_CAPACITY
- 0 <= tail < INT_RING_CAPACITY
5. **What is the time complexity of push, pop, and peek?**
- The time complexity is O(1). None of these operations sorts the elements in the buffer